#ifndef ITEMWIN_H
#define ITEMWIN_H

#include <QWidget>

namespace Ui {
class ItemWin;
}

class ItemWin : public QWidget
{
    Q_OBJECT

public:
    explicit ItemWin(QWidget *parent = nullptr);
    ~ItemWin();
    void setinfo(QString name, QString price, QString pictrue);
private:
    Ui::ItemWin *ui;
};

#endif // ITEMWIN_H
