#include "kaizhuo_ui.h"
#include "ui_kaizhuo_ui.h"
#include "menuwindow.h"
#include <QTime>
#include <QDate>
kaizhuo_ui::kaizhuo_ui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kaizhuo_ui)
{
    ui->setupUi(this);
    ui->tableEt->installEventFilter(this);
    ui->peopleEt->installEventFilter(this);
    ui->worknum->installEventFilter(this);
    mtimer.start(1000);
    connect(&mtimer, &QTimer::timeout, this, &kaizhuo_ui::show_time);
}

kaizhuo_ui::~kaizhuo_ui()
{
    delete ui;
}


void kaizhuo_ui::show_time()
{
    QString date = QDate::currentDate().toString("yyyy-MM-dd");
    QString time = QTime::currentTime().toString("hh:mm:ss");
    ui->label->setText(date);
    ui->label_2->setText(time);
    if(!mtimer.isActive())
    {
        mtimer.isActive();
    }

}

void kaizhuo_ui::on_sureBt_clicked()
{
    MenuWindow *menuwin = new MenuWindow;
    emit sneddata();
    menuwin->show();
}
