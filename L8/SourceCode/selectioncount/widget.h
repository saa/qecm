#include <QTableView>
#include <QStandardItemModel>
#include <QLabel>

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
private:
    QTableView *m_view;
    QLabel *m_label;
    QStandardItemModel *m_model;
    
    void updateLabelText(int count);
};
