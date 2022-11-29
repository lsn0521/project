#ifndef CONSOLEWINDOW_H
#define CONSOLEWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>
#include <QTimer>

#include <QtNetwork/QTcpSocket>
namespace Ui {
class ConsoleWindow;
}

class ConsoleWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConsoleWindow(QWidget *parent = nullptr);
    ~ConsoleWindow();
    void setMsocket(QTcpSocket *value);
    void setdata(QString arg);
    void set_numdata(QString argA,QString argB);
    QString desk_num;
    QString ser_num;



private slots:

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::ConsoleWindow *ui;
    QTcpSocket *msocket;

};

#endif // CONSOLEWINDOW_H
