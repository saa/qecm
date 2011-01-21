#include <QtGui>
#include "todoview.h"

int main(int argc, char **argv){
    QApplication app(argc, argv);
    TodoView view;
    view.show();
    return app.exec();
}
