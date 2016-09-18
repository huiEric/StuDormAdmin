#ifndef DLG_5_H
#define DLG_5_H

#include <QDialog>

namespace Ui {
class dlg_5;
}

class dlg_5 : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_5(QWidget *parent = 0);
    ~dlg_5();

private:
    Ui::dlg_5 *ui;
};

#endif // DLG_5_H
