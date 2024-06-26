﻿#ifndef COLLAPSEVIEWITEM_H
#define COLLAPSEVIEWITEM_H

#include <QWidget>
#include "client.h"
#include <QList>


namespace Ui {
class CollapseViewItem;
}



class CollapseViewItem : public QWidget
{
    Q_OBJECT

public:
    explicit CollapseViewItem(QString titleText,QWidget *parent = 0);
    ~CollapseViewItem();

    /**
     * @brief 设置标题文字
     * @param titleText
     */
    void setTitleText(QString titleText);

    /**
     * @brief 添加展开抽屉后的内容项目
     * @param widgets 项目列表
     */
    void addSubItems(QList<QWidget *> widgets);

    /**
     * @brief 添加展开抽屉后的内容项目
     * @param widgets 项目
     */
    void addSubItem(QWidget*widget);

private slots:

    /**
     * @brief 点击按钮进行项目折叠
     */
    void onCollapseButClick();

private:
    Ui::CollapseViewItem *ui;

};

#endif // COLLAPSEVIEWITEM_H
