#ifndef DLG_2_H
#define DLG_2_H

#include <QDialog>
#include "dlg_3.h"

namespace Ui {
class dlg_2;
}

class dlg_2 : public QDialog
{
    Q_OBJECT

private slots:
    void on_pushButton_clicked();
    //void query(costNode *pCost);

public:
    explicit dlg_2(QWidget *parent = 0);
    ~dlg_2();
    void update(costNode *pCost);

private:
    Ui::dlg_2 *ui;
};

#endif // DLG_2_H
