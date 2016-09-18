#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "dlg_1.h"
#include "dlg_2.h"
#include "dlg_3.h"
#include "dlg_4.h"
#include "dlg_5.h"
#include "dlg_6.h"
#include "dlg_7.h"
#include "dlg_8.h"
#include "dlg_9.h"
#include "dlg_10.h"
#include "dlg_11.h"
#include "dlg_12.h"
#include "dlg_13.h"
#include "dlg_14.h"
#include "dlg_15.h"
#include "dlg_16.h"
#include <QTextStream>
#include "main.h"
#include <QDateTime>
#include <QProcess>
#include <windows.h>

QTextStream cin(stdin, QIODevice::ReadOnly);
QTextStream cout(stdout, QIODevice::WriteOnly);

void setWarning(const char *warning);

extern INFO info;
extern COST cost;
extern DORM dorm;
extern dormNode *head;
extern char id[12];
extern char c[10];
extern char dormID[5];
extern unsigned num;
dormNode *p;
infoNode *pInfo;
costNode *pCost;

struct CLASS{
    infoNode *p;
    struct CLASS *next;
};
typedef struct CLASS CLASS;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//录入学生基本信息
void MainWindow::on_action_6_triggered()
{
    dlg_1 *dlg = new dlg_1(this);
    dlg->show();
    if(dlg->exec()==QDialog::Accepted)
    {
        if(strlen(info.id)!=10 || !isalpha(info.id[0]))
        {
            dlg_8 *dlg8 = new dlg_8(this);
            dlg8->setWarning("学号输入错误！");
            dlg8->show();
            return;
        }
        for(unsigned i = 1; i < strlen(info.id); i++)
        {
            if(!isdigit(info.id[i]))
            {
                dlg_8 *dlg8 = new dlg_8(this);
                dlg8->setWarning("学号输入错误！");
                dlg8->show();
                return;
            }
        }
        if(!(strlen(info.name)>0 && strlen(info.name)<20))
        {
            dlg_8 *dlg8 = new dlg_8(this);
            dlg8->setWarning("学生姓名输入错误！");
            dlg8->show();
            return;
        }
        for(unsigned i = 0; i < strlen(info.name); i++)
        {
            if(!isalpha(info.name[i]))
            {
                dlg_8 *dlg8 = new dlg_8(this);
                dlg8->setWarning("学生姓名输入错误！");
                dlg8->show();
                return;
            }
        }
        if(!(strlen(info.Class)==6 && isalpha(info.Class[0]) && isalpha(info.Class[1]) && isdigit(info.Class[2]) && isdigit(info.Class[3]) && isdigit(info.Class[4]) && isdigit(info.Class[5])))
        {
            dlg_8 *dlg8 = new dlg_8(this);
            dlg8->setWarning("班级输入错误！");
            dlg8->show();
            return;
        }
        if(!(strlen(info.dorm)==4 && isalpha(info.dorm[0]) && (isalpha(info.dorm[1])) && (isdigit(info.dorm[2])) && isdigit(info.dorm[3])))
        {
            dlg_8 *dlg8 = new dlg_8(this);
            dlg8->setWarning("宿舍楼号输入错误！");
            dlg8->show();
            return;
        }
        if(strlen(info.room)!=3 || !isdigit(info.room[0]) || !isdigit(info.room[1]) || !isdigit(info.room[2]))
        {
            dlg_8 *dlg8 = new dlg_8(this);
            dlg8->setWarning("房间号输入错误！");
            dlg8->show();
            return;
        }
        if(strlen(info.tel)!=11)
        {
            dlg_8 *dlg8 = new dlg_8(this);
            dlg8->setWarning("联系电话输入错误！");
            dlg8->show();
            return;
        }
        for(unsigned i = 0; i < strlen(info.tel); i++)
        {
            if(!isdigit(info.tel[i]))
            {
                dlg_8 *dlg8 = new dlg_8(this);
                dlg8->setWarning("联系电话输入错误！");
                dlg8->show();
                return;
            }
        }
        dormNode *p = head;
        while(p->next)
        {
            if(strcmp(p->dorm.dormID,info.dorm))
            {
                p = p->next;
                continue;
            }
            infoNode *pInfo = p->iNode;
            while(pInfo)
            {
                if(!strcmp(pInfo->info.id,info.id))
                {
                    pInfo->info = info;
                    return;
                }
                pInfo = pInfo->next;
            }
            break;
        }
        if(!(p->next))
        {
            dlg_8 *dlg8 = new dlg_8(this);
            dlg8->setWarning("该宿舍楼不存在！");
            dlg8->show();
            return;
        }
        if(!pInfo)
        {
            pInfo = (infoNode *)malloc(sizeof(infoNode));
            pInfo->info = info;
            pInfo->cNode = NULL;
            pInfo->next = p->iNode;
            p->iNode = pInfo;
        }
     }
}

//录入学生住宿缴费信息
void MainWindow::on_action_7_triggered()
{
    dlg_2 *dlg = new dlg_2(this);
    dlg->show();
    if(dlg->exec()==QDialog::Accepted)
    {
        /*数据格式检查*/
        if(strlen(cost.id)!=10 || !isalpha(cost.id[0]))
        {
            dlg_8 *dlg8 = new dlg_8(this);
            dlg8->setWarning("学号输入错误！");
            dlg8->show();
            return;
        }
        for(unsigned i = 1; i < strlen(cost.id); i++)
        {
            if(!isdigit(cost.id[i]))
            {
                dlg_8 *dlg8 = new dlg_8(this);
                dlg8->setWarning("学号输入错误！");
                dlg8->show();
                return;
            }
        }
        if(!(strlen(cost.name)>0 && strlen(cost.name)<20))
        {
            dlg_8 *dlg8 = new dlg_8(this);
            dlg8->setWarning("学生姓名输入错误！");
            dlg8->show();
            return;
        }
        for(unsigned i = 0; i < strlen(cost.name); i++)
        {
            if(!isalpha(cost.name[i]))
            {
                dlg_8 *dlg8 = new dlg_8(this);
                dlg8->setWarning("学生姓名输入错误！");
                dlg8->show();
                return;
            }
        }
        if(!(strlen(cost.payee)>0 && strlen(cost.payee)<20))
        {
            dlg_8 *dlg8 = new dlg_8(this);
            dlg8->setWarning("收款人姓名输入错误！");
            dlg8->show();
            return;
        }
        for(unsigned i = 0; i < strlen(cost.payee); i++)
        {
            if(!isalpha(cost.payee[i]))
            {
                dlg_8 *dlg8 = new dlg_8(this);
                dlg8->setWarning("收款人姓名输入错误！");
                dlg8->show();
                return;
            }
        }
        dormNode *p = head;
        while(p->next)
        {
            infoNode *pInfo = p->iNode;
            while(pInfo)
            {
                if(!strcmp(pInfo->info.id, cost.id))
                {
                    pCost = pInfo->cNode;
                    if(!pCost)
                    {
                        pInfo->cNode = (costNode *)malloc(sizeof(costNode));
                        pInfo->cNode->cost = cost;
                        pInfo->cNode->next = NULL;
                        return;
                    }
                    while(pCost->next)
                    {
                        pCost = pCost->next;
                    }
                    pCost->next = (costNode *)malloc(sizeof(costNode));
                    pCost->next->cost = cost;
                    pCost->next->next = NULL;
                    return;
                }
                pInfo = pInfo->next;
            }
            p = p->next;
        }
        dlg_8 *dlg8 = new dlg_8(this);
        dlg8->setWarning("该学生不存在！");
        dlg8->show();
        return;
    }
}

