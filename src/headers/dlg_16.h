#ifndef DLG_16_H
#define DLG_16_H

#include <QDialog>

namespace Ui {
class dlg_16;
}

class dlg_16 : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_16(QWidget *parent = 0);
    ~dlg_16();

private:
    Ui::dlg_16 *ui;
};

#endif // DLG_16_H
