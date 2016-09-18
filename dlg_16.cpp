#include "dlg_16.h"
#include "ui_dlg_16.h"

dlg_16::dlg_16(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_16)
{
    ui->setupUi(this);
}

dlg_16::~dlg_16()
{
    delete ui;
}
