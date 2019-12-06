#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ws2811.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    WS2811 ws2811;
    QPalette pal;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setState();

private slots:
    void on_pushButtonUpdate_clicked();

    void on_pushButtonOpen_clicked();

    void on_pushButtonSend_clicked();

    void on_spinBoxG_valueChanged(int arg1);

    void on_spinBoxR_valueChanged(int arg1);

    void on_spinBoxB_valueChanged(int arg1);

    void on_verticalSlider_sliderMoved(int position);

    void on_verticalSlider_2_sliderMoved(int position);

    void on_verticalSlider_3_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
