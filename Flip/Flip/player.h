#pragma once
#include <QPoint>
#include <QVector>
#include "missile.h"
#include <QFrame>


class Player: public QFrame
{
    Q_OBJECT
public:
    Player(QFrame* parent = NULL);
    void draw(QPainter& p);
    void paintEvent(QPaintEvent* event);
    void setX(int x);
    void setY(int y);
private slots:
    void _teste();
private:
    int _x;
    int _y;
    QVector <Missile> _municao;
};
