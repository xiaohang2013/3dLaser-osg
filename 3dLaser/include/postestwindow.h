#ifndef POSTESTWINDOW_H
#define POSTESTWINDOW_H

#include <QtWidgets/QDialog>

namespace Ui {
class PosTestWindow;
}

class PosTestWindow: public QDialog
{
    Q_OBJECT

public:
    explicit PosTestWindow(QWidget *parent = 0);
    ~PosTestWindow();

private:
    Ui::PosTestWindow *ui;
};

#endif // LASERCALWINDOW_H

