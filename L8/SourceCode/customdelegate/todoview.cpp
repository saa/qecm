#include "todoview.h"
#include <QDate>
#include "piedelegate.h"

TodoView::TodoView(QWidget *parent) : QTableView(parent)
{
    m_model = new QStandardItemModel(0, 3, this);
    QStringList labels;
    labels.append("Name");
    labels.append("Deadline");
    labels.append("Completed (in %)");
    m_model->setHorizontalHeaderLabels(labels);

    QList<QStandardItem*> rowData;
    for(int i=0;i<3;++i) rowData.append(new QStandardItem);
    rowData[0]->setText("Repair the car");
    rowData[0]->setData("The cooling system leaks", Qt::ToolTipRole);
    rowData[1]->setData(QDate(2010, 12, 1), Qt::DisplayRole);
    rowData[2]->setData(100, Qt::DisplayRole);
    m_model->appendRow(rowData);
    updateEntry(rowData[0]);

    rowData.clear();
    for(int i=0;i<3;++i) rowData.append(new QStandardItem);
    rowData[0]->setText("Do the laundry");
    rowData[0]->setData("The laundry is in the basket in the bathroom", Qt::ToolTipRole);
    rowData[1]->setData(QDate(2010, 8, 31), Qt::DisplayRole);
    rowData[2]->setData(0, Qt::DisplayRole);
    m_model->appendRow(rowData);
    updateEntry(rowData[0]);

    rowData.clear();
    for(int i=0;i<3;++i) rowData.append(new QStandardItem);
    rowData[0]->setText("Develop my first Qt project");
    rowData[0]->setData("Implement a 'hello Qt world' app", Qt::ToolTipRole);
    rowData[1]->setData(QDate(2010, 11, 16), Qt::DisplayRole);
    rowData[2]->setData(30, Qt::DisplayRole);
    m_model->appendRow(rowData);
    updateEntry(rowData[0]);


    setModel(m_model);
    connect(m_model, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(updateEntry(QStandardItem*)));

    setItemDelegateForColumn(2, new PieDelegate(this));
}

void TodoView::updateEntry(QStandardItem *item)
{
    int row = item->row();
    QList<QStandardItem*> items;
    items.append(m_model->item(row, 0));
    items.append(m_model->item(row, 1));
    items.append(m_model->item(row, 2));

    int completeness = items[2]->data(Qt::DisplayRole).toInt();
    QColor color = Qt::green;
    if(completeness == 0)
        color = Qt::red;
    else if(completeness < 100)
        color = Qt::yellow;
    foreach(QStandardItem *i, items)
        i->setBackground(color);

    QFont f;
    f.setBold(true);
    QDate currentDate = QDate::currentDate();
    if(items[1]->data(Qt::DisplayRole).toDate() < currentDate) {
        foreach(QStandardItem *i, items)
            i->setFont(f);
    } else {
        foreach(QStandardItem *i, items)
            i->setFont(QFont());
    }
}
