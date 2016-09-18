#include "dlg_3.h"
#include "ui_dlg_3.h"
#include "main.h"

dlg_3::dlg_3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_3)
{
    ui->setupUi(this);
}

dlg_3::~dlg_3()
{
    delete ui;
}

DORM dorm;
void dlg_3::on_pushButton_clicked()
{
    QList<QLineEdit *> lineEdit = findChildren<QLineEdit *>();
    if(lineEdit.count()==0)
    {
        return;
    }
    strcpy(dorm.dormID,ui->lineEdit->text().toLocal8Bit().data());
    strcpy(dorm.admin,ui->lineEdit_2->text().toLocal8Bit().data());
    strcpy(dorm.tel,ui->lineEdit_3->text().toLocal8Bit().data());
    dorm.NumOfRoom = ui->spinBox->value();
    dorm.NumOfBed = ui->spinBox_2->value();
    dorm.fee = ui->doubleSpinBox->value();
}

void dlg_3::query(dormNode *p)
{
    QList<QLineEdit *> lineEdit = findChildren<QLineEdit *>();
    for(int i=0;i<lineEdit.count();i++)
    {
        delete lineEdit[i];
    }
    delete ui->doubleSpinBox;
    QList<QSpinBox *> spinBox = findChildren<QSpinBox *>();
    for(int i=0;i<spinBox.count();i++)
    {
        delete spinBox[i];
    }
    QLabel *labels[6];
    for(int i=0;i<6;i++)
    {
        unsigned height = 30 + i*50;
        labels[i] = new QLabel(this);
        labels[i]->setGeometry(240, height, 161, 31);
        labels[i]->setStyleSheet("font-size:10;font-style:Adobe 宋体 Std L;");
    }
    labels[0]->setText(p->dorm.dormID);
    labels[1]->setText(p->dorm.admin);
    labels[2]->setText(p->dorm.tel);
    labels[3]->setText(QString("%1").arg(p->dorm.NumOfRoom));
    labels[4]->setText(QString("%1").arg(p->dorm.NumOfBed));
    labels[5]->setText(QString("%1").arg(p->dorm.fee));
}

void dlg_3::update(dormNode *p)
{
    ui->lineEdit->setText(p->dorm.dormID);
    ui->lineEdit_2->setText(p->dorm.admin);
    ui->lineEdit_3->setText(p->dorm.tel);
    ui->spinBox->setValue(p->dorm.NumOfRoom);
    ui->spinBox_2->setValue(p->dorm.NumOfBed);
    ui->doubleSpinBox->setValue(p->dorm.fee);
}
