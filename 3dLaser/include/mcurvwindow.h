#ifndef MCURVWINDOW_H
#define MCURVWINDOW_H

#include <QDialog>

namespace Ui {
class McurvWindow;
}

class McurvWindow : public QDialog
{
    Q_OBJECT

public:
    explicit McurvWindow(QWidget *parent = 0);
    ~McurvWindow();

private:
    Ui::McurvWindow *ui;
};

#endif // MCURVWINDOW_H
