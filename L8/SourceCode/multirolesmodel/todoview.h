#include <QTableView>
#include <QStandardItemModel>

class TodoView : public QTableView {
public:
    TodoView(QWidget *parent = 0);
private:
    QStandardItemModel *m_model;
    void updateEntry(QStandardItem *);
};
