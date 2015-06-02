#include "scenery.h"
#include <QApplication>
#include <QHBoxLayout>

int main(int argc, char *argv[])

{
    QApplication app(argc, argv);
    QWidget window;
    QHBoxLayout* _layout = new QHBoxLayout();

    window.setWindowTitle("Flip Game");

    Scenary tabuleiro(&window);

    _layout->addWidget(&tabuleiro);
    window.setLayout(_layout);
    _layout->setContentsMargins(0, 0, 0, 0);
    window.setMinimumSize(800,600);
    window.show();


    return app.exec();
}

