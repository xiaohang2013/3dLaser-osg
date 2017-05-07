#ifndef MARKWINDOW_H
#define MARKWINDOW_H

#include <QtWidgets/QDialog>
#pragma execution_character_set("utf-8")

namespace Ui {
    class MarkWindow;
}

class MarkWindow : public QDialog
{
    Q_OBJECT
public:
    explicit MarkWindow(QWidget *parent = 0);
    ~MarkWindow();
    
    private slots:
private:
    Ui::MarkWindow *ui;
};
#endif