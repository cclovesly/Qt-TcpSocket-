#ifndef REGDLG_H
#define REGDLG_H

#include <QDialog>
#include "src/ui/loginform.h"
namespace Ui {
class regdlg;
}

class regdlg : public QDialog
{
    Q_OBJECT

public:
    explicit regdlg(QWidget *parent = nullptr);
    ~regdlg();
private slots:
    void on_toolButton_clicked();

private:
    Ui::regdlg *ui;
};

#endif // REGDLG_H
