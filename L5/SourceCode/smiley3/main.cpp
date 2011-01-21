#include <QtGui/QApplication>
#include <QLayout>
#include <QSlider>
#include "smiley.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    QVBoxLayout *l = new QVBoxLayout(&w);

    Smiley *smiley = new Smiley;
    QSlider *slider = new QSlider(Qt::Horizontal);
    l->addWidget(smiley);
    l->addWidget(slider);
    slider->setRange(0,100);
    QObject::connect(slider, SIGNAL(valueChanged(int)), smiley, SLOT(setSmileSize(int)));
    QObject::connect(smiley, SIGNAL(smileSizeChanged(int)), slider, SLOT(setValue(int)));
    slider->setValue(smiley->smileSize());
    w.show();
    return a.exec();
}
