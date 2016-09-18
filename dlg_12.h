#ifndef DLG_12_H
#define DLG_12_H

#include <QDialog>
#include "dlg_3.h"

namespace Ui {
class dlg_12;
}

class dlg_12 : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_12(QWidget *parent = 0);
    ~dlg_12();
    void display(Fees *head);

private:
    Ui::dlg_12 *ui;
};

#endif // DLG_12_H
