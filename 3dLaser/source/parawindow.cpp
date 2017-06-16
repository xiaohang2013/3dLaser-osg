#include "parawindow.h"
#include "ui_parawindow.h"
ParaWindow::ParaWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParaWindow)
{
    ui->setupUi(this);
    crystal = new Crystal;
    scaner = new Scaner;
    laser = new Laser;
    motor = new Motor;
    plat = new Plat;
    initParam();
    updateMotorPara();
    updateSortPara();
    updateScanPara();
}

ParaWindow::~ParaWindow()
{
    delete ui;
}

void ParaWindow::initParam()
{
    //motor
    motor->motorX.ratio = 0;
    motor->motorY.ratio = 0;
    motor->motorZ.ratio = 0;
    motor->motorX.offset = 0;
    motor->motorY.offset = 0;
    motor->motorZ.offset = 0;
    motor->motorX.v0 = 0;
    motor->motorY.v0 = 0;
    motor->motorZ.v0 = 0;
    motor->motorX.v = 0;
    motor->motorY.v = 0;
    motor->motorZ.v = 0;
    motor->motorX.a = 0;
    motor->motorY.a = 0;
    motor->motorZ.a = 0;
    motor->motorX.inchCtrl = 0;
    motor->motorY.inchCtrl = 0;
    motor->motorZ.inchCtrl = 0;
    //laser
    laser->ratio = 10;
    laser->frequency = 1000;
    laser->focalLenth = 100;
    laser->isMicroStep = true;
    laser->isSerialLink = false;
    laser->lightOutDelay = 0;
    laser->preHeatTime = 0;
    scaner->delay = 0;
    scaner->speed = 0;
    scaner->microStepDelay = 0;
    scaner->isXYExchange = false;
    scaner->XScaner.ratio = 0;
    scaner->XScaner.adjust = 0;
    scaner->XScaner.fineTrim = 0;
    scaner->YScaner.ratio = 0;
    scaner->YScaner.adjust = 0;
    scaner->YScaner.fineTrim = 0;
    //sort
    crystal->size.x = 60;
    crystal->size.y = 60;
    crystal->size.z = 60;
    crystal->layMin = 0.02;
    crystal->blockSet.angle = 0.0;
    crystal->blockSet.size.x = 0.0;
    crystal->blockSet.size.y = 0.0;
    crystal->blockSet.size.z = 0.0;
    crystal->blockSet.width = 0.0;
    crystal->blockSet.fuzzyRatio = 0.0;
    crystal->blockSet.stdDev = 0.0;
    crystal->blockSet.blockType = Block_Min;
    crystal->blockSet.borderType = Border_Vertical;
    crystal->scanType = Scan_MIN;
    crystal->mov.x = 0.0;
    crystal->mov.y = 0.0;
    crystal->mov.z = 0.0;
    crystal->pointCloud.correctType = Correct_None;
    crystal->pointCloud.pointMax.x = 0.0;
    crystal->pointCloud.pointMax.y = 0.0;
    crystal->pointCloud.pointMax.z = 0.0;
    crystal->pointCloud.pointMin.x = 0.0;
    crystal->pointCloud.pointMin.y = 0.0;
    crystal->pointCloud.pointMin.z = 0.0;
    crystal->pointCloud.pointNum = 0;
    crystal->curvMode = single_model_one;
    crystal->isAlarm = false;
    //plat
    plat->size.x = 300.0;
    plat->size.y = 300.0;
    plat->size.z = 150.0;
    plat->mechPos.x = 0.0;
    plat->mechPos.y = 0.0;
    plat->mechPos.z = 0.0;
    plat->relPos.x = 0.0;
    plat->relPos.y = 0.0;
    plat->relPos.z = 0.0;
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
    ui->le_mo_ratioX->setText(QString::number(motor->motorX.ratio, 'f', 2));
    ui->le_mo_ratioY->setText(QString::number(motor->motorY.ratio, 'f', 2));
    ui->le_mo_ratioZ->setText(QString::number(motor->motorZ.ratio, 'f', 2));
    ui->le_s0_X->setText(QString::number(motor->motorX.offset, 'f', 2));
    ui->le_s0_Y->setText(QString::number(motor->motorY.offset, 'f', 2));
    ui->le_s0_Z->setText(QString::number(motor->motorZ.offset, 'f', 2));
    ui->le_sp_v0_X->setText(QString::number(motor->motorX.v0, 'f', 2));
    ui->le_sp_v0_Y->setText(QString::number(motor->motorY.v0, 'f', 2));
    ui->le_sp_v0_Z->setText(QString::number(motor->motorZ.v0, 'f', 2));
    ui->le_sp_v_X->setText(QString::number(motor->motorX.v, 'f', 2));
    ui->le_sp_v_Y->setText(QString::number(motor->motorY.v, 'f', 2));
    ui->le_sp_v_Z->setText(QString::number(motor->motorZ.v, 'f', 2));
    ui->le_sp_a_X->setText(QString::number(motor->motorX.a, 'f', 2));
    ui->le_sp_a_Y->setText(QString::number(motor->motorY.a, 'f', 2));
    ui->le_sp_a_Z->setText(QString::number(motor->motorZ.a, 'f', 2));
    ui->le_inch_X->setText(QString::number(motor->motorX.inchCtrl, 10));
    ui->le_inch_Y->setText(QString::number(motor->motorY.inchCtrl, 10));
    ui->le_inch_Z->setText(QString::number(motor->motorZ.inchCtrl, 10));
}

