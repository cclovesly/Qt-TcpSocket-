#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <QByteArray>


namespace Ui {
class QQServer;
}

class QQServer : public QDialog
{
    Q_OBJECT

public:
    explicit QQServer(QWidget *parent = nullptr);
    ~QQServer();

    QTcpServer *tcpserver;
    QTcpSocket *tcpsocket;

private slots:
    void on_connectbt_clicked();

    void newConnection_Slot();
    void readyRead_Slot();

    void on_disconnectbt_clicked();

    void on_sendbt_clicked();

private:
    Ui::QQServer *ui;
    QTcpSocket *socket;
};

#endif // MAINWINDOW_H
