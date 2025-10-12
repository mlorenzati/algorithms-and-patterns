#include <QApplication>
#include "graphicsConsole.h"
#include "graph.h"
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    GraphicsConsole &gc = GraphicsConsole::getInstance();
    gc.setWindowTitle("Graph visualizer - Dijkstra");
    gc.show();

    Graph graph(gc);
    if (!graph.loadFromFile("graph.conf")) {
        qWarning("Could not load graph.conf");
        return -1;
    }

    graph.draw();

    int source = 0; // Nodo inicial
    graph.dijkstraInit(source);

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        graph.dijkstraStep(gc);
    });
    timer.start(800);

    return app.exec();
}