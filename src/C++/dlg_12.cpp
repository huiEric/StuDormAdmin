#include "dlg_12.h"
#include "ui_dlg_12.h"
#include "dlg_3.h"

dlg_12::dlg_12(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_12)
{
    ui->setupUi(this);
}

dlg_12::~dlg_12()
{
    delete ui;
}

void dlg_12::display(Fees *head)
{
    Fees *p = head;
    Fee *p_f;
    unsigned n=0;
    while(p->next)
    {
        p_f = p->f;
        while(p_f)
        {
            unsigned height=50 + n*30;
            QLabel *labels[3];
            for(unsigned i=0;i<3;i++)
            {
                labels[i] = new QLabel(this);
                labels[i]->setStyleSheet("font-size:10;font-style:Adobe ¿¬Ìå Std R");
            }
            labels[0]->setGeometry(QRect(90, height, 54, 21));
            labels[0]->setText(p_f->y);
            labels[1]->setGeometry(QRect(280, height, 54, 21));
            labels[1]->setText(p->dormID);
            labels[2]->setGeometry(QRect(480, height, 54, 21));
            labels[2]->setText(QString("%1").arg(p_f->fee));
            n++;
            p_f = p_f->next;
        }
        p = p->next;
    }
}
