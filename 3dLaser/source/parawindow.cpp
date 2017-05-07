#include "parawindow.h"
#include "ui_parawindow.h"

ParaWindow::ParaWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParaWindow)
{
    ui->setupUi(this);
}

ParaWindow::~ParaWindow()
{
    delete ui;
}

void ParaWindow::slot_btn_motor()
{
    ui->para_sort->hide();
    ui->para_scan->hide();
    ui->para_motor->show();
}

void ParaWindow::slot_btn_scan()
{
    ui->para_sort->hide();
    ui->para_scan->show();
    ui->para_motor->hide();
}

void ParaWindow::slot_btn_sort()
{
    ui->para_sort->show();
    ui->para_scan->hide();
    ui->para_motor->hide();
}
