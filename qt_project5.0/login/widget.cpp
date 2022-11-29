#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QTextStream>
#include "consolewindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QCryptographicHash>
#include <QSqlTableModel>
#include <QTcpSocket>
#include <QJsonParseError>
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonParseError>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);
    allmoney=0;
    ui->label_user_name->setScaledContents(true);   //图片自适应label大小
    ui->label_pwd->setScaledContents(true);         //图片自适应label大小

    ui->lineE_pwd->setEchoMode(QLineEdit::Password);//设置为小黑点

    connect(ui->btn_1,SIGNAL(clicked(bool)),this,SLOT(set_style()));
    connect(ui->btn_2,SIGNAL(clicked(bool)),this,SLOT(set_style()));
    connect(ui->btn_3,SIGNAL(clicked(bool)),this,SLOT(set_style()));
    connect(ui->btn_4,SIGNAL(clicked(bool)),this,SLOT(set_style()));

    //监听
    mserver.listen(QHostAddress::Any,9999);
    //当有客户端连接就会发送newconnection信号
    connect(&mserver,&QTcpServer::newConnection, this, &Widget::new_client);

}
//连接
void Widget::new_client()
{
    qDebug()<<"新客户端连接";
    msocket = mserver.nextPendingConnection(); //获取与客户端通信的套接字
    //发送数据
    connect(msocket,&QTcpSocket::readyRead, this, &Widget::read_data);
}
//开桌解析
void Widget::jiexi(QByteArray arr)
{
    //创建表格模型
    QSqlTableModel model;//会自动绑定到默认连接的数据
    model.setTable("indent");//绑定表格
    model.select();

    QJsonParseError jsonerror;
    QJsonDocument doc = QJsonDocument::fromJson(arr, &jsonerror);
    if(jsonerror.error != QJsonParseError::NoError) //判断是否json格式错误
    {
         qDebug()<<"json error";
    }
    QJsonObject obj = doc.object();
     QString gongh = obj["gonghao"].toString();
     QString zhuoh = obj["zhuohao"].toString();
     QString dingdan = obj["dingdan"].toString();
     QString rens = obj["renshu"].toString();
     QString xiadantime = obj["xiadantime"].toString();
     //保存桌号、服务号
     desknum = zhuoh;
     sernum = gongh;


     //获取表格的记录（一行的结构）
     QSqlRecord record = model.record(); //只有字段没有数据

     //给记录添加数据
     record.setValue("employeeid",gongh);
     record.setValue("desknumber",zhuoh);
     record.setValue("peoplenumber",rens);
     record.setValue("ordernumber",dingdan);
     record.setValue("starttime",xiadantime);

     //插入到数据库模型中
     if(!model.insertRecord(0, record))
     {
         qDebug()<<model.lastError().text();
     }


}
//订单
void Widget::jiexi_dd(QByteArray arr)
{
    //创建表格模型
    QSqlTableModel model;//会自动绑定到默认连接的数据
    model.setTable("indent");//绑定表格
    model.select();

    QJsonParseError jsonerror;
    QJsonDocument doc = QJsonDocument::fromJson(arr, &jsonerror);

    if(jsonerror.error != QJsonParseError::NoError) //判断是否json格式错误
    {
         qDebug()<<"json error"<<"8888";
    }
     QJsonObject obj = doc.object();
     QJsonArray resultArray = obj.value("dingdan").toArray();
     QString shul = obj["shul"].toString();
     int sl=shul.toUInt();
     QJsonObject  *arrObj1=  new QJsonObject[sl];
     QString num[sl];
     QString name[sl] ;
     QString price[sl];

     for (int i=0;i<sl;i++)
     {
        arrObj1[i] = resultArray.at(i).toObject();
         num[i] = arrObj1[i]["num"].toString();
          name[i] = arrObj1[i]["name"].toString();
          price[i] = arrObj1[i]["price"].toString();
          allmoney+=num[i].toUInt()*price[i].toUInt();


     //获取表格的记录（一行的结构）
     QSqlRecord record = model.record(); //只有字段没有数据
     record.setValue("menuid",name[i]);
     record.setValue("price",price[i]);
     record.setValue("amount",num[i]);

     //插入到数据库模型中
     if(!model.insertRecord(0, record))
     {
         qDebug()<<model.lastError().text();
     }

  }
         qDebug()<<allmoney;

}

