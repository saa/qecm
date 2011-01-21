#include "smiley.h"
#include <QPainter>

Smiley::Smiley(QWidget *parent)
    : QWidget(parent)
{
}

QSize Smiley::sizeHint() const {
    return QSize(200,200);
}

void Smiley::paintEvent(QPaintEvent *pe) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QPoint center = rect().center();
    int size = qMin(width(), height());
    
    // enter your code here
    // draw round face with center in 'center' and diameter of 'size'

    // draw eyes
    int eyeHeight = center.y() - size/4;
    QPoint leftEye(center.x()-size/8, eyeHeight);
    QPoint rightEye(center.x()+size/8, eyeHeight);

    paintEye(&painter, leftEye, size/8);
    paintEye(&painter, rightEye, size/8);

    // draw smile

    int smileHeight = center.y()-size/8;
    paintSmile(&painter, QRect(center.x()-size/3, smileHeight, 2*size/3, size/2));

}

void Smiley::paintEye(QPainter *painter, const QPoint &pt, int size) {
    // enter your code here
    // paint an ellipse with center in pt, height of size and width of size/2
}

void Smiley::paintSmile(QPainter *painter, const QRect &r) {
    // enter your code here
    // draw an arc inside the area of r
}
