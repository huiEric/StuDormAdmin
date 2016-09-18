#include "dlg_13.h"
#include "ui_dlg_13.h"
#include "dlg_3.h"
#include <QScrollArea>


dlg_13::dlg_13(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_13)
{
    ui->setupUi(this);
}

dlg_13::~dlg_13()
{
    delete ui;
}

void dlg_13::display(OWE *head)
{
    OWE *p = head;
    unsigned n=0;
    QScrollArea *pArea= new QScrollArea(this);
    QWidget * qw = new QWidget(pArea);
    pArea->setWidget(qw);
    pArea->setGeometry(QRect(0, 59, 731, 300));
    qw->setGeometry(QRect(0, 59, 625, 500));
    pArea->setStyleSheet("border: none;");
    while(p->next)
    {
        unsigned height = 10 + n*30;
        QLabel *labels[5];
        for(unsigned i=0;i<5;i++)
        {
            labels[i] = new QLabel(qw);
            labels[i]->setStyleSheet("font-size:10;font-style:Adobe ¿¬Ìå Std R");
        }
        labels[0]->setGeometry(QRect(90, height, 54, 21));
        labels[0]->setText(p->id);
        labels[1]->setGeometry(QRect(200, height, 54, 21));
        labels[1]->setText(p->name);
        labels[2]->setGeometry(QRect(310, height, 81, 21));
        labels[2]->setText(p->dorm);
        labels[3]->setGeometry(QRect(450, height, 54, 21));
        labels[3]->setText(QString("%1").arg(p->year));
        labels[4]->setGeometry(QRect(540, height, 81, 21));
        labels[4]->setText(QString("%1").arg(p->fee));
        n++;
        p = p->next;
    }
    pArea->show();
}
