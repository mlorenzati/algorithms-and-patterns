#ifndef HILBERT_H
#include "graphicsConsole.h"

#include <QObject>
#include <QColor>
#include "graphicsConsole.h"  // Your GraphicsConsole header

class Hilbert : public QObject
{
    Q_OBJECT

public:
    Hilbert(QObject *parent = nullptr);
    void A(int i);
    void B(int i);
    void C(int i);
    void D(int i);

public slots:
    void render();


private:
    GraphicsConsole &gc;
    int x = 0, y = 0, h = 0;
    static constexpr int n = 5;
    static constexpr int h0 = 512;
};

#define HILBERT_H
#endif