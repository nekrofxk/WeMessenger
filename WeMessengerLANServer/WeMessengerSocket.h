#ifndef WEMESSENGERSOCKET_H
#define WEMESSENGERSOCKET_H

#include <QTcpSocket>

class WeMessengerSocket : public QTcpSocket
{
    Q_OBJECT
public:
    WeMessengerSocket(qintptr handle, QObject *parent = nullptr);
signals:
    void WeReadyRead(WeMessengerSocket *);
    void WeStateChanged(WeMessengerSocket *, int);
};

#endif // WEMESSENGERSOCKET_H
