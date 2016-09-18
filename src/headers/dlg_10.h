#ifndef DLG_10_H
#define DLG_10_H

#include <QDialog>
#include "dlg_3.h"

namespace Ui {
class dlg_10;
}

class dlg_10 : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_10(QWidget *parent = 0);
    ~dlg_10();
    void display(liveNode *h_l);

private:
    Ui::dlg_10 *ui;
};

#endif // DLG_10_H