//开桌协议
void Widget::kaizuo(QString tapy)
{//menu_rec menu_taste menu_soup menu_dessert

    QString mune[4]={"menu_rec","menu_taste","menu_soup","menu_dessert"};
    if(tapy=="0"||tapy=="1"||tapy=="5")
    //查询
    { model.setTable("menu_rec");qDebug()<<"tapy1";}
    if(tapy=="2")
    //查询
    { model.setTable("menu_taste");qDebug()<<"tapy2";}
    if(tapy=="3")
    //查询
    { model.setTable("menu_soup");qDebug()<<"tapy3";}
    if(tapy=="4")
    //查询
    { model.setTable("menu_dessert");qDebug()<<"tapy4";}

    model.select();
    int row = model.rowCount(); //保存表格中有多少条记录

   //this->msocket->write( QString::number(row).toUtf8());
    qDebug()<<row<<"00000";
                        //菜品编号 名字   价格     类别        折扣        路径       推荐度         备注
    QString array[8] = {"menuid","name","price","classify","discount","pictrue","recommends","remarks"};
    QJsonObject obj;
    for(int i=0;i<row;i++)
    {
         QSqlRecord rec = model.record(i);
         QString buff[8] = {rec.value("menuid").toString(),rec.value("name").toString(),rec.value("price").toString()
                                                   ,rec.value("classify").toString(),rec.value("discount").toString(),rec.value("pictrue").toString()
                                                   ,rec.value("recommends").toString(),rec.value("remarks").toString()};

         //if(!rec.value("menuid").toString().isEmpty() && !table.isEmpty()&&!num.isEmpty())
             //创建一个对象

            for(int j=0;j<8;j++)
            {
            obj.insert(array[j],buff[j]); //往对象中插入一个键值对
            }
            objArray.append(obj);
    }

    QJsonObject allObj;
    //定义数组
    QJsonArray allArray;
    for(QJsonObject obj: objArray)
    {
        allArray.append(obj);
    }
     allObj.insert("caidan",allArray);
     allObj.insert("tapy",tapy);
     allObj.insert("row", QString::number(row));
    QJsonDocument doc;
    doc.setObject(allObj);
    QString data = doc.toJson();  //转字符串
    QByteArray arr = data.toUtf8();
    this->msocket->write(arr);
    objArray.clear();

}
//计算总价
void Widget::send_all()
{
     QJsonObject obj;
     obj.insert("tapy","6");
     obj.insert("all",QString::number(allmoney));
     QJsonDocument doc;
     doc.setObject(obj);
     QString data = doc.toJson();  //转字符串
     QByteArray arr = data.toUtf8();
     qDebug()<<"发送价格:"<<allmoney;
     this->msocket->write(arr);
     allmoney = 0;
}
//读取判断json数据
void Widget::read_data()
{
    QTcpSocket *msocket = (QTcpSocket*)sender();
    QString msg = msocket->readAll();
    //qDebug()<<msg;
    QByteArray arr = msg.toUtf8();
    //data数据是从第一个界面传递过来的
    QJsonParseError jsonerror;
    QJsonDocument doc = QJsonDocument::fromJson(arr, &jsonerror);
    if(jsonerror.error != QJsonParseError::NoError) //判断是否json格式错误
    {
         qDebug()<<"json error"<<"错了";
    }
    QJsonObject obj = doc.object();
    QString tapy = obj["tapy"].toString();
    if(tapy=="0")
    {
       kaizuo(tapy);
       jiexi(arr);
    }

     if(tapy=="1")
     {
        kaizuo(tapy);
     }
     if(tapy=="2")
     {
         kaizuo(tapy);
     }
     if(tapy=="3")
     {
         kaizuo(tapy);
     }
     if(tapy=="4")
     {
         kaizuo(tapy);
     }
     if(tapy=="5")
     {
         kaizuo(tapy);
     }
     if(tapy=="6")
     {
       jiexi_dd(arr);
       send_all();

     }
     if(tapy=="7")
     {
         qDebug()<<"桌号"<<desknum;
         QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),QString(desknum+"号桌客人需要服务"));
         QTimer::singleShot(1000,m_box,SLOT(accept()));
         m_box->exec();
         win->set_numdata(desknum,sernum);
     }


}

