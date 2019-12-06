#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     pal = palette();
        pal.setColor(QPalette::Window, QColor(128,125,123));
        this->setPalette(pal);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonUpdate_clicked()
{
    ui->comboBoxPorts->clear();
    ui->comboBoxPorts->addItems(ws2811.getPorts());
}

void MainWindow::on_pushButtonOpen_clicked()
{
    if(ws2811.isOpen())
    {
        ui->pushButtonOpen->setText("Open");
        ws2811.close();
    }
    else if(ws2811.open(ui->comboBoxPorts->currentText()))
    {
        ui->pushButtonOpen->setText("Close");
    }
}

void MainWindow::setState()
{
    QByteArray qb;
    qb.append(static_cast<char>(ui->spinBoxG->value()));
    qb.append(static_cast<char>(ui->spinBoxR->value()));
    qb.append(static_cast<char>(ui->spinBoxB->value()));
    pal.setColor(QPalette::Window, QColor((uchar)qb.at(1),(uchar)qb.at(0),(uchar)qb.at(2)));
    this->setPalette(pal);
    ws2811.send(qb);

}

void MainWindow::on_pushButtonSend_clicked()
{
    setState();
}

void MainWindow::on_spinBoxG_valueChanged(int )
{
    setState();
}

void MainWindow::on_spinBoxR_valueChanged(int )
{
    setState();
}

void MainWindow::on_spinBoxB_valueChanged(int )
{
    setState();
}

void MainWindow::on_verticalSlider_sliderMoved(int position)
{
    ui->spinBoxG->setValue(position);
    setState();
}

void MainWindow::on_verticalSlider_2_sliderMoved(int position)
{
    ui->spinBoxR->setValue(position);
    setState();
}

void MainWindow::on_verticalSlider_3_sliderMoved(int position)
{
    ui->spinBoxB->setValue(position);
    setState();
}
