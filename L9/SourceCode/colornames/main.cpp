#include <QtGui>
#include "listmodel.h"

int main(int argc, char **argv){
    QApplication app(argc, argv);
    QListView view;
    view.setModel(new ListModel(&view));
    view.show();
    return app.exec();
}
