#ifndef SFKEY_H
#define SFKEY_H

#include <QWidget>

namespace Ui {
class sfkey;
}

class sfkey : public QWidget
{
    Q_OBJECT

public:
    explicit sfkey(QWidget *parent = nullptr);
    ~sfkey();

private slots:

    void on_enBt_clicked();

    void on_delBt_clicked();

private:
    Ui::sfkey *ui;
};

#endif // SFKEY_H
