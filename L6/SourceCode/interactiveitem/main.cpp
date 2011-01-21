#include <QtGui/QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "smileyitem.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsView w;
    QGraphicsScene scene;
    w.setScene(&scene);
    SmileyItem *item = new SmileyItem;
    scene.addItem(item);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    w.setRenderHint(QPainter::Antialiasing);
    w.show();
    w.resize(600,400);
    return a.exec();
}
