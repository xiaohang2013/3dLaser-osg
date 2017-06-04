#include "addtextdialog.h"
#include "ui_addtextdialog.h"
#include "systemfontfunction.h"

#include <QFontDialog>
#include <QMessageBox>

const QString _LeftToRight("左向右");
const QString _RightToLeft("右向左");
const QString _Vertical("竖直");

addTextDialog::addTextDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addTextDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Text");
    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint | Qt::WindowStaysOnTopHint);

    ui->cb_layout->addItem(_LeftToRight);
    ui->cb_layout->addItem(_RightToLeft);
    ui->cb_layout->addItem(_Vertical);
    ui->cb_layout->setCurrentIndex(layout);

    ui->cb_font->setCurrentFont(QFont("宋体"));

    connect(ui->rb_2DText,SIGNAL(toggled(bool)), this, SLOT(on_textModeSelectionChanged()));
    connect(ui->rb_3DText,SIGNAL(toggled(bool)), this, SLOT(on_textModeSelectionChanged()));
//    connect(ui->pb_FontSet, SIGNAL(clicked()), this, SLOT(on_SetFont()));
    connect(ui->pb_previewEffect, SIGNAL(clicked()), this, SLOT(on_previewEffect()));
}

addTextDialog::~addTextDialog()
{
    delete ui;
}

void addTextDialog::accept()
{
    if(getTextPrmOnUI())
    {
        emit signalAddText();
        QDialog::accept();
    }
}

void addTextDialog::reject()
{
    emit signalCancelToAddText();
    QDialog::reject();
}

// 字体模式改变
void addTextDialog::on_textModeSelectionChanged()
{
    ui->doubleSpinBox_Depth->setEnabled(ui->rb_3DText->isChecked());
}


void addTextDialog::on_previewEffect()
{
    if(getTextPrmOnUI())
        emit signalPreviewText();
}

bool addTextDialog::getTextPrmOnUI()
{
    if(ui->rb_2DText->isChecked()) mode=TextMode2D;
    else if(ui->rb_3DText->isChecked()) mode=TextMode3D;

    depth = ui->doubleSpinBox_Depth->value();
    QString fontFamily = ui->cb_font->currentFont().family();
    SystemFontFunction sff;
    QString englishName=sff.getEnglishName(fontFamily);
    fontFile = QString::fromStdString(sff.GetSystemFontFile(englishName.toStdString()));
    if(fontFile.isEmpty())
    {
        QMessageBox::information(this, tr("提示"),"所选字体不支持！");
        return false;
    }

    layout = Layout(ui->cb_layout->currentIndex());
    height = ui->doubleSpinBox_height->value();
    text = ui->textEdit->toPlainText().trimmed();
    if(text.isEmpty())
    {
        QMessageBox::warning(this, tr("提示"), tr("请输入文本内容！"));
        return false;
    }

    centerPoint.x()=ui->doubleSpinBox_X->value();
    centerPoint.y()=ui->doubleSpinBox_Y->value();
    centerPoint.z()=ui->doubleSpinBox_Z->value();
    rotation.x()=ui->doubleSpinBox_RotateX->value();
    rotation.y()=ui->doubleSpinBox_RotateY->value();
    rotation.z()=ui->doubleSpinBox_RotateZ->value();
    return true;
}
