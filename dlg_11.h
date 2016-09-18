#ifndef DLG_11_H
#define DLG_11_H

#include <QDialog>
#include "dlg_3.h"

namespace Ui {
class dlg_11;
}

class dlg_11 : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_11(QWidget *parent = 0);
    ~dlg_11();
    void display(Types t[]);

private:
    Ui::dlg_11 *ui;
};

#endif // DLG_11_H