/*
* 槽函数-皮肤设置
*/
QPushButton* btn;
void Widget::set_style()
{
    btn = qobject_cast<QPushButton*>(sender());//获取发射信号的对象
    QString filePath;
    if("btn_1" == btn->objectName())        //粉色
    {
        filePath = ":/res/qss/style-1.qss";
    }else if("btn_2" == btn->objectName())  //黄蓝
    {
        filePath = ":/res/qss/style-2.qss";
    }else if("btn_3" == btn->objectName())  //浅紫
    {
        filePath = ":/res/qss/style-3.qss";
    }else if("btn_4" == btn->objectName())  //青绿
    {
        filePath = ":/res/qss/style-4.qss";
    }

    /*皮肤设置*/
    QFile file(filePath);/*QSS文件所在的路径*/
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    this->setStyleSheet(stylesheet);
    file.close();
}

Widget::~Widget()
{
    delete ui;
}
//登录
void Widget::on_btn_login_clicked()
{
       //窗口跳转
       ConsoleWindow *con = new ConsoleWindow();
this->win = con;
       QString user = ui->lineE_user_name->text();
       QString ps = ui->lineE_pwd->text();
       //密码加密MD5加密
       QCryptographicHash hash(QCryptographicHash::Md5);//创建加密对象
       hash.addData(ps.toUtf8(), ps.size());//添加要加密的数据（明码）
       QByteArray array = hash.result();//获取加密后的结果--占用16字节，转十六进制32位
       QString password = array.toHex();//转十六进制（字符）
       //查询
       QString sql=QString("select * from user where name='%1' and password='%2'")
               .arg(user).arg(password);
       //执行语句
       QSqlQuery query;
       query.exec(sql);
       //设置message

       //设置文本框的大小和颜色

       if(query.next()) //true说明已经查到一条数据
       {
           con->show();
           this->hide();
       }else
       {
               QMessageBox box;
               //设置文本框的大小和颜色
               box.setIconPixmap(QPixmap(":/res/usr/tips.png"));
               QPixmap map;
               box.setStyleSheet(
                           "QPushButton {"
                                              "background-color:#89AFDE;"
                                              " border-style: outset;"
                                              " border-width: 1px;"
                                              " border-radius: 5px;"
                                              " border-color: beige;"
                                              " font: bold 18px;"
                                              " min-width: 5em;"
                                              " min-height: 2em;"
                                              "}"
                              "QLabel { min-width:200px;min-height:200px;font:20px;background-color:rbga(255,255,255,0);}"
                              "map{min-width:100px;min-height:100px;}"                  );


               box.setText("用户名或密码错误，请重试");
               box.setWindowTitle("提示");
               box.exec();
       }
       con->setdata(user);

}
//注册
void Widget::on_btn_sign_clicked()
{

    QString ps = ui->lineE_pwd->text();
    //密码加密MD5加密
    QCryptographicHash hash(QCryptographicHash::Md5);//创建加密对象
    hash.addData(ps.toUtf8(), ps.size());//添加要加密的数据（明码）
    QByteArray array = hash.result();//获取加密后的结果--占用16字节，转十六进制32位
    QString password = array.toHex();


    QString insertSql = QString("insert into user(name, password) values('%1','%2')")
            .arg(ui->lineE_user_name->text()).arg(password);
    QSqlQuery query;
    if(!query.exec(insertSql))
    {
        QMessageBox::warning(this,"注册提示","注册失败-用户已经存在");
        return;
    }else
    {
        QMessageBox::warning(this,"注册提示","注册成功");
    }
}
