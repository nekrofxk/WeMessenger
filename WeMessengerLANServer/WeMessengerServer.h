#ifndef WEMESSENGERSERVER_H
#define WEMESSENGERSERVER_H

#include <QTcpServer>

class WeMessengerSocket;

class WeMessengerServer : public QTcpServer
{
public:
    WeMessengerServer(QObject *parent = nullptr);
    bool startServer(quint16 port);
protected:
    void incomingConnection(qintptr handle);
private:
    QList<WeMessengerSocket *> mSockets;
};

#endif // WEMESSENGERSERVER_H
