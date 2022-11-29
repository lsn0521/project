#ifndef WIDGET_H
#define WIDGET_H

#include "consolewindow.h"

#include <QSqlTableModel>
#include <QWidget>

#include <QtNetwork/QTcpServer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void jiexi(QByteArray arr);

    void kaizuo(QString tapy);

    void send_all();

    ConsoleWindow *win;

    void jiexi_dd(QByteArray arr);
public slots:
    void set_style();

    void new_client();

    void read_data();

private slots:
    void on_btn_login_clicked();

    void on_btn_sign_clicked();

private:
    Ui::Widget *ui;
    QTcpServer mserver;
    QTcpSocket *msocket;
    QSqlTableModel model;
    QVector<QJsonObject> objArray;
    int allmoney;
    QString desknum;
    QString sernum;

};

#endif // WIDGET_H
