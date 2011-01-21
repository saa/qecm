#include "smiley.h"
#include <QPainter>
#include <QMouseEvent>
#include <cmath>

Smiley::Smiley(QWidget *parent)
    : QWidget(parent)
{
    m_smileSize = 100;
}

QSize Smiley::sizeHint() const {
    return QSize(200,200);
}

void Smiley::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QPoint center = rect().center();
    // draw face
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::yellow);
    int size = qMin(width(), height());
    painter.drawEllipse(center, size/2, size/2);

    // draw eyes

    int eyeHeight = center.y() - size/4;
    QPoint leftEye(center.x()-size/8, eyeHeight);
    QPoint rightEye(center.x()+size/8, eyeHeight);

    paintEye(&painter, leftEye, size/8, focusPoint.isNull() ? leftEye : focusPoint);
    paintEye(&painter, rightEye, size/8, focusPoint.isNull() ? rightEye : focusPoint);

    // draw smile

    int smileHeight = center.y()-size/8;

    paintSmile(&painter, QRect(center.x()-size/3, smileHeight, 2*size/3, size/2), 0.9*m_smileSize);

}

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


void Smiley::paintEye(QPainter *painter, const QPoint &pt, int size, const QPoint &focus) {
    painter->save();
    QPen pen(Qt::black);
    pen.setWidth(2);
    painter->setPen(pen);
    painter->setBrush(Qt::white);
    painter->drawEllipse(pt, size/2, size);

    pen.setWidth(0);
    painter->setPen(pen);
    painter->setBrush(Qt::black);
    painter->drawEllipse(computePupil(pt, focus, size/2, size), size/8, size/8);
    painter->restore();
}

void Smiley::paintSmile(QPainter *painter, const QRect &r, int angle) {
    painter->save();
    
    // enter your code here
    
    painter->restore();
}

void Smiley::mousePressEvent(QMouseEvent *me) {
    focusPoint = me->pos();
    update();
}

void Smiley::mouseMoveEvent(QMouseEvent *me) {
    focusPoint = me->pos();
    update();
}

void Smiley::mouseReleaseEvent(QMouseEvent *) {
    focusPoint = QPoint();
    update();
}

void Smiley::setSmileSize(int size) {
    // enter your code here
}

int Smiley::smileSize() const {
    return m_smileSize;
}
