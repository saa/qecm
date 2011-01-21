#include "listmodel.h"

ListModel::ListModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

int ListModel::rowCount(const QModelIndex &parent) const
{
    return 0;
}

QVariant ListModel::data(const QModelIndex &index, int role) const
{
    return QVariant();
}
