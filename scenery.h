#pragma once
#include <QFrame>
#include <QTimer>
#include <QDateTime>
#include <QVector>
#include <QPoint>

class Scenary : public QFrame
{
    Q_OBJECT
public:
    Scenary(QWidget* parent = NULL);
    void draw();
    void define_Scenary(int type);

    void paintEvent(QPaintEvent* event);
    void keyPressEvent(QKeyEvent* event);
    void resizeEvent(QResizeEvent* event);

private:

    QVector< QVector <QPoint> > RectPos;
    QVector< QVector <int> >  RectColors;
    int _Rows;
    int _Col;
    int _w_sz;
    int _h_sz;
    int _x;
    int _y;
};
