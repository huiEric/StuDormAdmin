#ifndef DLG_14_H
#define DLG_14_H

#include <QDialog>
#include "dlg_3.h"

namespace Ui {
class dlg_14;
}

class dlg_14 : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_14(QWidget *parent = 0);
    ~dlg_14();
    void display(CLASS_DORM *head);

private:
    Ui::dlg_14 *ui;
};

#endif // DLG_14_H
