#ifndef KAIZHUO_UI_H
#define KAIZHUO_UI_H
#include <QTimer>
#include <QWidget>

namespace Ui {
class kaizhuo_ui;
}

class kaizhuo_ui : public QWidget
{
    Q_OBJECT

public:
    explicit kaizhuo_ui(QWidget *parent = nullptr);
    ~kaizhuo_ui();
protected slots:
    void show_time();
signals:
    void sneddata();
private slots:
    void on_sureBt_clicked();

private:
    Ui::kaizhuo_ui *ui;
    QTimer mtimer ;//定时器对象
};

#endif // KAIZHUO_UI_H
