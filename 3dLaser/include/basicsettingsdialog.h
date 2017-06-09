#ifndef BASICSETTINGSDIALOG_H
#define BASICSETTINGSDIALOG_H

#include <osg/Vec3>

#include <QDialog>

namespace Ui {
class BasicSettingsDialog;
}


class BasicSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    enum CrystalType
    {
        BOX,//方形
        CYLINDER //圆形
    };

public:
    explicit BasicSettingsDialog(const osg::Vec3 &modelSize = osg::Vec3(0.f,0.f,0.f),
                                 QWidget *parent = 0);
    ~BasicSettingsDialog();

private:
    Ui::BasicSettingsDialog *ui;

private slots:
    void on_LockXYZCheckedChanged();
    void on_ScaleXValueChanged();
    void on_hSliderXYZValueChanged();
    void on_CrystalTypeSelectChanged();

// functions
private:
    void accept();
    void updateScaleUI();
    bool getPrmOnUI();
    void updateCrystalTypeUI(CrystalType type);

// public functions
public:
    void initUI_ModelSRT();
    void setModelSize(const osg::Vec3 &modelSize);
    void setCrystalPrm(CrystalType type, const osg::Vec3 &size, float zRot, float height, float diameter);

// public variables
public:
    bool isScaleXYZLocked=true;
    osg::Vec3 scale;
    osg::Vec3 trans;
    osg::Vec3 rotate;
    CrystalType crystalType = BOX;
    osg::Vec3 crystalSize;
    float crystalZRot;//方形水晶Z旋转角（-180~+180）
    float crystalHeight;//圆形水晶高度
    float crystalDiameter;//圆形水晶直径
};

#endif // BASICSETTINGSDIALOG_H
