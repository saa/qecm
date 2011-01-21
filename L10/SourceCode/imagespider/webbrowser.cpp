#include "webbrowser.h"
#include <QLayout>
#include <QToolButton>
#include <QLineEdit>
#include <QWebView>
#include <QSplitter>
#include <QListView>
#include <QStringListModel>
#include <QWebPage>
#include <QWebFrame>
#include <QWebElementCollection>

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

    browser = new QWebView(this);
    connect(browser, SIGNAL(urlChanged(QUrl)), this, SLOT(updateAddressBar(QUrl)));


    imageList = new QListView;

    QSplitter *splitter = new QSplitter;
    splitter->addWidget(browser);
    splitter->addWidget(imageList);

    mainLayout->addWidget(splitter);

    backButton->setDefaultAction(browser->pageAction(QWebPage::Back));
    forwardButton->setDefaultAction(browser->pageAction(QWebPage::Forward));
    reloadButton->setDefaultAction(browser->pageAction(QWebPage::Reload));
}

void WebBrowser::loadPage() {
    QUrl address = QUrl::fromUserInput(addressBar->text());
    browser->load(address);
}

void WebBrowser::updateAddressBar(const QUrl &url) {
    addressBar->setText(url.toString());
}

void WebBrowser::scanPageForImages() {
    QStringListModel *model = new QStringListModel(imageList);
    QStringList images;
    imageList->setModel(model);

    // enter your code here

    model->setStringList(images);
}
