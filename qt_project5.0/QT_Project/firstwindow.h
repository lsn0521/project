#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H
#include <QTimer>
#include <QMainWindow>
#include <QTcpSocket>
QT_BEGIN_NAMESPACE
namespace Ui { class FirstWindow; }
QT_END_NAMESPACE

class FirstWindow : public QMainWindow
{
    Q_OBJECT

public:
    FirstWindow(QWidget *parent = nullptr);
    ~FirstWindow();
    void recveid();

    bool eventFilter(QObject *watched, QEvent *event);

    void show_time();

    QString dd;
    QString sj;
private slots:
    void on_sureBt_clicked();
private:
    Ui::FirstWindow *ui;
    QTimer mtimer ;//定时器对象
    QTcpSocket msocket;
QVector<QJsonObject> objArray;
};
#endif // FIRSTWINDOW_H
