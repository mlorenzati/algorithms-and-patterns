#include <QApplication>
#include "maze.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    Maze m;
    m.render();
    
    return app.exec();
}