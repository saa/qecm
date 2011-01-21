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

    // add eyes
    QGraphicsEllipseItem *leftEye = new QGraphicsEllipseItem(QRectF(-6, -12, 12, 24), face);
    leftEye->setPen(thickPen);
    leftEye->setBrush(Qt::white);
    leftEye->setPos(-15, -25);

    QGraphicsEllipseItem *rightEye = new QGraphicsEllipseItem(QRectF(-6, -12, 12, 24), face);
    rightEye->setPen(thickPen);
    rightEye->setBrush(Qt::white);
    rightEye->setPos(15, -25);

    // add smile

    QPainterPath smileArc;
    QRect rect(-33, -15, 66, 50);
    smileArc.arcMoveTo(rect, 0);
    smileArc.arcTo(rect, 0, -180);
    QGraphicsPathItem *smile = new QGraphicsPathItem(smileArc, face);
    smile->setPen(thickPen);

    return face;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsView w;
    QGraphicsScene scene;
    w.setScene(&scene);

    QGraphicsItem *smiley1 = addSmiley();
    scene.addItem(smiley1);

    QGraphicsItem *smiley2 = addSmiley();
    scene.addItem(smiley2);

    QGraphicsItem *smiley3 = addSmiley();
    scene.addItem(smiley3);

    // enter your code here
    
    w.setRenderHint(QPainter::Antialiasing);
    w.show();

    return a.exec();
}
