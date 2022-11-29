#ifndef SOFTKEYINPUTWIN_H
#define SOFTKEYINPUTWIN_H

#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QToolButton>
#include <QFile>
#include <QMap>

class SoftKeyInputWin : public QWidget
{
    Q_OBJECT

public:
    SoftKeyInputWin(QWidget *parent = nullptr);
    ~SoftKeyInputWin();

protected slots:
    void backspace();//退位键
    void space();
    void button_click();;
    void selectzh();
private:
    bool isCh = false;  //中英文标志位
    bool is_caps = false;//大小写切换标志位
private:
    QVBoxLayout   *verticalLayout;

//    QHBoxLayout *layout0;
//    QLineEdit *pyEdit;
//    QPushButton *s[4];
//    QPushButton *next;
//    QSpacerItem *horizontalSpacer;

    QHBoxLayout *layout1;
    QToolButton *b1[4];
    QStringList b1s;

    QHBoxLayout *layout2;
    QToolButton *b2[4];
    QStringList b2s;

    QHBoxLayout *layout3;
    QToolButton *b3[4];
    QStringList b3s;

private:
    void layout1Win();
    void layout2Win();
    void layout3Win();



private:

    int num;

};
#endif // SOFTKEYINPUTWIN_H
