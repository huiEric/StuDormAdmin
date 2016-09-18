#include "dlg_10.h"
#include "ui_dlg_10.h"
#include "dlg_3.h"

dlg_10::dlg_10(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_10)
{
    ui->setupUi(this);
}

dlg_10::~dlg_10()
{
    delete ui;
}

void dlg_10::display(liveNode *h_l)
{
    liveNode *p_l=h_l;
    unsigned n=0;
    while(p_l->next)
    {
        unsigned height = 70 + n*30;
        QLabel *dormID = new QLabel(this);
        dormID->setGeometry(QRect(80, height, 71, 21));
        dormID->setStyleSheet("font-size:10;font-style:Adobe 楷体 Std R");
        dormID->setText(p_l->live.dormID);
        QLabel *canlive = new QLabel(this);
        canlive->setGeometry(QRect(190, height, 81, 21));
        canlive->setStyleSheet("font-size:10;font-style:Adobe 楷体 Std R");
        canlive->setText(QString("%1").arg(p_l->live.canlive));
        QLabel *inlive = new QLabel(this);
        inlive->setGeometry(QRect(320, height, 91, 21));
        inlive->setStyleSheet("font-size:10;font-style:Adobe 楷体 Std R");
        inlive->setText(QString("%1").arg(p_l->live.inlive));
        QLabel *emptybed = new QLabel(this);
        emptybed->setGeometry(QRect(450, height, 71, 21));
        emptybed->setStyleSheet("font-size:10;font-style:Adobe 楷体 Std R");
        emptybed->setText(QString("%1").arg(p_l->live.emptybed));
        QLabel *rate = new QLabel(this);
        rate->setGeometry(QRect(570, height, 61, 21));
        rate->setStyleSheet("font-size:10;font-style:Adobe 楷体 Std R");
        double d=p_l->live.rate;
        QString str = QString::number(d*100, 'f', 2);
        char s[100];
        strcpy(s, str.toLatin1().data());
        strcat(s, "%");
        rate->setText(s);
        n++;
        p_l = p_l->next;
    }
}
