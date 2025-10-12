#include "graph.h"
#include <fstream>
#include <limits>
#include <sstream>
#include <QColor>

const int INF = std::numeric_limits<int>::max();

Graph::Graph(GraphicsConsole &gc) : gc(gc) {
    QObject::connect(&gc, &GraphicsConsole::resized, this, &Graph::render);
}

void Graph::render() {
    dijkstraReset();
    dijkstraInit(sourceNode);
    draw();
}

void Graph::clear() {
    nodes.clear();
    edges.clear();
    dist.clear();
    prev.clear();
    visited.clear();
    running = false;
}

bool Graph::loadFromFile(const std::string &filename) {
    clear();
    std::ifstream file(filename);
    if (!file.is_open())
        return false;

    int n;
    file >> n;
    for (int i = 0; i < n; i++) {
        std::string label; int x, y;
        file >> label >> x >> y;
        Node node;
        node.label = label;
        node.x = x;
        node.y = y;
        nodes.push_back(node);
    }

    int e;
    file >> e;
    for (int i = 0; i < e; i++) {
        int from, to, w;
        file >> from >> to >> w;
        edges.push_back({from, to, w});
    }
    return true;
}

void Graph::dijkstraReset()
{
    dist.assign(nodes.size(), std::numeric_limits<int>::max());
    prev.assign(nodes.size(), -1);
    visited.assign(nodes.size(), false);
    while (!pq.empty()) pq.pop();
    running = false;
    gc.clear();
    draw();
}

void Graph::draw() {
    gc.clear();

    // Dibujar Edges
    for (auto &e : edges) {
        gc.setColor(QColor(0, 0, 0)); // negro
        gc.drawLine(nodes[e.from].x, nodes[e.from].y,
                    nodes[e.to].x, nodes[e.to].y);

        int mx = (nodes[e.from].x + nodes[e.to].x) / 2;
        int my = (nodes[e.from].y + nodes[e.to].y) / 2;
        gc.drawText(mx - 5, my - 10, QString::number(e.weight));
    }

    // Draw nodes
    for (size_t i = 0; i < nodes.size(); i++) {
        if (!visited.empty()) {
            if (visited[i]) gc.setColor(QColor(0, 200, 0));           // verde
            else if (dist[i] < INF) gc.setColor(QColor(255, 255, 0)); // amarillo
            else gc.setColor(QColor(180, 180, 180));                  // gris
        } else gc.setColor(QColor(200, 200, 200));

        gc.fillRect(nodes[i].x - 10, nodes[i].y - 10, 20, 20);
        gc.setColor(QColor(0, 0, 0));
        gc.drawText(nodes[i].x - 5, nodes[i].y + 5, QString::fromStdString(nodes[i].label));
    }
}

void Graph::dijkstraInit(int source) {
    dist.assign(nodes.size(), INF);
    prev.assign(nodes.size(), -1);
    visited.assign(nodes.size(), false);
    sourceNode = source;
    dist[source] = 0;
    while (!pq.empty()) pq.pop();
    pq.push({0, source});
    running = true;
}

void Graph::dijkstraStep(GraphicsConsole &gc) {
    if (!running || pq.empty()) {
        running = false;
        return;
    }

    auto [d, u] = pq.top(); pq.pop();
    if (visited[u]) return;
    visited[u] = true;

    // Relajar vecinos
    for (auto &e : edges) {
        if (e.from == u) {
            int v = e.to;
            if (dist[u] + e.weight < dist[v]) {
                dist[v] = dist[u] + e.weight;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    gc.clear();
    draw();

    // Dibujar camino parcial en rojo
    gc.setColor(QColor(255, 0, 0));
    for (size_t i = 0; i < nodes.size(); i++) {
        if (prev[i] != -1) {
            gc.drawLine(nodes[i].x, nodes[i].y,
                        nodes[prev[i]].x, nodes[prev[i]].y);
        }
    }
}