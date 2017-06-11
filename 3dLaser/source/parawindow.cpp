#include "parawindow.h"
#include "ui_parawindow.h"
ParaWindow::ParaWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParaWindow)
{
    ui->setupUi(this);
    updateMotorPara();
    updateSortPara();
    updateScanPara();
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


void ParaWindow::updateMotorPara()
{
    //motor
    ui->le_mo_ratioX->setText(QString::number(motor->motorX.ratio), 'f', 2);
    ui->le_mo_ratioY->setText(QString::number(motor->motorY.ratio), 'f', 2);
    ui->le_mo_ratioZ->setText(QString::number(motor->motorZ.ratio), 'f', 2);
    ui->le_s0_X->setText(QString::number(motor->motorX.offset), 'f', 2);
    ui->le_s0_Y->setText(QString::number(motor->motorY.offset), 'f', 2);
    ui->le_s0_Z->setText(QString::number(motor->motorZ.offset), 'f', 2);
    ui->le_sp_v0_X->setText(QString::number(motor->motorX.v0), 'f', 2);
    ui->le_sp_v0_Y->setText(QString::number(motor->motorY.v0), 'f', 2);
    ui->le_sp_v0_Z->setText(QString::number(motor->motorZ.v0), 'f', 2);
    ui->le_sp_v_X->setText(QString::number(motor->motorX.v), 'f', 2);
    ui->le_sp_v_Y->setText(QString::number(motor->motorY.v), 'f', 2);
    ui->le_sp_v_Z->setText(QString::number(motor->motorZ.v), 'f', 2);
    ui->le_sp_a_X->setText(QString::number(motor->motorX.a), 'f', 2);
    ui->le_sp_a_Y->setText(QString::number(motor->motorY.a), 'f', 2);
    ui->le_sp_a_Z->setText(QString::number(motor->motorZ.a), 'f', 2);
}

void ParaWindow::updateScanPara()
{

}

void ParaWindow::updateSortPara()
{
    //sort
    ui->le_cry_width->setText(QString::number(crystal->size.x), 'f', 2);
    ui->le_cry_len->setText(QString::number(crystal->size.y), 'f', 2);
    ui->le_cry_high->setText(QString::number(crystal->size.z), 'f', 2);
    ui->le_min_layer->setText(QString::number(crystal->layMin), 'f', 2);
    ui->le_border_angle->setText(QString::number(crystal->blockSet.angle), 'f', 2);
    ui->le_border_width->setText(QString::number(crystal->blockSet.width), 'f', 2);
    ui->le_split_size_X->setText(QString::number(crystal->blockSet.size.x), 'f', 2);
    ui->le_split_size_Y->setText(QString::number(crystal->blockSet.size.y), 'f', 2);
    ui->le_split_size_Z->setText(QString::number(crystal->blockSet.size.z), 'f', 2);
    ui->le_para_ratio->setText(QString::number(crystal->blockSet.fuzzyRatio), 'f', 2);
}
