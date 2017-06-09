#include "basicsettingsdialog.h"

BasicSettingsDialog::BasicSettingsDialog(const osg::Vec3 &modelSize, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BasicSettingsDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Setting");
    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint | Qt::WindowStaysOnTopHint);
    setModelSize(modelSize);
    initUI_ModelSRT();
    updateScaleUI();
//    crystalType = type;
//    updateCrystalTypeUI(type);

    connect(ui->checkBox_LockXYZ, SIGNAL(toggled(bool)), this, SLOT(on_LockXYZCheckedChanged()));
    connect(ui->spinBox_ScaleX, SIGNAL(valueChanged(int)), this, SLOT(on_ScaleXValueChanged()));
    connect(ui->hSlider_X, SIGNAL(valueChanged(int)), this, SLOT(on_hSliderXYZValueChanged()));
    connect(ui->hSlider_Y, SIGNAL(valueChanged(int)), this, SLOT(on_hSliderXYZValueChanged()));
    connect(ui->hSlider_Z, SIGNAL(valueChanged(int)), this, SLOT(on_hSliderXYZValueChanged()));
    connect(ui->rb_SquareCrystal, SIGNAL(toggled(bool)), this, SLOT(on_CrystalTypeSelectChanged()));
    connect(ui->rb_RoundCrystal, SIGNAL(toggled(bool)), this, SLOT(on_CrystalTypeSelectChanged()));
}

BasicSettingsDialog::~BasicSettingsDialog()
{
    delete ui;
}

void BasicSettingsDialog::on_LockXYZCheckedChanged()
{
    isScaleXYZLocked = ui->checkBox_LockXYZ->isChecked();
    updateScaleUI();
}

void BasicSettingsDialog::on_ScaleXValueChanged()
{
    if(ui->checkBox_LockXYZ->isChecked())
    {
        int valueX=ui->spinBox_ScaleX->value();
        ui->spinBox_ScaleY->setValue(valueX);
        ui->spinBox_ScaleZ->setValue(valueX);
    }
}

void BasicSettingsDialog::on_hSliderXYZValueChanged()
{
    ui->label_AngleX->setText(QString("%1°").arg(ui->hSlider_X->value()));
    ui->label_AngleY->setText(QString("%1°").arg(ui->hSlider_Y->value()));
    ui->label_AngleZ->setText(QString("%1°").arg(ui->hSlider_Z->value()));
}

void BasicSettingsDialog::on_CrystalTypeSelectChanged()
{
    if(ui->rb_SquareCrystal->isChecked())
        crystalType = BOX;
    else if(ui->rb_RoundCrystal->isChecked())
        crystalType = CYLINDER;
    updateCrystalTypeUI(crystalType);
}

void BasicSettingsDialog::accept()
{
    if(getPrmOnUI())
        QDialog::accept();
}

void BasicSettingsDialog::updateScaleUI()
{
    ui->spinBox_ScaleY->setEnabled(!ui->checkBox_LockXYZ->isChecked());
    ui->spinBox_ScaleZ->setEnabled(!ui->checkBox_LockXYZ->isChecked());
}

bool BasicSettingsDialog::getPrmOnUI()
{
    isScaleXYZLocked = ui->checkBox_LockXYZ->isChecked();
    scale.set((float)ui->spinBox_ScaleX->value()/100.0, (float)ui->spinBox_ScaleY->value()/100.0, (float)ui->spinBox_ScaleZ->value()/100.0);
    trans.set(ui->doubleSpinBox_TransX->value(),ui->doubleSpinBox_TransY->value(),ui->doubleSpinBox_TransZ->value());
    rotate.set(ui->hSlider_X->value(), ui->hSlider_Y->value(), ui->hSlider_Z->value());
    if(ui->rb_SquareCrystal->isChecked())
        crystalType = BOX;
    else if(ui->rb_RoundCrystal->isChecked())
        crystalType = CYLINDER;
    crystalSize.set(ui->doubleSpinBox_CrystalSizeX->value(),ui->doubleSpinBox_CrystalSizeY->value(),ui->doubleSpinBox_CrystalSizeZ->value());
    crystalZRot = ui->doubleSpinBox_CrystalZRotate->value();
    crystalHeight = ui->doubleSpinBox_CrystalHeight->value();
    crystalDiameter = ui->doubleSpinBox_CrystalDiameter->value();
    return true;
}

void BasicSettingsDialog::updateCrystalTypeUI(BasicSettingsDialog::CrystalType type)
{
    ui->rb_SquareCrystal->setChecked(type == BOX);
    ui->rb_RoundCrystal->setChecked(type == CYLINDER);
    ui->doubleSpinBox_CrystalSizeX->setEnabled(type == BOX);
    ui->doubleSpinBox_CrystalSizeY->setEnabled(type == BOX);
    ui->doubleSpinBox_CrystalSizeZ->setEnabled(type == BOX);
    ui->doubleSpinBox_CrystalZRotate->setEnabled(type == BOX);
    ui->doubleSpinBox_CrystalHeight->setEnabled(type == CYLINDER);
    ui->doubleSpinBox_CrystalDiameter->setEnabled(type == CYLINDER);
}

// 初始化模型SRT的UI
void BasicSettingsDialog::initUI_ModelSRT()
{
    ui->spinBox_ScaleX->setValue(100);
    ui->spinBox_ScaleY->setValue(100);
    ui->spinBox_ScaleZ->setValue(100);
    ui->doubleSpinBox_TransX->setValue(0.f);
    ui->doubleSpinBox_TransY->setValue(0.f);
    ui->doubleSpinBox_TransZ->setValue(0.f);
    ui->hSlider_X->setValue(0);
    ui->hSlider_Y->setValue(0);
    ui->hSlider_Z->setValue(0);
}

void BasicSettingsDialog::setModelSize(const osg::Vec3 &modelSize)
{
    ui->lineEdit_SizeX->setText(QString::number(modelSize.x(),'f',2));
    ui->lineEdit_SizeY->setText(QString::number(modelSize.y(),'f',2));
    ui->lineEdit_SizeZ->setText(QString::number(modelSize.z(),'f',2));
}

void BasicSettingsDialog::setCrystalPrm(BasicSettingsDialog::CrystalType type, const osg::Vec3 &size, float zRot, float height, float diameter)
{
    updateCrystalTypeUI(type);
    ui->doubleSpinBox_CrystalSizeX->setValue(size.x());
    ui->doubleSpinBox_CrystalSizeY->setValue(size.y());
    ui->doubleSpinBox_CrystalSizeZ->setValue(size.z());
    ui->doubleSpinBox_CrystalZRotate->setValue(zRot);
    ui->doubleSpinBox_CrystalHeight->setValue(height);
    ui->doubleSpinBox_CrystalDiameter->setValue(diameter);
}
