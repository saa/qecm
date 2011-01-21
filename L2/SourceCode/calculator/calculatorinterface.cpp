#include "calculatorinterface.h"
#include "ui_calculatorinterface.h"

#include <QSignalMapper>
#include "calculator.h"

CalculatorInterface::CalculatorInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculatorInterface),
    m_calculator(new Calculator(this))
{
    ui->setupUi(this);

    // Add code here

    m_calculator->allClear();
}

CalculatorInterface::~CalculatorInterface()
{
    delete ui;
}

void CalculatorInterface::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
