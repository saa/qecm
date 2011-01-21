#ifndef FILELISTWIDGET_H
#define FILELISTWIDGET_H

#include <QWidget>

#include <QLineEdit>
#include <QListWidget>

class FileListWidget : public QWidget
{
Q_OBJECT
public:
    explicit FileListWidget(QWidget *parent = 0);

private slots:
    void addClicked();
    void removeClicked();

    void loadClicked();
    void saveClicked();

private:
    QLineEdit *m_entryField;
    QListWidget *m_list;
};

#endif // FILELISTWIDGET_H
