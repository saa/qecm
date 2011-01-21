#ifndef SMILEY_H
#define SMILEY_H

#include <QtGui/QWidget>

class Smiley : public QWidget
{
    Q_OBJECT

public:
    Smiley(QWidget *parent = 0);
    QSize sizeHint() const;
protected:
    void paintEvent(QPaintEvent *);
    void paintEye(QPainter *painter, const QPoint &pt, int size, const QPoint &focus = QPoint());
    void paintSmile(QPainter *painter, const QRect &r);

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
private:
    QPoint focusPoint;
};

#endif // SMILEY_H
