#include <QtGui/QApplication>
#include "smiley.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Smiley w;
    w.show();

    return a.exec();
}
