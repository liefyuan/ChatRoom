#pragma once

#include <QtSql>
#include <QDebug>

//连接数据库
static bool createConnection()
{
    // Mysql db init
//	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//	db.setHostName("localhost");
//	db.setPort(3306);
//	db.setUserName("root");
//	db.setPassword("123456");
//	db.setDatabaseName("chatroom");
//	bool ok = db.open();
//	db.exec("SET NAMES 'GBK'");
//	if (!ok)
//	{
//		return false;
//	}
//	else
//	{
//		return true;
//	}
    // SQLite db init
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("ChatRoom.db");


    bool ok = db.open();

    QSqlQuery sql_query;
    if(!sql_query.exec("create table userinfo"
                       "(id int primary key, "
                       "account text, "
                       "password text,"
                       "status int,"
                       "name text, "
                       "ip text, "
                       "descriptor text"
                       ")"))
    {
        qDebug() << "Error: Fail to create table."<< sql_query.lastError();
    }
    else
    {
        qDebug() << "Table created!";
    }

    if(!ok)
    {
        return false;
    }
    else
    {
        return true;
    }
}


