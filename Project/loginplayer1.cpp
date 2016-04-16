#include "loginplayer1.h"
#include "ui_loginplayer1.h"

loginPlayer1::loginPlayer1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginPlayer1)
{
    ui->setupUi(this);
}

loginPlayer1::~loginPlayer1()
{
    delete ui;
}
