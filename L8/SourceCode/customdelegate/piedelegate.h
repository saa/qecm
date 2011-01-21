#ifndef PIEDELEGATE_H
#define PIEDELEGATE_H

#include <QStyledItemDelegate>

class PieDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit PieDelegate(QObject *parent = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
signals:

public slots:

};

#endif // PIEDELEGATE_H
