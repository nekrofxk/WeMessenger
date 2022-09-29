#include "WeMessegerConnectionDialog.h"
#include "ui_WeMessegerConnectionDialog.h"

WeMessegerConnectionDialog::WeMessegerConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WeMessegerConnectionDialog)
{
    ui->setupUi(this);
    setWindowTitle("WeChat");

}

WeMessegerConnectionDialog::~WeMessegerConnectionDialog()
{
    delete ui;
}

void WeMessegerConnectionDialog::on_okButton_clicked()
{
    mHostname = ui->hostname->text();
    mPort = ui->port->value();
    accept();
}

void WeMessegerConnectionDialog::on_cancelButton_clicked()
{
    reject();
}
