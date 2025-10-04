#include "maze.h"
#include <QObject>
#include <QVector>
#include <QStack>
#include <QThread>
#include <QApplication>
#include <QRandomGenerator>

Maze::Maze(QObject *parent) : QObject(parent), gc(GraphicsConsole::getInstance()) {
    gc.setWindowTitle("Maze Generator & Solver");
    gc.resize(800, 800);
    gc.show();
    solveTimer.setSingleShot(true);

    QObject::connect(&gc, &GraphicsConsole::resized, this, &Maze::render);
    QObject::connect(&solveTimer, &QTimer::timeout, this, &Maze::solveLater);
}

void Maze::render() {
    if (solveTimer.isActive()) {
        solveTimer.stop();
    }
        
    gridX = gc.width() / CELL_SIZE;
    gridY = gc.height() / CELL_SIZE;

    generateMaze();
    drawMaze();
    gc.update();

    solveTimer.start(1000);
}

void Maze::solveLater() {
    solveMaze();
}

void Maze::generateMaze() {
    maze = QVector<QVector<Cell>>(gridY, QVector<Cell>(gridX));
    QStack<QPair<int, int>> stack;

    int cx = 0, cy = 0;
    maze[cy][cx].visited = true;
    stack.push({cx, cy});

    while (!stack.isEmpty()) {
        auto [x, y] = stack.top();
        QVector<QPair<int, int>> neighbors;

        if (y > 0 && !maze[y - 1][x].visited) neighbors.push_back({x, y - 1});
        if (x < gridX - 1 && !maze[y][x + 1].visited) neighbors.push_back({x + 1, y});
        if (y < gridY - 1 && !maze[y + 1][x].visited) neighbors.push_back({x, y + 1});
        if (x > 0 && !maze[y][x - 1].visited) neighbors.push_back({x - 1, y});

        if (!neighbors.isEmpty()) {
            auto [nx, ny] = neighbors[QRandomGenerator::global()->bounded(neighbors.size())];
            removeWall(x, y, nx, ny);
            maze[ny][nx].visited = true;
            stack.push({nx, ny});
        } else {
            stack.pop();
        }
    }
}

void Maze::removeWall(int x, int y, int nx, int ny) {
    if (ny == y - 1) { // up
        maze[y][x].walls[0] = false;
        maze[ny][nx].walls[2] = false;
    } else if (nx == x + 1) { // right
        maze[y][x].walls[1] = false;
        maze[ny][nx].walls[3] = false;
    } else if (ny == y + 1) { // down
        maze[y][x].walls[2] = false;
        maze[ny][nx].walls[0] = false;
    } else if (nx == x - 1) { // left
        maze[y][x].walls[3] = false;
        maze[ny][nx].walls[1] = false;
    }
}

void Maze::drawMaze() {
    gc.clear();
    gc.setColor(Qt::black);

    for (int y = 0; y < gridY; ++y) {
        for (int x = 0; x < gridX; ++x) {
            int px = x * CELL_SIZE;
            int py = y * CELL_SIZE;
            const Cell &c = maze[y][x];

            if (c.walls[0]) gc.drawLine(px, py, px + CELL_SIZE, py);
            if (c.walls[1]) gc.drawLine(px + CELL_SIZE, py, px + CELL_SIZE, py + CELL_SIZE);
            if (c.walls[2]) gc.drawLine(px, py + CELL_SIZE, px + CELL_SIZE, py + CELL_SIZE);
            if (c.walls[3]) gc.drawLine(px, py, px, py + CELL_SIZE);
        }
    }
}

bool Maze::solveMaze() {
    QVector<QVector<bool>> visited(gridY, QVector<bool>(gridX, false));
    return backtrack(0, 0, visited);
}

bool Maze::backtrack(int x, int y, QVector<QVector<bool>> &visited) {
   if (x == gridX - 1 && y == gridY - 1) {
        markCell(x, y, Qt::green);
        return true;
    }

    visited[y][x] = true;
    markCell(x, y, Qt::blue);

    struct Move { int dx, dy, wall; };
    QVector<Move> dirs = {{0,-1,0}, {1,0,1}, {0,1,2}, {-1,0,3}};

    for (const auto &d : dirs) {
        int nx = x + d.dx, ny = y + d.dy;
        if (nx < 0 || ny < 0 || nx >= gridX || ny >= gridY) continue;
        if (visited[ny][nx]) continue;
        if (maze[y][x].walls[d.wall]) continue;

        if (backtrack(nx, ny, visited))
            return true;
    }

    markCell(x, y, Qt::red); // dead end
    return false;
}

void Maze::markCell(int x, int y, const QColor &color) {
    gc.setColor(color);
    int px = x * CELL_SIZE + CELL_SIZE / 4;
    int py = y * CELL_SIZE + CELL_SIZE / 4;
    int s = CELL_SIZE / 2;
    gc.fillRect(px, py, s, s);
    gc.update();
    QThread::msleep(RESOLVE_DELAY);  // Pause some ms
    QApplication::processEvents();
}