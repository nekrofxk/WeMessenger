#include "WeMessengerSocket.h"

WeMessengerSocket::WeMessengerSocket(qintptr handle, QObject *parent)
    : QTcpSocket(parent)
{
    setSocketDescriptor(handle);

    connect(this, &WeMessengerSocket::readyRead, [&](){
        emit WeReadyRead(this);
    });

    connect(this, &WeMessengerSocket::stateChanged,[&](int S){
        emit WeStateChanged(this, S);
    });
}
