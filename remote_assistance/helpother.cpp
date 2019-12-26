#include "helpother.h"
#include <QVBoxLayout>
#include <DApplication>
#include <DTitlebar>
#include <QDebug>
#include <QDesktopWidget>
#include <QMessageBox>
#include <DWidgetUtil>

#define WIN_SIZE QSize(360, 320)
#define BTN_SIZE QSize(162,37)

helpOther::helpOther(QWidget *parent) : DMainWindow(parent)
{
    DTitlebar *tit = this->titlebar();
    tit->setFixedHeight(40);
    tit->setIcon(QIcon(":/images/heart.png")); //添加图标
    tit->setTitle("帮助别人");
    this->setFixedSize(WIN_SIZE);
    // w.setAttribute(Qt::WA_TranslucentBackground);
    Dtk::Widget::moveToCenter(this);
    inputCode();
}

void helpOther::inputCode()
{
    helpInputCode = new DWidget;
    setCentralWidget(helpInputCode);
    code_edit = new QLineEdit(this);
    code_edit->setAlignment(Qt::AlignCenter);
    QLineEdit{"text-align:center"};
    code_edit->setClearButtonEnabled(false);
    QFont code_edit_font = QFont("思源黑体", 26);
    code_edit_font.setLetterSpacing(QFont::PercentageSpacing, 180);
    code_edit->setFont(code_edit_font);
    code_edit->setFixedSize(331, 72);

    descr1 = new DLabel(this);
    descr1->setText(tr("请在上方输入你想要帮助的人提供给你的验证码，完成后点击连接开始"));
    QFont descr1_font = QFont("思源黑体", 7);
    descr1->setFont(descr1_font);
    descr2 = new DLabel(this);
    descr2->setText(tr("协助对方"));
    QFont descr2_font = QFont("思源黑体", 7);
    descr2->setFont(descr2_font);

    QVBoxLayout *descLayout;
    descLayout = new QVBoxLayout;
    descLayout->addWidget(descr1, 0, Qt::AlignCenter);
    descLayout->addWidget(descr2, 0, Qt::AlignCenter);

    cancle_btn = new DSuggestButton(this);
    cancle_btn->setText("取消");
    cancle_btn->setFixedSize(BTN_SIZE);

    QVBoxLayout *helpLayout;
    helpLayout = new QVBoxLayout;
    helpLayout->addStretch(30);
    helpLayout->setMargin(15);
    helpLayout->setSpacing(10);
    helpLayout->addWidget(code_edit, 0, Qt::AlignCenter);
    helpLayout->addLayout(descLayout);
    helpLayout->addStretch(40);
    helpLayout->addWidget(cancle_btn, 0, Qt::AlignCenter);
    helpLayout->addStretch(40);
    helpInputCode->setLayout(helpLayout);
    connect(cancle_btn, &DSuggestButton::clicked, this, &helpOther::close);
    connect(code_edit, SIGNAL(textChanged(const QString &)), this, SLOT(setCompleter(const QString &)));
}

void helpOther::setUpConn()
{
    startConn = new QWidget();
    setCentralWidget(startConn);
    DPictureSequenceView *generateView = new DPictureSequenceView(this);
    generateView->setPictureSequence(":/images/Spinner/Spinner30.png", QPair<int, int>(1, 10));
    generateView->setFixedSize(50, 50);
    generateView->setSpeed(66);
    please_wait = new DLabel;
    please_wait->setText(tr("正在建立连接，请稍候..."));
    QVBoxLayout *loadLayout;
    loadLayout = new QVBoxLayout;
    loadLayout->setMargin(45);
    loadLayout->setSpacing(15);
    loadLayout->addWidget(generateView, 0, Qt::AlignCenter);
    loadLayout->addWidget(please_wait, 0, Qt::AlignCenter);

    cancel_btn = new DSuggestButton("取消", this);
    cancel_btn->setFixedSize(BTN_SIZE);
    QVBoxLayout *vLayout;
    vLayout = new QVBoxLayout;
    vLayout->setMargin(5);
    vLayout->setSpacing(20);
    vLayout->addLayout(loadLayout);
    vLayout->addWidget(cancel_btn, 0, Qt::AlignCenter);
    vLayout->addStretch(40);
    startConn->setLayout(vLayout);
    connect(cancel_btn, &DSuggestButton::clicked, this, &helpOther::close);

    if (code_edit->text().toInt() == clipBoard->text().toInt()) {
        time = new QTimer(this);
        time->setInterval(5 * 1000);
        time->setSingleShot(false);
        connect(time, &QTimer::timeout, this, &helpOther::remotAssiant);
        time->start();
    }
}

