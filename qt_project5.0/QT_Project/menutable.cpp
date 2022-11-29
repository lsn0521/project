#include "menutable.h"
#include "ui_menutable.h"
MenuTable::MenuTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuTable)
{
    ui->setupUi(this);

}

MenuTable::~MenuTable()
{
    delete ui;
}


void MenuTable::setinfo_01(QString name, QString price, QString pictrue,QString discount,QString recommends)
{
    ui->nameLB->setText(name);
    ui->priLB->setText(price);
    ui->label->setText(discount);
    ui->tjLB->setText(recommends);
    QPixmap mmp(pictrue);
    mmp = mmp.scaledToWidth(ui->picLB->width());
    ui->picLB->setPixmap(mmp);
}

void MenuTable::setinfo(QString name, QString price, QString pictrue)
{
    ui->nameLB->setText(name);
    ui->priLB->setText(price);
    QPixmap mmp(pictrue);
    mmp = mmp.scaledToWidth(ui->picLB->width());  //设置对应的框
    ui->picLB->setPixmap(mmp);
}

void MenuTable::on_addBt_clicked()
{
    QString pridata = ui->priLB->text();
    QString name = ui->nameLB->text();
    emit sendData(name,pridata);
}
