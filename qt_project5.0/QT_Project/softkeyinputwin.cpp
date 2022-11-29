#include "softkeyinputwin.h"

#include <QKeyEvent>
#include <QDebug>
#include <QApplication>

SoftKeyInputWin::SoftKeyInputWin(QWidget *parent)
    : QWidget(parent)
{
    num = 0;

    b1s<<"1"<<"2"<<"3"<<"退格";
    b2s<<"4"<<"5"<<"6"<<"清除";
    b3s<<"7"<<"8"<<"9"<<"0";

    this->setStyleSheet(QString::fromUtf8("\n"
                                        "QToolButton\n"
                                        "{\n"
                                        "	border-radius:10px;\n"
                                        "	background-color: rgba(0, 255, 255, 0.6);\n"
                                        "   color: rgb(0,0,0);\n"
                                        "   font: 28px '微软雅黑';\n "
                                        "	\n"
                                        "}\n"
                                        ""));
    verticalLayout = new QVBoxLayout(this);
    //ui->setupUi(this);
    layout1Win();
    layout2Win();
    layout3Win();
}

void SoftKeyInputWin::layout1Win()
{
    layout1 = new QHBoxLayout();
    layout1->setSpacing(1);
    layout1->setObjectName(QString::fromUtf8("layout1"));
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    for(int i=0; i<4; i++)
    {
        b1[i] = new QToolButton(this);
        b1[i]->setObjectName(QString::fromUtf8("toolButton"));
        sizePolicy.setHeightForWidth(b1[i]->sizePolicy().hasHeightForWidth());
        b1[i]->setSizePolicy(sizePolicy);
        b1[i]->setMinimumSize(QSize(50, 20));
        b1[i]->setMaximumSize(QSize(16777215, 16777215));
        layout1->addWidget(b1[i]);
        b1[i]->setText(b1s.at(i));
        if(i<3) //最后一个关联其槽函数
            connect(b1[i],&QToolButton::clicked,this, &SoftKeyInputWin::button_click);
    }
    verticalLayout->addLayout(layout1);
    connect(b1[3],&QToolButton::clicked,this, &SoftKeyInputWin::backspace);//单独写backspace 的功能
}

void SoftKeyInputWin::backspace() //退位他功能
{
   //定义一个事件，Key_Backspace撤消按钮
   QKeyEvent* key = new QKeyEvent(QEvent::KeyPress,Qt::Key_Backspace,Qt::NoModifier, " ");
   //通过postEvent将事件key发送出去给QApplication::focusWidget()，
   //在当前窗口界面中有焦点的控件
   QApplication::postEvent(QApplication::focusWidget(),key);
}

void SoftKeyInputWin::layout2Win()
{
    layout2 = new QHBoxLayout();
    layout2->setSpacing(1);
    layout2->setObjectName(QString::fromUtf8("layout2"));
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    for(int i=0; i<4; i++)
    {
        b2[i] = new QToolButton(this);
        b2[i]->setObjectName(QString::fromUtf8("toolButton"));
        sizePolicy.setHeightForWidth(b2[i]->sizePolicy().hasHeightForWidth());
        b2[i]->setSizePolicy(sizePolicy);
        b2[i]->setMinimumSize(QSize(50, 20));
        b2[i]->setMaximumSize(QSize(16777215, 16777215));
        layout2->addWidget(b2[i]);
        b2[i]->setText(b2s.at(i));
        if(i<3)
            connect(b2[i],&QToolButton::clicked,this, &SoftKeyInputWin::button_click);
    }
    verticalLayout->addLayout(layout2);
    connect(b2[3],&QToolButton::clicked,this, &SoftKeyInputWin::space);
}

void SoftKeyInputWin::space()
{
//    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Space, Qt::NoModifier, " ");
//    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Space, Qt::NoModifier, " ");
//    QApplication::sendEvent(QApplication::focusWidget(), &keyPress);
//    QApplication::sendEvent(QApplication::focusWidget(), &keyRelease);
     for(int i = 0;i<16 ;i++)   //调用16次退位键
     {
         backspace();
     }

}

void SoftKeyInputWin::layout3Win()
{
    layout3 = new QHBoxLayout();
    layout3->setSpacing(1);
    layout3->setObjectName(QString::fromUtf8("layout3"));
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    for(int i=0; i<4; i++)
    {
        b3[i] = new QToolButton(this);
        b3[i]->setObjectName(QString::fromUtf8("toolButton"));
        sizePolicy.setHeightForWidth(b3[i]->sizePolicy().hasHeightForWidth());
        b3[i]->setSizePolicy(sizePolicy);
        b3[i]->setMinimumSize(QSize(50, 30));
        b3[i]->setMaximumSize(QSize(16777215, 16777215));
        layout3->addWidget(b3[i]);
        b3[i]->setText(b3s.at(i));
        connect(b3[i],&QToolButton::clicked,this, &SoftKeyInputWin::button_click);
    }
    verticalLayout->addLayout(layout3);
}

void SoftKeyInputWin::button_click()
{
    QToolButton *button = (QToolButton* )sender();
    //模拟物理键盘按下动作
    QString str = button->text();

    QChar ch = str.at(0);
    //创建一个按键事件                        //事件类型按下或释放，键值，组合键，按键输入的内容
    QKeyEvent *key = new QKeyEvent(QKeyEvent::KeyPress,ch.toLatin1(),Qt::NoModifier,str);
    //派发                   //获取焦点的窗口
    QApplication::postEvent(QApplication::focusWidget(),key);

}

void SoftKeyInputWin::selectzh()
{
//    pyEdit->clear();
    QPushButton *button = (QPushButton*)sender();
    QString str = button->text();
    str.remove(0,2);
    //创建一个按键事件                        //事件类型按下或释放，键值，组合键，按键输入的内容
    QKeyEvent *key = new QKeyEvent(QKeyEvent::KeyPress,Qt::Key_A,Qt::NoModifier,str);
    //派发                   //获取焦点的窗口
    QApplication::postEvent(QApplication::focusWidget(),key);
}

SoftKeyInputWin::~SoftKeyInputWin()
{
}

