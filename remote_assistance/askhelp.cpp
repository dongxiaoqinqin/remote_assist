#include "askhelp.h"
#include <DSpinner>
#include "dpicturesequenceview.h"
#include <QVBoxLayout>
#include <QDesktopWidget>
#include <DApplication>
#include <QWaitCondition>
#include <QTimer>
#include <QDebug>
#include <DTitlebar>
#include <DSpinner>
#include <QTime>
#include <DWidgetUtil>

#define WIN_SIZE QSize(360, 320)
#define BTN_SIZE QSize(162,37)

askHelp::askHelp(QWidget *parent) : DMainWindow(parent)
{
    DTitlebar *tit = this->titlebar();
    tit->setFixedHeight(40);
   // setAttribute(Qt::WA_TranslucentBackground);
    tit->setIcon(QIcon(":/images/hand.png")); //添加图标
    tit->setTitle("我要求助");
    this->setFixedSize(WIN_SIZE);
    Dtk::Widget::moveToCenter(this);
    generCode();
    connect(cancel_btn,&DSuggestButton::clicked,this,&askHelp::close);
    time = new QTimer(this);
    time->setInterval(2*1000);
    time->setSingleShot(false);
    connect(time,&QTimer::timeout,this,&askHelp::getCode);
    time->start();
}

void askHelp::generCode()
{
    askH = new QWidget();
    setCentralWidget(askH);
    DPictureSequenceView *generateView = new DPictureSequenceView(this);
    generateView->setPictureSequence(":/images/Spinner/Spinner30.png", QPair<int, int>(1, 10));
    generateView->setFixedSize(50, 50);
    generateView->setSpeed(33);
//    auto spinner = new DSpinner;
//    spinner->setFixedSize(50, 50);
//    spinner->start();
    please_wait = new DLabel;
    please_wait->setText(tr("正在生成请求验证码，请稍候..."));
    QVBoxLayout *loadLayout;
    loadLayout = new QVBoxLayout;
    loadLayout->setMargin(45);
    loadLayout->setSpacing(15);
    loadLayout->addWidget(generateView,0,Qt::AlignCenter);
//    loadLayout->addWidget(spinner,0,Qt::AlignCenter);
    loadLayout->addWidget(please_wait,0,Qt::AlignCenter);

    cancel_btn = new DSuggestButton("取消",this);
    cancel_btn->setFixedSize(BTN_SIZE);
    QVBoxLayout *vLayout;
    vLayout = new QVBoxLayout;
    vLayout->setMargin(5);
    vLayout->setSpacing(20);
    vLayout->addLayout(loadLayout);
    vLayout->addWidget(cancel_btn,0,Qt::AlignCenter);
    vLayout->addStretch(40);
    askH->setLayout(vLayout);
    connect(cancel_btn,&DSuggestButton::clicked,this,&askHelp::close);
}

