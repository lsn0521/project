#include "menu_addwindow.h"
#include "ui_menu_addwindow.h"
#include <QFileDialog>
#include <QtSql/QSqlTableModel>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QCryptographicHash>
#include <QSqlTableModel>

menu_addwindow::menu_addwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu_addwindow)
{
    ui->setupUi(this);
}

menu_addwindow::~menu_addwindow()
{
    delete ui;
}
//浏览图片
void menu_addwindow::on_browserrBt_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this);

    QPixmap mmp(filename);
    QString fname = ui->nameEdit->text().toUtf8().toBase64();//图片名称转换
    QString filepath = QString("./pic/%1.jpg").arg(fname);
    mmp.save(filepath);
    ui->pictEdit->setText(filepath);

    mmp = mmp.scaledToWidth(ui->label->width());
    ui->label->setPixmap(mmp);
}

//返回
void menu_addwindow::on_pushButton_clicked()
{
    this->parentWidget()->show();
    delete this;
}

//推荐
void menu_addwindow::on_selectBt_rec_clicked()
{
    //创建表格模型
    QSqlTableModel model;//会自动绑定到默认连接的数据
    model.setTable("menu_rec");//绑定表格
    model.select();
    //获取表格的记录（一行的结构）
    QSqlRecord record = model.record(); //只有字段没有数据

    //给记录添加数据
    record.setValue("menuid",ui->idEdit->text());
    record.setValue("name",ui->nameEdit->text());
    record.setValue("price",ui->priEdit->text());
    record.setValue("discount",ui->disEdit->text());
    record.setValue("classify",ui->classEdit->text());
    record.setValue("pictrue",ui->pictEdit->text());
    record.setValue("recommends",ui->recEdit->text());
    record.setValue("remarks",ui->reEdit->text());

    //插入到数据库模型中
    if(!model.insertRecord(0, record))
    {
        qDebug()<<model.lastError().text();
    }
    //提交
    if(!model.submit())
    {
        QMessageBox::warning(this,"插入提示","插入失败");
        return;
    }else
    {
        QMessageBox::warning(this,"插入提示","插入成功");
    }
}


//炖汤
void menu_addwindow::on_selectBt_soup_clicked()
{
    //创建表格模型
    QSqlTableModel model;//会自动绑定到默认连接的数据
    model.setTable("menu_soup");//绑定表格
    model.select();
    //获取表格的记录（一行的结构）
    QSqlRecord record = model.record(); //只有字段没有数据

    //给记录添加数据
    record.setValue("menuid",ui->idEdit->text());
    record.setValue("name",ui->nameEdit->text());
    record.setValue("price",ui->priEdit->text());
    record.setValue("discount",ui->disEdit->text());
    record.setValue("classify",ui->classEdit->text());
    record.setValue("pictrue",ui->pictEdit->text());
    record.setValue("recommends",ui->recEdit->text());
    record.setValue("remarks",ui->reEdit->text());

    //插入到数据库模型中
    if(!model.insertRecord(0, record))
    {
        qDebug()<<model.lastError().text();
    }
    //提交
    if(!model.submit())
    {
        QMessageBox::warning(this,"插入提示","插入失败");
        return;
    }else
    {
        QMessageBox::warning(this,"插入提示","插入成功");
    }
}

//味道
void menu_addwindow::on_selectBt_taste_clicked()
{
    //创建表格模型
    QSqlTableModel model;//会自动绑定到默认连接的数据
    model.setTable("menu_taste");//绑定表格
    model.select();
    //获取表格的记录（一行的结构）
    QSqlRecord record = model.record(); //只有字段没有数据

    //给记录添加数据
    record.setValue("menuid",ui->idEdit->text());
    record.setValue("name",ui->nameEdit->text());
    record.setValue("price",ui->priEdit->text());
    record.setValue("discount",ui->disEdit->text());
    record.setValue("classify",ui->classEdit->text());
    record.setValue("pictrue",ui->pictEdit->text());
    record.setValue("recommends",ui->recEdit->text());
    record.setValue("remarks",ui->reEdit->text());

    //插入到数据库模型中
    if(!model.insertRecord(0, record))
    {
        qDebug()<<model.lastError().text();
    }
    //提交
    if(!model.submit())
    {
        QMessageBox::warning(this,"插入提示","插入失败");
        return;
    }else
    {
        QMessageBox::warning(this,"插入提示","插入成功");
    }
}

//甜品
void menu_addwindow::on_selectBt_dessert_clicked()
{
    //创建表格模型
    QSqlTableModel model;//会自动绑定到默认连接的数据
    model.setTable("menu_dessert");//绑定表格
    model.select();
    //获取表格的记录（一行的结构）
    QSqlRecord record = model.record(); //只有字段没有数据

    //给记录添加数据
    record.setValue("menuid",ui->idEdit->text());
    record.setValue("name",ui->nameEdit->text());
    record.setValue("price",ui->priEdit->text());
    record.setValue("discount",ui->disEdit->text());
    record.setValue("classify",ui->classEdit->text());
    record.setValue("pictrue",ui->pictEdit->text());
    record.setValue("recommends",ui->recEdit->text());
    record.setValue("remarks",ui->reEdit->text());

    //插入到数据库模型中
    if(!model.insertRecord(0, record))
    {
        qDebug()<<model.lastError().text();
    }
    //提交
    if(!model.submit())
    {
        QMessageBox::warning(this,"插入提示","插入失败");
        return;
    }else
    {
        QMessageBox::warning(this,"插入提示","插入成功");
    }
}
void menu_addwindow::setMsocket(QTcpSocket *value)
{
    this->msocket = value;
}
