#ifndef SMILEY_H
#define SMILEY_H

#include <QtGui/QWidget>

class Smiley : public QWidget
{
public:
    Smiley(QWidget *parent = 0);
    QSize sizeHint() const;
    int smileSize() const;
public slots:
    void setSmileSize(int);

protected:
    void paintEvent(QPaintEvent *);
    void paintEye(QPainter *painter, const QPoint &pt, int size, const QPoint &focus = QPoint());
    void paintSmile(QPainter *painter, const QRect &r, int angle);

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
private:
    QPoint focusPoint;
    int m_smileSize;
};

#endif // SMILEY_H
