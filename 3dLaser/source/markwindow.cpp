#include "markwindow.h"
#include "ui_markwindow.h"
#include <string>
using namespace std;

/************************全局变量区****************************/

/************************全局函数区****************************/
MarkWindow::MarkWindow(QWidget *parent) :
QDialog(parent),
ui(new Ui::MarkWindow)
{
    ui->setupUi(this);
    this->setVisible(false);
    Qt::WindowFlags flags = Qt::Dialog;
    flags |= Qt::WindowCloseButtonHint;
    setWindowFlags(flags);
}

MarkWindow::~MarkWindow()
{
    delete ui;
}
