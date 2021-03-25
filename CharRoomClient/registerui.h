#ifndef REGISTERUI_H
#define REGISTERUI_H

#include <QDialog>
#include "SocketConnect.h"
#include <QtNetwork>

namespace Ui {
class RegisterUI;
}

class RegisterUI : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterUI(QWidget *parent = nullptr);
    ~RegisterUI();

private:
    SocketConnect *socketConnect;	//Socket单例

private slots:
    void btnOK_Slots();			//确定按钮
    void btnCancel_Slots();		//取消按钮
    void userRegister_Slots(QString);	//接收账号槽函数

private:
    Ui::RegisterUI *ui;
};

#endif // REGISTERUI_H