//录入宿舍楼基本信息
void MainWindow::on_action_8_triggered()
{
    dlg_3 *dlg = new dlg_3(this);
    dlg->show();
    if(dlg->exec()==QDialog::Accepted)
    {
        /*输入数据格式检查*/
        if(!(strlen(dorm.dormID)==4 && isalpha(dorm.dormID[0])&&(isalpha(dorm.dormID[1]))&&(isdigit(dorm.dormID[2]))&&isdigit(dorm.dormID[3])))
        {
            dlg_8 *dlg8 = new dlg_8(this);
            dlg8->setWarning("宿舍楼号输入错误！");
            dlg8->show();
            return;
        }
        if(!(strlen(dorm.admin)>0 && strlen(dorm.admin)<20))
        {
            dlg_8 *dlg8 = new dlg_8(this);
            dlg8->setWarning("栋长姓名输入错误！");
            dlg8->show();
            return;
        }
        for(unsigned i = 0; i < strlen(dorm.admin); i++)
        {
            if(!isalpha(dorm.admin[i]))
            {
                dlg_8 *dlg8 = new dlg_8(this);
                dlg8->setWarning("栋长姓名输入错误！");
                dlg8->show();
                return;
            }
        }
        if(strlen(dorm.tel)!=8)
        {
            dlg_8 *dlg8 = new dlg_8(this);
            dlg8->setWarning("值班室电话输入错误！");
            dlg8->show();
            return;
        }
        for(unsigned i = 0; i < strlen(dorm.tel); i++)
        {
            if(!isdigit(dorm.tel[i]))
            {
                dlg_8 *dlg8 = new dlg_8(this);
                dlg8->setWarning("值班室电话输入错误！");
                dlg8->show();
                return;
            }
        }
        /*存进链表*/
        dormNode *p = head;
        while(p->next)
        {
            if(!strcmp(p->dorm.dormID,dorm.dormID))
            {
                return;
            }
            p=p->next;
        }
        p->dorm = dorm;
        p->next = (dormNode *)malloc(sizeof(dormNode));
        p = p->next;
        p->next = NULL;
        p->iNode = NULL;
    }
}

/*修改学生基本信息*/
void MainWindow::on_action_9_triggered()
{
    dlg_4 *dlg = new dlg_4(this);
    dlg->show();
    if(dlg->exec()==QDialog::Accepted)
    {
        p = head;
        while(p->next)
        {
            pInfo = p->iNode;
            while(pInfo)
            {
                if(!strcmp(id, pInfo->info.id))
                {
                    dlg_1 *dlg1 = new dlg_1(this);
                    dlg1->setWindowTitle("修改学生基本信息");
                    dlg1->update(pInfo);
                    dlg1->show();
                    if(dlg1->exec()==QDialog::Accepted)
                    {
                        if(strlen(info.id)!=10 || !isalpha(info.id[0]))
                        {
                            dlg_8 *dlg8 = new dlg_8(this);
                            dlg8->setWarning("学号输入错误！");
                            dlg8->show();
                            return;
                        }
                        for(unsigned i = 1; i < strlen(info.id); i++)
                        {
                            if(!isdigit(info.id[i]))
                            {
                                dlg_8 *dlg8 = new dlg_8(this);
                                dlg8->setWarning("学号输入错误！");
                                dlg8->show();
                                return;
                            }
                        }
                        if(!(strlen(info.name)>0 && strlen(info.name)<20))
                        {
                            dlg_8 *dlg8 = new dlg_8(this);
                            dlg8->setWarning("学生姓名输入错误！");
                            dlg8->show();
                            return;
                        }
                        for(unsigned i = 0; i < strlen(info.name); i++)
                        {
                            if(!isalpha(info.name[i]))
                            {
                                dlg_8 *dlg8 = new dlg_8(this);
                                dlg8->setWarning("学生姓名输入错误！");
                                dlg8->show();
                                return;
                            }
                        }
                        if(!(strlen(info.Class)==6 && isalpha(info.Class[0]) && isalpha(info.Class[1]) && isdigit(info.Class[2]) && isdigit(info.Class[3]) && isdigit(info.Class[4]) && isdigit(info.Class[5])))
                        {
                            dlg_8 *dlg8 = new dlg_8(this);
                            dlg8->setWarning("班级输入错误！");
                            dlg8->show();
                            return;
                        }
                        if(!(strlen(info.dorm)==4 && isalpha(info.dorm[0]) && (isalpha(info.dorm[1])) && (isdigit(info.dorm[2])) && isdigit(info.dorm[3])))
                        {
                            dlg_8 *dlg8 = new dlg_8(this);
                            dlg8->setWarning("宿舍楼号输入错误！");
                            dlg8->show();
                            return;
                        }
                        if(strlen(info.room)!=3 || !isdigit(info.room[0]) || !isdigit(info.room[1]) || !isdigit(info.room[2]))
                        {
                            dlg_8 *dlg8 = new dlg_8(this);
                            dlg8->setWarning("房间号输入错误！");
                            dlg8->show();
                            return;
                        }
                        if(strlen(info.tel)!=11)
                        {
                            dlg_8 *dlg8 = new dlg_8(this);
                            dlg8->setWarning("联系电话输入错误！");
                            dlg8->show();
                            return;
                        }
                        for(unsigned i = 0; i < strlen(info.tel); i++)
                        {
                            if(!isdigit(info.tel[i]))
                            {
                                dlg_8 *dlg8 = new dlg_8(this);
                                dlg8->setWarning("联系电话输入错误！");
                                dlg8->show();
                                return;
                            }
                        }
                        dormNode *p = head;
                        while(p->next)
                        {
                            if(strcmp(p->dorm.dormID,info.dorm))
                            {
                                p = p->next;
                                continue;
                            }
                            infoNode *pInfo = p->iNode;
                            while(pInfo)
                            {
                                if(!strcmp(pInfo->info.id,info.id))
                                {
                                    pInfo->info = info;
                                    return;
                                }
                                pInfo = pInfo->next;
                            }
                            break;
                        }
                        if(!(p->next))
                        {
                            dlg_8 *dlg8 = new dlg_8(this);
                            dlg8->setWarning("该宿舍楼不存在！");
                            dlg8->show();
                            return;
                        }
                        if(!pInfo)
                        {
                            dlg_8 *dlg8 = new dlg_8(this);
                            dlg8->setWindowTitle("修改学生基本信息");
                            dlg8->setWarning("该学生不存在！");
                            dlg8->show();
                        }
                    }
                    return;
                }
                pInfo = pInfo->next;
            }
            p = p->next;
        }
    }
}

