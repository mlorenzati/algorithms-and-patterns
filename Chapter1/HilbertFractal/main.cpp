#include <QApplication>
#include "hilbert.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    Hilbert h;
    h.render();

    return app.exec();
}