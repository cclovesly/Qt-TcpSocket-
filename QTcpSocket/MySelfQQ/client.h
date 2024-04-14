#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QTcpSocket>

namespace Ui {
class client;
}

class client : public QDialog
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client();

    QTcpSocket *tcpsocket;

private slots:
    void on_openclient_clicked();

    void connected_SLOT();
    void readyRead_Slot();

    void on_closeclient_clicked();

    void on_sent_clicked();

private:
    Ui::client *ui;
};

#endif // MAINWINDOW_H
