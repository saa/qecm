#include <QtGui/QApplication>
#include "filechooser.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FileChooser w;
    w.show();

    return a.exec();
}
