#ifndef PARAWINDOW_H
#define PARAWINDOW_H

#include <QDialog>

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


private slots:
    void slot_btn_motor();
    void slot_btn_scan();
    void slot_btn_sort();
};

#endif // PARAWINDOW_H
