#include "statscreen.h"
#include "ui_statscreen.h"
#include "gamemenu.h"
#include "loginplayer2.h"
#include "global.h"
#include "loginplayer1.h"
statScreen::statScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statScreen)
{
    ui->setupUi(this);
}

statScreen::~statScreen()
{
    delete ui;
}

void statScreen::on_pushButton_clicked()
{
    gameMenu gamemenu;
    gamemenu.setModal(true);
    gamemenu.exec();
}

void statScreen::on_pushButton_2_clicked()
{
    player player1;
    ui->player1Name->setText(player1.getName());
}
