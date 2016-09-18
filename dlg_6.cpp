#include "dlg_6.h"
#include "ui_dlg_6.h"

dlg_6::dlg_6(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_6)
{
    ui->setupUi(this);
}

dlg_6::~dlg_6()
{
    delete ui;
}

char c[10];      /*查询时输入的班级*/
void dlg_6::on_pushButton_clicked()
{
    strcpy(c, ui->lineEdit->text().toLocal8Bit().data());
}
