#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "menutable.h"
#include <QTcpSocket>

#include <QJsonParseError>
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonParseError>
#include <QMessageBox>

QVector<MenuWindow::OrderList> MenuWindow::olist;

MenuWindow::MenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    this->ip = "192.168.5.15";
    msocket.connectToHost(ip,9999);
    //连接成功信号， 断开信号， 读书节信号
    connect(&msocket, &QTcpSocket::connected, this, &MenuWindow::connect_suc);
    connect(&msocket, &QTcpSocket::disconnected, this, &MenuWindow::connect_dis);
    connect(&msocket, &QTcpSocket::readyRead, this, &MenuWindow::read_data);

}

MenuWindow::~MenuWindow()
{
    delete listwin;
    delete ui;
}

//网络
void MenuWindow::connect_suc()
{

}
void MenuWindow::connect_dis()
{
}
void MenuWindow::read_data()
{
     QString msg = msocket.readAll();
     QByteArray arr = msg.toUtf8();

     //data数据是从第一个界面传递过来的
     QJsonParseError jsonerror;
     QJsonDocument doc = QJsonDocument::fromJson(arr, &jsonerror);
     if(jsonerror.error != QJsonParseError::NoError) //判断是否json格式错误
     {
          qDebug()<<"json error";
     }
     QJsonObject obj = doc.object();
     QString tapy = obj["tapy"].toString();
     row = obj["row"].toString();
     if(tapy=="1"||tapy=="0")
    {
        jiexi(arr);
    }
     if(tapy=="2")
     {
        jiexi(arr);
     }
     if(tapy=="3")
     {
        jiexi(arr);
     }
     if(tapy=="4")
     {
        jiexi(arr);
     }
     if(tapy=="5")
     {
        jiexi_01(arr);
     }
     if(tapy=="6")
     {

         QByteArray arr = msg.toUtf8();

         //data数据是从第一个界面传递过来的
         QJsonParseError jsonerror;
         QJsonDocument doc = QJsonDocument::fromJson(arr, &jsonerror);
         if(jsonerror.error != QJsonParseError::NoError) //判断是否json格式错误
         {
              qDebug()<<"json error";
         }
         QJsonObject obj = doc.object();
         QString allmoney = obj["all"].toString();
         qDebug()<<"allmoney"<<allmoney;
         this->money = allmoney.toInt();
         qDebug()<<"money:"<<money;

     }

}

void MenuWindow::jiexi(QByteArray arr)
{
    QJsonParseError jsonerror;
    QJsonDocument doc = QJsonDocument::fromJson(arr, &jsonerror);

    if(jsonerror.error != QJsonParseError::NoError) //判断是否json格式错误
    {
         qDebug()<<"json error"<<"8888";
    }
     QJsonObject obj = doc.object();
     QJsonArray resultArray = obj.value("caidan").toArray();
     int a = row.toInt();
     QJsonObject  *arrObj1=  new QJsonObject[a];
    int aa=0;int bb=0;
     for (int i=0;i<a;i++)
     {
        arrObj1[i] = resultArray.at(i).toObject();
         menuid = arrObj1[i]["menuid"].toString();
         name = arrObj1[i]["name"].toString();
         price = arrObj1[i]["price"].toString();
         classify = arrObj1[i]["classify"].toString();
         discount= arrObj1[i]["discount"].toString();
         pictrue= arrObj1[i]["pictrue"].toString();
         recommends = arrObj1[i]["recommends"].toString();
         remarks= arrObj1[i]["remarks"].toString();
         charu(row,aa,bb);
           bb++;
         if(bb==3)
            {
                aa++;
                bb=0;
            }
     }

}

void MenuWindow::jiexi_01(QByteArray arr)
{
    QJsonParseError jsonerror;
    QJsonDocument doc = QJsonDocument::fromJson(arr, &jsonerror);

    if(jsonerror.error != QJsonParseError::NoError) //判断是否json格式错误
    {
         qDebug()<<"json error"<<"8888";
    }
     QJsonObject obj = doc.object();
     QJsonArray resultArray = obj.value("caidan").toArray();
     int a = row.toInt();
     QJsonObject  *arrObj1=  new QJsonObject[a];
    int aa=0;int bb=0;
     for (int i=0;i<a;i++)
     {
        arrObj1[i] = resultArray.at(i).toObject();
         menuid = arrObj1[i]["menuid"].toString();
         name = arrObj1[i]["name"].toString();
         price = arrObj1[i]["price"].toString();
         classify = arrObj1[i]["classify"].toString();
         discount= arrObj1[i]["discount"].toString();
         pictrue= arrObj1[i]["pictrue"].toString();
         recommends = arrObj1[i]["recommends"].toString();
         remarks= arrObj1[i]["remarks"].toString();
         listwin->charu(name, price, pictrue,discount,recommends,row,aa,bb);
         bb++;
         if(bb==3)
            {
                aa++;
                bb=0;
            }
     }

}


//shangcai
void MenuWindow::charu(QString row1,int aa,int bb)
{
    int row=row1.toUInt();
    int trow = row/3;
    if(row%3==1) trow+=1;
    if(row%3==2) trow+=1;
    int tcol = 3;
    ui->Table_on->setRowCount(trow);
    ui->Table_on->setColumnCount(tcol);
    int i=aa;
    if(i<trow)
    {
        int j=bb;
         if(j<tcol)
        {
            MenuTable *win = new MenuTable(this);
            ui->Table_on->setCellWidget(i,j, win);
            connect(win,&MenuTable::sendData,this,&MenuWindow::reciveData);
            win->setinfo(rec.value("name").toString(), rec.value("price").toString(),rec.value("pictrue").toString());
            win->setinfo_01(name, price, pictrue,discount,recommends);
        }

    }
}


