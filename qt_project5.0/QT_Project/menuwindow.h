#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QTcpSocket>
#include "form.h"
#include "listwindow.h"
namespace Ui {
class MenuWindow;
}

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:

    QString menuid ;
    QString name;
    QString price ;
    QString classify ;
    QString discount;
    QString pictrue;
    QString recommends ;
    QString remarks;
    QString row ;

    static int get_pridata();
    void revcived_order();

    struct OrderList{
        QString name;
        int price;
        int num;
        Form *item;
    };
    void reciveData(QString name, QString price);

    static QVector<OrderList> olist;

//signals:
//    void sendallprice(int allprice);

    explicit MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();

    void setFirstData(QString data);

    void jiexi(QByteArray arr);

    void charu(QString row,int aa,int bb);

    void jiexi_01(QByteArray arr);
private slots:
    void connect_suc();

    void connect_dis();

    void read_data();

    void on_Recombt_clicked();

    void on_guicaibt_clicked();

    void on_yuecai_clicked();

    void on_yinpin_clicked();

private slots:
    void on_Orderbt_clicked();

    void on_servicebt_clicked();

private:
    Ui::MenuWindow *ui;
    QTcpSocket msocket;
    QString ip;
    QSqlTableModel model;
    QSqlRecord rec;
    int recordnumber; //记得第一行数据
    int open_listwindow;
    ListWindow *listwin;
    int money;
protected:
    QVector<QJsonObject> objArray;
};

static int all_price_finsh =0;

#endif // MENUWINDOW_H
