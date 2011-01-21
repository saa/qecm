#include <QTableView>
#include <QStandardItemModel>

class TodoView : public QTableView {
    Q_OBJECT
public:
    TodoView(QWidget *parent = 0);
private:
    QStandardItemModel *m_model;
private slots:
    void updateEntry(QStandardItem *);
};
