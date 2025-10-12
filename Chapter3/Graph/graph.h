#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <queue>
#include <string>
#include <QObject>
#include "graphicsConsole.h"

struct Edge {
    int from;
    int to;
    int weight;
};

struct Node {
    std::string label;
    int x, y;
};


class Graph : public QObject
{
    Q_OBJECT

public:
    Graph(GraphicsConsole &gc);

    void clear();
    bool loadFromFile(const std::string &filename);
    void dijkstraInit(int source);
    void dijkstraStep(GraphicsConsole &gc);
    void dijkstraReset();
    void draw();

public slots:
    void render();
    
private:
    GraphicsConsole &gc;
    std::vector<Node> nodes;
    std::vector<Edge> edges;
    std::vector<int> dist;
    std::vector<int> prev;
    std::vector<bool> visited;

    int sourceNode;
    bool running = false;

    struct QItem {
        int d, v;
        bool operator>(const QItem &o) const { return d > o.d; }
    };
    std::priority_queue<QItem, std::vector<QItem>, std::greater<QItem>> pq;
};

#endif