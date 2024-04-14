#include "collapseviewitem.h"
#include "ui_collapseviewitem.h"

#include <QPushButton>
#include <QLabel>
#include <QLayout>
#include <QDebug>
#include <QTime>

int MAX_PERSON_PIC_NUM = 9;

CollapseViewItem::CollapseViewItem(QString titleText, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CollapseViewItem)
{
    ui->setupUi(this);
    ui->label->setProperty("slected", !ui->item_con->isVisible());

    // 根据时间制作随机种子
    QTime time = QTime::currentTime();
    qsrand(time.msec() + time.second() * 1000);

    // 随机产生好友数目
    int personNumber = qrand() % (MAX_PERSON_PIC_NUM - 1) + 1;

    for (int i = 0; i < personNumber; i++) {
        // 随机选择好友头像
        QString picPath = QString(":/media/person/media/person/%1.jpg")
                .arg(QString::number(qrand() % (MAX_PERSON_PIC_NUM - 1) + 1));

        // 创建一个QPushButton作为可点击的按钮
        QPushButton *button = new QPushButton(this);
        button->setIcon(QIcon(picPath)); // 设置按钮的图标为随机选择的头像
        button->setIconSize(QSize(50, 50)); // 设置图标大小

        // 连接按钮的点击信号到槽函数，以便处理按钮点击事件
        connect(button, &QPushButton::clicked, [picPath, this]() {
            qDebug() << "Button clicked with image path:" << picPath;

            // 创建客户端窗口实例
            client *clientWindow = new client(); // 假设客户端窗口需要图像路径作为参数

            // 显示客户端窗口
            clientWindow->show();
        });

        // 将按钮添加到布局中
        ui->item_con->layout()->addWidget(button);
    }

    qDebug() << "personNumber:" << personNumber;

    // 随机产生未上线好友数目
    int offlinPerson = qrand() % personNumber;

    titleText = QString("%1 (%2/%3)")
            .arg(titleText, QString::number(offlinPerson), QString::number(personNumber));

    this->setTitleText(titleText);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onCollapseButClick()));
}

CollapseViewItem::~CollapseViewItem()
{
    delete ui;
}

void CollapseViewItem::setTitleText(QString titleText)
{
    ui->pushButton->setText(titleText);
}

void CollapseViewItem::addSubItems(QList<QWidget *> widgets)
{
    foreach (QWidget *var, widgets) {
        addSubItem(var);
    }
}

void CollapseViewItem::addSubItem(QWidget *widget)
{
    ui->item_con->layout()->addWidget(widget);
}

void CollapseViewItem::onCollapseButClick()
{
    // 设置为相反的显示状态
    ui->item_con->setVisible(!ui->item_con->isVisible());
    ui->label->setProperty("slected", ui->item_con->isVisible());

    if (ui->item_con->isVisible()) {
        ui->label->setStyleSheet("QLabel{"
                                     "background-image: url(:/sys/arrow_d.png);background-repeat:no;background-position:center;"
                                     "}");
    } else {
        ui->label->setStyleSheet("QLabel{"
                                     "background-image: url(:/sys/arrow_r.png);background-repeat:no;background-position:center;"
                                     "}");
    }

    ui->label->update();
}
