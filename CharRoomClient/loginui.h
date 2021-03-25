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
    SocketConnect *socketConnect;	//Socket����
    RegisterUI* registerUI;			//ע�����

private slots:
    void btnRegister_Slots();	//ע�ᰴť
    void btnLogin_Slots();		//��¼��ť
    void userLoginCheck_Slots(int);	//��¼�����Ϣ

private:
    Ui::LoginUI *ui;
};

#endif // LOGINUI_H