void helpOther::setCompleter(const QString &)
{
//    qDebug() << "aaa" << code_edit->text().toInt() << endl;
//    qDebug() << "bbb" << clipBoard->text().toInt() << endl;
    for (int i = 0; i < code_edit->text().length(); i++) {
        if (code_edit->text()[i] < '0' || code_edit->text()[i] > '9') {
            QMessageBox::information(this, "提示", "请输入数字",
                                    QMessageBox::Yes);
        }
    }
    if (code_edit->text().length() > 6) {
        QMessageBox::information(this, "提示", "验证码不能超过6位",
                                QMessageBox::Cancel);
    }
    disconnect(cancle_btn, &DSuggestButton::clicked, this, &helpOther::close);
    cancle_btn->setText("连接");
    connect(cancle_btn, &DSuggestButton::clicked, this, &helpOther::setUpConn);
    if (code_edit->text().toInt() != clipBoard->text().toInt()) {
        connect(cancle_btn, &DSuggestButton::clicked, this, &helpOther::errorConn);
    }
}

void helpOther::errorConn()
{
    failConn = new QWidget();
    setCentralWidget(failConn);
    fail_conn = new DLabel;
    fail_conn->setText(tr("连接失败"));
    QFont fail_conn_font = QFont("思源黑体", 16);
    fail_conn->setFont(fail_conn_font);
    fail_conn->setStyleSheet("color:#FF5736");

    dec_reson = new DLabel;
    dec_reson->setText(tr("网络连接状态不是很稳定，点击重试按钮再次尝试连接"));
    QFont dec_reson_font = QFont("思源黑体", 7);
    dec_reson->setFont(dec_reson_font);
    QVBoxLayout *loadLayout;
    loadLayout = new QVBoxLayout;
    loadLayout->setMargin(45);
    loadLayout->setSpacing(35);
    loadLayout->addWidget(fail_conn, 0, Qt::AlignCenter);
    loadLayout->addWidget(dec_reson, 0, Qt::AlignCenter);

    agin_btn = new DSuggestButton("重试", this);
    agin_btn->setFixedSize(BTN_SIZE);
    QVBoxLayout *vLayout;
    vLayout = new QVBoxLayout;
    vLayout->setMargin(5);
    vLayout->setSpacing(20);
    vLayout->addLayout(loadLayout);
    vLayout->addWidget(agin_btn, 0, Qt::AlignCenter);
    vLayout->addStretch(40);
    failConn->setLayout(vLayout);
    connect(agin_btn, &DSuggestButton::clicked, this, &helpOther::inputCode);
}

void helpOther::remotAssiant()
{
    remoteAss = new QWidget();
    setCentralWidget(remoteAss);
    remot_now = new DLabel;
    remot_now->setText(tr("您正在进行远程协助"));
    QFont remot_now_font = QFont("思源黑体", 16);
    remot_now->setFont(remot_now_font);

    des_remot = new DLabel;
    des_remot->setText(tr("当前已经有一个连接会话，如果您想建立新的连接，请先断开"));
    QFont des_remot_font = QFont("思源黑体", 7);
    des_remot->setFont(des_remot_font);
    QVBoxLayout *loadLayout;
    loadLayout = new QVBoxLayout;
    loadLayout->setMargin(45);
    loadLayout->setSpacing(35);
    loadLayout->addWidget(remot_now, 0, Qt::AlignCenter);
    loadLayout->addWidget(des_remot, 0, Qt::AlignCenter);

    break_btn = new DSuggestButton("断开", this);
    break_btn->setFixedSize(BTN_SIZE);
    QVBoxLayout *vLayout;
    vLayout = new QVBoxLayout;
    vLayout->setMargin(5);
    vLayout->setSpacing(20);
    vLayout->addLayout(loadLayout);
    vLayout->addWidget(break_btn, 0, Qt::AlignCenter);
    vLayout->addStretch(40);
    remoteAss->setLayout(vLayout);
    connect(break_btn, &DSuggestButton::clicked, this, &helpOther::on_break_btn_clicked);
}

void helpOther::on_break_btn_clicked()
{
    emit sendOsignal();
    this->close();
}




