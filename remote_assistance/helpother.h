#ifndef HELPOTHER_H
#define HELPOTHER_H

#include <QWidget>
#include <QLineEdit>
#include <DWarningButton>
#include <DLabel>
#include <DWidget>
#include <DSuggestButton>
#include <DMainWindow>
#include <QTimer>
#include <QClipboard>
#include "dpicturesequenceview.h"
#include "askhelp.h"

DWIDGET_USE_NAMESPACE

class helpOther : public DMainWindow
{
    Q_OBJECT
public:
    explicit helpOther(QWidget *parent = nullptr);
    void inputCode();
    void remotAssiant();

private:
    QClipboard *clipBoard;
    QLineEdit *code_edit;
    DWarningButton *errbtn;
    DLabel *descr1;
    DLabel *descr2;
    DSuggestButton *cancle_btn;

    DWidget *helpInputCode;
    DWidget *verCode;
    DWidget *startConn;
    DWidget *failConn;
    DWidget *succesConn;
    DWidget *remoteAss;

    QTimer *timer;
    QTimer *tim;
    QTimer *time;
    DLabel *please_wait;
    DSuggestButton *cancel_btn;

    DLabel *fail_conn;
    DLabel * dec_reson;
    DSuggestButton *agin_btn;

    DLabel *remot_now;
    DLabel *des_remot;
    DSuggestButton *break_btn;

signals:
    void sendOsignal(); //向主界面通知关闭的消息

public slots:
    void on_break_btn_clicked();
    void setUpConn();
    void setCompleter(const QString &);
    void errorConn();
};

#endif // HELPOTHER_H
