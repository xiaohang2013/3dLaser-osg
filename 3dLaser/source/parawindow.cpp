#include "parawindow.h"
#include "ui_parawindow.h"
#include "macro.h"
#include <QSettings>
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
    //initParam();
    isUpdate = false;
    //readIniFile();
    //updatePara();
}

ParaWindow::~ParaWindow()
{
    delete ui;
}

void ParaWindow::initParam()
{
    //motor
    motor->motorX.ratio = 640;
    motor->motorY.ratio = 640;
    motor->motorZ.ratio = 427;
    motor->motorX.offset = 0;
    motor->motorY.offset = 0;
    motor->motorZ.offset = 0;
    motor->motorX.v0 = 6000;
    motor->motorY.v0 = 6000;
    motor->motorZ.v0 = 6000;
    motor->motorX.v = 16000;
    motor->motorY.v = 19200;
    motor->motorZ.v = 15000;
    motor->motorX.a = 50000;
    motor->motorY.a = 50000;
    motor->motorZ.a = 50000;
    motor->motorX.inchCtrl = 0;
    motor->motorY.inchCtrl = 0;
    motor->motorZ.inchCtrl = 0;
    motor->motorX.num = 3;
    motor->motorY.num = 2;
    motor->motorZ.num = 1;
    motor->motorX.limitP = ACTIVE; //IN10
    motor->motorX.limitN = ACTIVE; //IN9
    motor->motorY.limitP = ACTIVE; //IN8
    motor->motorY.limitN = ACTIVE; //IN7
    motor->motorZ.limitP = ACTIVE; //IN5
    motor->motorZ.limitN = ACTIVE; //IN6


    //laser
    laser->ratio = 30;
    laser->frequency = 3000;
    laser->focalLenth = 120;
    laser->isMicroStep = true;
    laser->isSerialLink = false;
    laser->lightOutDelay = 5;
    laser->preHeatTime = 0;
    scaner->delay = 250;
    scaner->speed = 4000;
    scaner->microStepDelay = 0;
    scaner->isXYExchange = true;
    scaner->XScaner.ratio = -172.34;
    scaner->XScaner.adjust = 0;
    scaner->XScaner.fineTrim = 0;
    scaner->YScaner.ratio = 171.66;
    scaner->YScaner.adjust = 0;
    scaner->YScaner.fineTrim = 0;
    //sort
    crystal->size.x = 60.0;
    crystal->size.y = 60.0;
    crystal->size.z = 60.0;
    crystal->layMin = 0.08;
    crystal->blockSet.angle = 0.0;
    crystal->blockSet.size.x = 30.0;
    crystal->blockSet.size.y = 30.0;
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
    plat->size.z = 200.0;
    plat->mechPos.x = 0.0;
    plat->mechPos.y = 0.0;
    plat->mechPos.z = 0.0;
    plat->relPos.x = 0.0;
    plat->relPos.y = 0.0;
    plat->relPos.z = 0.0;
    plat->HomPos.x = 0.0;
    plat->HomPos.y = 0.0;
    plat->HomPos.z = 0.0;
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


void ParaWindow::slot_btn_enter()
{
    //motor
    motor->motorX.ratio = ui->le_mo_ratioX->text().toFloat();
    motor->motorY.ratio = ui->le_mo_ratioY->text().toFloat();
    motor->motorZ.ratio = ui->le_mo_ratioZ->text().toFloat();
    motor->motorX.offset = ui->le_s0_X->text().toInt();
    motor->motorY.offset = ui->le_s0_Y->text().toInt();
    motor->motorZ.offset = ui->le_s0_Z->text().toInt();
    motor->motorX.v0 = ui->le_sp_v0_X->text().toInt();
    motor->motorY.v0 = ui->le_sp_v0_Y->text().toInt();
    motor->motorZ.v0 = ui->le_sp_v0_Z->text().toInt();
    motor->motorX.v = ui->le_sp_v_X->text().toInt();
    motor->motorY.v = ui->le_sp_v_Y->text().toInt();
    motor->motorZ.v = ui->le_sp_v_Z->text().toInt();
    motor->motorX.a = ui->le_sp_a_X->text().toInt();
    motor->motorY.a = ui->le_sp_a_Y->text().toInt();
    motor->motorZ.a = ui->le_sp_a_Z->text().toInt();
    motor->motorX.inchCtrl = ui->le_inch_X->text().toInt();
    motor->motorY.inchCtrl = ui->le_inch_Y->text().toInt();
    motor->motorZ.inchCtrl = ui->le_inch_Z->text().toInt();
    //laser
    laser->ratio = ui->sl_laser_r->value();
    laser->frequency = ui->sl_laser_f->value();
    laser->focalLenth = ui->le_laser_focalLen->text().toInt();
    laser->lightOutDelay = ui->le_laser_lightOutDelay->text().toInt();
    laser->preHeatTime = ui->le_laser_preHeatTime->text().toInt();
    scaner->delay = ui->le_scan_delay->text().toInt();
    scaner->speed = ui->le_scan_speed->text().toInt();
    scaner->microStepDelay = ui->le_scan_microStepDelay->text().toInt();
    scaner->XScaner.ratio = ui->le_la_r_X->text().toInt();
    scaner->XScaner.adjust = ui->le_la_v_X->text().toInt();
    scaner->XScaner.fineTrim = ui->le_la_u_X->text().toInt();
    scaner->YScaner.ratio = ui->le_la_r_Y->text().toInt();
    scaner->YScaner.adjust = ui->le_la_v_Y->text().toInt();
    scaner->YScaner.fineTrim = ui->le_la_u_Y->text().toInt();
    if (ui->cb_scan_exchangeXY->isChecked())
        scaner->isXYExchange = true;
    else
        scaner->isXYExchange = false;

    if (ui->cb_scan_stepOver->isChecked())
        laser->isMicroStep = true;
    else
        laser->isMicroStep = true;

    if (ui->cb_la_r232->isChecked())
        laser->isSerialLink = true;
    else
        laser->isSerialLink = false;
    //crystal
    crystal->size.x = ui->le_cry_width->text().toFloat();
    crystal->size.y = ui->le_cry_len->text().toFloat();
    crystal->size.z = ui->le_cry_high->text().toFloat();
    crystal->layMin = ui->le_min_layer->text().toInt();
    crystal->blockSet.size.x = ui->le_split_size_X->text().toFloat();
    crystal->blockSet.size.y = ui->le_split_size_Y->text().toFloat();
    crystal->blockSet.size.z = ui->le_split_size_Z->text().toFloat();
    crystal->blockSet.angle = ui->le_border_angle->text().toFloat();
    crystal->blockSet.width = ui->le_border_width->text().toFloat();
    crystal->blockSet.fuzzyRatio = ui->le_para_ratio->text().toFloat();
    if (ui->rbtn_split_vertical->isChecked())
        crystal->blockSet.borderType = Border_Vertical;
    else if (ui->rbtn_split_bevel)
        crystal->blockSet.borderType = Border_Bevel;
    crystal->blockSet.blockType = Block_Min;
    if (ui->rbtn_sort_y2x->isChecked())
        crystal->scanType = Scan_Y2X;
    else if (ui->rbtn_sort_min->isChecked())
        crystal->scanType = Scan_MIN;
    else if (ui->rbtn_sort_x2y->isChecked())
        crystal->scanType = Scan_X2Y;

    if (ui->rbtn_correct_none->isChecked())
        crystal->pointCloud.correctType = Correct_None;
    else if (ui->rbtn_correct_x2y->isChecked())
        crystal->pointCloud.correctType = Correct_X2Y;
    else if (ui->rbtn_correct_y2x->isChecked())
        crystal->pointCloud.correctType = Correct_Y2X;

    setIsUpdate(true);
}

void ParaWindow::slot_btn_cancel()
{
    if (ui->para_motor->isVisible())
        updateMotorPara();
    else if (ui->para_scan->isVisible())
        updateScanPara();
    else if (ui->para_sort->isVisible())
        updateSortPara();
    else
        updatePara();
    setIsUpdate(false);
}


void ParaWindow::slot_change_f()
{
    ui->lb_laser_f_v->setText(QString::number(ui->sl_laser_f->value(), 10));
    ui->lb_laser_pulse_low->setText(QString::number(ui->sl_laser_f->value() * ui->sl_laser_r->value()/100)+"us");
    ui->lb_laser_pulse_high->setText(QString::number(ui->sl_laser_f->value() * (100-ui->sl_laser_r->value())/100)+"us");
}

void ParaWindow::slot_change_r()
{
    ui->lb_laser_r_v->setText(QString::number(ui->sl_laser_r->value(), 10));
    ui->lb_laser_pulse_low->setText(QString::number(ui->sl_laser_f->value() * ui->sl_laser_r->value()/100)+"us");
    ui->lb_laser_pulse_high->setText(QString::number(ui->sl_laser_f->value() * (100-ui->sl_laser_r->value())/100)+"us");
}

void ParaWindow::setIsUpdate(bool b)
{
    isUpdate = b;
}

bool ParaWindow::getIsUpdate()
{
    return isUpdate;
}

void ParaWindow::updatePara()
{
    updateSortPara();
    updateMotorPara();
    updateScanPara();
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
    ui->le_la_r_X->setText(QString::number(scaner->XScaner.ratio, 'f', 2));
    ui->le_la_v_X->setText(QString::number(scaner->XScaner.adjust, 10));
    ui->le_la_u_X->setText(QString::number(scaner->XScaner.fineTrim, 10));
    ui->le_la_r_Y->setText(QString::number(scaner->YScaner.ratio, 'f', 2));
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


void ParaWindow::slot_btn_read()
{
    readIniFile();
}

void ParaWindow::slot_btn_write()
{
    writeIniFile();
}

int ParaWindow::readIniFile()
{
    QSettings iniFile(INI_PATH, QSettings::IniFormat);
    iniFile.beginGroup("Motor");
    motor->motorX.ratio = iniFile.value("motorX.ratio").toInt();
    motor->motorX.offset = iniFile.value("motorX.offset").toInt();
    motor->motorX.stepAngle = iniFile.value("motorX.stepAngle").toFloat();
    motor->motorX.subdivision = iniFile.value("motorX.subdivision").toInt();
    motor->motorX.v0 = iniFile.value("motorX.v0").toInt();
    motor->motorX.v = iniFile.value("motorX.v").toInt();
    motor->motorX.a = iniFile.value("motorX.a").toInt();
    motor->motorX.inchCtrl = iniFile.value("motorX.inchCtrl").toInt();
    motor->motorX.mod = (MovMode)iniFile.value("motorX.mod").toInt();
    motor->motorX.num = iniFile.value("motorX.num").toInt();
    motor->motorX.limitP = (LimitType)iniFile.value("motorX.limitP").toInt();
    motor->motorX.limitN = (LimitType)iniFile.value("motorX.limitN").toInt();
    motor->motorX.limitL = (LimitType)iniFile.value("motorX.limitL").toInt();
    motor->motorY.ratio = iniFile.value("motorY.ratio").toInt();
    motor->motorY.offset = iniFile.value("motorY.offset").toInt();
    motor->motorY.stepAngle = iniFile.value("motorY.stepAngle").toFloat();
    motor->motorY.subdivision = iniFile.value("motorY.subdivision").toInt();
    motor->motorY.v0 = iniFile.value("motorY.v0").toInt();
    motor->motorY.v = iniFile.value("motorY.v").toInt();
    motor->motorY.a = iniFile.value("motorY.a").toInt();
    motor->motorY.inchCtrl = iniFile.value("motorY.inchCtrl").toInt();
    motor->motorY.mod = (MovMode)iniFile.value("motorY.mod").toInt();
    motor->motorY.num = iniFile.value("motorY.num").toInt();
    motor->motorY.limitP = (LimitType)iniFile.value("motorY.limitP").toInt();
    motor->motorY.limitN = (LimitType)iniFile.value("motorY.limitN").toInt();
    motor->motorY.limitL = (LimitType)iniFile.value("motorY.limitL").toInt();
    motor->motorZ.ratio = iniFile.value("motorZ.ratio").toInt();
    motor->motorZ.offset = iniFile.value("motorZ.offset").toInt();
    motor->motorZ.stepAngle = iniFile.value("motorZ.stepAngle").toFloat();
    motor->motorZ.subdivision = iniFile.value("motorZ.subdivision").toInt();
    motor->motorZ.v0 = iniFile.value("motorZ.v0").toInt();
    motor->motorZ.v = iniFile.value("motorZ.v").toInt();
    motor->motorZ.a = iniFile.value("motorZ.a").toInt();
    motor->motorZ.inchCtrl = iniFile.value("motorZ.inchCtrl").toInt();
    motor->motorZ.mod = (MovMode)iniFile.value("motorZ.mod").toInt();
    motor->motorZ.num = iniFile.value("motorZ.num").toInt();
    motor->motorZ.limitP = (LimitType)iniFile.value("motorZ.limitP").toInt();
    motor->motorZ.limitN = (LimitType)iniFile.value("motorZ.limitN").toInt();
    motor->motorZ.limitL = (LimitType)iniFile.value("motorZ.limitL").toInt();
    iniFile.endGroup();
    iniFile.beginGroup("Laser");
    laser->ratio = iniFile.value("ratio").toInt();
    laser->frequency = iniFile.value("frequency").toInt();
    laser->focalLenth = iniFile.value("focalLenth").toInt();
    laser->isMicroStep = iniFile.value("isMicroStep").toInt();
    laser->lightOutDelay = iniFile.value("lightOutDelay").toInt();
    laser->preHeatTime = iniFile.value("preHeatTime").toInt();
    iniFile.endGroup();
    iniFile.beginGroup("Scaner");
    scaner->delay = iniFile.value("delay").toInt();
    scaner->speed = iniFile.value("speed").toInt();
    scaner->microStepDelay = iniFile.value("microStepDelay").toInt();
    scaner->isXYExchange = iniFile.value("isXYExchange").toBool();
    scaner->XScaner.ratio = iniFile.value("XScaner.ratio").toInt();
    scaner->XScaner.adjust = iniFile.value("XScaner.adjust").toInt();
    scaner->XScaner.fineTrim = iniFile.value("XScaner.fineTrim").toInt();
    scaner->YScaner.ratio = iniFile.value("YScaner.ratio").toInt();
    scaner->YScaner.adjust = iniFile.value("YScaner.adjust").toInt();
    scaner->YScaner.fineTrim = iniFile.value("YScaner.fineTrim").toInt();
    iniFile.endGroup();
    iniFile.beginGroup("Crystal");
    crystal->curvMode = (CurvMode)iniFile.value("curvMode").toInt();
    crystal->isAlarm = iniFile.value("isAlarm").toBool();
    crystal->size.x = iniFile.value("size.x").toFloat();
    crystal->size.y = iniFile.value("size.y").toFloat();
    crystal->size.z = iniFile.value("size.z").toFloat();
    crystal->layMin = iniFile.value("layMin").toFloat();
    crystal->blockSet.angle = iniFile.value("blockSet.angle").toFloat();
    crystal->blockSet.width = iniFile.value("blockSet.width").toFloat();
    crystal->blockSet.fuzzyRatio = iniFile.value("blockSet.fuzzyRatio").toFloat();
    crystal->blockSet.stdDev = iniFile.value("blockSet.stdDev").toFloat();
    crystal->blockSet.blockType = (BlockType)iniFile.value("blockSet.blockType").toInt();
    crystal->blockSet.borderType = (BorderType)iniFile.value("blockSet.borderType").toInt();
    crystal->blockSet.size.x = iniFile.value("blockSet.size.x").toFloat();
    crystal->blockSet.size.y = iniFile.value("blockSet.size.y").toFloat();
    crystal->blockSet.size.z = iniFile.value("blockSet.size.z").toFloat();
    crystal->scanType = (ScanType)iniFile.value("scanType").toInt();
    crystal->mov.x = iniFile.value("mov.x").toFloat();
    crystal->mov.y = iniFile.value("mov.y").toFloat();
    crystal->mov.z = iniFile.value("mov.z").toFloat();
    crystal->pointCloud.pointNum = iniFile.value("pointCloud.pointNum").toInt();
    crystal->pointCloud.pointMax.x = iniFile.value("pointCloud.pointMax.x").toFloat();
    crystal->pointCloud.pointMax.y = iniFile.value("pointCloud.pointMax.y").toFloat();
    crystal->pointCloud.pointMax.z = iniFile.value("pointCloud.pointMax.z").toFloat();
    crystal->pointCloud.pointMin.x = iniFile.value("pointCloud.pointMin.x").toFloat();
    crystal->pointCloud.pointMin.y = iniFile.value("pointCloud.pointMin.y").toFloat();
    crystal->pointCloud.pointMin.z = iniFile.value("pointCloud.pointMin.z").toFloat();
    iniFile.endGroup();
    iniFile.beginGroup("Plat");
    plat->size.x = iniFile.value("size.x").toFloat();
    plat->size.y = iniFile.value("size.y").toFloat();
    plat->size.z = iniFile.value("size.z").toFloat();
    plat->mechPos.x = iniFile.value("mechPos.x").toFloat();
    plat->mechPos.y = iniFile.value("mechPos.y").toFloat();
    plat->mechPos.z = iniFile.value("mechPos.z").toFloat();
    plat->relPos.x = iniFile.value("relPos.x").toFloat();
    plat->relPos.y = iniFile.value("relPos.y").toFloat();
    plat->relPos.z = iniFile.value("relPos.z").toFloat();
    plat->HomPos.x = iniFile.value("HomPos.x").toFloat();
    plat->HomPos.y = iniFile.value("HomPos.y").toFloat();
    plat->HomPos.z = iniFile.value("HomPos.z").toFloat();
    iniFile.endGroup();
    return CUR_OK;
}

int ParaWindow::writeIniFile()
{
    //motor
    QSettings iniFile(INI_PATH, QSettings::IniFormat);
    iniFile.beginGroup("Motor");
    iniFile.setValue("motorX.ratio", QString::number(motor->motorX.ratio, 10));
    iniFile.setValue("motorX.offset", QString::number(motor->motorX.offset, 10));
    iniFile.setValue("motorX.stepAngle", QString::number(motor->motorX.stepAngle, 'f', 2));
    iniFile.setValue("motorX.subdivision", QString::number(motor->motorX.subdivision, 10));
    iniFile.setValue("motorX.v0", QString::number(motor->motorX.v0, 10));
    iniFile.setValue("motorX.v", QString::number(motor->motorX.v, 10));
    iniFile.setValue("motorX.a", QString::number(motor->motorX.a, 10));
    iniFile.setValue("motorX.inchCtrl", QString::number(motor->motorX.inchCtrl, 10));
    iniFile.setValue("motorX.mod", QString::number(motor->motorX.mod));
    iniFile.setValue("motorX.num", QString::number(motor->motorX.num));
    iniFile.setValue("motorX.limitP", QString::number(motor->motorX.limitP));
    iniFile.setValue("motorX.limitN", QString::number(motor->motorX.limitN));
    iniFile.setValue("motorX.limitL", QString::number(motor->motorX.limitL));
    iniFile.setValue("motorY.ratio", QString::number(motor->motorY.ratio, 10));
    iniFile.setValue("motorY.offset", QString::number(motor->motorY.offset, 10));
    iniFile.setValue("motorY.stepAngle", QString::number(motor->motorY.stepAngle, 'f', 2));
    iniFile.setValue("motorY.subdivision", QString::number(motor->motorY.subdivision, 10));
    iniFile.setValue("motorY.v0", QString::number(motor->motorY.v0, 10));
    iniFile.setValue("motorY.v", QString::number(motor->motorY.v, 10));
    iniFile.setValue("motorY.a", QString::number(motor->motorY.a, 10));
    iniFile.setValue("motorY.inchCtrl", QString::number(motor->motorY.inchCtrl, 10));
    iniFile.setValue("motorY.mod", QString::number(motor->motorY.mod));
    iniFile.setValue("motorY.num", QString::number(motor->motorY.num));
    iniFile.setValue("motorY.limitP", QString::number(motor->motorY.limitP));
    iniFile.setValue("motorY.limitN", QString::number(motor->motorY.limitN));
    iniFile.setValue("motorY.limitL", QString::number(motor->motorY.limitL));
    iniFile.setValue("motorZ.ratio", QString::number(motor->motorZ.ratio, 10));
    iniFile.setValue("motorZ.offset", QString::number(motor->motorZ.offset, 10));
    iniFile.setValue("motorZ.stepAngle", QString::number(motor->motorZ.stepAngle, 'f', 2));
    iniFile.setValue("motorZ.subdivision", QString::number(motor->motorZ.subdivision, 10));
    iniFile.setValue("motorZ.v0", QString::number(motor->motorZ.v0, 10));
    iniFile.setValue("motorZ.v", QString::number(motor->motorZ.v, 10));
    iniFile.setValue("motorZ.a", QString::number(motor->motorZ.a, 10));
    iniFile.setValue("motorZ.inchCtrl", QString::number(motor->motorZ.inchCtrl, 10));
    iniFile.setValue("motorZ.mod", QString::number(motor->motorZ.mod));
    iniFile.setValue("motorZ.num", QString::number(motor->motorZ.num));
    iniFile.setValue("motorZ.limitP", QString::number(motor->motorZ.limitP));
    iniFile.setValue("motorZ.limitN", QString::number(motor->motorZ.limitN));
    iniFile.setValue("motorZ.limitL", QString::number(motor->motorZ.limitL));
    iniFile.endGroup();
    iniFile.beginGroup("Laser");
    iniFile.setValue("ratio", QString::number(laser->ratio, 10));
    iniFile.setValue("frequency", QString::number(laser->frequency, 10));
    iniFile.setValue("focalLenth", QString::number(laser->focalLenth, 10));
    iniFile.setValue("isMicroStep", QString::number(laser->isMicroStep, 10));
    iniFile.setValue("isSerialLink", QString::number(laser->isSerialLink, 10));
    iniFile.setValue("lightOutDelay", QString::number(laser->lightOutDelay, 10));
    iniFile.setValue("preHeatTime", QString::number(laser->preHeatTime, 10));
    iniFile.endGroup();
    iniFile.beginGroup("Scaner");
    iniFile.setValue("delay", QString::number(scaner->delay, 10));
    iniFile.setValue("speed", QString::number(scaner->speed, 10));
    iniFile.setValue("microStepDelay", QString::number(scaner->microStepDelay, 10));
    iniFile.setValue("isXYExchange", QString::number(scaner->isXYExchange, 10));
    iniFile.setValue("XScaner.ratio", QString::number(scaner->XScaner.ratio, 'f', 2));
    iniFile.setValue("XScaner.adjust", QString::number(scaner->XScaner.adjust, 10));
    iniFile.setValue("XScaner.fineTrim", QString::number(scaner->XScaner.fineTrim, 10));
    iniFile.setValue("YScaner.ratio", QString::number(scaner->YScaner.ratio, 'f', 2));
    iniFile.setValue("YScaner.adjust", QString::number(scaner->YScaner.adjust, 10));
    iniFile.setValue("YScaner.fineTrim", QString::number(scaner->YScaner.fineTrim, 10));
    iniFile.endGroup();
    iniFile.beginGroup("Crystal");
    iniFile.setValue("curvMode",QString::number(crystal->curvMode, 10));
    iniFile.setValue("isAlarm",QString::number(crystal->isAlarm, 10));
    iniFile.setValue("size.x",QString::number(crystal->size.x, 'f', 2));
    iniFile.setValue("size.y",QString::number(crystal->size.y, 'f', 2));
    iniFile.setValue("size.z",QString::number(crystal->size.z, 'f', 2));
    iniFile.setValue("layMin",crystal->layMin);
    iniFile.setValue("blockSet.angle",QString::number(crystal->blockSet.angle, 'f', 2));
    iniFile.setValue("blockSet.width",QString::number(crystal->blockSet.width, 'f', 2));
    iniFile.setValue("blockSet.fuzzyRatio",QString::number(crystal->blockSet.fuzzyRatio, 'f', 2));
    iniFile.setValue("blockSet.stdDev",QString::number(crystal->blockSet.stdDev, 'f', 2));
    iniFile.setValue("blockSet.blockType",QString::number(crystal->blockSet.blockType, 10));
    iniFile.setValue("blockSet.borderType",QString::number(crystal->blockSet.borderType, 10));
    iniFile.setValue("blockSet.size.x",QString::number(crystal->blockSet.size.x, 'f', 2));
    iniFile.setValue("blockSet.size.y",QString::number(crystal->blockSet.size.y, 'f', 2));
    iniFile.setValue("blockSet.size.z",QString::number(crystal->blockSet.size.z, 'f', 2));
    iniFile.setValue("scanType",QString::number(crystal->scanType, 10));
    iniFile.setValue("mov.x",QString::number(crystal->mov.x, 'f', 2));
    iniFile.setValue("mov.y",QString::number(crystal->mov.y, 'f', 2));
    iniFile.setValue("mov.z",QString::number(crystal->mov.z, 'f', 2));
    iniFile.setValue("pointCloud.pointNum",QString::number(crystal->pointCloud.pointNum, 10));
    iniFile.setValue("pointCloud.pointMax.x",QString::number(crystal->pointCloud.pointMax.x, 'f', 2));
    iniFile.setValue("pointCloud.pointMax.y",QString::number(crystal->pointCloud.pointMax.y, 'f', 2));
    iniFile.setValue("pointCloud.pointMax.z",QString::number(crystal->pointCloud.pointMax.z, 'f', 2));
    iniFile.setValue("pointCloud.pointMin.x",QString::number(crystal->pointCloud.pointMin.x, 'f', 2));
    iniFile.setValue("pointCloud.pointMin.y",QString::number(crystal->pointCloud.pointMin.y, 'f', 2));
    iniFile.setValue("pointCloud.pointMin.z",QString::number(crystal->pointCloud.pointMin.z, 'f', 2));
    iniFile.endGroup();
    iniFile.beginGroup("Plat");
    iniFile.setValue("size.x", QString::number(plat->size.x, 'f', 2));
    iniFile.setValue("size.y", QString::number(plat->size.y, 'f', 2));
    iniFile.setValue("size.z", QString::number(plat->size.z, 'f', 2));
    iniFile.setValue("mechPos.x", QString::number(plat->mechPos.x, 'f', 2));
    iniFile.setValue("mechPos.y", QString::number(plat->mechPos.y, 'f', 2));
    iniFile.setValue("mechPos.z", QString::number(plat->mechPos.z, 'f', 2));
    iniFile.setValue("relPos.x", QString::number(plat->relPos.x, 'f', 2));
    iniFile.setValue("relPos.y", QString::number(plat->relPos.y, 'f', 2));
    iniFile.setValue("relPos.z", QString::number(plat->relPos.z, 'f', 2));
    iniFile.setValue("HomPos.x", QString::number(plat->HomPos.x, 'f', 2));
    iniFile.setValue("HomPos.y", QString::number(plat->HomPos.y, 'f', 2));
    iniFile.setValue("HomPos.z", QString::number(plat->HomPos.z, 'f', 2));
    iniFile.endGroup();
    return CUR_OK;
}
