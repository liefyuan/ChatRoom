#include "mainwindow.h"

#include <QApplication>
#include "loginui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginUI l;
    MainWindow w;

    int ok = l.exec();

    if (ok == QDialog::Accepted)
    {
        w.setWindowTitle("Client");
        w.show();
        return a.exec();
    }
    else
    {
        return 0;
    }
}
