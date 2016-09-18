#ifndef DLG_1_H
#define DLG_1_H

#include <QDialog>
#include "dlg_3.h"

namespace Ui {
class dlg_1;
}

class dlg_1 : public QDialog
{
    Q_OBJECT

private slots:
    void on_pushButton_clicked();

public:
    explicit dlg_1(QWidget *parent = 0);
    ~dlg_1();
    void query(infoNode *pInfo);
    void update(infoNode *pInfo);

public:
    Ui::dlg_1 *ui;
};

#endif // DLG_1_H
