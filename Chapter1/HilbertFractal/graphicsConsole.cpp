#include "graphicsConsole.h"
#include <QVBoxLayout>
#include <QMenuBar>
#include <QMessageBox>
#include <QResizeEvent>

GraphicsConsole::GraphicsConsole(QWidget* parent)
    : QMainWindow(parent)
{
    setWindowTitle("Graphics Console - Qt6");
    resize(800, 600);

    initUI();
}

void GraphicsConsole::initUI()
{
    canvas = new CanvasWidget(this);
    setCentralWidget(canvas);

    QMenu* fileMenu = menuBar()->addMenu("File");
    QAction* clearAction = fileMenu->addAction("Clear");
    QAction* hideAction  = fileMenu->addAction("Hide");
    QMenu* helpMenu = menuBar()->addMenu("Help");
    QAction* aboutAction = helpMenu->addAction("About");

    connect(clearAction, &QAction::triggered, this, &GraphicsConsole::clear);
    connect(hideAction, &QAction::triggered, this, &QWidget::hide);
    connect(aboutAction, &QAction::triggered, [this](){
        QMessageBox::information(this, "About", "GraphicsConsole - Qt6 Version");
    });

    buffer = QImage(size(), QImage::Format_ARGB32);
    buffer.fill(Qt::white);
}

void GraphicsConsole::resizeEvent(QResizeEvent* event)
{
    QImage newBuf(event->size(), QImage::Format_ARGB32);
    newBuf.fill(Qt::white);
    
    // Keep old drawing? (just for fun)
    if (false) {
        QPainter p(&newBuf);
        p.drawImage(0,0, buffer);
    }

    buffer = newBuf;
    emit resized();

    QMainWindow::resizeEvent(event);
}

void GraphicsConsole::clear()
{
    buffer.fill(Qt::white);
    canvas->update();
}

void GraphicsConsole::drawRect(int x, int y, int w, int h)
{
    QPainter p(&buffer);
    p.setPen(color);
    p.drawRect(x, y, w, h);
    canvas->update();
}

void GraphicsConsole::fillRect(int x, int y, int w, int h)
{
    QPainter p(&buffer);
    p.setBrush(color);
    p.setPen(Qt::NoPen);
    p.drawRect(x, y, w, h);
    canvas->update();
}

void GraphicsConsole::drawLine(int x1, int y1, int x2, int y2)
{
    QPainter p(&buffer);
    p.setPen(color);
    p.drawLine(x1, y1, x2, y2);
    canvas->update();
}

void GraphicsConsole::drawOval(int x, int y, int w, int h)
{
    QPainter p(&buffer);
    p.setPen(color);
    p.drawEllipse(x, y, w, h);
    canvas->update();
}

void GraphicsConsole::fillOval(int x, int y, int w, int h)
{
    QPainter p(&buffer);
    p.setBrush(color);
    p.setPen(Qt::NoPen);
    p.drawEllipse(x, y, w, h);
    canvas->update();
}

// --- CanvasWidget implementation ---
GraphicsConsole::CanvasWidget::CanvasWidget(GraphicsConsole* parent)
    : QWidget(parent), gc(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

void GraphicsConsole::CanvasWidget::paintEvent(QPaintEvent* event)
{
    QPainter p(this);
    p.drawImage(0, 0, gc->buffer);
}