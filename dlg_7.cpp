#include "dlg_7.h"
#include "ui_dlg_7.h"

dlg_7::dlg_7(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_7)
{
    ui->setupUi(this);
}

dlg_7::~dlg_7()
{
    delete ui;
}

char dormID[5];
void dlg_7::on_pushButton_clicked()
{
    strcpy(dormID, ui->lineEdit->text().toLocal8Bit().data());
}
