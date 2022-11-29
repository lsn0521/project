#include"form.h"
#include "listwindow.h"
#include "ui_listwindow.h"
#include "menutable.h"
#include "menuwindow.h"
#include "checkwindow.h"
#include <algorithm>
#include <QDebug>
#include <QTcpSocket>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonParseError>


//void ListWindow::recvice_allprice(int all_price)
//{
//    ui->AllLB->setText(QString::number(all_price));
//}

void ListWindow::getmoney(int value)
{
    this->money = value;
    qDebug()<<"this->money:"<<money;
    ui->AllLB->setText(QString::number(this->money));
}

ListWindow::ListWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ListWindow)
{
    ui->setupUi(this);

    for(int i=0;i<MenuWindow::olist.count();i++)
    {
        MenuWindow::OrderList ost = MenuWindow::olist.at(i);
        QListWidgetItem *aitem = new QListWidgetItem;
        MenuWindow::olist[i].item = new Form();
        qDebug()<<ost.name;
        qDebug()<<ost.price;
        qDebug()<<"ost.item->cai_number"<<ost.item->cai_number;
        qDebug()<<"num"<<ost.num;

        MenuWindow::olist[i].item->setInfo(QString::number(ost.price),ost.name,ost.num);
        ui->listWidget->addItem(aitem);
        aitem->setSizeHint(MenuWindow::olist[i].item->sizeHint());
        ui->listWidget->setItemWidget(aitem, MenuWindow::olist[i].item);
        connect(MenuWindow::olist[i].item, &Form::delform, this, &ListWindow::del_form);
    }

    qDebug()<<"all_pri:"<<money;

}

ListWindow::~ListWindow()
{
    delete ui;
}

void ListWindow::reciveData(QString name, QString pridata)
{
    int i=0;
    for(i=0; i<MenuWindow::olist.size(); i++)
    {
        MenuWindow::OrderList obj = MenuWindow::olist.at(i);
        if(obj.name == name)
        {
            qDebug()<<"aaa22";
            MenuWindow::olist.at(i).item->addnumber();
            all_pri = zongjia();
            ui->AllLB->setText(QString::number(all_pri));
            //obj.item->addnumber();
            break;
        }
    }
    if(i == MenuWindow::olist.size())
    {
        Form *form = new Form();
        connect(form, &Form::delform, this, &ListWindow::del_form);
        MenuWindow::OrderList obj;
        obj.name = name;
        obj.price = pridata.toInt();
        obj.num = 1;
        obj.item = form;
        form->setInfo(pridata,name,1);
        QListWidgetItem *aitem = new QListWidgetItem;
        ui->listWidget->addItem(aitem);
        aitem->setSizeHint(form->sizeHint());
        ui->listWidget->setItemWidget(aitem, form);
        MenuWindow::olist.append(obj);
        all_pri = zongjia();
        ui->AllLB->setText(QString::number(all_pri));
    }
}
void ListWindow::del_form()
{
    Form *form = (Form*)sender();
    qDebug()<<"数组元素个数："<<MenuWindow::olist.count();
    for(int i=0; i<MenuWindow::olist.count(); i++)
    {
        MenuWindow::OrderList obj = MenuWindow::olist.at(i);
        if(obj.item->cai_name == form->cai_name)
        {
            MenuWindow::olist.removeAt(i);
            all_pri = zongjia();
            ui->AllLB->setText(QString::number(all_pri));
            break;
        }
    }

    for(int i=0; i<ui->listWidget->count(); i++)
    {

        QWidget *w = ui->listWidget->itemWidget(ui->listWidget->item(i));
        if(w == form)
        {
            delete ui->listWidget->item(i);
        }
    }
    all_pri = zongjia();
    ui->AllLB->setText(QString::number(all_pri));
}

void ListWindow::on_returnBt_clicked()
{

    this->parentWidget()->show();
    delete this;
}
void ListWindow::charu(QString name,QString price,QString pictrue,QString discount,QString recommends,QString row1,int aa,int bb)
{
#if 1
    int row=row1.toUInt();
    int trow = row/3;
    if(row%3==1) trow+=1;
    if(row%3==2) trow+=1;
    int tcol = 2;
    ui->tableWidget->setRowCount(trow);
    ui->tableWidget->setColumnCount(tcol);
    int i=aa;
    if(i<trow)
    {
        int j=bb;
         if(j<tcol)
        {
            MenuTable *win = new MenuTable();
            ui->tableWidget->setCellWidget(i,j, win);
            //win->setinfo(rec.value("name").toString(), rec.value("price").toString(),rec.value("pictrue").toString());
            win->setinfo_01(name, price, pictrue,discount,recommends);
            connect(win,&MenuTable::sendData,this,&ListWindow::reciveData);
        }

    }
#endif

}

int zongjia()
{
    int all_price;
    for(int i=0;i<MenuWindow::olist.count(); i++)
    {
        qDebug()<<MenuWindow::olist[i].name<<" "<<MenuWindow::olist[i].num;
        all_price=MenuWindow::olist[i].price*MenuWindow::olist[i].num;
    }

    return all_price;
}

void ListWindow::on_Order_Bt_clicked()
{
    emit send_order();
    this->parentWidget()->show();
    //this->hide();
    delete this;
}

void ListWindow::on_finishBt_clicked()
{
      CheckWindow *check = new CheckWindow(this);
      check->show();
      this->hide();
      //this->close();

}
