#ifndef WEMESSEGERCONNECTIONDIALOG_H
#define WEMESSEGERCONNECTIONDIALOG_H

#include <QDialog>

namespace Ui {
class WeMessegerConnectionDialog;
}

class WeMessegerConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WeMessegerConnectionDialog(QWidget *parent = nullptr);
    ~WeMessegerConnectionDialog();

    QString hostname() const;
    quint16 port() const;


private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::WeMessegerConnectionDialog *ui;
    QString mHostname;
    quint16 mPort;
};

inline QString WeMessegerConnectionDialog::hostname() const
{
    return mHostname;
}

inline quint16 WeMessegerConnectionDialog::port() const
{
    return mPort;
}

#endif // WEMESSEGERCONNECTIONDIALOG_H
