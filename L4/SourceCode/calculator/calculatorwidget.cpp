#include "calculatorwidget.h"

#include <QHBoxLayout>
#include <QFont>

CalculatorWidget::CalculatorWidget(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget( m_firstValue = new QLineEdit() );
    layout->addWidget( new QLabel("+") );
    layout->addWidget( m_secondValue = new QLineEdit() );
    layout->addWidget( new QLabel("=") );
    layout->addWidget( m_result = new QLabel() );

    QFont font = m_result->font();
    font.setBold(true);
    m_result->setFont(font);

    connect(m_firstValue, SIGNAL(textChanged(QString)), this, SLOT(valueChanged()));
    connect(m_secondValue, SIGNAL(textChanged(QString)), this, SLOT(valueChanged()));

    m_firstValue->setText("0");
    m_secondValue->setText("0");
}

void CalculatorWidget::valueChanged()
{
    // Enter your code here
    //
    // The input data is available from the QLineEdit pointers m_firstValue and m_secondValue
    // The QLabel pointer m_result points to the result display widget
}
