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
    quint16 port;		//�˿ںţ���ͻ�����ͬ
    void showServerHostIP();	//��ʾ������ip��ַ

    DoTcpServer* server;	//����һ��ȫ�ֵ�server����

public slots:
    void cleanBtn_Slots();	//������ť
    void serverUIAddUser_Slots(QString, QString, QString, QString);
    void serverUIDeleteUser_Slots(QString);
    void serverUIChatMessage_Slots(QString);

private:
    void closeEvent(QCloseEvent *event);	//��д�رմ��ں���

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
