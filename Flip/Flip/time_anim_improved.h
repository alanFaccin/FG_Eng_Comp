#pragma once
#include "scenery.h"
#include <QHBoxLayout>
#include <QWidget>
#include <QGroupBox>
#include <QLabel>

class TimeAnimationImproved : public QWidget
{
    Q_OBJECT
public:
    TimeAnimationImproved(QWidget* parent = NULL);

public slots:
    //void reset();

private slots:
    void _tick();

private:

    QVBoxLayout* _main_layout;
    QGridLayout* _h_layout;
    Scenary * _tabuleiro;

    qint64 _last_time_60fps;
    qint64 _accumulator60;
    int _max_fps;
    int _counter;
    float _constant_dt;
};
