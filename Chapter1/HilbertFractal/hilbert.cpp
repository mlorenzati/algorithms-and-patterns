#include "hilbert.h"
#include <QObject>
#include <algorithm>

Hilbert::Hilbert(QObject *parent) : QObject(parent), gc(GraphicsConsole::getInstance()) {
    GraphicsConsole *pGc = &gc;
    QObject::connect(pGc, &GraphicsConsole::resized, this, &Hilbert::render);
    gc.setWindowTitle("Curvas de Hilbert...");
    gc.resize(h0, h0);
    gc.show();
}

void Hilbert::render() {
    QVector<QColor> colors = {Qt::red, Qt::blue, Qt::yellow, Qt::green, Qt::black, QColorConstants::Svg::orange };

    gc.setColor(Qt::red);
    
    int maxx = gc.getCanvas()->width();
    int maxy = gc.getCanvas()->height();

    h = std::min(maxx, maxy);

    int i = 0;
    int x0 = h / 2;
    int y0 = x0;

    do {
        gc.setColor(colors[i % colors.size()]);
        ++i;
        h /= 2;
        x0 += h / 2;
        y0 += h / 2;
        x = x0;
        y = y0;
        A(i);
    } while (i != n);

    gc.update(); // repaint buffer to widget
}

void Hilbert::A(int i) {
    if (i > 0) {
        D(i - 1);
        gc.drawLine(x, y, x - h, y); x -= h;
        A(i - 1);
        gc.drawLine(x, y, x, y - h); y -= h;
        A(i - 1);
        gc.drawLine(x, y, x + h, y); x += h;
        B(i - 1);
    }
}

void Hilbert::B(int i) {
    if (i > 0) {
        C(i - 1);
        gc.drawLine(x, y, x, y + h); y += h;
        B(i - 1);
        gc.drawLine(x, y, x + h, y); x += h;
        B(i - 1);
        gc.drawLine(x, y, x, y - h); y -= h;
        A(i - 1);
    }
}

void Hilbert::C(int i) {
    if (i > 0) {
        B(i - 1);
        gc.drawLine(x, y, x + h, y); x += h;
        C(i - 1);
        gc.drawLine(x, y, x, y + h); y += h;
        C(i - 1);
        gc.drawLine(x, y, x - h, y); x -= h;
        D(i - 1);
    }
}

void Hilbert::D(int i) {
    if (i > 0) {
        A(i - 1);
        gc.drawLine(x, y, x, y - h); y -= h;
        D(i - 1);
        gc.drawLine(x, y, x - h, y); x -= h;
        D(i - 1);
        gc.drawLine(x, y, x, y + h); y += h;
        C(i - 1);
    }
}