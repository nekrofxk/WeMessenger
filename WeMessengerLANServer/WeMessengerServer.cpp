#include "WeMessengerServer.h"
#include "WeMessengerSocket.h"
#include <QTextStream>
#include <QDebug>

WeMessengerServer::WeMessengerServer(QObject *parent)
    :QTcpServer(parent)
{

}

bool WeMessengerServer::startServer(quint16 port)
{
    return listen(QHostAddress::Any, port);
}

void WeMessengerServer::incomingConnection(qintptr handle)
{
    qDebug() << "Client connected with handle:" << handle;
    auto socket = new WeMessengerSocket(handle, this);
    mSockets << socket;

    for(auto i : mSockets){
        QTextStream T(i);
        T << "Server : You are Connected.";
        i->flush();
    }

    connect(socket, &WeMessengerSocket::WeReadyRead, [&](WeMessengerSocket *S){
       // qDebug() << "WeReadyRead";
        QTextStream T(S);
        auto text = T.readAll();

        for(auto i : mSockets){
            QTextStream K(i);
            K << text;
            i->flush();
        }
    });

    connect(socket, &WeMessengerSocket::WeStateChanged, [&](WeMessengerSocket *S, int ST){
        qDebug() << "WeStateChanged with handle" << S->socketDescriptor();
        if(ST == QTcpSocket::UnconnectedState){
            qDebug() << "User disconnected" << S->socketDescriptor();
            mSockets.removeOne(S);
            for (auto i : mSockets){
                QTextStream K(i);
                K << "Server : The client"
                  << S->socketDescriptor()
                  << "has been disconnected...";
                i->flush();
            }
        }
    });
}
