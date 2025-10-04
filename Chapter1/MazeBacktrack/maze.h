#ifndef MAZE_H
#define MAZE_H

#include "graphicsConsole.h"
#include <QObject>
#include <QColor>
#include <QTimer>

class Maze : public QObject
{
    Q_OBJECT

public:
    Maze(QObject *parent = nullptr);

public slots:
    void render();
    void solveLater();
private:
    struct Cell {
        bool visited = false;
        bool walls[4] = {true, true, true, true}; // top, right, bottom, left
    };

    static constexpr int CELL_SIZE = 20;
    static constexpr int RESOLVE_DELAY = 5;
    int gridX;
    int gridY;

    QVector<QVector<Cell>> maze;
    GraphicsConsole &gc;
    QTimer solveTimer;

    void generateMaze();
    void removeWall(int x, int y, int nx, int ny);
    void drawMaze();
    bool solveMaze();
    bool backtrack(int x, int y, QVector<QVector<bool>> &visited);
    void markCell(int x, int y, const QColor &color);
};

#endif