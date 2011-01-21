#ifndef WEBBROWSER_H
#define WEBBROWSER_H

#include <QWidget>
#include <QUrl>

class QLineEdit;
class QToolButton;
class QWebView;

class WebBrowser : public QWidget
{
    Q_OBJECT
public:
    WebBrowser(QWidget *parent = 0);

signals:

public slots:
    void loadPage();
    void updateAddressBar(const QUrl &url);
private:
    QLineEdit *addressBar;
    QToolButton *backButton;
    QToolButton *forwardButton;
    QToolButton *reloadButton;

    QWebView *browser;
};

#endif // WEBBROWSER_H
