#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    void setInfo(QString price,QString cai_name , int number);

    void addnumber();
private slots:
    void on_subBt_clicked();

    void on_pushButton_clicked();
signals:
    void delform();
private:
    Ui::Form *ui;
public:
    int cai_price;
    int cai_number;
    QString cai_name;
    void tonbu();
};

#endif // FORM_H
