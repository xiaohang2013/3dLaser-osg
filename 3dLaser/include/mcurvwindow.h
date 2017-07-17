#ifndef MCURVWINDOW_H
#define MCURVWINDOW_H

#include <QDialog>

namespace Ui {
class McurvWindow;
}

class BatchEngravingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BatchEngravingDialog(QWidget *parent = 0);
    ~BatchEngravingDialog();

private:
    Ui::McurvWindow *ui;
};

#endif // MCURVWINDOW_H
