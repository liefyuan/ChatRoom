#include "loginui.h"
#include "ui_loginui.h"
#include <QMessageBox>

LoginUI::LoginUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginUI)
{
    ui->setupUi(this);

    socketConnect = SocketConnect::GetIntance(); //获取Socket的单例
    socketConnect->port = 8030;			         //设置端口号
    socketConnect->serverIP = "0.0.0.0";         //初始化服务器ip地址
    ui->portLabel->setText(QString::number(socketConnect->port));
    ui->loginBtn->setFocus();


    connect(ui->registerBtn, SIGNAL(clicked()),
            this, SLOT(btnRegister_Slots()));			    //注册按钮
    connect(ui->loginBtn, SIGNAL(clicked()),
            this, SLOT(btnLogin_Slots()));					//登录按钮
    connect(socketConnect, SIGNAL(userLoginCheck_Signals(int)),
            this, SLOT(userLoginCheck_Slots(int)));	        //接收登录检查信息
}

LoginUI::~LoginUI()
{
    delete ui;
}

//注册按钮
void LoginUI::btnRegister_Slots()
{
    //获取服务器ip地址
    socketConnect->serverIP = ui->serverIPLineEdit->text();

    registerUI = new RegisterUI(this);
    int ok = registerUI->exec();
}

//登录按钮
void LoginUI::btnLogin_Slots()
{
    //获取服务器ip地址
    socketConnect->serverIP = ui->serverIPLineEdit->text();

    qDebug() << "Server IP:" << socketConnect->serverIP;

    if (ui->accountLineEdit->text().isEmpty() || ui->passwordLineEdit->text().isEmpty())
    {
        QMessageBox::information(this,
                                 QString::fromLocal8Bit("提示"),
                                 QString::fromLocal8Bit("请输入账号或密码！！"));
        return;
    }
    if (ui->serverIPLineEdit->text().isEmpty())
    {
        QMessageBox::information(this,
                                 QString::fromLocal8Bit("提示"),
                                 QString::fromLocal8Bit("请输入 ip 地址"));
        return;
    }

    //获取账号、密码
    socketConnect->userAccount = ui->accountLineEdit->text();
    socketConnect->userPassword = ui->passwordLineEdit->text();

    //连接服务器并发送数据给服务器
    if (!socketConnect->hostAddress->setAddress(socketConnect->serverIP))
    {
        return;
    }
    socketConnect->connectToHost(*socketConnect->hostAddress, socketConnect->port);

    if (socketConnect->waitForConnected())
    {
        socketConnect->sendRequest(RequestTypeEnum::USERLOGIN);
    }
    else
    {
        QMessageBox::information(this,
                                 QString::fromLocal8Bit("提示"),
                                 QString::fromLocal8Bit("连接服务器失败！"));
        ui->loginBtn->setFocus();
        return;
    }
}

//登录检查信息
void LoginUI::userLoginCheck_Slots(int ok)
{
    qDebug() << "Login Check!";
    if (ok == 1)
    {
        qDebug() << QString::fromLocal8Bit("登录成功");
        accept();
    }
    else if (ok == 2)
    {
        QMessageBox::information(this,
                                 QString::fromLocal8Bit("提示"),
                                 QString::fromLocal8Bit("你已登录，请关闭程序后再登录！"));
        socketConnect->disconnectFromHost();
    }
    else
    {
        QMessageBox::information(this,
                                 QString::fromLocal8Bit("提示"),
                                 QString::fromLocal8Bit("用户名或密码错误！"));
        socketConnect->disconnectFromHost();
    }
}
