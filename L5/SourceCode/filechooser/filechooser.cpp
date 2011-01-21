#include "filechooser.h"
#include <QFileDialog>
#include <QLayout>
#include <QLineEdit>
#include <QPushButton>

FileChooser::FileChooser(QWidget *parent)
    : QWidget(parent)
{
    lineEdit = new QLineEdit(this);
    button = new QPushButton(tr("..."), this);
    
    lineEdit->setGeometry(5, 5, 200, 20);
    button->setGeometry(210, 5, 20, 20);

    // enter your code here
    // create a layout, set it on the widget and add the two child widgets to it
    // make a signal-slot connection between the two widgets
    //
}

void FileChooser::chooseFile() {
    // enter your code here
    // ask the user for a file name and set its path as text of lineEdit
}
