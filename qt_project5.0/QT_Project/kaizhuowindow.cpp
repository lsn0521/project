#include "kaizhuowindow.h"
#include "ui_kaizhuowindow.h"
kaizhuoWindow::kaizhuoWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::kaizhuoWindow)
{
    ui->setupUi(this);
}

kaizhuoWindow::~kaizhuoWindow()
{
    delete ui;
}

