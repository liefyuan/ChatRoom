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
    SocketConnect* chatRoom;	//Socket����

    int userNameSwitch = 1;

private:
    virtual void closeEvent(QCloseEvent *event);	//��д�رմ��ں���

public slots:
    void noticeAllClient_Slots(QString, QString);
    void updateAllUser_Slots(QString, QString);
    void userExit_Slots(QString, QString);
    void sendMessageBtn_Slots();
    void chatMessage_Slots(QString);
protected:
    bool eventFilter(QObject * target, QEvent * event); //�¼������������ڰ��س���ʱ�ύ����

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
