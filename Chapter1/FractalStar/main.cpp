#include <QApplication>
#include "fractal.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    Fractal f;
    f.render();

    return app.exec();
}