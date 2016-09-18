#include "dlg_2.h"
#include "ui_dlg_2.h"
#include "main.h"
#include <QTextStream>

dlg_2::dlg_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_2)
{
    ui->setupUi(this);
}

dlg_2::~dlg_2()
{
    delete ui;
}

COST cost;
void dlg_2::on_pushButton_clicked()
{
    strcpy(cost.id,ui->lineEdit->text().toLocal8Bit().data());
    strcpy(cost.name,ui->lineEdit_2->text().toLocal8Bit().data());
    strcpy(cost.date,ui->dateEdit->date().toString("yyyy/MM/dd").toLocal8Bit().data());
    cost.cost = ui->doubleSpinBox->value();
    char s[100];
    strcpy(s, ui->dateEdit_2->date().toString("yyyy").toLocal8Bit().data());
    strcat(s, ui->label_7->text().toLocal8Bit().data());
    strcpy(cost.use, s);
    strcpy(cost.payee, ui->lineEdit_3->text().toLocal8Bit().data());
}

void dlg_2::update(costNode *pCost)
{
    //QTextStream cout(stdout, QIODevice::WriteOnly);
    ui->lineEdit->setText(pCost->cost.id);
    ui->lineEdit_2->setText(pCost->cost.name);
    char s[5];
    strncpy(s, pCost->cost.use, 4);
    ui->dateEdit_2->setDateTime(QDateTime::fromString(QString(s), "yyyy"));
    ui->lineEdit_3->setText(pCost->cost.payee);
    ui->dateEdit->setDateTime(QDateTime::fromString(QString(pCost->cost.date), "yyyy/MM/dd"));
    ui->doubleSpinBox->setValue(pCost->cost.cost);
}
