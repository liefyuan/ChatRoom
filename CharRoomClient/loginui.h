#ifndef LOGINUI_H
#define LOGINUI_H

#include <QDialog>
#include "RegisterUI.h"
#include "SocketConnect.h"

namespace Ui {
class LoginUI;
}

class LoginUI : public QDialog
{
    Q_OBJECT

public:
    explicit LoginUI(QWidget *parent = nullptr);
    ~LoginUI();

private:
    SocketConnect *socketConnect;	//Socket单例
    RegisterUI* registerUI;			//注册界面

private slots:
    void btnRegister_Slots();	//注册按钮
    void btnLogin_Slots();		//登录按钮
    void userLoginCheck_Slots(int);	//登录检查信息

private:
    Ui::LoginUI *ui;
};

#endif // LOGINUI_H
