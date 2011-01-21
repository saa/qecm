#include "listmodel.h"
#include <QColor>

ListModel::ListModel(QObject *parent) :
    QAbstractListModel(parent)
{
    m_items = QColor::colorNames();
}

int ListModel::rowCount(const QModelIndex &parent) const
{
    return m_items.size();
}

QVariant ListModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    const QString &name = m_items.at(row);
    if(role==Qt::DisplayRole)
        return name;
    QColor color = QColor(name);
    if(role == Qt::DecorationRole){
        return color;
    }
    if(role == Qt::ToolTipRole) {
        QString toolTip = QString("Color: %1<br/>"
                                  "RGB: %2, %3, %4<br/>"
                                  "HSV: %5, %6, %7");
            return toolTip.arg(name)
                          .arg(color.red())
                          .arg(color.green())
                          .arg(color.blue())
                          .arg(color.hue())
                          .arg(color.saturation())
                          .arg(color.value());
    }
    return QVariant();
}

Qt::ItemFlags ListModel::flags(const QModelIndex &index) const
{
    // enter your code here
    return QAbstractListModel::flags(index);
}

bool ListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    return false;
}
