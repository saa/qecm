#include "udpchat.h"
#include <QLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <QUdpSocket>
#include <QLabel>

UDPChat::UDPChat(QWidget *parent) :
    QWidget(parent)
{
    socket = 0;
    QVBoxLayout *l = new QVBoxLayout(this);
    QHBoxLayout *nickLayout = new QHBoxLayout;
    QLabel *label = new QLabel(tr("My nick:"));

    nick = new QLineEdit;
    nick->setText(tr("Somebody you know"));

    nickLayout->addWidget(label);
    nickLayout->addWidget(nick);
    l->addLayout(nickLayout);

    messageWindow = new QTextEdit;
    messageWindow->setReadOnly(true);
    message = new QLineEdit;

    l->addWidget(messageWindow);
    l->addWidget(message);
    connect(message, SIGNAL(returnPressed()), this, SLOT(sendMessage()));
}

void UDPChat::sendMessage() {
    // введите Ваш код здесь
}

void UDPChat::showMessage(const QString &nick, const QString &message) {
    QString line = tr("<b>%1</b> says: <i>%2</i>").arg(nick).arg(message);
    messageWindow->append(line);
}

QByteArray UDPChat::encodeMessage(const QString &nick, const QString &message) const {
    QByteArray ba;
    QDataStream stream(&ba, QIODevice::WriteOnly);
    stream << nick << message;
    return ba;
}

QPair<QString,QString> UDPChat::decodeMessage(const QByteArray &ba) const {
    QDataStream stream(ba);
    QString nick, message;
    stream >> nick >> message;
    return qMakePair(nick, message);
}

void UDPChat::startNetworking(int port) {
    // введите Ваш код здесь
}

void UDPChat::processPendingDatagrams() {
    // введите Ваш код здесь
}
