#ifndef CHECK_H
#define CHECK_H

#include <QWidget>

namespace Ui {
class check;
}

class check : public QWidget
{
    Q_OBJECT

public:
    explicit check(QWidget *parent = nullptr);
    ~check();

private:
    Ui::check *ui;
};

#endif // CHECK_H
