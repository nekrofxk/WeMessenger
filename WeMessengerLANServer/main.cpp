#include <QCoreApplication>
#include "WeMessengerServer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    WeMessengerServer Server;
    if(!Server.startServer(1234)){
        qDebug() << "Error :" << Server.errorString();
        return 1;
    }
    qDebug() << "Server started...";
    return a.exec();
}
