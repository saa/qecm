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

    // enter your code here

    return QVariant();
}
