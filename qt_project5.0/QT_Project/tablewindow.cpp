#include "tablewindow.h"
#include "ui_tablewindow.h"
#include "menutable.h"
TAbleWindow::TAbleWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TAbleWindow)
{
    ui->setupUi(this);
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<4; j++)
        {
            //创建一个窗口
            MenuTable *talb = new MenuTable;
            //ItemWin *win = new ItemWin;
            ui->tableWidget->setCellWidget(i,j, talb);
        }
    }
}

TAbleWindow::~TAbleWindow()
{
    delete ui;
}
