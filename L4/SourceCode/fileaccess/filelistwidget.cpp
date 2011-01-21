#include "filelistwidget.h"

#include <QGridLayout>
#include <QPushButton>

#include <QFile>
#include <QTextStream>

FileListWidget::FileListWidget(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout *layout = new QGridLayout(this);
    QPushButton *addButton, *removeButton, *clearButton, *saveButton, *loadButton;
    layout->addWidget(m_entryField = new QLineEdit, 0, 0);
    layout->addWidget(addButton = new QPushButton("Add"), 0, 1);
    layout->addWidget(removeButton = new QPushButton("Remove"), 1, 1);
    layout->addWidget(clearButton = new QPushButton("Clear"), 2, 1);
    layout->addWidget(saveButton = new QPushButton("Save"), 4, 1);
    layout->addWidget(loadButton = new QPushButton("Load"), 5, 1);
    layout->addWidget(m_list = new QListWidget, 1, 0, 5, 1);

    connect(m_entryField, SIGNAL(returnPressed()), this, SLOT(addClicked()));
    connect(addButton, SIGNAL(clicked()), this, SLOT(addClicked()));
    connect(removeButton, SIGNAL(clicked()), this, SLOT(removeClicked()));
    connect(clearButton, SIGNAL(clicked()), m_list, SLOT(clear()));

    connect(saveButton, SIGNAL(clicked()), this, SLOT(saveClicked()));
    connect(loadButton, SIGNAL(clicked()), this, SLOT(loadClicked()));
}

void FileListWidget::addClicked()
{
    m_list->addItem(m_entryField->text());
    m_entryField->setText("");
    m_entryField->setFocus();
}

void FileListWidget::removeClicked()
{
    foreach (QListWidgetItem *item, m_list->selectedItems())
        delete item;
}

void FileListWidget::loadClicked()
{
    // Enter your code here
    //
    // The list widget is pointed at by m_list
}

void FileListWidget::saveClicked()
{
    // Enter your code here
    //
    // The list widget is pointed at by m_list
}
