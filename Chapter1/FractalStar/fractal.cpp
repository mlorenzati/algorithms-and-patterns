#include "fractal.h"
#include <QObject>

Fractal::Fractal() : gc(GraphicsConsole::getInstance())
{
    gc.setWindowTitle("A Fractal Star");
    gc.resize(1024, 768);
    gc.show();
    GraphicsConsole *pGc = &gc;
    QObject::connect(pGc, &GraphicsConsole::resized, this, &Fractal::render);
}

void Fractal::render()
{
    int maxx = gc.getCanvas()->width();
    int maxy = gc.getCanvas()->height();

    int r = maxx / 8;
    int cx = maxx / 2;
    int cy = maxy / 2;

    star(cx, cy, r);
}

void Fractal::star(int x, int y, int r)
{
    if(r > 0)
    {
        star(x-r, y+r, r/2);
        star(x+r, y+r, r/2);
        star(x-r, y-r, r/2);
        star(x+r, y-r, r/2);
        box(x, y, r);
    }
}

void Fractal::box(int x, int y, int r)
{
    int left = x - r;
    int top  = y - r;

    gc.setColor(Qt::white);
    gc.fillRect(left, top, 2*r, 2*r);

    gc.setColor(Qt::blue);
    gc.drawRect(left, top, 2*r, 2*r);
}