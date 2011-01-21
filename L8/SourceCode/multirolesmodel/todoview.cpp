#include "todoview.h"
#include <QDate>

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
    rowData[1]->setData(QDate(2010, 12, 1), Qt::DisplayRole);
    rowData[2]->setData(100, Qt::DisplayRole);
    m_model->appendRow(rowData);
    updateEntry(rowData[0]);

    rowData.clear();
    for(int i=0;i<3;++i) rowData.append(new QStandardItem);
    rowData[0]->setText("Do the laundry");
    rowData[1]->setData(QDate(2010, 8, 31), Qt::DisplayRole);
    rowData[2]->setData(0, Qt::DisplayRole);
    m_model->appendRow(rowData);
    updateEntry(rowData[0]);

    rowData.clear();
    for(int i=0;i<3;++i) rowData.append(new QStandardItem);
    rowData[0]->setText("Develop my first Qt project");
    rowData[1]->setData(QDate(2010, 11, 16), Qt::DisplayRole);
    rowData[2]->setData(50, Qt::DisplayRole);
    m_model->appendRow(rowData);
    updateEntry(rowData[0]);


    setModel(m_model);
}

void TodoView::updateEntry(QStandardItem *item)
{
    // enter your code here
}