//修改学生住宿缴费信息
void MainWindow::on_action_10_triggered()
{
    dlg_4 *dlg = new dlg_4(this);
    dlg->setWindowTitle("修改学生住宿缴费信息");
    dlg->show();
    if(dlg->exec()==QDialog::Accepted)
    {
        p = head;
        while(p->next)
        {
            pInfo = p->iNode;
            while(pInfo)
            {
                if(!strcmp(pInfo->info.id, id))
                {
                    pCost = pInfo->cNode;
                    unsigned n = 0;
                    dlg_9 *dlg9 = new dlg_9(this);
                    while(pCost)
                    {
                        dlg9->addLine(n, pCost, false);
                        n++;
                        pCost = pCost->next;
                    }
                    dlg9->show();
                    if(dlg9->exec()==QDialog::Accepted)
                    {
                        if(num<1 || num>n)
                        {
                            dlg_8 *dlg8 = new dlg_8(this);
                            dlg8->setWarning("序号输入错误!");
                            dlg8->show();
                            cout << num << endl;
                            cout << n << endl;
                            return;
                        }
                        pCost = pInfo->cNode;
                        for(unsigned i=1;i<num;i++)
                        {
                            pCost = pCost->next;
                        }
                        dlg_2 *dlg2 = new dlg_2(this);
                        dlg2->setWindowTitle("修改学生住宿缴费信息");
                        dlg2->update(pCost);
                        dlg2->show();
                        if(dlg2->exec()==QDialog::Accepted)
                        {
                            /*数据格式检查*/
                            if(strlen(cost.id)!=10 || !isalpha(cost.id[0]))
                            {
                                dlg_8 *dlg8 = new dlg_8(this);
                                dlg8->setWarning("学号输入错误！");
                                dlg8->show();
                                return;
                            }
                            for(unsigned i = 1; i < strlen(cost.id); i++)
                            {
                                if(!isdigit(cost.id[i]))
                                {
                                    dlg_8 *dlg8 = new dlg_8(this);
                                    dlg8->setWarning("学号输入错误！");
                                    dlg8->show();
                                    return;
                                }
                            }
                            if(!(strlen(cost.name)>0 && strlen(cost.name)<20))
                            {
                                dlg_8 *dlg8 = new dlg_8(this);
                                dlg8->setWarning("学生姓名输入错误！");
                                dlg8->show();
                                return;
                            }
                            for(unsigned i = 0; i < strlen(cost.name); i++)
                            {
                                if(!isalpha(cost.name[i]))
                                {
                                    dlg_8 *dlg8 = new dlg_8(this);
                                    dlg8->setWarning("学生姓名输入错误！");
                                    dlg8->show();
                                    return;
                                }
                            }
                            if(!(strlen(cost.payee)>0 && strlen(cost.payee)<20))
                            {
                                dlg_8 *dlg8 = new dlg_8(this);
                                dlg8->setWarning("收款人姓名输入错误！");
                                dlg8->show();
                                return;
                            }
                            for(unsigned i = 0; i < strlen(cost.payee); i++)
                            {
                                if(!isalpha(cost.payee[i]))
                                {
                                    dlg_8 *dlg8 = new dlg_8(this);
                                    dlg8->setWarning("收款人姓名输入错误！");
                                    dlg8->show();
                                    return;
                                }
                            }
                            pCost->cost = cost;
                        }
                    }
                    return;
                }
                pInfo = pInfo->next;
            }
            p = p->next;
        }
        dlg_8 *dlg8 = new dlg_8(this);
        dlg8->setWindowTitle("修改学生住宿缴费信息");
        dlg8->setWarning("该学生不存在！");
        dlg8->show();
    }
}

//修改宿舍楼基本信息
void MainWindow::on_action_11_triggered()
{
    dlg_7 *dlg7 = new dlg_7(this);
    dlg7->setWindowTitle("修改宿舍楼基本信息");
    dlg7->show();
    if(dlg7->exec()==QDialog::Accepted)
    {
        p = head;
        while(p->next)
        {
            if(!strcmp(p->dorm.dormID, dormID))
            {
                dlg_3 *dlg3 = new dlg_3(this);
                dlg3->update(p);
                dlg3->show();
                if(dlg3->exec()==QDialog::Accepted)
                {
                    /*输入数据格式检查*/
                    if(!(strlen(dorm.dormID)==4 && isalpha(dorm.dormID[0])&&(isalpha(dorm.dormID[1]))&&(isdigit(dorm.dormID[2]))&&isdigit(dorm.dormID[3])))
                    {
                        dlg_8 *dlg8 = new dlg_8(this);
                        dlg8->setWarning("宿舍楼号输入错误！");
                        dlg8->show();
                        return;
                    }
                    if(!(strlen(dorm.admin)>0 && strlen(dorm.admin)<20))
                    {
                        dlg_8 *dlg8 = new dlg_8(this);
                        dlg8->setWarning("栋长姓名输入错误！");
                        dlg8->show();
                        return;
                    }
                    for(unsigned i = 0; i < strlen(dorm.admin); i++)
                    {
                        if(!isalpha(dorm.admin[i]))
                        {
                            dlg_8 *dlg8 = new dlg_8(this);
                            dlg8->setWarning("栋长姓名输入错误！");
                            dlg8->show();
                            return;
                        }
                    }
                    if(strlen(dorm.tel)!=8)
                    {
                        dlg_8 *dlg8 = new dlg_8(this);
                        dlg8->setWarning("值班室电话输入错误！");
                        dlg8->show();
                        return;
                    }
                    for(unsigned i = 0; i < strlen(dorm.tel); i++)
                    {
                        if(!isdigit(dorm.tel[i]))
                        {
                            dlg_8 *dlg8 = new dlg_8(this);
                            dlg8->setWarning("值班室电话输入错误！");
                            dlg8->show();
                            return;
                        }
                    }
                    p->dorm = dorm;
                    dlg_8 *dlg8 = new dlg_8(this);
                    dlg8->setWindowTitle("修改宿舍楼基本信息");
                    dlg8->setWarning("修改成功！");
                    dlg8->show();
                    return;
                }
            }
            p = p->next;
        }
        dlg_8 *dlg8 = new dlg_8(this);
        dlg8->setWarning("该宿舍楼不存在！");
        dlg8->show();
        return;
    }
}

