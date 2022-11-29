#include "consolewindow.h"
#include "menu_addwindow.h"
#include "ui_consolewindow.h"
#include "menu_addwindow.h"
#include "select_menuwindow.h"
#include "orderwindow.h"
#include <QTime>
#include <QDate>

ConsoleWindow::ConsoleWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConsoleWindow)
{
    ui->setupUi(this);

}

ConsoleWindow::~ConsoleWindow()
{
    delete ui;
}
//获取text显示名字
void ConsoleWindow::setdata(QString arg)
{
    ui->userEdit->setText(arg);
}
//获取服务消息
void ConsoleWindow::set_numdata(QString argA, QString argB)
{
    desk_num = argA;
    ser_num = argB;
    if(desk_num != "0")
    {
        ui->label_5->setText("1");
    }
}

//菜品管理
void ConsoleWindow::on_pushButton_3_clicked()
{
    menu_addwindow *win = new menu_addwindow(this);
    win->show();
    this->hide();
}
//菜品列表
void ConsoleWindow::on_pushButton_2_clicked()
{
    select_menuwindow *win = new select_menuwindow(this);
    win->show();
    this->hide();
}
//订单管理
void ConsoleWindow::on_pushButton_clicked()
{
    orderwindow *win = new orderwindow(this);
    win->show();
    this->hide();
}
void ConsoleWindow::setMsocket(QTcpSocket *value)
{
    this->msocket = value;
}

//服务消息通知
void ConsoleWindow::on_pushButton_7_clicked()
{
    ui->label_des->setText("桌号:"+desk_num);
    ui->label_ser->setText("服务号:"+ser_num);
    ui->label_5->setText("0");

}
