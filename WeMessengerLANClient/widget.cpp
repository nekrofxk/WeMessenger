#include "widget.h"
#include "ui_widget.h"
#include "WeMessegerConnectionDialog.h"
#include <QTcpSocket>
#include <QTextStream>

Widget::Widget(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket = new QTcpSocket(this);

    connect(mSocket, &QTcpSocket::readyRead, [&](){
        QTextStream T(mSocket);
        auto text = T.readAll();
        ui->textEdit->append(text);
    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_sendButton_clicked()
{
    QTextStream T(mSocket);
    T << ui->nickname->text() << ": " << ui->message->text();
    mSocket->flush();
    ui->message->clear();
}

void Widget::on_connectButton_clicked()
{
    WeMessegerConnectionDialog MD(this);
    if(MD.exec() == QDialog::Rejected){
        return;
    }
    mSocket->connectToHost(MD.hostname(), MD.port());
}
