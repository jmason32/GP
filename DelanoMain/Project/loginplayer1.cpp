#include "loginplayer1.h"
#include "loginplayer2.h"
#include "global.h"
#include "ui_loginplayer1.h"
#include "makenewaccount.h"
#include "mainwindow.h"
#include "statscreen.h"
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
extern player player1;

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

int StrToInt(std::string const& s)
{
    std::istringstream iss(s);
    int value;
    if (!(iss >> value)) throw std::runtime_error("invalid int");
    return value;
}
void loginPlayer1::on_pushButton_2_clicked()
{
    //When the user clicks "Clear", removes information on screen
    ui->userNameLine->setText("");
    ui->passwordLine->setText("");
}

//Functions as the login button for player
//We will have an object extract out information
void loginPlayer1::on_pushButton_clicked()
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
    //Vectors to hold info
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
    //Get password and points
        for(int z = 0; z <myVector.size(); z++){
            if(myVector[z] == password1){
                correctPassword = true;
                theScore = vectorz[z+1];
                //stringstream convert(theScore);

                //int theNewScore =0;
                //convert>>(theNewScore);
                //int numbs = std::stoi(theScore);
                qDebug() << QString(theScore);

                break;
            }
        }
        string s = theScore.toStdString();
        stringstream str(s);
        string w;
        //s>>w;
        str<< theScore.toStdString();
        //fgets(deezNutts, 256, stdin);

        if(correctUsername == true && correctPassword == true){
           // int numbs = 0;
            QMessageBox msgBox;
            msgBox.setText("Player 1 is" + username + " ." + '\n' + "Welcome Back!" + " You have " + theScore);
            msgBox.exec();
            QString points = "100";

            //IMPORTANT INITALIZES PLAYER 1 (GLOBAL OBJECT) to be used
            //For the rest of the program
            player player1(username, theScore);
            statScreen stats;
            stats.setModal(true);
            this->close();

            stats.exec();
        }
        else{
                QMessageBox msgBox;
                msgBox.setText("This user does not exist! Create an account please!");
                msgBox.exec();
            }


}

//If the player clicks this button, shows the
//Create an account screen
void loginPlayer1::on_pushButton_3_clicked()
{
    makenewaccount makenewaccount;
    makenewaccount.setModal(true);
    makenewaccount.exec();
}
