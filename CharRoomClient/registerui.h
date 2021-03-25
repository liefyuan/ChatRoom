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
    SocketConnect *socketConnect;	//Socket����

private slots:
    void btnOK_Slots();			//ȷ����ť
    void btnCancel_Slots();		//ȡ����ť
    void userRegister_Slots(QString);	//�����˺Ųۺ���

private:
    Ui::RegisterUI *ui;
};

#endif // REGISTERUI_H
