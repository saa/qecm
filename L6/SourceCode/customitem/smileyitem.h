#ifndef SMILEYITEM_H
#define SMILEYITEM_H

#include <QGraphicsItem>

class SmileyItem : public QGraphicsItem
{
public:
    SmileyItem();
    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 );
protected:
    void paintEye(QPainter *painter, const QPointF &pt);
    void paintSmile(QPainter *painter, const QRectF &rect);
};

#endif // SMILEYITEM_H