//删除学生基本信息
void MainWindow::on_action_12_triggered()
{
    dlg_4 *dlg = new dlg_4(this);
    dlg->setWindowTitle("删除学生基本信息");
    dlg->show();
    if(dlg->exec()==QDialog::Accepted)
    {
        p = head;
        while(p->next)
        {
            pInfo = p->iNode;
            if(!pInfo)
            {
                continue;
            }
            if(!strcmp(pInfo->info.id, id))
            {
                dlg_1 *dlg1 = new dlg_1(this);
                dlg1->setWindowTitle("删除学生基本信息");
                dlg1->query(pInfo);
                dlg1->show();
                if(dlg1->exec()==QDialog::Accepted)
                {
                    dlg_5 *dlg5 = new dlg_5(this);
                    dlg5->show();
                    if(dlg5->exec()==QDialog::Accepted)
                    {
                        p->iNode = pInfo->next;
                        return;
                    }
                }
                return;
            }
            while(pInfo->next)
            {
                if(!strcmp(id, pInfo->next->info.id))
                {
                    dlg_1 *dlg1 = new dlg_1(this);
                    dlg1->setWindowTitle("删除学生基本信息");
                    dlg1->query(pInfo->next);
                    dlg1->show();
                    if(dlg1->exec()==QDialog::Accepted)
                    {
                        dlg_5 *dlg5 = new dlg_5(this);
                        dlg5->show();
                        if(dlg5->exec()==QDialog::Accepted)
                        {
                            pInfo->next = pInfo->next->next;
                            return;
                        }
                    }
                    return;
                }
                pInfo = pInfo->next;
            }
            p = p->next;
        }
        dlg_8 *dlg8 = new dlg_8(this);
        dlg8->setWindowTitle("删除学生基本信息");
        dlg8->setWarning("该学生不存在！");
        dlg8->show();
    }
}

//删除学生住宿缴费信息
void MainWindow::on_action_13_triggered()
{
    dlg_4 *dlg = new dlg_4(this);
    dlg->setWindowTitle("删除学生住宿缴费信息");
    dlg->show();
    if(dlg->exec()==QDialog::Accepted)
    {
        p = head;
        while(p->next)
        {
            pInfo = p->iNode;
            while(pInfo)
            {
                if(!strcmp(pInfo->info.id, id))
                {
                    pCost = pInfo->cNode;
                    unsigned n = 0;
                    dlg_9 *dlg9 = new dlg_9(this);
                    dlg9->setWindowTitle("删除学生住宿缴费信息");
                    while(pCost)
                    {
                        dlg9->addLine(n, pCost, false);
                        n++;
                        pCost = pCost->next;
                    }
                    dlg9->show();
                    if(dlg9->exec()==QDialog::Accepted)
                    {
                        if(num<1 || num>=n)
                        {
                            dlg_8 *dlg8 = new dlg_8(this);
                            dlg8->setWarning("序号输入错误!");
                            dlg8->show();
                        }
                        dlg_5 *dlg5 = new dlg_5(this);
                        dlg5->setWindowTitle("删除学生住宿缴费信息");
                        dlg5->show();
                        if(dlg5->exec()==QDialog::Accepted)
                        {
                            pCost = pInfo->cNode;
                            if(!pCost)
                            {
                                return;
                            }
                            if(num==1)
                            {
                                pInfo->cNode = pCost->next;
                            }
                            for(unsigned i=1;i<num-1;i++)
                            {
                                pCost = pCost->next;
                            }
                            pCost->next = pCost->next->next;
                        }
                    }
                    return;
                }
                pInfo = pInfo->next;
            }
            p = p->next;
        }
        dlg_8 *dlg8 = new dlg_8(this);
        dlg8->setWindowTitle("修改学生住宿缴费信息");
        dlg8->setWarning("该学生不存在！");
        dlg8->show();
    }
}

//删除宿舍楼基本信息
void MainWindow::on_action_3_triggered()
{
    dlg_7 *dlg = new dlg_7(this);
    dlg->setWindowTitle("删除宿舍楼基本信息");
    dlg->show();
    if(dlg->exec()==QDialog::Accepted)
    {
        p = head;
        if(!strcmp(p->dorm.dormID, dormID))
        {
            dlg_3 *dlg3 = new dlg_3(this);
            dlg3->setWindowTitle("删除宿舍楼基本信息");
            dlg3->query(p->next);
            dlg3->show();
            if(dlg3->exec()==QDialog::Accepted)
            {
                dlg_5 *dlg5 = new dlg_5(this);
                dlg5->setWindowTitle("删除宿舍楼基本信息");
                dlg5->show();
                if(dlg5->exec()==QDialog::Accepted)
                {
                    head = p->next;
                    if(!head)
                    {
                        head = (dormNode *)malloc(sizeof(dormNode));
                        head->iNode = NULL;
                        head->next = NULL;
                    }
                }
            }
            return;
        }
        while(p->next->next)
        {
            if(!strcmp(p->next->dorm.dormID, dormID))
            {
                dlg_3 *dlg3 = new dlg_3(this);
                dlg3->setWindowTitle("删除宿舍楼基本信息");
                dlg3->query(p->next);
                dlg3->show();
                if(dlg3->exec()==QDialog::Accepted)
                {
                    dlg_5 *dlg5 = new dlg_5(this);
                    dlg5->setWindowTitle("删除宿舍楼基本信息");
                    dlg5->show();
                    if(dlg5->exec()==QDialog::Accepted)
                    {
                        p->next = p->next->next;
                        return;
                    }
                }
                return;
            }
            p = p->next;
        }
        dlg_8 *dlg8 = new dlg_8(this);
        dlg8->setWarning("该宿舍楼不存在！");
        dlg8->show();
    }
}

/*查询学生基本信息*/
void MainWindow::on_action_17_triggered()
{
    dlg_4 *dlg = new dlg_4(this);
    dlg->setWindowTitle("查询学生基本信息");
    dlg->show();
    if(dlg->exec()==QDialog::Accepted)
    {
        p = head;
        while(p->next)
        {
            pInfo = p->iNode;
            while(pInfo)
            {
                if(!strcmp(id, pInfo->info.id))
                {
                    dlg_1 *dlg1 = new dlg_1(this);
                    dlg1->setWindowTitle("查询学生基本信息");
                    dlg1->query(pInfo);
                    dlg1->show();
                    return;
                }
                pInfo = pInfo->next;
            }
            p = p->next;
        }
        dlg_8 *dlg8 = new dlg_8(this);
        dlg8->setWindowTitle("查询学生基本信息");
        dlg8->setWarning("该学生不存在！");
        dlg8->show();
    }
}
void MainWindow::on_pushButton_clicked()
{
    strcpy(id, ui->lineEdit->text().toLocal8Bit().data());
    p = head;
    while(p->next)
    {
        pInfo = p->iNode;
        while(pInfo)
        {
            if(!strcmp(id, pInfo->info.id))
            {
                dlg_1 *dlg1 = new dlg_1(this);
                dlg1->setWindowTitle("查询学生基本信息");
                dlg1->query(pInfo);
                dlg1->show();
                return;
            }
            pInfo = pInfo->next;
        }
        p = p->next;
    }
    dlg_8 *dlg8 = new dlg_8(this);
    dlg8->setWindowTitle("查询学生基本信息");
    dlg8->setWarning("该学生不存在！");
    dlg8->show();
}

