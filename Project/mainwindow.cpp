#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginplayer1.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->progressBar, SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
//Below are methods that change the type of question picked
//and creates a marker that will load the type of questions
//from our database
void MainWindow::on_pushButton_clicked()
{
    ui->label->setText("This is a Program");
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->nameOfGame->setText("You selected History!");
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->nameOfGame->setText("You selected Sports!");
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->nameOfGame->setText("You selected Animals!");
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->nameOfGame->setText("You selected Technology!");
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->nameOfGame->setText("You selected Business!");
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->nameOfGame->setText("You selected Video Games!");

}

void MainWindow::on_pushButton_8_clicked()
{
    ui->nameOfGame->setText("You selected Movies!");
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->nameOfGame->setText("You selected University of Florida!");
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->nameOfGame->setText("You selected Health!");
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->nameOfGame->setText("You selected College!");
}

void MainWindow::on_pushButton_12_clicked()
{
    loginPlayer1 login1;
    login1.setModal(true);
    login1.exec();
}
