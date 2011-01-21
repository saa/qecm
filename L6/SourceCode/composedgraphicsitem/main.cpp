#include <QtGui/QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>


QGraphicsItem *addSmiley() {
    QPen thickPen(Qt::black);
    thickPen.setWidth(2);

    // add face
    QGraphicsEllipseItem *face = new QGraphicsEllipseItem(QRect(-50, -50, 100, 100));
    face->setPen(Qt::NoPen);
    face->setBrush(Qt::yellow);
    
    // enter your code here
    // add eyes
    // add smile
    return face;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsView w;
    QGraphicsScene scene;
    w.setScene(&scene);
    scene.addItem(addSmiley());

    w.setRenderHint(QPainter::Antialiasing);
    w.show();

    return a.exec();
}