/*查询学生住宿缴费信息*/
void MainWindow::on_action_20_triggered()
{
    dlg_4 *dlg = new dlg_4(this);
    dlg->setWindowTitle("查询学生住宿缴费信息");
    dlg->show();
    if(dlg->exec()==QDialog::Accepted)
    {
        p = head;
        while(p->next)
        {
            pInfo = p->iNode;
            while(pInfo)
            {
                if(!strcmp(pInfo->info.id, id))
                {
                    pCost = pInfo->cNode;
                    int n = 0;
                    dlg_9 *dlg9 = new dlg_9(this);
                    while(pCost)
                    {
                        dlg9->addLine(n, pCost, true);
                        n++;
                        pCost = pCost->next;
                    }
                    dlg9->show();
                    return;
                }
                pInfo = pInfo->next;
            }
            p = p->next;
        }
        dlg_8 *dlg8 = new dlg_8(this);
        dlg8->setWindowTitle("查询学生住宿缴费信息");
        dlg8->setWarning("该学生不存在！");
        dlg8->show();
    }
}
void MainWindow::on_pushButton_2_clicked()
{
    strcpy(id, ui->lineEdit_2->text().toLocal8Bit().data());
    p = head;
    while(p->next)
    {
        pInfo = p->iNode;
        while(pInfo)
        {
            if(!strcmp(pInfo->info.id, id))
            {
                pCost = pInfo->cNode;
                int n = 0;
                dlg_9 *dlg9 = new dlg_9(this);
                while(pCost)
                {
                    dlg9->addLine(n, pCost, true);
                    n++;
                    pCost = pCost->next;
                }
                dlg9->show();
                return;
            }
            pInfo = pInfo->next;
        }
        p = p->next;
    }
    dlg_8 *dlg8 = new dlg_8(this);
    dlg8->setWindowTitle("查询学生住宿缴费信息");
    dlg8->setWarning("该学生不存在！");
    dlg8->show();
}

/*查询一个班级所有学生的住宿缴费信息*/
void MainWindow::on_action_21_triggered()
{
    dlg_6 *dlg = new dlg_6(this);
    dlg->show();
    if(dlg->exec()==QDialog::Accepted)
    {
        /*建立指向同一个班级的学生的指针链表*/
        CLASS *head_c = (CLASS *)malloc(sizeof(CLASS));
        CLASS *p_c = head_c;
        p_c->next = NULL;
        p = head;
        while(p->next)
        {
            pInfo = p->iNode;
            while(pInfo)
            {
                if(!strcmp(pInfo->info.Class, c))
                {
                    p_c->p = pInfo;
                    p_c->next = (CLASS *)malloc(sizeof(CLASS));
                    p_c = p_c->next;
                    p_c->next = NULL;
                }
                pInfo = pInfo->next;
            }
            p = p->next;
        }
        /*对指针链表进行排序*/
        p_c = head_c;
        if(p_c->next==NULL)
        {
            dlg_8 *dlg8 = new dlg_8(this);
            dlg8->setWarning("该班级不存在！");    /*班级学生链表为空，班级不存在*/
            dlg8->show();
            return;
        }
        int swapped = 1;  /*记录本次循环是否有交换发生*/
        while(swapped)
        {
            swapped = 0;
            p_c = head_c;
            while(p_c->next->next)
            {
                if(strcmp(p_c->p->info.id, p_c->next->p->info.id)>0)
                {
                    infoNode *t = p_c->p;
                    p_c->p = p_c->next->p;
                    p_c->next->p = t;
                    swapped = 1;
                }
                p_c = p_c->next;
            }
        }
        /*按学号从小到大输出*/
        p_c = head_c;
        dlg_9 *dlg9 = new dlg_9(this);
        int n = 0;
        while(p_c->next)
        {
            pCost = p_c->p->cNode;
            while(pCost)
            {
                unsigned height = 70 + n*30;
                dlg9->addLine(height, pCost, true);
                pCost = pCost->next;
                n++;
            }
            p_c = p_c->next;
        }
        dlg9->show();
        return;
    }
}
void MainWindow::on_pushButton_3_clicked()
{
    strcpy(c, ui->lineEdit_3->text().toLocal8Bit().data());
    /*建立指向同一个班级的学生的指针链表*/
    CLASS *head_c = (CLASS *)malloc(sizeof(CLASS));
    CLASS *p_c = head_c;
    p_c->next = NULL;
    p = head;
    while(p->next)
    {
        pInfo = p->iNode;
        while(pInfo)
        {
            if(!strcmp(pInfo->info.Class, c))
            {
                p_c->p = pInfo;
                p_c->next = (CLASS *)malloc(sizeof(CLASS));
                p_c = p_c->next;
                p_c->next = NULL;
            }
            pInfo = pInfo->next;
        }
        p = p->next;
    }
    /*对指针链表进行排序*/
    p_c = head_c;
    if(p_c->next==NULL)
    {
        dlg_8 *dlg8 = new dlg_8(this);
        dlg8->setWarning("该班级不存在！");    /*班级学生链表为空，班级不存在*/
        dlg8->show();
        return;
    }
    int swapped = 1;  /*记录本次循环是否有交换发生*/
    while(swapped)
    {
        swapped = 0;
        p_c = head_c;
        while(p_c->next->next)
        {
            if(strcmp(p_c->p->info.id, p_c->next->p->info.id)>0)
            {
                infoNode *t = p_c->p;
                p_c->p = p_c->next->p;
                p_c->next->p = t;
                swapped = 1;
            }
            p_c = p_c->next;
        }
    }
    /*按学号从小到大输出*/
    p_c = head_c;
    dlg_9 *dlg9 = new dlg_9(this);
    int n = 0;
    while(p_c->next)
    {
        pCost = p_c->p->cNode;
        while(pCost)
        {
            unsigned height = 70 + n*30;
            dlg9->addLine(height, pCost, true);
            pCost = pCost->next;
            n++;
        }
        p_c = p_c->next;
    }
    dlg9->show();
    return;
}

/*查询宿舍楼基本信息*/
void MainWindow::on_action_19_triggered()
{
    dlg_7 *dlg = new dlg_7(this);
    dlg->show();
    if(dlg->exec()==QDialog::Accepted)
    {
        p = head;
        while(p->next)
        {
            if(!strcmp(p->dorm.dormID, dormID))
            {
                dlg_3 *dlg3 = new dlg_3(this);
                dlg3->setWindowTitle("查询宿舍楼基本信息");
                dlg3->query(p);
                dlg3->show();
                return;
            }
            p = p->next;
        }
        dlg_8 *dlg8 = new dlg_8(this);
        dlg8->setWarning("该宿舍楼不存在！");
        dlg8->show();
    }
}
void MainWindow::on_pushButton_4_clicked()
{
    strcpy(dormID, ui->lineEdit_4->text().toLocal8Bit().data());
    p = head;
    while(p->next)
    {
        if(!strcmp(p->dorm.dormID, dormID))
        {
            dlg_3 *dlg3 = new dlg_3(this);
            dlg3->setWindowTitle("查询宿舍楼基本信息");
            dlg3->query(p);
            dlg3->show();
            return;
        }
        p = p->next;
    }
    dlg_8 *dlg8 = new dlg_8(this);
    dlg8->setWarning("该宿舍楼不存在！");
    dlg8->show();
}

