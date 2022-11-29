#include "checkwindow.h"
#include "ui_checkwindow.h"
#include "firstwindow.h"



CheckWindow::CheckWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CheckWindow)
{
    //skip();
    ui->setupUi(this);
}

CheckWindow::~CheckWindow()
{

    delete ui;
}
void CheckWindow::skip()
{
    FirstWindow *win = new FirstWindow();
    win->show();
    delete this;
}
