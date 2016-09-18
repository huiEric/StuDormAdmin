#include "dlg_11.h"
#include "ui_dlg_11.h"
#include "dlg_3.h"

dlg_11::dlg_11(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_11)
{
    ui->setupUi(this);
}

dlg_11::~dlg_11()
{
    delete ui;
}

void dlg_11::display(Types t[])
{
    for(unsigned i=0;i<8;i++)
    {
        QLabel *labels[6];
        unsigned height=80 + i*30;
        for(unsigned j=0;j<6;j++)
        {
           labels[j] = new QLabel(this);
           labels[j]->setStyleSheet("font-size:10;font-style:Adobe ¿¬Ìå Std R");
        }
        labels[0]->setGeometry(QRect(90, height, 54, 31));
        labels[0]->setText(t[i].sex);
        labels[1]->setGeometry(QRect(160, height, 54, 31));
        labels[1]->setText(t[i].grade);
        labels[2]->setGeometry(QRect(250, height, 54, 31));
        labels[2]->setText(QString("%1").arg(t[i].zhuan));
        labels[3]->setGeometry(QRect(360, height, 54, 31));
        labels[3]->setText(QString("%1").arg(t[i].benke));
        labels[4]->setGeometry(QRect(470, height, 54, 31));
        labels[4]->setText(QString("%1").arg(t[i].shuoshi));
        labels[5]->setGeometry(QRect(570, height, 54, 31));
        labels[5]->setText(QString("%1").arg(t[i].boshi));
    }
}
