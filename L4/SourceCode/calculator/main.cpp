#include <QApplication>

#include "calculatorwidget.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    CalculatorWidget w;
    w.show();
    return a.exec();
}
