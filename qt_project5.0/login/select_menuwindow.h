#ifndef SELECT_MENUWINDOW_H
#define SELECT_MENUWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>

#include <QtNetwork/QTcpSocket>

namespace Ui {
class select_menuwindow;
}

class select_menuwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit select_menuwindow(QWidget *parent = nullptr);
    ~select_menuwindow();
    void setMsocket(QTcpSocket *value);


private slots:

    void on_updateBt_clicked();

    void on_pushButton_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void on_selectBt_rec_clicked();

    void on_selectBt_taste_clicked();

    void on_selectBt_soup_clicked();

    void on_selectBt_dessert_clicked();

    void on_browserrBt_clicked();

private:
    Ui::select_menuwindow *ui;
    QSqlTableModel model;
    QTcpSocket *msocket;
    QSqlRecord rec;
    int recordnumber; //记得第一行数据
    int a = 0;
};

#endif // SELECT_MENUWINDOW_H
