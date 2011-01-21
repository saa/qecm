#include <QApplication>
#include "udpchat.h"

int main(int argc, char **argv){
    QApplication app(argc, argv);
    UDPChat chat;
    chat.setWindowTitle("udpchat");
    chat.startNetworking();
    chat.show();
    return app.exec();
}
