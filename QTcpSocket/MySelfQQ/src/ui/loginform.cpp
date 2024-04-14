#include "loginform.h"
#include "ui_loginform.h"


#include "mainform.h"
#include <QMessageBox>
#include <QGridLayout>
#include <QPushButton>

LoginForm::LoginForm(QWidget *parent) :
    MoveableFramelessWindow(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);

    //关联登录按钮点击
    connect(ui->minpushBtn, &QPushButton::clicked,this,&LoginForm::doMinBtnClick);
    connect(ui->closepushBtn, &QPushButton::clicked,this,&LoginForm::doCloseBtnClick);
}

void LoginForm::SqlLogin(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
        db.setHostName("127.0.0.1");
                db.setPort(3306);
                db.setDatabaseName("Mysql"); //不是Database,记得别填错
                db.setUserName("root");
                db.setPassword("123");
                bool ok = db.open();
                if (ok){
                    //QMessageBox::information(this, "infor", "数据库已连接");
                }
                else {
                    //QMessageBox::information(this, "infor", "连接失败");
                    qDebug()<<"error open database because"<<db.lastError().text();
                }
                //查询表数据
}

LoginForm::~LoginForm()
{
    delete ui;
}

QWidget *LoginForm::getDragnWidget()
{
    return ui->login_top_widget;
}

void LoginForm::doLoginBtnClick()
{
    this->close();
    MainForm* mainDlg = new MainForm;
    mainDlg->show();
}

void LoginForm::doMinBtnClick()
{
    showMinimized();
}

void LoginForm::doCloseBtnClick()
{
    close();
}

void LoginForm::on_pushButton_login_clicked()
{
    SqlLogin();
    QSqlQuery query;
    QString username = ui->lineEdit_un->text();
    QString password = ui->lineEdit_pass->text();
    query.prepare("SELECT * FROM USER WHERE name = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if(query.exec()){
        if(query.next()){
            connect(ui->pushButton_login, &QPushButton::clicked, this, &LoginForm::doLoginBtnClick);
        } else {
            QMessageBox::information(this, "用户不存在", "请注册");
        }
    } else {
        qDebug() << "查询执行失败：" << query.lastError().text();
    }
}


void LoginForm::on_toolButton_clicked()
{
    regdlg *wd=new regdlg;
    wd->show();

}

