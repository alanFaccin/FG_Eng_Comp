/* Copyright (C) 2014 Karl Phillip Buhr <karlphillip@gmail.com>
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike License.
 * To view a copy of this license, visit:
 *      https://creativecommons.org/licenses/by-sa/2.5/legalcode
 *
 * Or to read the human-readable summary of the license:
 *      https://creativecommons.org/licenses/by-sa/2.5/
 */
#include "time_anim_improved.h"
#include <qDebug>

TimeAnimationImproved::TimeAnimationImproved(QWidget* parent) : QWidget(parent)
{
    _counter = 0;
    _accumulator60 = 0;
    _max_fps = 60;
    _constant_dt = 1000 / _max_fps;
    _last_time_60fps = QDateTime::currentMSecsSinceEpoch();

    // Start timer
    QTimer::singleShot(1000/_max_fps, this, SLOT(_tick()));
}

void TimeAnimationImproved::_tick()
{
    /* Decide which canvas should be updated */

    qint64 now = QDateTime::currentMSecsSinceEpoch();

    // 60 FPS canvas must be draw every time, so we ignore _counter
    {
        // Compute how much time passed since the last update
        qint64 passed = now - _last_time_60fps;

        _accumulator60 += passed;
        while (_accumulator60 >= _constant_dt)
        {
            _accumulator60 -= _constant_dt;
        }

        _tabuleiro->draw();
        _last_time_60fps = now;
    }

    _counter++;
    _counter = _counter % 60; // Ranges from 0 to 59

    //qDebug()<<"tick";

    // Reset the timer
    QTimer::singleShot(1000/_max_fps, this, SLOT(_tick()));

}