void ParaWindow::updateScanPara()
{
    //scaner
    ui->sl_laser_r->setSliderPosition(laser->ratio);
    ui->sl_laser_f->setSliderPosition(laser->frequency);
    ui->lb_laser_r_v->setText(QString::number(laser->ratio, 10));
    ui->lb_laser_f_v->setText(QString::number(laser->frequency, 10));
    ui->lb_laser_pulse_low->setText(QString::number(laser->frequency * laser->ratio/100)+"us");
    ui->lb_laser_pulse_high->setText(QString::number(laser->frequency * (100-laser->ratio)/100)+"us");
    ui->le_laser_focalLen->setText(QString::number(laser->focalLenth, 'f', 2));
    ui->le_laser_lightOutDelay->setText(QString::number(laser->lightOutDelay, 'f', 2));
    ui->le_laser_preHeatTime->setText(QString::number(laser->preHeatTime));
    ui->le_scan_delay->setText(QString::number(scaner->delay, 'f', 2));
    ui->le_scan_speed->setText(QString::number(scaner->speed, 'f', 2));
    ui->le_scan_microStepDelay->setText(QString::number(scaner->microStepDelay, 'f', 2));
    if (scaner->isXYExchange)
        ui->cb_scan_exchangeXY->setChecked(true);
    else
        ui->cb_scan_exchangeXY->setChecked(false);
    if (scaner->microStepDelay)
        ui->cb_scan_stepOver->setChecked(true);
    else
        ui->cb_scan_stepOver->setChecked(false);
    ui->le_la_r_X->setText(QString::number(scaner->XScaner.ratio, 10));
    ui->le_la_v_X->setText(QString::number(scaner->XScaner.adjust, 10));
    ui->le_la_u_X->setText(QString::number(scaner->XScaner.fineTrim, 10));
    ui->le_la_r_Y->setText(QString::number(scaner->YScaner.ratio, 10));
    ui->le_la_v_Y->setText(QString::number(scaner->YScaner.adjust, 10));
    ui->le_la_u_Y->setText(QString::number(scaner->YScaner.fineTrim, 10));
    if (laser->isSerialLink)
        ui->cb_la_r232->setChecked(true);
    else
        ui->cb_la_r232->setChecked(false);
}

