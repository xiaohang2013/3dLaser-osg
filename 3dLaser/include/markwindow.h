#ifndef MARKWINDOW_H
#define MARKWINDOW_H

#include <QtWidgets/QDialog>
#if _MSC_VER >= 1600
   #pragma execution_character_set("utf-8")
#endif

namespace Ui {
    class MarkWindow;
}

class MarkCodeWindow : public QDialog
{
    Q_OBJECT
public:
    explicit MarkCodeWindow(QWidget *parent = 0);
    ~MarkCodeWindow();

private:
    Ui::MarkWindow *ui;
};
#endif
