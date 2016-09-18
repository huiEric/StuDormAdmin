#ifndef DLG_15_H
#define DLG_15_H

#include <QDialog>

namespace Ui {
class dlg_15;
}

class dlg_15 : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_15(QWidget *parent = 0);
    ~dlg_15();

private:
    Ui::dlg_15 *ui;
};

#endif // DLG_15_H
