#include "form.h"
#include "ui_form.h"
#include <QString>
#include <QDebug>
#include "menuwindow.h"
#include "listwindow.h"
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::setInfo(QString price, QString name, int number)
{
    this->cai_price = price.toInt();
    this->cai_name = name;
    this->cai_number = number;
    ui->cai_namelb->setText(this->cai_name);
    ui->cai_price_lb->setText(QString::number( this->cai_price));
    ui->cai_number_lb->setText(QString::number( this->cai_number));
}

void Form::on_subBt_clicked()
{
    if(this->cai_number <=1)
    { 
        emit delform();
    }
    else
    {     
        this->cai_number--;
        tonbu();
        ui->cai_number_lb->setText(QString::number(cai_number));

    }
}

void Form::on_pushButton_clicked()
{
    this->cai_number+=1;
    if(cai_number == 10)
    {
        this->cai_number-=1;
    }
    tonbu();
    ui->cai_number_lb->setText(QString::number(cai_number));
}

void Form::addnumber()
{
    cai_number+=1;
    if(cai_number == 10)
    {
        this->cai_number-=1;
    }
    tonbu();
    ui->cai_number_lb->setText(QString::number(cai_number));
}


void Form::tonbu()
{
    for(int i=0;i<MenuWindow::olist.count();i++)
    {
        if(this->cai_name==MenuWindow::olist.at(i).item->cai_name)
        {
            MenuWindow::olist[i].num = this->cai_number;
        }
    }
}
