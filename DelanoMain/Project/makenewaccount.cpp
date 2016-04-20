#include "makenewaccount.h"
#include "ui_makenewaccount.h"
#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QVector>
#include <fstream>
#include <string>
makenewaccount::makenewaccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::makenewaccount)
{
    ui->setupUi(this);
}

makenewaccount::~makenewaccount()
{
    delete ui;
}

void makenewaccount::on_pushButton_clicked()
{
    QFile file = ("loginID.txt");

    //Converts the lines into a qstring
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    //Checks if the input is valid
    if(username =="" && password =="" || username =="" || password =="" || username == password){
        QMessageBox wrongInput;
        wrongInput.setText("You need to put valid ID! Try Again");
        wrongInput.exec();
    }




    //Now creates the ID
    else{
    QFile file = ("loginID.txt");
    if(file.open(QFile::Append | QIODevice::ReadWrite | QIODevice::Text)){
        QTextStream stream(&file);
        stream <<'\n'<< username <<'\n';
        stream << password <<'\n';
        stream << "0";
    }
    QMessageBox msgBox;
    msgBox.setText("Your Account Credentials for " + username + " is created!" );
    msgBox.exec();
    }
    }

