#include "piedelegate.h"
#include <QPainter>

PieDelegate::PieDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

void PieDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QVariant value = index.data(Qt::BackgroundRole);
    if(value.isValid())
        painter->fillRect(option.rect, qvariant_cast<QColor>(value));

    painter->setRenderHint(QPainter::Antialiasing);
    QRect rect(option.rect.center().x() - option.rect.height()/2,
               option.rect.top(), option.rect.height(), option.rect.height());
    rect.adjust(2, 2, -2, -2);

    // enter your code here

    painter->setPen(Qt::black);
    painter->setBrush(Qt::NoBrush);
    painter->drawEllipse(rect);
}
