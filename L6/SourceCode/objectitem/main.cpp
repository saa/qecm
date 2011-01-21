#include <QtGui/QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLayout>
#include <QSlider>
#include "smileyitem.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    QGraphicsView *view = new QGraphicsView;
    QGraphicsScene scene;
    view->setScene(&scene);
    SmileyItem *item = new SmileyItem;
    scene.addItem(item);
    item->setFlag(QGraphicsItem::ItemIsMovable);

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0,100);
    slider->setValue(item->smileSize());
    QObject::connect(slider, SIGNAL(valueChanged(int)), item, SLOT(setSmileSize(int)));
    QObject::connect(item, SIGNAL(smileSizeChanged(int)), slider, SLOT(setValue(int)));

    QVBoxLayout *l = new QVBoxLayout(&w);
    l->addWidget(view);
    l->addWidget(slider);

    view->setRenderHint(QPainter::Antialiasing);
    w.show();
    w.resize(600,400);
    return a.exec();
}
