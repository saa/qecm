#include "calculator.h"

Calculator::Calculator(QObject *parent) :
    QObject(parent), m_lastResult(0), m_currentNumber(0), m_isAdding(true)
{
}

void Calculator::numEntered(int num)
{
    m_currentNumber = m_currentNumber*10 + num;
    emit displayChanged(QString::number(m_currentNumber));
}

void Calculator::clear()
{
    m_currentNumber = 0;
    emit displayChanged(QString::number(m_currentNumber));
}

void Calculator::allClear()
{
    m_currentNumber = 0;
    m_lastResult = 0;
    emit displayChanged(QString::number(m_currentNumber));
}

void Calculator::additionMode()
{
    calculate();
    m_isAdding = true;
}

void Calculator::subtractionMode()
{
    calculate();
    m_isAdding = false;
}

void Calculator::calculate()
{
    m_lastResult += m_isAdding?m_currentNumber:-m_currentNumber;
    m_currentNumber = 0;
    emit displayChanged(QString::number(m_lastResult));
}
