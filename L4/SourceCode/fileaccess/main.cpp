#include <QApplication>

#include "filelistwidget.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    FileListWidget w;
    w.show();
    return a.exec();
}
