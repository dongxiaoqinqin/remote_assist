#ifndef ASKHELP_H
#define ASKHELP_H

#include <QWidget>
#include <DSuggestButton>
#include <DFrame>
#include <DLabel>
#include <DWidget>
#include <DMainWindow>
#include <QClipboard>


DWIDGET_USE_NAMESPACE

class askHelp : public DMainWindow
{
    Q_OBJECT
public:
    explicit askHelp(QWidget *parent = nullptr);
    void generCode();
    int getVerCode();
    QClipboard *clipBoard;
private:
    DPushButton *ask_help_btn;
    DLabel *titLabel;
    DLabel *please_wait;
    DSuggestButton *cancel_btn;
    QTimer *time;
    QTimer *timer;
    DLabel *Verification_code;
    DLabel *description_ver1;
    DLabel *description_ver2;
    DSuggestButton *copy_btn;
    DWidget *askH;
    DWidget *askHL;
    DWidget *askHlSucces;
    DLabel *code_success;
    DLabel *desc_ver1;
    DLabel *desc_ver2;
    DSuggestButton *copy_bttn;

signals:
    void sendsignal(); //向主界面通知关闭的消息

public slots:
    void on_copy_bttn_clicked();
    void getCode();
    void sucessCopy();
};

#endif // ASKHELP_H
