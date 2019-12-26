#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DMainWindow>
#include <QWidget>
#include "askhelp.h"
#include "helpother.h"

DWIDGET_USE_NAMESPACE


class MainWindow : public DMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    void InIt();
private:
    QWidget *startMain;
    DLabel *head;
    DLabel *logo;
    DLabel *description_lab1;
    DLabel *description_lab2;
    DLabel *description_lab3;
    DPushButton *ask_help_btn;
    DPushButton *help_btn;
    askHelp *aHelp;
    helpOther *hOther;
    DStackedWidget *stack;
signals:

public slots:
   //  void toAskSlot();
//     void toHelpSlot();
     void on_ask_help_btn_clicked();
     void askHshow();
     void on_help_btn_clicked();
     void hOthershow();

};

#endif // MAINWINDOW_H
