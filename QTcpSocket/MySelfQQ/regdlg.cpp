#include "regdlg.h"
#include "ui_regdlg.h"
#include <QMessageBox>

regdlg::regdlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::regdlg)
{
    ui->setupUi(this);
}

regdlg::~regdlg()
{
    delete ui;
}

void regdlg::on_toolButton_clicked()
{
    LoginForm lgf;
    lgf.SqlLogin();
    QSqlQuery query;
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    int maxId = query.value(0).toInt();
    query.prepare("INSERT INTO USER (ID, NAME, PASSWORD) VALUES (:id, :username, :password)");
    query.bindValue(":id", maxId++);
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "注册成功");
        this->close();
    } else {
        qDebug() << "Query execution failed: " << query.lastError().text();
    }
}