void MenuWindow::setFirstData(QString data)
{
    QByteArray arr = data.toUtf8();
    //data数据是从第一个界面传递过来的
    QJsonParseError jsonerror;
    QJsonDocument doc = QJsonDocument::fromJson(arr, &jsonerror);
    if(jsonerror.error != QJsonParseError::NoError) //判断是否json格式错误
    {
         qDebug()<<"json error";
    }
    QJsonObject obj = doc.object();

     QString tapy = obj["tapy"].toString();
     QString gongh = obj["gonghao"].toString();
     QString zhuoh = obj["zhuohao"].toString();
     QString dingdan = obj["dingdan"].toString();
      QString rens = obj["renshu"].toString();
    //通过temperature获取对应值,字符串
   ui->OrderEdit->setText(dingdan);
   ui->peopleEdit->setText(rens);
   ui->serEdit->setText(gongh);
   ui->tableEdit->setText(zhuoh);

   this->msocket.write(arr);
}
//QAbstractSocket::ConnectedState;
void MenuWindow::on_Recombt_clicked()
{
    qDebug()<<"1";
     QJsonObject obj;
     obj.insert("tapy","1");
     QJsonDocument doc;
     doc.setObject(obj);
     QString data = doc.toJson();  //转字符串
     QByteArray arr = data.toUtf8();
     this->msocket.write(arr);
}

void MenuWindow::on_guicaibt_clicked()
{
    qDebug()<<"2";
    QJsonObject obj;
     obj.insert("tapy","2");
     QJsonDocument doc;
     doc.setObject(obj);
     QString data = doc.toJson();  //转字符串
     QByteArray arr = data.toUtf8();
     this->msocket.write(arr);
}


void MenuWindow::on_yuecai_clicked()
{
    qDebug()<<"3";
    QJsonObject obj;
     obj.insert("tapy","3");
     QJsonDocument doc;
     doc.setObject(obj);
     QString data = doc.toJson();  //转字符串
     QByteArray arr = data.toUtf8();
     this->msocket.write(arr);
}

void MenuWindow::on_yinpin_clicked()
{
    qDebug()<<"4";
    QJsonObject obj;
     obj.insert("tapy","4");
     QJsonDocument doc;
     doc.setObject(obj);
     QString data = doc.toJson();  //转字符串
     QByteArray arr = data.toUtf8();
     this->msocket.write(arr);
}

void MenuWindow::on_Orderbt_clicked()
{

    qDebug()<<"5";
    QJsonObject obj;
    obj.insert("tapy","5");
    QJsonDocument doc;
    doc.setObject(obj);
    QString data = doc.toJson();  //转字符串
    QByteArray arr = data.toUtf8();
    this->msocket.write(arr);
    listwin = new ListWindow(this);
    listwin->show();
    this->hide();

    listwin->getmoney(this->money);
    connect(listwin,&ListWindow::send_order,this,&MenuWindow::revcived_order);
}

int MenuWindow::get_pridata()
{
    return all_price_finsh;
}

void MenuWindow::revcived_order()
{
    qDebug()<<"%%";
       QString array[3]={"num","name","price"};
       QJsonObject obj;
          for(int i=0;i<olist.count();i++)
          {
              qDebug()<<"jinlaile888888-----";
              OrderList ost = olist.at(i);
//               for(int i=0;i<olist.count();i++)
//               {
                   QString buff[3]={QString::number(ost.item->cai_number),ost.name,QString::number(ost.price)};
                   for (int j= 0;j<3;j++)
                   {
                      obj.insert(array[j],buff[j]);
                   }
                   objArray.append(obj);
               //}
          }
             QJsonObject allObj;  //{}
      //定义数组
      QJsonArray allArray; //[]
      for(QJsonObject obj: objArray)
      {
          allArray.append(obj);  //[{},{},{}]
      }
       allObj.insert("dingdan",allArray);
       allObj.insert("tapy","6");
       allObj.insert("shul",QString::number( olist.count()));
      QJsonDocument doc;
      doc.setObject(allObj);
      QString data = doc.toJson();  //转字符串
      QByteArray arr = data.toUtf8();
      this->msocket.write(arr);
      objArray.clear();
}

void MenuWindow::reciveData(QString name,QString price)
{
    int i=0;
    for(i=0; i<olist.count(); i++)
    {
        OrderList obj = olist.at(i);
        if(obj.name == name)
        {
            olist[i].num+=1;
            //调用改数字的的函数
             olist[i].item->addnumber();
            //qDebug()<<obj.item->cai_number;
            break;
        }
    }
    if(i == olist.size())
    {
        Form *form = new Form();
        OrderList obj;
        obj.name = name;
        obj.price = price.toInt();
        obj.item = form;
        obj.num = 1;
        form->setInfo(price,name,1);
        olist.append(obj);
        //qDebug()<<olist.count();
    }

}

void MenuWindow::on_servicebt_clicked()
{
    QJsonObject obj;
    obj.insert("tapy","7");
    QJsonDocument doc;
    doc.setObject(obj);
    QString data = doc.toJson();  //转字符串
    QByteArray arr = data.toUtf8();
    this->msocket.write(arr);
   QMessageBox::StandardButton result = QMessageBox::information(this, "提示","服务员已收到请求，请稍等");

}
