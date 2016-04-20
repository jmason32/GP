#include "loginplayer2.h"
#include "mainwindow.h"
#include "global.h"
#include "ui_loginplayer2.h"
#include "statscreen.h"
#include "makenewaccount.h"
#include "loginplayer1.h"
#include "player.h"
#include <string>
#include <QFile>
#include <QVector>
#include <QTextStream>
#include <QVector>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QVector>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

using namespace std;
extern player player2(QString name, QString dog);

loginplayer2::loginplayer2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginplayer2)
{
    ui->setupUi(this);
}

loginplayer2::~loginplayer2()
{
    delete ui;
}

void loginplayer2::on_pushButton_2_clicked()
{
    //When the user clicks "Clear", removes information on screen
    ui->userNameLine->setText("");
    ui->passwordLine->setText("");
}

void loginplayer2::on_pushButton_clicked()
{
    QString username = ui->userNameLine->text();
    string username1 = username.toStdString();
    QString password = ui->passwordLine->text();
    string password1 = password.toStdString();

    bool correctUsername = false;
    bool correctPassword = false;
    QFile file = "loginID.txt";
    int i = 0;

    //QVector <QString> vector;
    //Converts the lines into a qstring
    string filename = "loginID.txt";
    string line = "";
    vector<string> myVector;
    QVector<QString>vectorz;
    vector<int>scoreVec;
    ifstream files(filename.c_str());
    while(!files.eof()){
        getline(files, line);
        myVector.push_back(line);
        vectorz.push_back(QString::fromStdString(line));
        i++;
    }
    files.close();
    //Loop to search username and password
    for(int i = 0; i < myVector.size(); i++){
        if(myVector[i] == username1){
            correctUsername = true;
            break;
        }
    }
    QString theScore= "";
        for(int z = 0; z <myVector.size(); z++){
            if(myVector[z] == password1){
                correctPassword = true;
                theScore = vectorz[z+1];

                break;
            }
        }
        string s = theScore.toStdString();
stringstream str(s);
string w;
//s>>w;
str<< theScore.toStdString();

        string deezNutts = (theScore.toStdString()).c_str();
        int x = std::stoi(deezNutts);
        qDebug() << QString(x);
        if(correctUsername == true && correctPassword == true){
            QMessageBox msgBox;
            msgBox.setText("Player 2 is " + username + " ." + '\n' + "Welcome Back!");
            msgBox.exec();

            //IMPORTANT INITALIZES PLAYER 1 (GLOBAL OBJECT) to be used
            //For the rest of the program
           // player2(username, theScore);

            statScreen screen;
            screen.setModal(true);
            this->close();
            screen.exec();
        }
        else{
                QMessageBox msgBox;
                msgBox.setText("This user does not exist! Create an account please!");
                msgBox.exec();
            }

}


//If the player clicks this button, shows the
//Create an account screen
void loginplayer2::on_pushButton_3_clicked()
{
    makenewaccount makenewaccount;
    makenewaccount.setModal(true);
    makenewaccount.exec();
}
