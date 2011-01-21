#include "smileyitem.h"
#include <QPainter>
#include <QGraphicsSceneHoverEvent>
#include <cmath>

/*
 * Adapted from Eyes.c (from xeyes distribution)
 */
QPoint computePupil (const QPoint &center, const QPoint &focus, int eyeWidth, int eyeHeight)
{
    QPointF dPoint = focus-center;
    if (dPoint.x() == 0 && dPoint.y() == 0) {
        return center;
    } else {
        double angle = atan2 (dPoint.y(), dPoint.x());
        double cosa = cos (angle);
        double sina = sin (angle);
        double h = hypot (eyeHeight * cosa, eyeWidth * sina);
        double x = (eyeWidth * eyeHeight) * cosa / h;
        double y = (eyeWidth * eyeHeight) * sina / h;
        double dist = hypot (x*0.7, y*0.7); //?
        if (dist > hypot (dPoint.x(), dPoint.y())) {
            return dPoint.toPoint()+center;
        } else {
            return QPoint(dist*cosa+center.x(), dist*sina+center.y());
        }
    }
}

SmileyItem::SmileyItem()
{
    setAcceptHoverEvents(true);
    m_bigEyes = false;
    m_smileSize = 100;
}

QRectF SmileyItem::boundingRect() const {
    return QRectF(-50, -50, 100, 100);
}

QPainterPath SmileyItem::shape() const {
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}

void SmileyItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget ) {
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());

    paintEye(painter, QPointF(-15,-25), m_focus, m_bigEyes);
    paintEye(painter, QPointF(15, -25), m_focus, m_bigEyes);

    paintSmile(painter, QRectF(-33, -12, 66, 50), 0.9*m_smileSize);
}

void SmileyItem::paintEye(QPainter *painter, const QPointF &pt, const QPointF &focus, bool bigEye) {
    QPen pen(Qt::black);
    pen.setWidthF(1.5);
    painter->setPen(pen);
    painter->setBrush(Qt::white);
    QSize eyeSize(6,12);
    if(bigEye)
        eyeSize+=QSize(2,4);
    painter->drawEllipse(pt, eyeSize.width(), eyeSize.height());


    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::black);
    QPoint pupilPoint = focus.isNull() ? pt.toPoint() : computePupil(pt.toPoint(), focus.toPoint(),
                                                                     eyeSize.width(), eyeSize.height());
    painter->drawEllipse(pupilPoint, 2, 2);
}

void SmileyItem::paintSmile(QPainter *painter, const QRectF &rect, int angle) {
    QPen pen(Qt::black);
    pen.setWidthF(1.5);
    painter->setPen(pen);
    painter->drawArc(rect, -(90-angle)*16, -2*angle*16);
}

void SmileyItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    m_focus = event->pos();
    update();
}

void SmileyItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event) {
    m_focus = event->pos();
    update();
}

void SmileyItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    m_focus = QPointF();
    update();
}

void SmileyItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    m_bigEyes = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void SmileyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    m_bigEyes = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

int SmileyItem::smileSize() const {
    return m_smileSize;
}

void SmileyItem::setSmileSize(int size) {
}
