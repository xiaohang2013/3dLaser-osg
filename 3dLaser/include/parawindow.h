#ifndef PARAWINDOW_H
#define PARAWINDOW_H

#include <QDialog>
#include "parameter.h"

namespace Ui {
class ParaWindow;
}

class ParaWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ParaWindow(QWidget *parent = 0);
    ~ParaWindow();

private:
    Ui::ParaWindow *ui;
    Motor *motor;
    Scaner *scaner;
    Crystal *crystal;


private slots:
    void slot_btn_motor();
    void slot_btn_scan();
    void slot_btn_sort();
    void updateMotorPara();
    void updateScanPara();
    void updateSortPara();
};

#endif // PARAWINDOW_H
