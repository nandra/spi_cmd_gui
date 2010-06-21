#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iqrf.h>
#include <QTime>
#include <QString>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (iqrf_init_device() < 0) {
        ui->pushButton->setDisabled(true);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_released()
{
    QString data = ui->lineEdit->displayText();
    if (data != "") {

         /* if data are ready print to text array in Terminal label */
        QString str;
        QTime tm;
        str.append(tm.currentTime().toString());
        str.append(" TxD : \"");
        str.append(data);
        str.append("\"");
        ui->textEdit->append(str);

        QByteArray arr = data.toAscii();
        int i = arr.count();
        unsigned char *data = (unsigned char *)arr.data();

        iqrf_read_write_spi_cmd_data(data, i, true);
        ui->lineEdit->clear();

    }

}

void MainWindow::on_lineEdit_returnPressed()
{
    this->on_pushButton_released();
}
