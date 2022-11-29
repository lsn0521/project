#ifndef MENU_ADDWINDOW_H
#define MENU_ADDWINDOW_H

#include <QMainWindow>

#include <QtNetwork/QTcpSocket>

namespace Ui {
class menu_addwindow;
}

class menu_addwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu_addwindow(QWidget *parent = nullptr);
    ~menu_addwindow();
    void setMsocket(QTcpSocket *value);

private slots:
    void on_browserrBt_clicked();

    void on_pushButton_clicked();

    void on_selectBt_rec_clicked();

    void on_selectBt_taste_clicked();

    void on_selectBt_soup_clicked();

    void on_selectBt_dessert_clicked();

private:
    Ui::menu_addwindow *ui;
    QTcpSocket *msocket;
};

#endif // MENU_ADDWINDOW_H
