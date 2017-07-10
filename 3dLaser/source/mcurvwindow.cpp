#include "mcurvwindow.h"
#include "ui_mcurvwindow.h"
#include <string>
using namespace std;

/************************全局变量区****************************/

/************************全局函数区****************************/
McurvWindow::McurvWindow(QWidget *parent) :
QDialog(parent),
ui(new Ui::McurvWindow)
{
    ui->setupUi(this);
    this->setVisible(false);
    Qt::WindowFlags flags = Qt::Dialog;
    flags |= Qt::WindowCloseButtonHint;
    setWindowFlags(flags);
}

McurvWindow::~McurvWindow()
{
    delete ui;
}