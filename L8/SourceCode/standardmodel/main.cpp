#include <QtGui>

int main(int argc, char **argv){
    QApplication app(argc, argv);
    QTableView view;
    QStandardItemModel *model = new QStandardItemModel(&view);

    QStringList labels;
    labels.append("Name");
    labels.append("Deadline");
    labels.append("Completed (in %)");

    view.setModel(model);
    view.show();
    return app.exec();
}
