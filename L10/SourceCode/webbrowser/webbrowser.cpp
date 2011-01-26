#include "webbrowser.h"
#include <QLayout>
#include <QToolButton>
#include <QLineEdit>
#include <QWebView>

WebBrowser::WebBrowser(QWidget *parent) :
    QWidget(parent)
{
    addressBar = new QLineEdit(this);
    backButton = new QToolButton(this);
    forwardButton = new QToolButton(this);
    reloadButton = new QToolButton(this);

    backButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    forwardButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    reloadButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);


    connect(addressBar, SIGNAL(returnPressed()), this, SLOT(loadPage()));

    QHBoxLayout *toolsLayout = new QHBoxLayout;
    toolsLayout->addWidget(backButton);
    toolsLayout->addWidget(forwardButton);
    toolsLayout->addWidget(reloadButton);
    toolsLayout->addWidget(addressBar);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(toolsLayout);

    // введите Ваш код здесь
}

void WebBrowser::loadPage() {
    // введите Ваш код здесь
}

void WebBrowser::updateAddressBar(const QUrl &url) {
    // введите Ваш код здесь
}
