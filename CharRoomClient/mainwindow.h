#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "SocketConnect.h"

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
    SocketConnect* chatRoom;	//Socket单例

    int userNameSwitch = 1;

private:
    virtual void closeEvent(QCloseEvent *event);	//重写关闭窗口函数

public slots:
    void noticeAllClient_Slots(QString, QString);
    void updateAllUser_Slots(QString, QString);
    void userExit_Slots(QString, QString);
    void sendMessageBtn_Slots();
    void chatMessage_Slots(QString);
protected:
    bool eventFilter(QObject * target, QEvent * event); //事件过滤器，用于按回车键时提交数据

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
