#include "startmain.h"
//#include "askhelp.h"
#include <DPushButton>
#include <QVBoxLayout>
#include <DFrame>

#define BTN_SIZE QSize(164,40)

startMain::startMain(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("远程协助");
    logo =new DLabel;
    logo->setFixedSize(57,64);
    QPixmap pixmap(":/images/mainlogo.png");
    pixmap.scaled(logo->size(),Qt::KeepAspectRatio);
    logo->setScaledContents(true);
    logo->setPixmap(pixmap);
    logo->setStyleSheet("background-color:blue");

    description_lab1 = new DLabel;
    description_lab1->setText("这是由deepin团队开发的远程协助应用，如果您在使");
    QFont description_lab1_font = QFont("思源黑体",8);
    description_lab1->setFont(description_lab1_font);
    description_lab2 = new DLabel;
    description_lab2->setText("用的过程中遇到了困难，或者有人求助于你，请点击");
    QFont description_lab2_font = QFont("思源黑体",8);
    description_lab2->setFont(description_lab2_font);
    description_lab3 = new DLabel;
    description_lab3->setText("下方的我要求助或帮助别人。");
    QFont description_lab3_font = QFont("思源黑体",8);
    description_lab3->setFont(description_lab3_font);
    QVBoxLayout *descLayout;
    descLayout = new QVBoxLayout;
    descLayout->setMargin(10);
    descLayout->setSpacing(0);
    descLayout->addWidget(description_lab1,0,Qt::AlignCenter);
    descLayout->addWidget(description_lab2,0,Qt::AlignCenter);
    descLayout->addWidget(description_lab3,0,Qt::AlignCenter);

    ask_help_btn = new DPushButton;
    ask_help_btn->setFixedSize(BTN_SIZE);
    ask_help_btn->setText("我要求助");
    ask_help_btn->setIcon(QIcon(":/images/hand.png"));

    help_btn = new DPushButton;
    help_btn->setFixedSize(BTN_SIZE);
    help_btn->setText("帮助别人");
    help_btn->setIcon(QIcon(":/images/heart.png"));

    QVBoxLayout *btnLayout;
    btnLayout = new QVBoxLayout;
//    btnLayout->setMargin(10);
//    btnLayout->setSpacing(10);
    btnLayout->addWidget(ask_help_btn,0,Qt::AlignCenter);
    btnLayout->addWidget(help_btn,0,Qt::AlignCenter);

    QVBoxLayout *vLayout;
    vLayout = new QVBoxLayout;
    vLayout->setMargin(10);
   // vLayout->setSpacing(10);
    vLayout->addWidget(logo,0,Qt::AlignCenter);
    vLayout->addLayout(descLayout);
    vLayout->addLayout(btnLayout);
    vLayout->addStretch(40);
    setLayout(vLayout);

   // connect(ask_help_btn,SIGNAL(clicked()),this,SLOT(toAskSlot()));
   // connect(help_btn,SIGNAL(clicked()),this,SLOT(toHelpSlot()));

}

//void startMain::toAskSlot()
//{
//    //this->hide();
//    aHelp = new askHelp;
//    aHelp->show();
//}

//void startMain::toHelpSlot()
//{
//    hOther = new helpOther;
//    hOther->show();
//}
