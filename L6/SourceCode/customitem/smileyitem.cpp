#include "smileyitem.h"
#include <QPainter>

SmileyItem::SmileyItem()
{
}

QRectF SmileyItem::boundingRect() const {
    QRectF br;
    // enter your code here
    return br;
}

void SmileyItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget ) {
    // enter your code here
    paintEye(painter, QPointF());
    paintEye(painter, QPointF());
    paintSmile(painter, QRectF());
}

void SmileyItem::paintEye(QPainter *painter, const QPointF &pt) {
    // enter your code here
}

void SmileyItem::paintSmile(QPainter *painter, const QRectF &rect) {
    // enter your code here
}
