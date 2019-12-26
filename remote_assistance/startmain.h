#ifndef START_H
#define START_H

#include <QWidget>
#include <DPushButton>
#include <DToolButton>
#include <DLabel>
#include "askhelp.h"
#include "helpother.h"

DWIDGET_USE_NAMESPACE

class startMain : public QWidget
{
    Q_OBJECT
public:
    explicit startMain(QWidget *parent = nullptr);
    askHelp *aHelp;
    helpOther *hOther;

private:
    DLabel *head;
    DLabel *logo;
    DLabel *description_lab1;
    DLabel *description_lab2;
    DLabel *description_lab3;
    DPushButton *ask_help_btn;
    DPushButton *help_btn;
signals:

public slots:
//     void toAskSlot();
//     void toHelpSlot();
};

#endif // START_H
