#include "firstwindow.h"
#include "ui_firstwindow.h"
#include "kaizhuo_ui.h"
#include "QDebug"
#include "menuwindow.h"
#include <QRect>
#include <QTime>
#include <QDate>
#include <QTcpSocket>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonParseError>
FirstWindow::FirstWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FirstWindow)
{
    ui->setupUi(this);
    //connect(ui->widget,&kaizhuo_ui::sneddata,this,&FirstWindow::recveid);
    ui->widget_2->hide();
    ui->tableEt->installEventFilter(this);
    ui->peopleEt->installEventFilter(this);
    ui->workEt->installEventFilter(this);
    mtimer.start(1000);
    connect(&mtimer, &QTimer::timeout, this, &FirstWindow::show_time);
}
//显示时间
void FirstWindow::show_time()
{
    QString date = QDate::currentDate().toString("yyyy-MM-dd");
    QString time = QTime::currentTime().toString("hh:mm:ss");
    ui->label->setText(date);
    ui->label_2->setText(time);
    if(!mtimer.isActive())
    {
        mtimer.isActive();
    }
    QString data = QDate::currentDate().toString("yyyyMMdd");
    QString time1 = QTime::currentTime().toString("hhmmss");
    dd=data+time1;
    sj=date+time;
}
//软键盘焦点
bool FirstWindow::eventFilter(QObject *watched, QEvent *event)
{

    // 输入框的焦点进入事件
    if(watched->inherits("QLineEdit")) //判断对象是否是QLineEdit
    {
        if(event->type() == QEvent::FocusIn) //获取焦点事件
        {
            qDebug()<<"事件过滤";
            ui->widget_2 ->show();
            ui->kaizhuo->setGeometry(120,10,500,250);
        }
        if(event->type() == QEvent::FocusOut) //失去焦点事件
        {

            ui->widget_2->hide();
            ui->kaizhuo->setGeometry(90,30,600,400);
        }
    }

    return QMainWindow::eventFilter(watched, event);
}

FirstWindow::~FirstWindow()
{
    delete ui;
}

void FirstWindow::recveid()
{
    this->close();
}


void FirstWindow::on_sureBt_clicked()
{
    MenuWindow *menuwin = new MenuWindow(this);

    QString peo = ui->workEt->text();
    QString table = ui->tableEt->text();
    QString num = ui->peopleEt->text();
    dd=dd+table+num;
    QJsonObject obj;
    if(!peo.isEmpty() && !table.isEmpty()&&!num.isEmpty())
    {
         //创建一个对象
        obj.insert("tapy","0");
        obj.insert("gonghao",peo); //往对象中插入一个键值对
        obj.insert("zhuohao",table);//往对象中插入一个键值对
        obj.insert("renshu",num);
        obj.insert("dingdan",dd);
        obj.insert("xiadantime",sj);
        //把对象添加到容器
    }

    QJsonDocument doc;
    doc.setObject(obj);
    QString data = doc.toJson();  //转字符串
    menuwin->setFirstData(data);

    menuwin->show();
    this->hide();
}
