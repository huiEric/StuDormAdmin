#include "dlg_4.h"
#include "ui_dlg_4.h"

dlg_4::dlg_4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_4)
{
    ui->setupUi(this);
}

dlg_4::~dlg_4()
{
    delete ui;
}

char id[12];
void dlg_4::on_pushButton_clicked()
{
    strcpy(id, ui->lineEdit->text().toLocal8Bit().data());
}
