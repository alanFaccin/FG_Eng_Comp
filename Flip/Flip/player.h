#pragma once
#include <QPoint>
#include <QVector>
#include "missile.h"
#include <QFrame>


class Player: public QFrame
{
    Q_OBJECT
public:
    Player(QFrame* parent = NULL, const QColor color = Qt::black, int x=0, int y=0);
    void draw(QPainter& p);
    void draw2();
    void paintEvent(QPaintEvent* event);
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
    int getH_size();
    int getW_size();
    void setH_size(int h);
    void setW_size(int w);
private slots:
    void _teste();
private:
    QColor _color;
    int _x;
    int _y;
    int _h_sz;
    int _w_sz;
    QVector <Missile> _municao;
};