//close
void MainWindow::closeEvent(QCloseEvent *e)
{
    if(e)
    {
        dormNode *p;
        infoNode *pInfo;
        costNode *pCost;
        FILE *f1, *f2, *f3;
        f1 = fopen("info.txt", "w");
        f2 = fopen("cost.txt", "w");
        f3 = fopen("dorm.txt", "w");
        if(f1==NULL || f2==NULL || f3==NULL)
        {
            cout << "文件打开失败" << endl;
            exit(0);
        }
        if(fgetc(f3)==EOF)
        {
            fprintf(f3, "%-20s%-30s%-30s%-20s%-20s%-7s\n", "宿舍楼号", "栋长姓名", "值班室电话", "房间数", "床位数", "每床位年住宿费");
        }
        if(fgetc(f1)==EOF)
        {
            fprintf(f1, "%-22s%-32s%-12s%-29s%-30s%-12s%-24s%-20s%-17s%-19s%-13s%-30s\n", "学号", "姓名", "性别", "出生日期", "类别", "学制", "入学时间", "年级", "班级", "宿舍楼号", "房间号", "联系电话");
        }
        if(fgetc(f2)==EOF)
        {
            fprintf(f2, "%-20s%-24s%-29s%-21s%-28s%-25s\n", "学号", "  姓名", "缴费日期", "缴费金额", "用途", "收款人");
        }
        fseek(f1, 0, SEEK_END);
        fseek(f2, 0, SEEK_END);
        fseek(f3, 0, SEEK_END);
        p = head;
        while(p->next)
        {
            fprintf(f3, "%-16s%-26s%-25s%-17hd%-17hd%-4.2f\n", p->dorm.dormID, p->dorm.admin, p->dorm.tel, p->dorm.NumOfRoom, p->dorm.NumOfBed, p->dorm.fee);
            pInfo = p->iNode;
            while(pInfo)
            {
                fprintf(f1, "%-20s%-30s%-10c%-25s%-30s%-10hd%-20s%-20s%-15s%-15s%-10s%-30s\n", pInfo->info.id, pInfo->info.name, pInfo->info.gender, pInfo->info.birth, pInfo->info.type, pInfo->info.studyTime, pInfo->info.admittedTime, pInfo->info.grade, pInfo->info.Class, pInfo->info.dorm, pInfo->info.room, pInfo->info.tel);
                pCost = pInfo->cNode;
                while(pCost)
                {
                    fprintf(f2, "%-20s%-20s%-25s%-4.2f          %-30s%-30s\n", pCost->cost.id, pCost->cost.name, pCost->cost.date, pCost->cost.cost, pCost->cost.use, pCost->cost.payee);
                    pCost = pCost->next;
                }
                pInfo = pInfo->next;
            }
            p = p->next;
        }
        fclose(f1);
        fclose(f2);
        fclose(f3);
    }
}

//统计宿舍楼入住情况
void MainWindow::on_action_22_triggered()
{
    liveNode *h_l = (liveNode *)malloc(sizeof(liveNode));
    liveNode *p_l = h_l;
    p_l->next = NULL;
    p = head;
    while(p->next)
    {
        strcpy(p_l->live.dormID, p->dorm.dormID);
        p_l->live.canlive = p->dorm.NumOfBed;
        unsigned n=0;
        pInfo = p->iNode;
        while(pInfo)
        {
            n++;
            pInfo = pInfo->next;
        }
        p_l->live.inlive = n;
        p_l->live.emptybed = p_l->live.canlive - n;
        p_l->live.rate = (double)n/p_l->live.canlive;
        p_l->next = (liveNode *)malloc(sizeof(liveNode));
        p_l = p_l->next;
        p_l->next = NULL;
        p = p->next;
    }
    p_l = h_l;
    int swapped=1;
    while(swapped)
    {
        swapped = 0;
        if(p_l->next==NULL)
        {
            dlg_8 *dlg8 = new dlg_8(this);
            dlg8->setWarning("您还没有录入任何宿舍楼！");
            dlg8->show();
            return;
        }
        if(p_l->next->next==NULL)
        {
            break;
        }
        while(p_l->next->next)
        {
            if(p_l->live.rate<p_l->next->live.rate)
            {
                liveSta t = p_l->live;
                p_l->live = p_l->next->live;
                p_l->next->live = t;
                swapped = 1;
            }
            p_l = p_l->next;
        }
        p_l = h_l;
    }
    dlg_10 *dlg = new dlg_10(this);
    dlg->display(h_l);
    dlg->show();
}

