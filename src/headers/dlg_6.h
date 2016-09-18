#ifndef DLG_6_H
#define DLG_6_H

#include <QDialog>

namespace Ui {
class dlg_6;
}

class dlg_6 : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_6(QWidget *parent = 0);
    ~dlg_6();

private slots:
    void on_pushButton_clicked();

private:
    Ui::dlg_6 *ui;
};

#endif // DLG_6_H
