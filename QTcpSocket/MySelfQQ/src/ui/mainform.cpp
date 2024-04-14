#include "mainform.h"
#include "ui_mainform.h"

#include "collapseview.h"
#include "colorpickform.h"


#include <QDebug>
#include <QDesktopWidget>
#include <QApplication>

//主串口与屏幕边缘的距离
int MAIN_FORM_OADDING = 10;

MainForm::MainForm(QWidget *parent) :
    MoveableFramelessWindow(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);

    //加入联系人列表
    ui->page_Friend->layout()->addWidget(new CollapseView());
    ui->center_stack->setCurrentIndex(0);

    //获取屏幕
    QDesktopWidget* desktopWidget = QApplication::desktop();

    //得到屏幕宽度
    int screenWidth = desktopWidget->width();

    //转移到右边
    this->move(screenWidth - MAIN_FORM_OADDING - this->width(),MAIN_FORM_OADDING);

    m_naviBtns[0] = ui->pushButton_skin;
    m_naviBtns[1] = ui->minpushBtn;
    m_naviBtns[2] = ui->closepushBtn;
    m_naviBtns[3] = ui->pushBtn_Friend;
    m_naviBtns[4] = ui->pushBtn_Group;
    m_naviBtns[5] = ui->pushBtn_Message;

    for(unsigned int i = 0; i < 6; i++)
    {
        connect(m_naviBtns[i], &QPushButton::clicked, this, &MainForm::navigateButtonClick);
    }
}

void MainForm::navigateButtonClick()
{
    QPushButton* btn = (QPushButton*)sender();
    QString sName = btn->objectName();

    if (sName == "pushButton_skin")
    {
        doChangeColor();
    }
    else if (sName == "minpushBtn")
    {
        doMinBtnClick();
    }
    else if (sName == "closepushBtn")
    {
        doCloseBtnClick();
    }
    else if (sName == "pushBtn_Friend")
    {
        ui->center_stack->setCurrentIndex(0);
    }
    else if (sName == "pushBtn_Group")
    {
        ui->center_stack->setCurrentIndex(1);
    }
    else if (sName == "pushBtn_Message")
    {
        ui->center_stack->setCurrentIndex(2);
    }
}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::doMinBtnClick()
{
    showMinimized();
}

void MainForm::doCloseBtnClick()
{
    close();
}

void MainForm::doChangeColor()
{
    MY_COLOR_PICK_FORM.show();
    MY_COLOR_PICK_FORM.raise();
    MY_COLOR_PICK_FORM.setFocus();

    ColorPickForm*f=&(MY_COLOR_PICK_FORM);

    connect(f,SIGNAL(themColorChanged(QString)),this,SLOT(onThemeColorChange(QString)));
}

void MainForm::onThemeColorChange(QString colorStr)
{
    //组合成qcc样式表
    QString style=QString("#%1{background-color:%2;}").arg(ui->centralwidget->objectName(),colorStr);
    //定义样式
    ui->centralwidget->setStyleSheet(style);

}



QWidget *MainForm::getDragnWidget()
{
    return ui->main_top;
}
