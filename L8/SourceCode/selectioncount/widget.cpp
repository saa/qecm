#include "widget.h"
#include <QLayout>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    m_model = new QStandardItemModel(0, 4, this);
    QStringList labels;
    labels.append("Column 1");
    labels.append("Column 2");
    labels.append("Column 3");
    labels.append("Column 4");
    m_model->setHorizontalHeaderLabels(labels);
    for(int j = 0; j<10; ++j) {
        QList<QStandardItem*> rowData;
        for(int i=0;i<4;++i)
            rowData.append(new QStandardItem(QString("Row %1 Column %2").arg(j+1).arg(i+1)));
        m_model->appendRow(rowData);
    }

    m_view = new QTableView(this);
    m_view->setModel(m_model);
    m_view->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_label = new QLabel(this);

    QVBoxLayout *l = new QVBoxLayout(this);
    l->addWidget(m_view);
    l->addWidget(m_label);
    updateLabelText(0);
}

void Widget::updateLabelText(int count) {
    switch(count){
    case 0: m_label->setText("No items selected"); return;
    case 1: m_label->setText("One item selected"); return;
    default: m_label->setText(QString("%1 items selected").arg(count)); return;
    }
}
