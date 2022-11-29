#include "sfkey.h"
#include "ui_sfkey.h"

#include <qevent.h>

sfkey::sfkey(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sfkey)
{
    ui->setupUi(this);
}

sfkey::~sfkey()
{
    delete ui;
}


void sfkey::on_enBt_clicked()
{

}

void sfkey::on_delBt_clicked()
{
    QKeyEvent *key = new QKeyEvent(QKeyEvent::KeyPress,Qt::Key_Backspace,Qt::NoModifier," ");
    //派发                   //获取焦点的窗口
    QApplication::postEvent(QApplication::focusWidget(),key);
}
