#include "dlg_14.h"
#include "ui_dlg_14.h"
#include "dlg_3.h"

dlg_14::dlg_14(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_14)
{
    ui->setupUi(this);
}

dlg_14::~dlg_14()
{
    delete ui;
}

void dlg_14::display(CLASS_DORM *head)
{
    char room[1000];
    CLASS_DORM *p_c = head;
    ROOM *p_r;
    unsigned height , n = 0;
    while(p_c->next)
    {
        p_r = p_c->roomNode;
        if(p_r)
        {
            strcpy(room, p_r->room);
            p_r = p_r->next;
        }
        while(p_r)
        {
            strcat(room, ",");
            strcat(room,  p_r->room);
            p_r = p_r->next;
        }
        height = 70 + n*30;
        QLabel *label_class = new QLabel(this);
        QLabel *label_room = new QLabel(this);
        label_class->setGeometry(QRect(140, height, 81, 20));
        label_class->setStyleSheet("font-size:10;font-style:Adobe ¿¬Ìå Std R");
        label_class->setText(p_c->Class);
        label_room->setGeometry(QRect(310, height, 300, 20));
        label_room->setStyleSheet("font-size:10;font-style:Adobe ¿¬Ìå Std R");
        label_room->setText(room);
        n++;
        p_c = p_c->next;
    }
}
