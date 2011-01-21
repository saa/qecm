#include <QtGui>
#include <QWebView>
#include "webbrowser.h"

int main(int argc, char **argv){
    QApplication app(argc, argv);
    WebBrowser browser;
    browser.show();
    return app.exec();
}
