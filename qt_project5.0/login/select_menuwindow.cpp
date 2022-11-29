#include "select_menuwindow.h"
#include "ui_select_menuwindow.h"
#include "itemwin.h"
#include <QFileDialog>
#include <menu_addwindow.h>
select_menuwindow::select_menuwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::select_menuwindow)
{
    ui->setupUi(this);
    //绑定表格
    model.setTable("menu_rec");
    model.setTable("menu_taste");
    model.setTable("menu_soup");
    model.setTable("menu_dessert");
    //select_send();
}

select_menuwindow::~select_menuwindow()
{
    delete ui;
}


//更新菜单
void select_menuwindow::on_updateBt_clicked()
{
    //更新数据库
    rec.setValue("name",ui->nameEdit->text());
    rec.setValue("price",ui->priceEdit->text());
    rec.setValue("pictrue",ui->pictrueEdit->text());
    rec.setValue("discount",ui->discountEdit->text());
    rec.setValue("classify",ui->classfiyEdit->text());
    rec.setValue("recommends",ui->recommendEdit->text());
    model.setRecord(recordnumber,rec);

    //更新列表
    ui->tableWidget->clear();
   if(a==1)
   {
    on_selectBt_rec_clicked();
   }
   if(a==2)
   {
    on_selectBt_taste_clicked();
   }
   if(a==3)
   {
    on_selectBt_soup_clicked();
   }
   if(a==4)
   {
    on_selectBt_dessert_clicked();
   }
}
//返回
void select_menuwindow::on_pushButton_clicked()
{
    this->parentWidget()->show();
    delete this;
}

void select_menuwindow::on_tableWidget_cellClicked(int row, int column)
{
    qDebug()<<row<<column;   //行和列
    rec = model.record(column+row*2);
    recordnumber = column+row*2; //保存第几行数据
    ui->nameEdit->setText(rec.value("name").toString());
    ui->priceEdit->setText(rec.value("price").toString());
    ui->recommendEdit->setText(rec.value("recommends").toString());
    ui->discountEdit->setText(rec.value("discount").toString());
    ui->classfiyEdit->setText(rec.value("classify").toString());

    ui->pictrueEdit->setText(rec.value("pictrue").toString());
    QPixmap mmp(ui->pictrueEdit->text());
    mmp = mmp.scaledToWidth(ui->picLb->width());
    ui->picLb->setPixmap(mmp);
}

//推荐查询
void select_menuwindow::on_selectBt_rec_clicked()
{
    a=1;
    model.setTable("menu_rec");
    //查询
    model.select();
    int row = model.rowCount(); //保存表格中有多少条记录
    //创建tableWidget行和列
    int trow = row/2; if(row%2!=0) trow+=1;
    int tcol = 2;
    ui->tableWidget->setRowCount(trow);
    ui->tableWidget->setColumnCount(tcol);

    //设置每一个格子的窗口
    for(int i=0; i<trow; i++)
    {
        for(int j=0; j<tcol; j++)
        {
            QSqlRecord rec = model.record(j+i*2);
            //创建一个窗口
            ItemWin *win = new ItemWin(this);
            ui->tableWidget->setCellWidget(i,j, win);
            win->setinfo(rec.value("name").toString(), rec.value("price").toString(),rec.value("pictrue").toString());
        }
    }
}
//味道查询
void select_menuwindow::on_selectBt_taste_clicked()
{
    a=2;
    model.setTable("menu_taste");
    //查询
    model.select();
    int row = model.rowCount(); //保存表格中有多少条记录
    //创建tableWidget行和列
    int trow = row/2; if(row%2!=0) trow+=1;
    int tcol = 2;
    ui->tableWidget->setRowCount(trow);
    ui->tableWidget->setColumnCount(tcol);

    //设置每一个格子的窗口
    for(int i=0; i<trow; i++)
    {
        for(int j=0; j<tcol; j++)
        {
            QSqlRecord rec = model.record(j+i*2);
            //创建一个窗口
            ItemWin *win = new ItemWin(this);
            ui->tableWidget->setCellWidget(i,j, win);
            win->setinfo(rec.value("name").toString(), rec.value("price").toString(),rec.value("pictrue").toString());
        }
    }
}
//炖汤查询
void select_menuwindow::on_selectBt_soup_clicked()
{
    a=3;
    model.setTable("menu_soup");
    //查询
    model.select();
    int row = model.rowCount(); //保存表格中有多少条记录
    //创建tableWidget行和列
    int trow = row/2; if(row%2!=0) trow+=1;
    int tcol = 2;
    ui->tableWidget->setRowCount(trow);
    ui->tableWidget->setColumnCount(tcol);

    //设置每一个格子的窗口
    for(int i=0; i<trow; i++)
    {
        for(int j=0; j<tcol; j++)
        {
            QSqlRecord rec = model.record(j+i*2);
            //创建一个窗口
            ItemWin *win = new ItemWin(this);
            ui->tableWidget->setCellWidget(i,j, win);
            win->setinfo(rec.value("name").toString(), rec.value("price").toString(),rec.value("pictrue").toString());
        }
    }
}
//甜品查询
void select_menuwindow::on_selectBt_dessert_clicked()
{
    a=4;
    model.setTable("menu_dessert");
    //查询
    model.select();
    int row = model.rowCount(); //保存表格中有多少条记录
    //创建tableWidget行和列
    int trow = row/2; if(row%2!=0) trow+=1;
    int tcol = 2;
    ui->tableWidget->setRowCount(trow);
    ui->tableWidget->setColumnCount(tcol);

    //设置每一个格子的窗口
    for(int i=0; i<trow; i++)
    {
        for(int j=0; j<tcol; j++)
        {
            QSqlRecord rec = model.record(j+i*2);
            //创建一个窗口
            ItemWin *win = new ItemWin(this);
            ui->tableWidget->setCellWidget(i,j, win);
            win->setinfo(rec.value("name").toString(), rec.value("price").toString(),rec.value("pictrue").toString());
        }
    }
}
//浏览
void select_menuwindow::on_browserrBt_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this);

    QPixmap mmp(filename);
    QString fname = ui->nameEdit->text().toUtf8().toBase64();//图片名称转换
    QString filepath = QString("./pic/%1.jpg").arg(fname);
    mmp.save(filepath);
    ui->pictrueEdit->setText(filepath);

    mmp = mmp.scaledToWidth(ui->picLb->width());
    ui->picLb->setPixmap(mmp);
}
