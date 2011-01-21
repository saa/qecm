#ifndef SMILEYITEM_H
#define SMILEYITEM_H

#include <QGraphicsItem>

class SmileyItem : public QGraphicsObject
{
public:
    SmileyItem();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 );
    int smileSize() const;
public slots:
    void setSmileSize(int);
protected:
    void paintEye(QPainter *painter, const QPointF &pt, const QPointF &focus, bool bigEye);
    void paintSmile(QPainter *painter, const QRectF &rect, int angle);

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    QPointF m_focus;
    bool m_bigEyes;
    int m_smileSize;
};

#endif // SMILEYITEM_H