//统计各年级在住学生
void MainWindow::on_action_23_triggered()
{
    Types t[8];
    for(unsigned i=0;i<8;i++)
    {
        t[i].benke = 0;
        t[i].boshi = 0;
        t[i].shuoshi = 0;
        t[i].zhuan = 0;
    }
    strcpy(t[0].sex, "男");
    strcpy(t[0].grade, "大一");
    strcpy(t[1].sex, "男");
    strcpy(t[1].grade, "大二");
    strcpy(t[2].sex, "男");
    strcpy(t[2].grade, "大三");
    strcpy(t[3].sex, "男");
    strcpy(t[3].grade, "大四");
    strcpy(t[4].sex, "女");
    strcpy(t[4].grade, "大一");
    strcpy(t[5].sex, "女");
    strcpy(t[5].grade, "大二");
    strcpy(t[6].sex, "女");
    strcpy(t[6].grade, "大三");
    strcpy(t[7].sex, "女");
    strcpy(t[7].grade, "大四");
    p = head;
    while(p->next)
    {
        pInfo = p->iNode;
        while(pInfo)
        {
            if(pInfo->info.gender=='m')
            {
                if(!strcmp(pInfo->info.grade, "大一"))
                {
                    if(!strcmp(pInfo->info.type, "本科"))
                    {
                        t[0].benke++;
                    }
                    if(!strcmp(pInfo->info.type, "专科"))
                    {
                        t[0].zhuan++;
                    }
                    if(!strcmp(pInfo->info.type, "博士研究生"))
                    {
                        t[0].boshi++;
                    }
                    if(!strcmp(pInfo->info.type, "硕士研究生"))
                    {
                        t[0].shuoshi++;
                    }
                }
                if(!strcmp(pInfo->info.grade, "大二"))
                {
                    if(!strcmp(pInfo->info.type, "本科"))
                    {
                        t[1].benke++;
                    }
                    if(!strcmp(pInfo->info.type, "专科"))
                    {
                        t[1].zhuan++;
                    }
                    if(!strcmp(pInfo->info.type, "博士研究生"))
                    {
                        t[1].boshi++;
                    }
                    if(!strcmp(pInfo->info.type, "硕士研究生"))
                    {
                        t[1].shuoshi++;
                    }
                }
                if(!strcmp(pInfo->info.grade, "大三"))
                {
                    if(!strcmp(pInfo->info.type, "本科"))
                    {
                        t[2].benke++;
                    }
                    if(!strcmp(pInfo->info.type, "专科"))
                    {
                        t[2].zhuan++;
                    }
                    if(!strcmp(pInfo->info.type, "博士研究生"))
                    {
                        t[2].boshi++;
                    }
                    if(!strcmp(pInfo->info.type, "硕士研究生"))
                    {
                        t[2].shuoshi++;
                    }
                }
                if(!strcmp(pInfo->info.grade, "大四"))
                {
                    if(!strcmp(pInfo->info.type, "本科"))
                    {
                        t[3].benke++;
                    }
                    if(!strcmp(pInfo->info.type, "专科"))
                    {
                        t[3].zhuan++;
                    }
                    if(!strcmp(pInfo->info.type, "博士研究生"))
                    {
                        t[3].boshi++;
                    }
                    if(!strcmp(pInfo->info.type, "硕士研究生"))
                    {
                        t[3].shuoshi++;
                    }
                }
            }
            if(pInfo->info.gender=='f')
            {
                if(!strcmp(pInfo->info.grade, "大一"))
                {
                    if(!strcmp(pInfo->info.type, "本科"))
                    {
                        t[4].benke++;
                    }
                    if(!strcmp(pInfo->info.type, "专科"))
                    {
                        t[4].zhuan++;
                    }
                    if(!strcmp(pInfo->info.type, "博士研究生"))
                    {
                        t[4].boshi++;
                    }
                    if(!strcmp(pInfo->info.type, "硕士研究生"))
                    {
                        t[4].shuoshi++;
                    }
                }
                if(!strcmp(pInfo->info.grade, "大二"))
                {
                    if(!strcmp(pInfo->info.type, "本科"))
                    {
                        t[5].benke++;
                    }
                    if(!strcmp(pInfo->info.type, "专科"))
                    {
                        t[5].zhuan++;
                    }
                    if(!strcmp(pInfo->info.type, "博士研究生"))
                    {
                        t[5].boshi++;
                    }
                    if(!strcmp(pInfo->info.type, "硕士研究生"))
                    {
                        t[5].shuoshi++;
                    }
                }
                if(!strcmp(pInfo->info.grade, "大三"))
                {
                    if(!strcmp(pInfo->info.type, "本科"))
                    {
                        t[6].benke++;
                    }
                    if(!strcmp(pInfo->info.type, "专科"))
                    {
                        t[6].zhuan++;
                    }
                    if(!strcmp(pInfo->info.type, "博士研究生"))
                    {
                        t[6].boshi++;
                    }
                    if(!strcmp(pInfo->info.type, "硕士研究生"))
                    {
                        t[6].shuoshi++;
                    }
                }
                if(!strcmp(pInfo->info.grade, "大四"))
                {
                    if(!strcmp(pInfo->info.type, "本科"))
                    {
                        t[7].benke++;
                    }
                    if(!strcmp(pInfo->info.type, "专科"))
                    {
                        t[7].zhuan++;
                    }
                    if(!strcmp(pInfo->info.type, "博士研究生"))
                    {
                        t[7].boshi++;
                    }
                    if(!strcmp(pInfo->info.type, "硕士研究生"))
                    {
                        t[7].shuoshi++;
                    }
                }
            }
            pInfo = pInfo->next;
        }
        p = p->next;
    }
    dlg_11 *dlg11 = new dlg_11(this);
    dlg11->display(t);
    dlg11->show();
}

//统计宿舍楼住宿费收入
void MainWindow::on_action_24_triggered()
{
    Fees *h_f = (Fees *)malloc(sizeof(Fees));
    Fees *p_f = h_f;
    p_f->next = NULL;
    p_f->f = NULL;
    p = head;
    while(p->next)
    {
        strcpy(p_f->dormID, p->dorm.dormID);
        p_f->f = (Fee *)malloc(sizeof(Fee));
        strcpy(p_f->f->y, "2015");
        p_f->f->fee = 0;
        p_f->f->next = (Fee *)malloc(sizeof(Fee));
        strcpy(p_f->f->next->y, "2016");
        p_f->f->next->fee = 0;
        p_f->f->next->next = NULL;
        pInfo = p->iNode;
        while(pInfo)
        {
            pCost = pInfo->cNode;
            while(pCost)
            {
                char s[5];
                strncpy(s, pCost->cost.use, 4);
                s[4]='\0';
                cout << s << endl;
                if(!strcmp(s, "2015"))
                {
                    cout << s << endl;
                    p_f->f->fee += pCost->cost.cost;
                }
                if(!strcmp(s, "2016"))
                {
                    p_f->f->next->fee += pCost->cost.cost;
                }
                pCost = pCost->next;
            }
            pInfo = pInfo->next;
        }
        p_f->next = (Fees *)malloc(sizeof(Fees));
        p_f = p_f->next;
        p_f->next = NULL;
        p = p->next;
    }
    dlg_12 *dlg12 = new dlg_12(this);
    dlg12->display(h_f);
    dlg12->show();
}

//统计欠缴住宿费学生
void MainWindow::on_action_25_triggered()
{
    p = head;
    OWE *h_o = (OWE *)malloc(sizeof(OWE));
    OWE *p_o = h_o;
    p_o->next = NULL;
    while(p->next)
    {
        pInfo = p->iNode;
        while(pInfo)
        {
            char s[5];
            strncpy(s, pInfo->info.admittedTime, 4);
            s[4]='\0';
            unsigned origin=QString(s).toInt();
            QDateTime d = QDateTime::currentDateTime();
            unsigned current=d.toString("yyyy").toInt();
            for(unsigned i=origin;i<current;i++)
            {
                double due=p->dorm.fee;
                pCost = pInfo->cNode;
                while (pCost)
                {
                    strncpy(s, pCost->cost.date, 4);
                    s[4]='\0';
                    unsigned time=QString(s).toInt();
                    if(time==i)
                    {
                        if(pCost->cost.cost<due)
                        {
                            strcpy(p_o->dorm, pInfo->info.dorm);
                            strcpy(p_o->id, pInfo->info.id);
                            strcpy(p_o->name, pInfo->info.name);
                            p_o->fee = due - pCost->cost.cost;
                            p_o->year = i;
                            p_o->next = (OWE *)malloc(sizeof(OWE));
                            p_o = p_o->next;
                            p_o->next = NULL;
                        }
                        break;
                    }
                    pCost = pCost->next;
                }
                if(!pCost)
                {
                    strcpy(p_o->dorm, pInfo->info.dorm);
                    strcpy(p_o->id, pInfo->info.id);
                    strcpy(p_o->name, pInfo->info.name);
                    p_o->fee = due;
                    p_o->year = i;
                    p_o->next = (OWE *)malloc(sizeof(OWE));
                    p_o = p_o->next;
                    p_o->next = NULL;
                }
            }
            pInfo = pInfo->next;
        }
        p = p->next;
    }
    dlg_13 *dlg13=new dlg_13(this);
    dlg13->display(h_o);
    dlg13->show();
}

