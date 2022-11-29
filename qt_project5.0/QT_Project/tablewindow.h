#ifndef TABLEWINDOW_H
#define TABLEWINDOW_H

#include <QMainWindow>

namespace Ui {
class TAbleWindow;
}

class TAbleWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TAbleWindow(QWidget *parent = nullptr);
    ~TAbleWindow();

private:
    Ui::TAbleWindow *ui;
};

#endif // TABLEWINDOW_H
