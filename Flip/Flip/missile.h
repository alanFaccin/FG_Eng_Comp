#pragma once
#include <QFrame>
#include <QMediaPlayer>


class Missile : public QFrame
{
Q_OBJECT
public:
    Missile(QFrame* parent = NULL, const QColor color = Qt::black, int x=0, int y=0);
    void draw(QPainter &p);
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
    void setDirection(char d);
    char getDirection();
    void set_h_sz(int h);
    void set_w_sz(int w);
    int get_h_sz();
    int get_w_sz();
    void setColor(QColor c);
    QColor getColor();
    QMediaPlayer* getFireSound();
    void setActive(bool act);
    bool getActive();
    void setQtdTiro(int t);
    int getQtdTiro();
    void addTiro();
    void resetTiro();

private slots:
    void move();

private:
    QColor _color;
    QMediaPlayer *_fire_sound;
    int _x;
    int _y;
    int _h_sz;
    int _w_sz;
    char _direction;
    bool _active;
    int _qtd_tiro;
};
