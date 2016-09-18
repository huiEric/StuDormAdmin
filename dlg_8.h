#ifndef DLG_8_H
#define DLG_8_H

#include <QDialog>

namespace Ui {
class dlg_8;
}

class dlg_8 : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_8(QWidget *parent = 0);
    ~dlg_8();
    void setWarning(const char *warning);

public:
    Ui::dlg_8 *ui;
};

#endif // DLG_8_H
