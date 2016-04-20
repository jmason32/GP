#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamemenu.h"
#include "loginplayer1.h"
#include "loginplayer2.h"
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
void MainWindow::on_pushButton_2_clicked()
{
    loginplayer2 login2;
    login2.setModal(true);
    login2.exec();
    ui->label->setText("This is a Program");
    ui->pushButton->setStyleSheet("border-image:url(C:/Users/Delano/Desktop/6vfIYsF.jpg);");
}


void MainWindow::on_pushButton_clicked()
{
    gameMenu gamemenu1;
    gamemenu1.setModal(true);
    gamemenu1.exec();
}
