#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DoTcpServer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    quint16 port;		//端口号，与客户端相同
    void showServerHostIP();	//显示服务器ip地址

    DoTcpServer* server;	//定义一个全局的server对象

public slots:
    void cleanBtn_Slots();	//清屏按钮
    void serverUIAddUser_Slots(QString, QString, QString, QString);
    void serverUIDeleteUser_Slots(QString);
    void serverUIChatMessage_Slots(QString);

private:
    void closeEvent(QCloseEvent *event);	//重写关闭窗口函数

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
