#pragma once
#include <QFrame>
#include <QTimer>
#include <QDateTime>
#include <QVector>
#include <QPoint>
#include "player.h"
#include "missile.h"
#include <QMediaPlayer>

class Scenary : public QFrame
{
    Q_OBJECT
public:
    Scenary(QWidget* parent = NULL);
    void draw();
    void define_Scenary(int type);
    int Colision_Player(Player *_p);
    int Colision_Missile_Scenary_white(Missile *_t);
    int Colision_Missile_Scenary_black(Missile *_t);
    int Colision_cenario();
    void movePalyer();
    Missile * getSpecial();

    // time animation improved
    qint64 _last_time_60fps;
    qint64 _accumulator60;
    int _max_fps;
    int _counter;
    float _constant_dt;


    void paintEvent(QPaintEvent* event);
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent *);
    void resizeEvent(QResizeEvent* event);

private slots:
    void _tick();


private:

    Player *_p1;
    Player *_p2;
    QVector< QVector <QPoint> > RectPos;
    QVector< QVector <int> >  RectColors;
    QVector <Missile*> _special;
    QMediaPlayer *_colision_music;
    int _Rows;
    int _Col;
    int _w_sz;
    int _h_sz;
    int _x;
    int _y;
    int _cont_t;

};
