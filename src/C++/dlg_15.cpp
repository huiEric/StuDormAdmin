#include "dlg_15.h"
#include "ui_dlg_15.h"

dlg_15::dlg_15(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_15)
{
    ui->setupUi(this);
}

dlg_15::~dlg_15()
{
    delete ui;
}
