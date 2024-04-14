#ifndef MAINFORM_H
#define MAINFORM_H


#include "moveableframelesswindow.h"
#include <QWidget>
#include <QPushButton>

namespace Ui {
class MainForm;
}

class MainForm : public MoveableFramelessWindow
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = 0);
    ~MainForm();

private slots:

    //最小化按钮点击
    void doMinBtnClick();

    //关闭按钮点击
    void doCloseBtnClick();

    void doChangeColor();

    void onThemeColorChange(QString colorStr);

    void navigateButtonClick();

protected:
      QWidget*getDragnWidget();

private:
    Ui::MainForm* ui;
    QPushButton* m_naviBtns[6];
};

#endif // MAINFORM_H
