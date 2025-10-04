#ifndef GRAPHICS_CONSOLE_H
#define GRAPHICS_CONSOLE_H

#include <QMainWindow>
#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QColor>
#include <QMenuBar>
#include <QPushButton>
#include <QTimer>

class GraphicsConsole : public QMainWindow
{
    Q_OBJECT
public:
    static GraphicsConsole& getInstance()
    {
        static GraphicsConsole instance;
        return instance;
    }

    void clear();
    void drawRect(int x, int y, int w, int h);
    void fillRect(int x, int y, int w, int h);
    void drawLine(int x1, int y1, int x2, int y2);
    void drawOval(int x, int y, int w, int h);
    void fillOval(int x, int y, int w, int h);
    QColor getColor() const { return color; }
    void setColor(const QColor& c) { color = c; }

    QWidget* getCanvas() { return canvas; }
signals:
    void resized();

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    GraphicsConsole(QWidget* parent = nullptr);
    GraphicsConsole(const GraphicsConsole&) = delete;
    GraphicsConsole& operator=(const GraphicsConsole&) = delete;

    class CanvasWidget : public QWidget
    {
    public:
        CanvasWidget(GraphicsConsole* parent);
    protected:
        void paintEvent(QPaintEvent* event) override;
    private:
        GraphicsConsole* gc;
    };

    void initUI();

    QImage buffer;
    CanvasWidget* canvas;
    QColor color = Qt::black;
};

#endif