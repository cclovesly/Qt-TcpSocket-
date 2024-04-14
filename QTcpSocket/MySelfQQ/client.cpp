#include "client.h"
#include "ui_client.h"
#include <QString>
#include <iostream>



client::client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);

    tcpsocket=new QTcpSocket(this);
}

client::~client()
{
    delete ui;
}



void client::connected_SLOT()
{
    QObject::connect(tcpsocket, &QTcpSocket::readyRead, this, &client::readyRead_Slot);
}
void client::readyRead_Slot()//定义接收信号的槽
{
    QString buf;
    buf=tcpsocket->readAll();
    ui->receivewd->appendPlainText(buf.toUtf8());//接收由tcp发送过来的信息
}


void client::on_openclient_clicked()
{
    tcpsocket->connectToHost(ui->ipnum->text(),ui->portnum->text().toInt());
    connect(tcpsocket,SIGNAL(connected()),this,SLOT(connected_SLOT()));
    printf("打开客户端 ");
}

void client::on_closeclient_clicked()
{
    tcpsocket->close();
    printf("关闭客户端 ");
}

void client::on_sent_clicked()
{
    tcpsocket->write(ui->sendwd->text().toUtf8().data());
}
