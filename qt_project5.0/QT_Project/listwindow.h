#ifndef LISTWINDOW_H
#define LISTWINDOW_H

#include "form.h"

#include <QMainWindow>
#include <QSqlTableModel>
#include <QTcpSocket>
#include <QSqlRecord>
namespace Ui {
class ListWindow;
}

class ListWindow : public QMainWindow
{
    Q_OBJECT
public:
    int all_pri;

    void getmoney(int value);

    explicit ListWindow(QWidget *parent = nullptr);

    ~ListWindow();
    void reciveData(QString name,QString pridata);

    void charu(QString name,QString price,QString pictrue,QString discount,QString recommends,QString row1,int aa,int bb);
protected slots:
    void del_form();
    void on_returnBt_clicked();
signals:
    void send_order();
private slots:
    void on_Order_Bt_clicked();

    void on_finishBt_clicked();


private:
    Ui::ListWindow *ui;
    QSqlTableModel model_0;
    QSqlRecord rec_0;
    QSqlRecord rec;
    int money;
    friend int zongjia();

};

int zongjia();

#endif // LISTWINDOW_H
