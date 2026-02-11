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

    gc.clear(Qt::black);
    star(cx, cy, r);
}

//#define PREORDER
void Fractal::star(int x, int y, int r)
{
    if(r > 0)
    {
            #ifdef PREORDER
        box(x, y, r);
            #endif
        star(x-r, y+r, r/2);
        star(x+r, y+r, r/2);
        star(x-r, y-r, r/2);
        star(x+r, y-r, r/2);
            #ifndef PREORDER
        box(x, y, r);
            #endif
    }
}

void Fractal::box(int x, int y, int r)
{
    int left = x - r;
    int top  = y - r;

    gc.setColor(Qt::black);
    gc.fillRect(left, top, 2*r, 2*r);

    gc.setColor(Qt::red);
    gc.drawRect(left, top, 2*r, 2*r);
}