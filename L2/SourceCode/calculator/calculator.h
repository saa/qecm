#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>

class Calculator : public QObject
{
Q_OBJECT
public:
    explicit Calculator(QObject *parent = 0);

public slots:
    void numEntered(int);

    void clear();
    void allClear();

    void additionMode();
    void subtractionMode();

    void calculate();

signals:
    void displayChanged(QString);

private:
    int m_lastResult;
    int m_currentNumber;
    bool m_isAdding;
};

#endif // CALCULATOR_H
