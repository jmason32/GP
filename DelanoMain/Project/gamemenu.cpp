#include "gamemenu.h"
#include "ui_gamemenu.h"
#include "game.h"
#include "sports.h"
#include "arts.h"
#include "music.h"
#include "science.h"
gameMenu::gameMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gameMenu)
{
    ui->setupUi(this);
}

gameMenu::~gameMenu()
{
    delete ui;
}

void gameMenu::on_historyButton_clicked()
{
    ui->category->setText("You selected History!");
    Game game;
    game.setModal(true);
    game.exec();

}

void gameMenu::on_scienceButton_clicked()
{
    ui->category->setText("You selected Science!");
    science science;
    science.setModal(true);
    science.exec();
}

void gameMenu::on_musicButton_clicked()
{
    ui->category->setText("You selected Music!");
    music music;
    music.setModal(true);
    music.exec();

}

void gameMenu::on_sportsButton_clicked()
{
    ui->category->setText("You selected Sports!");
    sports sports;
    sports.setModal(true);
    sports.exec();
}


void gameMenu::on_artsButton_clicked()
{
    ui->category->setText("You selected Arts and Literature!");
    arts arts;
    arts.setModal(true);
    arts.exec();
}
