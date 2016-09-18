#ifndef DLG_7_H
#define DLG_7_H

#include <QDialog>

namespace Ui {
class dlg_7;
}

class dlg_7 : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_7(QWidget *parent = 0);
    ~dlg_7();

private slots:
    void on_pushButton_clicked();

private:
    Ui::dlg_7 *ui;
};

#endif // DLG_7_H
