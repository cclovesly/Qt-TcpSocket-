#include "qqserver.h"
#include "ui_qqserver.h"


QQServer::QQServer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QQServer)
{
    ui->setupUi(this);

    tcpserver=new QTcpServer(this);
    tcpsocket=new QTcpSocket(this);

    connect(tcpserver,SIGNAL(newConnection()),this,SLOT(newConnection_Slot()));
}


void QQServer::newConnection_Slot()
{
    tcpsocket=tcpserver->nextPendingConnection(); //获取已经连接的客户端的SOCKET套接字
    connect(tcpsocket,SIGNAL(readyRead()),this,SLOT(readyRead_Slot()));//若客户端有消息进来的话,会触发信号readyRead_Slot();

    //获取对方的IP和端口
    QString sIp = tcpsocket->peerAddress().toString();
    quint16 sPort = tcpsocket->peerPort();
    qDebug() << sIp << sPort;
}

void QQServer::readyRead_Slot()
{
        QByteArray data = tcpsocket->readAll();
        QString buf = QString::fromUtf8(data);

        ui->receivewd->setText(buf);
}


QQServer::~QQServer()
{
    delete ui;
}


void QQServer::on_connectbt_clicked()//连接服务器
{
    tcpserver->listen(QHostAddress::Any,ui->portnum->text().toUInt());//监听端口号
}

void QQServer::on_disconnectbt_clicked()//关闭服务器
{
    tcpserver->close();
}

void QQServer::on_sendbt_clicked()//发送信息
{
    tcpsocket->write(ui->sendwd->text().toUtf8().data());
}
