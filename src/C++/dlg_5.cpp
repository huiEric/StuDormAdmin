#include "dlg_5.h"
#include "ui_dlg_5.h"

dlg_5::dlg_5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_5)
{
    ui->setupUi(this);
}

dlg_5::~dlg_5()
{
    delete ui;
}
