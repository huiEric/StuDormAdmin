#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_6_triggered();
    void on_action_7_triggered();
    void on_action_8_triggered();
    void on_action_9_triggered();
    void on_action_10_triggered();
    void on_action_11_triggered();
    void on_action_12_triggered();
    void on_action_13_triggered();
    void on_action_3_triggered();
    void on_action_17_triggered();
    void on_action_20_triggered();
    void on_action_21_triggered();
    void on_action_19_triggered();
    void on_action_22_triggered();
    void on_action_23_triggered();
    void on_action_24_triggered();
    void on_action_25_triggered();
    void on_action_26_triggered();
    void on_action_4_triggered();
    void on_action_5_triggered();
    void on_action_18_triggered();
    void on_action_15_triggered();
    void on_action_16_triggered();
    void on_action_triggered();
    void on_action_2_triggered();
    void on_action_Ctrl_Q_triggered();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void closeEvent(QCloseEvent *e);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
