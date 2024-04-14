#ifndef LOGINFORM_H
#define LOGINFORM_H


#include "moveableframelesswindow.h"
#include "regdlg.h"
#include "mainform.h"
#include <QWidget>
#include <QtSql/QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class LoginForm;
}

class LoginForm :public MoveableFramelessWindow
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = 0);
    ~LoginForm();
    void SqlLogin();
protected:
      QWidget* getDragnWidget();

private slots:

    //登录按钮点击
    void doLoginBtnClick();

    //最小化按钮点击
    void doMinBtnClick();

    //关闭按钮点击
    void doCloseBtnClick();

    void on_pushButton_login_clicked();

    void on_toolButton_clicked();

private:
    Ui::LoginForm* ui;
};

#endif // LOGINFORM_H
