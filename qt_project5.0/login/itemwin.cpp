#include "itemwin.h"
#include "ui_itemwin.h"

ItemWin::ItemWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemWin)
{
    ui->setupUi(this);
}

ItemWin::~ItemWin()
{
    delete ui;
}

void ItemWin::setinfo(QString name, QString price, QString pictrue)
{
    ui->nameLb->setText(name);
    ui->priceLb->setText(price);

    QPixmap mmp(pictrue);
    mmp = mmp.scaledToWidth(ui->pictrueLb->width());
    ui->pictrueLb->setPixmap(mmp);
}
