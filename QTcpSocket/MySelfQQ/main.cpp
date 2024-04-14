#include "mainwindow.h"
#include "src/ui/loginform.h"

#include "src/ui/mainform.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginForm loginDlg;
    loginDlg.show();

    return a.exec();
}
