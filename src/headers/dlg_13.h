#ifndef DLG_13_H
#define DLG_13_H

#include <QDialog>
#include "dlg_3.h"

namespace Ui {
class dlg_13;
}

class dlg_13 : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_13(QWidget *parent = 0);
    ~dlg_13();
    void display(OWE *head);

private:
    Ui::dlg_13 *ui;
};

#endif // DLG_13_H
