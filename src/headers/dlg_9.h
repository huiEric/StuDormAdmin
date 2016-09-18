#ifndef DLG_9_H
#define DLG_9_H

#include <QDialog>
#include "main.h"

namespace Ui {
class dlg_9;
}

class dlg_9 : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_9(QWidget *parent = 0);
    ~dlg_9();
    void addLine(unsigned n, costNode *pCost, bool q);

private slots:
    void on_pushButton_clicked();

private:
    Ui::dlg_9 *ui;
};

#endif // DLG_9_H
