#include "dlg_8.h"
#include "ui_dlg_8.h"

dlg_8::dlg_8(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_8)
{
    ui->setupUi(this);
}

dlg_8::~dlg_8()
{
    delete ui;
}

void dlg_8::setWarning(const char *warning)
{
    ui->label->setText(warning);
}
