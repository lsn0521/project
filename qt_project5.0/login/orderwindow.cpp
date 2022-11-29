#include "orderwindow.h"
#include "ui_orderwindow.h"

#include <QFileDialog>
#include <QtSql/QSqlTableModel>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QCryptographicHash>
#include <QSqlTableModel>


orderwindow::orderwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::orderwindow)
{
    ui->setupUi(this);
    model.setTable("indent");

//自动查询
   QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
   db.setDatabaseName("project.db");
   if (db.open())
   {
       QSqlQueryModel* qmodel = new QSqlQueryModel();
       qmodel->setQuery("select * from indent");
       ui->tableView->setModel(qmodel);
   }

}

orderwindow::~orderwindow()
{
    delete ui;
}
//返回
void orderwindow::on_order_back_clicked()
{
    this->parentWidget()->show();
    this->close();
}
//订单插入
void orderwindow::on_order_insert_clicked()
{
    QSqlTableModel model;//会自动绑定到默认连接的数据
    model.setTable("indent");//绑定表格
    model.select();
    //获取表格的记录（一行的结构）
    QSqlRecord record = model.record(); //只有字段没有数据

    //给记录添加数据
    record.setValue("employeeid",ui->empEdit->text());
    record.setValue("desknumber",ui->desEdit->text());
    record.setValue("peoplenumber",ui->peoEdit->text());
    record.setValue("ordernumber",ui->orderEdit->text());
    record.setValue("starttime",ui->timeEdit->text());
    record.setValue("menuid",ui->menuidEdit->text());
    record.setValue("price",ui->priEdit_7->text());
    record.setValue("amount",ui->amountEdit->text());
    //插入到数据库模型中
    if(!model.insertRecord(0, record))
    {
        qDebug()<<model.lastError().text();
    }
    //提交
    model.submit();
}
//查询按钮
void orderwindow::on_order_select_clicked()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

       db.setDatabaseName("project.db");
       if (db.open())
       {
           QSqlQueryModel* qmodel = new QSqlQueryModel();
           qmodel->setQuery("select * from indent");
           ui->tableView->setModel(qmodel);
       }
}