void askHelp::getCode()
{
    time->stop();
    askHL = new QWidget();
    setCentralWidget(askHL);
    Verification_code = new DLabel(this);
    Verification_code->setFixedWidth(200);

    Verification_code->setText(QString("%1").arg(askHelp::getVerCode()));
    QFont Verification_code_font =QFont("思源黑体",26);
    Verification_code_font.setLetterSpacing(QFont::PercentageSpacing, 180);
    Verification_code->setFont(Verification_code_font);
    Verification_code->setWordWrap(true);
   // Verification_code->setStyleSheet("background-color:red");

    description_ver1 = new DLabel(this);
    description_ver1->setText(tr("要开始共享您的页面，请将上面的验证码提供给协助您的人员，他们输"));
    QFont description_ver1_font = QFont("思源黑体",8);
    description_ver1->setFont(description_ver1_font);
    description_ver2 = new DLabel(this);
    description_ver2->setText(tr("入验证码后，您的共享会话会立即开始"));
    QFont description_ver2_font = QFont("思源黑体",8);
    description_ver2->setFont(description_ver2_font);

    QVBoxLayout *descLayout;
    descLayout = new QVBoxLayout;
    descLayout->setMargin(20);
    descLayout->setSpacing(0);
    descLayout->addWidget(description_ver1,0,Qt::AlignCenter);
    descLayout->addWidget(description_ver2,0,Qt::AlignCenter);
    copy_btn = new DSuggestButton("复制",this);
    copy_btn->setFixedSize(BTN_SIZE);

    QVBoxLayout *verCodeLayout;
    verCodeLayout = new QVBoxLayout;
    verCodeLayout->setMargin(35);
    verCodeLayout->setSpacing(20);
    verCodeLayout->addWidget(Verification_code,0,Qt::AlignCenter);
    verCodeLayout->addLayout(descLayout);
    verCodeLayout->addWidget(copy_btn,0,Qt::AlignCenter);
    verCodeLayout->addStretch(5);
    askHL->setLayout(verCodeLayout);

    connect(copy_btn,&DSuggestButton::clicked,this,[=](){
        clipBoard = QApplication::clipboard();
        clipBoard->clear();
        clipBoard->setText(Verification_code->text());
        qDebug()<<clipBoard->text()<<endl;
    });
    connect(copy_btn,&DSuggestButton::clicked,this,&askHelp::sucessCopy);
}

void askHelp::sucessCopy()
{
    askHlSucces = new QWidget();
    setCentralWidget(askHlSucces);
    code_success = new DLabel(this);
    code_success->setText("成功复制到粘贴版");
    code_success->setFixedWidth(200);
    QFont Verification_code_font = QFont("思源黑体",16);
    Verification_code_font.setLetterSpacing(QFont::PercentageSpacing, 118);
    code_success->setFont(Verification_code_font);
    code_success->setWordWrap(true);
    //code_success->setStyleSheet("background-color:red");

    desc_ver1 = new DLabel(this);
    desc_ver1->setText(tr("正在等待连接，请稍候..."));
    QFont description_ver1_font = QFont("思源黑体",8);
    desc_ver1->setFont(description_ver1_font);
    desc_ver2 = new DLabel(this);
    desc_ver2->setText(tr("连接成功后，此界面会自动隐藏到任务栏"));
    QFont description_ver2_font = QFont("思源黑体",8);
    desc_ver2->setFont(description_ver2_font);

    QVBoxLayout  *descLayout;
    descLayout = new QVBoxLayout;
    descLayout->setMargin(25);
    descLayout->setSpacing(0);
    descLayout->addWidget(desc_ver1,0,Qt::AlignCenter);
    descLayout->addWidget(desc_ver2,0,Qt::AlignCenter);
    copy_bttn = new DSuggestButton("复制",this);
    copy_bttn->setFixedSize(BTN_SIZE);

    QVBoxLayout *verCodeLayout;
    verCodeLayout = new QVBoxLayout;
    verCodeLayout->addStretch(10);
    verCodeLayout->setMargin(40);
    verCodeLayout->setSpacing(20);
    verCodeLayout->addWidget(code_success,0,Qt::AlignCenter);
    verCodeLayout->addLayout(descLayout);
    verCodeLayout->addWidget(copy_bttn,0,Qt::AlignCenter);
    askHlSucces->setLayout(verCodeLayout);

    connect(copy_bttn,&DSuggestButton::clicked,this,&askHelp::on_copy_bttn_clicked);
    time = new QTimer(this);
    time->setInterval(5*1000);
    time->setSingleShot(false);
    connect(time,&QTimer::timeout,this,&askHelp::hide);
    time->start();

}

void askHelp::on_copy_bttn_clicked()
{
    emit sendsignal();
    this->close();
}
int askHelp::getVerCode()
{
   // qsrand((unsigned int)QTime::currentTime().msecsSinceStartOfDay());
    int rand_code = qrand() % (999999 - 100000) +100000;
    return rand_code;
}






