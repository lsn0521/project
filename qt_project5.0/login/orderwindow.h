#ifndef ORDERWINDOW_H
#define ORDERWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>

#include <QtNetwork/QTcpSocket>

namespace Ui {
class orderwindow;
}

class orderwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit orderwindow(QWidget *parent = nullptr);
    ~orderwindow();
    void setMsocket(QTcpSocket *value);

private slots:

    void on_order_back_clicked();

    void on_order_insert_clicked();

    void on_order_select_clicked();


private:
    Ui::orderwindow *ui;
    QSqlTableModel model;
    QTcpSocket *msocket;
};

#endif // ORDERWINDOW_H
