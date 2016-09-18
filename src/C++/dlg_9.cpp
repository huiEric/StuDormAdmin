#include "dlg_9.h"
#include "ui_dlg_9.h"
#include "main.h"
#include "dlg_2.h"
#include <QLineEdit>
#include <QPushButton>

dlg_9::dlg_9(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_9)
{
    ui->setupUi(this);
}

dlg_9::~dlg_9()
{
    delete ui;
}

void dlg_9::addLine(unsigned n, costNode *pCost, bool q)
{
    if(q)
    {
        ui->lineEdit->setVisible(false);
        ui->pushButton->setVisible(false);
        ui->pushButton_2->setVisible(false);
    }
    unsigned height = 70 + n*30;
    QLabel *num = new QLabel(this);
    num->setGeometry(QRect(40, height, 71, 21));
    num->setStyleSheet("font-size:10;font-style:Adobe 宋体 Std L;");
    num->setText(QString("%1").arg(n+1));
    QLabel *id = new QLabel(this);
    id->setGeometry(QRect(80, height, 71, 21));
    id->setStyleSheet("font-size:10;font-style:Adobe 宋体 Std L;");
    id->setText(pCost->cost.id);
    QLabel *name = new QLabel(this);
    name->setGeometry(QRect(160, height, 81, 21));
    name->setStyleSheet("font-size:10;font-style:Adobe 宋体 Std L;");
    name->setText(pCost->cost.name);
    QLabel *date = new QLabel(this);
    date->setGeometry(QRect(250, height, 81, 21));
    date->setStyleSheet("font-size:10;font-style:Adobe 宋体 Std L;");
    date->setText(pCost->cost.date);
    QLabel *cost = new QLabel(this);
    cost->setGeometry(QRect(380, height, 91, 21));
    cost->setStyleSheet("font-size:10;font-style:Adobe 宋体 Std L;");
    cost->setText(QString("%1").arg(pCost->cost.cost));
    QLabel *use = new QLabel(this);
    use->setGeometry(QRect(500, height, 101, 21));
    use->setStyleSheet("font-size:10;font-style:Adobe 宋体 Std L;");
    use->setText(pCost->cost.use);
    QLabel *payee = new QLabel(this);
    payee->setGeometry(QRect(640, height, 101, 21));
    payee->setStyleSheet("font-size:10;font-style:Adobe 宋体 Std L;");
    payee->setText(pCost->cost.payee);
}

unsigned num;
void dlg_9::on_pushButton_clicked()
{
    bool ok;
    num = ui->lineEdit->text().toInt(&ok, 10);
}
