#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include "dlg_1.h"
#include "dlg_2.h"
#include "dlg_3.h"
#include "main.h"
#include <QTextStream>

dormNode *head;
void Load();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    Load();

    MainWindow w;
    w.show();

    return a.exec();
}

//ÔØÈëÊý¾Ý
void Load()
{
    head = (dormNode *)malloc(sizeof(dormNode));
    dormNode *p = head;
    p->next = NULL;
    p->iNode = NULL;
    infoNode *pInfo;
    costNode *pCost;
    char *s = (char *)malloc(100*sizeof(char));
    FILE *f1, *f2, *f3;
    f1 = fopen("info.txt", "r");
    f2 = fopen("cost.txt", "r");
    f3 = fopen("dorm.txt", "r");
    if(f3)
    {
        fscanf(f3, "%s%s%s%s%s%s", s, s, s, s, s, s);
        while(fgetc(f3)!=EOF)
        {
            fscanf(f3, "%s%s%s%hd%hd%f", p->dorm.dormID, p->dorm.admin,p->dorm.tel, &(p->dorm.NumOfRoom), &(p->dorm.NumOfBed), &(p->dorm.fee));
            if(p->dorm.NumOfRoom==0 || p->dorm.fee==0)
            {
                break;
            }
            p->next = (dormNode *)malloc(sizeof(dormNode));
            p->next->iNode = NULL;
            p->next->next = NULL;
            p = p->next;
        }
    }
    if(f1)
    {
        fscanf(f1, "%s%s%s%s%s%s%s%s%s%s%s%s", s, s, s, s, s, s, s, s, s, s, s, s);
        while(fgetc(f1)!=EOF)
        {
            pInfo = (infoNode *)malloc(sizeof(infoNode));
            pInfo->cNode = NULL;
            pInfo->next = NULL;
            fscanf(f1, "%s", s);
            strcpy(pInfo->info.id, s);
            fscanf(f1, "%s", s);
            strcpy(pInfo->info.name, s);
            fscanf(f1, "%s%c%s%s%hd%s%s%s%s%s%s", s, &(pInfo->info.gender), pInfo->info.birth, pInfo->info.type, &(pInfo->info.studyTime), pInfo->info.admittedTime, pInfo->info.grade, pInfo->info.Class, pInfo->info.dorm, pInfo->info.room, pInfo->info.tel);
            pInfo->info.gender = *s;
            if(strlen(pInfo->info.id)!=10)
            {
                break;
            }
            p = head;
            while(p->next)
            {
                if(!strcmp(p->dorm.dormID, pInfo->info.dorm))
                {
                    pInfo->next = p->iNode;
                    p->iNode = pInfo;
                    break;
                }
                p = p->next;
            }
        }
    }
    if(f2)
    {
        fscanf(f2, "%s%s%s%s%s%s", s, s, s, s, s, s);
        while(fgetc(f2)!=EOF)
        {
            pCost = (costNode *)malloc(sizeof(costNode));
            pCost->next = NULL;
            fscanf(f2, "%s%s%s%f%s%s", pCost->cost.id, pCost->cost.name, pCost->cost.date, &(pCost->cost.cost), pCost->cost.use, pCost->cost.payee);
            p = head;
            while(p->next)
            {
                pInfo = p->iNode;
                while(pInfo)
                {
                    if(!strcmp(pInfo->info.id, pCost->cost.id))
                    {
                        pCost->next = pInfo->cNode;
                        pInfo->cNode = pCost;
                        goto end;
                    }
                    pInfo = pInfo->next;
                }
                p = p->next;
            }
end:
            p = head;
        }
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    free(s);
}

