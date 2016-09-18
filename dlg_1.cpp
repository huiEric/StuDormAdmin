#include "dlg_1.h"
#include "ui_dlg_1.h"
#include "main.h"

dlg_1::dlg_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_1)
{
    ui->setupUi(this);
}

dlg_1::~dlg_1()
{
    delete ui;
}

INFO info;

void dlg_1::on_pushButton_clicked()
{
    QList<QLineEdit *> lineEdit = findChildren<QLineEdit *>();
    if(lineEdit.count()==0)
    {
        return;
    }
    strcpy(info.id,ui->lineEdit->text().toLocal8Bit().data());
    strcpy(info.name,ui->lineEdit_2->text().toLocal8Bit().data());
    if(ui->radioButton->isChecked())
    {
        info.gender = 'm';
    }
    else
    {
        info.gender = 'f';
    }
    strcpy(info.birth,ui->dateEdit->date().toString("yyyy/MM/dd").toLocal8Bit().data());
    strcpy(info.type,ui->comboBox->currentText().toLocal8Bit().data());
    if(ui->radioButton_3->isChecked())
    {
        info.studyTime = 4;
    }
    else
    {
        info.studyTime = 3;
    }
    strcpy(info.admittedTime,ui->dateEdit_2->date().toString("yyyy/MM").toLocal8Bit().data());
    strcpy(info.Class,ui->lineEdit_8->text().toLocal8Bit().data());
    strcpy(info.dorm,ui->lineEdit_9->text().toLocal8Bit().data());
    strcpy(info.room,ui->lineEdit_10->text().toLocal8Bit().data());
    strcpy(info.tel,ui->lineEdit_11->text().toLocal8Bit().data());
    strcpy(info.grade, ui->comboBox_2->currentText().toLocal8Bit().data());
}

void dlg_1::query(infoNode *pInfo)
{
    QList<QLineEdit *> lineEdit = findChildren<QLineEdit *>();
    for(int i=0;i<lineEdit.count();i++)
    {
        delete lineEdit[i];
    }
    QList<QRadioButton *> radioButton = findChildren<QRadioButton *>();
    for(int i=0;i<radioButton.count();i++)
    {
        delete radioButton[i];
    }
    delete ui->dateEdit;
    delete ui->dateEdit_2;
    delete ui->comboBox;
    delete ui->comboBox_2;
    QLabel *labels[12];
    for(int i=0;i<6;i++)
    {
        unsigned height = 30 + i*50;
        labels[i] = new QLabel(this);
        labels[i]->setGeometry(130, height, 161, 31);
        labels[i]->setStyleSheet("font-size:10;font-style:Adobe 瀹嬩綋 Std L;");
    }
    labels[0]->setText(pInfo->info.id);
    labels[1]->setText(pInfo->info.name);
    labels[2]->setText(QString(pInfo->info.gender));
    labels[3]->setText(pInfo->info.birth);
    labels[4]->setText(pInfo->info.type);
    labels[5]->setText(QString("%1").arg(pInfo->info.studyTime));
    for(int i=6;i<12;i++)
    {
        unsigned height = 30 + (i-6)*50;
        labels[i] = new QLabel(this);
        labels[i]->setGeometry(420, height, 161, 31);
        labels[i]->setStyleSheet("font-size:10;font-style:Adobe 瀹嬩綋 Std L;");
    }
    labels[6]->setText(pInfo->info.admittedTime);
    labels[7]->setText(pInfo->info.Class);
    labels[11]->setText(pInfo->info.dorm);
    labels[9]->setText(pInfo->info.room);
    labels[10]->setText(pInfo->info.tel);
    labels[8]->setText(pInfo->info.grade);
}

void dlg_1::update(infoNode *pInfo)
{
    ui->lineEdit->setText(pInfo->info.id);
    ui->lineEdit_2->setText(pInfo->info.name);
    ui->lineEdit_8->setText(pInfo->info.Class);
    ui->lineEdit_9->setText(pInfo->info.dorm);
    ui->lineEdit_10->setText(pInfo->info.room);
    ui->lineEdit_11->setText(pInfo->info.tel);
    if(pInfo->info.gender=='f')
    {
        ui->radioButton->setChecked(false);
        ui->radioButton_2->setChecked(true);
    }
    if(pInfo->info.studyTime==3)
    {
        ui->radioButton_3->setChecked(false);
        ui->radioButton_4->setChecked(true);
    }
    ui->dateEdit->setDateTime(QDateTime::fromString(QString(pInfo->info.birth), "yyyy/MM/dd"));
    ui->dateEdit_2->setDateTime(QDateTime::fromString(QString(pInfo->info.admittedTime), "yyyy/MM"));
    ui->comboBox->setCurrentText(pInfo->info.type);
    ui->comboBox_2->setCurrentText(pInfo->info.grade);
}
