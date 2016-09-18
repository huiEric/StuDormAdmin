#ifndef DLG_3_H
#define DLG_3_H

#include <QDialog>

struct INFO{
    char id[12];
    char name[20];
    char gender;
    char birth[12];
    char type[30];
    short studyTime;
    char admittedTime[8];
    char Class[10];
    char dorm[5];
    char room[5];
    char tel[20];
    char grade[20];
};
typedef struct INFO INFO;
struct COST{
    char id[12];
    char name[20];
    char date[12];
    float cost;
    char use[20];
    char payee[20];
};
typedef struct COST COST;
struct DORM{
    char dormID[5];
    char admin[20];
    char tel[20];
    short NumOfRoom;
    short NumOfBed;
    float fee;
};
typedef struct DORM DORM;
struct costNode{
    COST cost;
    struct costNode *next;
};
typedef struct costNode costNode;
struct infoNode{
    INFO info;
    costNode *cNode;
    struct infoNode *next;
};
typedef struct infoNode infoNode;
struct dormNode{
    DORM dorm;
    infoNode *iNode;
    struct dormNode *next;
};
typedef struct dormNode dormNode;
struct liveSta{
    char dormID[5];
    short canlive;
    short inlive;
    short emptybed;
    double rate;
};
typedef struct liveSta liveSta;
struct liveNode{
    liveSta live;
    struct liveNode *next;
};
typedef struct liveNode liveNode;
struct Types{
    char sex[10];
    char grade[20];
    unsigned zhuan;
    unsigned boshi;
    unsigned shuoshi;
    unsigned benke;
};
typedef struct Types Types;
struct Fee{
    char y[5];
    double fee;
    struct Fee *next;
};
typedef struct Fee Fee;
struct Fees{
    char dormID[5];
    Fee *f;
    struct Fees *next;
};
typedef struct Fees Fees;
struct OWE{
    char id[12];
    char name[20];
    char dorm[5];
    unsigned year;
    double fee;
    struct OWE *next;
};
typedef struct OWE OWE;
struct ROOM{
    char room[10];
    struct ROOM *next;
};
typedef struct ROOM ROOM;
struct CLASS_DORM{
    char Class[10];
    ROOM *roomNode;
    struct CLASS_DORM *next;
};
typedef struct CLASS_DORM CLASS_DORM;

namespace Ui {
class dlg_3;
}

class dlg_3 : public QDialog
{
    Q_OBJECT

private slots:
    void on_pushButton_clicked();

public:
    explicit dlg_3(QWidget *parent = 0);
    ~dlg_3();
    void query(dormNode *p);
    void update(dormNode *p);

private:
    Ui::dlg_3 *ui;
};

#endif // DLG_3_H