void ParaWindow::updateSortPara()
{
    //sort
    ui->le_cry_width->setText(QString::number(crystal->size.x, 'f', 2));
    ui->le_cry_len->setText(QString::number(crystal->size.y, 'f', 2));
    ui->le_cry_high->setText(QString::number(crystal->size.z, 'f', 2));
    ui->le_min_layer->setText(QString::number(crystal->layMin, 'f', 2));
    ui->le_border_angle->setText(QString::number(crystal->blockSet.angle, 'f', 2));
    ui->le_border_width->setText(QString::number(crystal->blockSet.width, 'f', 2));
    ui->le_split_size_X->setText(QString::number(crystal->blockSet.size.x, 'f', 2));
    ui->le_split_size_Y->setText(QString::number(crystal->blockSet.size.y, 'f', 2));
    ui->le_split_size_Z->setText(QString::number(crystal->blockSet.size.z, 'f', 2));
    ui->le_para_ratio->setText(QString::number(crystal->blockSet.fuzzyRatio, 'f', 2));
    ui->le_para_width->setText(QString::number(crystal->blockSet.width, 'f', 2));

    switch (crystal->scanType)
    {
    case Scan_X2Y:
        ui->rbtn_sort_x2y->setChecked(true);
        ui->rbtn_sort_y2x->setChecked(false);
        ui->rbtn_sort_min->setChecked(false);
        break;
    case Scan_Y2X:
        ui->rbtn_sort_x2y->setChecked(false);
        ui->rbtn_sort_y2x->setChecked(true);
        ui->rbtn_sort_min->setChecked(false);
        break;
    case Scan_MIN:
        ui->rbtn_sort_x2y->setChecked(false);
        ui->rbtn_sort_y2x->setChecked(false);
        ui->rbtn_sort_min->setChecked(true);
        break;
    default:
        ui->rbtn_sort_x2y->setChecked(true);
        ui->rbtn_sort_y2x->setChecked(false);
        ui->rbtn_sort_min->setChecked(false);
        break;
    };
    switch (crystal->blockSet.blockType)
    {
    case Correct_X2Y:
        ui->rbtn_correct_none->setChecked(false);
        ui->rbtn_correct_x2y->setChecked(true);
        ui->rbtn_correct_y2x->setChecked(false);
        break;
    case Correct_Y2X:
        ui->rbtn_correct_none->setChecked(false);
        ui->rbtn_correct_x2y->setChecked(false);
        ui->rbtn_correct_y2x->setChecked(true);
        break;
    case Correct_None:
        ui->rbtn_correct_none->setChecked(false);
        ui->rbtn_correct_x2y->setChecked(true);
        ui->rbtn_correct_y2x->setChecked(false);
        break;
    default:
        ui->rbtn_correct_none->setChecked(false);
        ui->rbtn_correct_x2y->setChecked(true);
        ui->rbtn_correct_y2x->setChecked(false);
        break;
    }
    switch (crystal->blockSet.borderType)
    {
    case Border_Vertical:
        ui->rbtn_split_bevel->setChecked(true);
        ui->rbtn_split_vertical->setChecked(false);
        break;
    case Border_Bevel:
        ui->rbtn_split_bevel->setChecked(false);
        ui->rbtn_split_vertical->setChecked(true);
    default:
        break;
    }
}
Motor *ParaWindow::getMotorRef()
{
    return motor;
}

void ParaWindow::setCrystalRef(Crystal *ref)
{
    if (NULL == ref) return;
    crystal = ref;
}

Crystal *ParaWindow::getCrystalRef()
{
    return crystal;
}

void ParaWindow::setScanerRef(Scaner *ref)
{
    if (NULL == ref) return;
    scaner = ref;
}

Scaner *ParaWindow::getScanerRef()
{
    return scaner;
}

void ParaWindow::setLaserRef(Laser *ref)
{
    if (NULL == ref) return;
    laser = ref;
}

Laser *ParaWindow::getLaserRef()
{
    return laser;
}

void ParaWindow::setPlatRef(Plat *ref)
{
    if (NULL == ref) return;
    plat = ref;
}

Plat *ParaWindow::getPlatRef()
{
    return plat;
}
