#ifndef FRACTAL_H
#define FRACTAL_H
#include "graphicsConsole.h"

class Fractal : public QObject {
    Q_OBJECT
public:
    Fractal();
public slots:
    void render();

private:
    void star(int x, int y, int r);
    void box(int x, int y, int r);

    GraphicsConsole& gc;
};

#endif