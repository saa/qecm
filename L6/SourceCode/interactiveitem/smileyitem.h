#ifndef SMILEYITEM_H
#define SMILEYITEM_H

#include <QGraphicsItem>

class SmileyItem : public QGraphicsItem
{
public:
    SmileyItem();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 );
protected:
    void paintEye(QPainter *painter, const QPointF &pt, const QPointF &focus, bool bigEye);
    void paintSmile(QPainter *painter, const QRectF &rect);

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    QPointF m_focus;
    bool m_bigEyes;
};

#endif // SMILEYITEM_H