//统计班级宿舍楼分布
void MainWindow::on_action_26_triggered()
{
    CLASS_DORM *h_c = (CLASS_DORM *)malloc(sizeof(CLASS_DORM));
    CLASS_DORM *p_c = h_c;
    ROOM *p_r = NULL;
    ROOM *p_r_2 = NULL;
    ROOM *p_r_3 = NULL;
    p_c->next = NULL;
    p_c->roomNode = NULL;
    p = head;
    while(p->next)
    {
        pInfo = p->iNode;
        while(pInfo)
        {
            p_c = h_c;
            while(strcmp(p_c->Class, pInfo->info.Class) && p_c->next)
            {
                p_c = p_c->next;
            }
            strcpy(p_c->Class, pInfo->info.Class);
            if(p_c->next==NULL)
            {
                p_c->next = (CLASS_DORM *)malloc(sizeof(CLASS_DORM));
                p_c->next->next = NULL;
                p_c->roomNode = NULL;
            }
            char room[10];
            strcpy(room, pInfo->info.dorm);
            strcat(room, "-");
            strcat(room, pInfo->info.room);
            p_r = (ROOM *)malloc(sizeof(ROOM));
            strcpy(p_r->room, room);
            p_r->next = p_c->roomNode;
            p_c->roomNode = p_r;
            pInfo = pInfo->next;
        }
        p = p->next;
    }
    p_c = h_c;
    while(p_c->next)
    {
        p_r = p_c->roomNode;
        while(p_r)
        {
            p_r_2 = p_r->next;
            p_r_3 = p_r;
            while(p_r_2)
            {
                if(!strcmp(p_r_2->room, p_r->room))
                {
                    p_r_3->next = p_r_2->next;
                }
                p_r_2 = p_r_2->next;
                p_r_3 = p_r_3->next;
            }
            p_r = p_r->next;
        }
        p_c = p_c->next;
    }
    dlg_14 *dlg14 = new dlg_14(this);
    dlg14->display(h_c);
    dlg14->show();
}

//文件编辑功能
//学生基本信息
void MainWindow::on_action_4_triggered()
{
    WinExec("notepad info.txt", SW_SHOW);
}
//住宿缴费信息
void MainWindow::on_action_5_triggered()
{
    WinExec("notepad cost.txt", SW_SHOW);
}
//宿舍楼基本信息
void MainWindow::on_action_18_triggered()
{
    WinExec("notepad dorm.txt", SW_SHOW);
}

//数据备份
void MainWindow::on_action_15_triggered()
{
    WinExec("cmd.exe /c if not exist backup md backup", SW_HIDE);
    WinExec("cmd.exe /c if exist backup/info.txt del info.txt", SW_HIDE);
    WinExec("cmd.exe /c if exist backup/cost.txt del oost.txt", SW_HIDE);
    WinExec("cmd.exe /c if exist backup/dorm.txt del dorm.txt", SW_HIDE);
    WinExec("cmd.exe /c copy info.txt backup", SW_HIDE);
    WinExec("cmd.exe /c copy cost.txt backup", SW_HIDE);
    WinExec("cmd.exe /c copy dorm.txt backup", SW_HIDE);
}

//数据恢复
void MainWindow::on_action_16_triggered()
{
    WinExec("cmd.exe /c if exist backup del info.txt", SW_HIDE);
    WinExec("cmd.exe /c if exist backup del cost.txt", SW_HIDE);
    WinExec("cmd.exe /c if exist backup del dorm.txt", SW_HIDE);
    WinExec("cmd.exe /c copy backup/info.txt .", SW_HIDE);
    WinExec("cmd.exe /c copy backup/cost.txt .", SW_HIDE);
    WinExec("cmd.exe /c copy backup/dorm.txt .", SW_HIDE);
}

//帮助主题
void MainWindow::on_action_triggered()
{
    dlg_15 *dlg15 = new dlg_15(this);
    dlg15->show();
}

//关于
void MainWindow::on_action_2_triggered()
{
    dlg_16 *dlg16 = new dlg_16(this);
    dlg16->show();
}

//退出
void MainWindow::on_action_Ctrl_Q_triggered()
{
    dormNode *p;
    infoNode *pInfo;
    costNode *pCost;
    FILE *f1, *f2, *f3;
    f1 = fopen("info.txt", "w");
    f2 = fopen("cost.txt", "w");
    f3 = fopen("dorm.txt", "w");
    if(f1==NULL || f2==NULL || f3==NULL)
    {
        cout << "文件打开失败" << endl;
        exit(0);
    }
    if(fgetc(f3)==EOF)
    {
        fprintf(f3, "%-20s%-30s%-30s%-20s%-20s%-7s\n", "宿舍楼号", "栋长姓名", "值班室电话", "房间数", "床位数", "每床位年住宿费");
    }
    if(fgetc(f1)==EOF)
    {
        fprintf(f1, "%-20s%-30s%-10s%-25s%-30s%-10s%-20s%-20s%-15s%-15s%-10s%-30s\n", "学号", "姓名", "性别", "出生日期", "类别", "学制", "入学时间", "年级", "班级", "宿舍楼号", "房间号", "联系电话");
    }
    if(fgetc(f2)==EOF)
    {
        fprintf(f2, "%-20s%-20s%-25s%-25s%-25s%-25s\n", "学号", "姓名", "缴费日期", "缴费金额", "用途", "收款人");
    }
    fseek(f1, 0, SEEK_END);
    fseek(f2, 0, SEEK_END);
    fseek(f3, 0, SEEK_END);
    p = head;
    while(p->next)
    {
        fprintf(f3, "%-16s%-26s%-25s%-17hd%-17hd%-4.2f\n", p->dorm.dormID, p->dorm.admin, p->dorm.tel, p->dorm.NumOfRoom, p->dorm.NumOfBed, p->dorm.fee);
        pInfo = p->iNode;
        while(pInfo)
        {
            fprintf(f1, "%-20s%-30s%-10c%-25s%-30s%-10hd%-20s%-20s%-15s%-15s%-10s%-30s\n", pInfo->info.id, pInfo->info.name, pInfo->info.gender, pInfo->info.birth, pInfo->info.type, pInfo->info.studyTime, pInfo->info.admittedTime, pInfo->info.grade, pInfo->info.Class, pInfo->info.dorm, pInfo->info.room, pInfo->info.tel);
            pCost = pInfo->cNode;
            while(pCost)
            {
                fprintf(f2, "%-20s%-20s%-25s%-4.2f          %-30s%-30s\n", pCost->cost.id, pCost->cost.name, pCost->cost.date, pCost->cost.cost, pCost->cost.use, pCost->cost.payee);
                pCost = pCost->next;
            }
            pInfo = pInfo->next;
        }
        p = p->next;
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    exit(0);
}
