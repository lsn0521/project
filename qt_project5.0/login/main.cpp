#include "widget.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFile file(":/res/qss/style-1.qss");/*QSS文件所在的路径*/

    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    app.setStyleSheet(stylesheet);
    file.close();
    QApplication a(argc, argv);
    //连接数据库-sqlite3
    QSqlDatabase  gecdb = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库属性
    gecdb.setDatabaseName("./project.db");
    //打开数据库
    if(!gecdb.open())
    {
        return -1;
    }
    //创建数据库管理员表格
    QString createsql = "create table if not exists user(id integer primary key autoincrement, name text,  password char(32));";
    QSqlQuery query;
    //执行sql语句
    if(!query.exec(createsql))
    {
    //输出执行语句出现的错误信息
        qDebug()<<query.lastError().text();
    }
/******四个菜单类型的数据表********/
    //创建数据库--推荐菜单表格
    createsql = "create table if not exists menu_rec(id integer primary key autoincrement,"
                " menuid int,name varchar(255) ,price float,classify text,discount float,pictrue varchar(255),recommends text,remarks text);";

    if(!query.exec(createsql))
    {
    //输出执行语句出现的错误信息
        qDebug()<<query.lastError().text();
    }
    //创建数据库--中国味道菜单表格
    createsql = "create table if not exists menu_taste(id integer primary key autoincrement,"
                " menuid int,name varchar(255) ,price float,classify text,discount float,pictrue varchar(255),recommends text,remarks text);";

    if(!query.exec(createsql))
    {
    //输出执行语句出现的错误信息
        qDebug()<<query.lastError().text();
    }
    //创建数据库--炖汤菜单表格
    createsql = "create table if not exists menu_soup(id integer primary key autoincrement,"
                " menuid int,name varchar(255) ,price float,classify text,discount float,pictrue varchar(255),recommends text,remarks text);";

    if(!query.exec(createsql))
    {
    //输出执行语句出现的错误信息
        qDebug()<<query.lastError().text();
    }
    //创建数据库--甜品菜单表格
    createsql = "create table if not exists menu_dessert(id integer primary key autoincrement,"
                " menuid int,name varchar(255) ,price float,classify text,discount float,pictrue varchar(255),recommends text,remarks text);";

    if(!query.exec(createsql))
    {
    //输出执行语句出现的错误信息
        qDebug()<<query.lastError().text();
    }
/**************/

    //创建数据库订单表格
    createsql = "create table if not exists indent(id integer primary key autoincrement,"
                "employeeid int,desknumber int,peoplenumber int,ordernumber varchar(255),starttime text,menuid int,price float,amount int);";
    if(!query.exec(createsql))
    {
    //输出执行语句出现的错误信息
        qDebug()<<query.lastError().text();
    }
    Widget w;
    w.show();

    return app.exec();
}
