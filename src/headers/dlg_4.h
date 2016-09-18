#ifndef DLG_4_H
#define DLG_4_H

#include <QDialog>

namespace Ui {
class dlg_4;
}

class dlg_4 : public QDialog
{
    Q_OBJECT

private slots:
    void on_pushButton_clicked();

public:
    explicit dlg_4(QWidget *parent = 0);
    ~dlg_4();

public:
    Ui::dlg_4 *ui;
};

#endif // DLG_4_H
