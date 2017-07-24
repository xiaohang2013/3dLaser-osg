#ifndef LASERCALWINDOW_H
#define LASERCALWINDOW_H

#include <QtWidgets/QDialog>

namespace Ui {
class LaserCalWindow;
}

class LaserCalWindow: public QDialog
{
    Q_OBJECT

public:
    explicit LaserCalWindow(QWidget *parent = 0);
    ~LaserCalWindow();

private:
    Ui::LaserCalWindow *ui;
};

#endif // LASERCALWINDOW_H

