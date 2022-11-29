#ifndef MENUTABLE_H
#define MENUTABLE_H

#include <QTcpSocket>
#include <QWidget>

namespace Ui {
class MenuTable;
}

class MenuTable : public QWidget
{
    Q_OBJECT
signals:
    void sendData(QString name,QString pri);
public:
    explicit MenuTable(QWidget *parent = nullptr);
    ~MenuTable();
void setinfo_01(QString name, QString price, QString pictrue,QString discount,QString recommends);

void setinfo(QString name, QString price, QString pictrue);
public slots:
void on_addBt_clicked();
private:
    Ui::MenuTable *ui;
};

#endif // MENUTABLE_H
