#ifndef UDPCHAT_H
#define UDPCHAT_H

#include <QWidget>

class QLineEdit;
class QTextEdit;
class QUdpSocket;
class UDPChat : public QWidget
{
    Q_OBJECT
public:
    explicit UDPChat(QWidget *parent = 0);
    void startNetworking(int port = 34567);
signals:

public slots:
    void sendMessage();
    void showMessage(const QString &nick, const QString &message);
    void processPendingDatagrams();
private:
    QLineEdit *nick;
    QTextEdit *messageWindow;
    QLineEdit *message;

    QByteArray encodeMessage(const QString &nick, const QString &message) const;
    QPair<QString,QString> decodeMessage(const QByteArray &ba) const;

    QUdpSocket *socket;
    quint16 socketPort;
};

#endif // UDPCHAT_H
