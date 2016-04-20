#include "science.h"
#include "ui_science.h"
#include <QCoreApplication>
#include <QDebug>
#include <QtCore>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include <thread>
#include <iostream>
#include <Windows.h>
#include <QMessageBox>
#include <QtCore>
#include <QDebug>
#include <QString>
#include <string>
#include <QVector>
#include <ctime>
using namespace std;
//int i = 0;
//bool ints= false;


science::science(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::science)

{
    ui->setupUi(this);
}

science::~science()
{
    delete ui;
}
//Generate random number list
/*void printout(QVector<QString> input) {
    int filesize = input.size();
   for (int i = 0; i < filesize; i++) {
        qDebug() << input.at(i);
    }
}*/

//Prints out int array for randnum
/*void print(int inputs[10]) {
   for (int i = 0; i < 10; i++) {
        qDebug() << inputs[i];
    }
}*/
//Checks to see randmon number is not the same
bool check5(int question_list[10], int r){
    bool repeat= false;
    for(int i = 0; i<10; i++){
        if (r == question_list[i]){
            repeat = true;
        }
    }
    return repeat;
}
//You would also create more pagaes just like this but with the different categories.
QVector<QString> science::vector(){
    //Creating the randmon number array and checking that numbers aren't the same
        int random;
        int hold[10];
        srand(time(NULL));
        for(int i=0; i<10; i++){
            random = qrand()%20 +1;
            while(check5(hold,random)){
                random = qrand() % 18 +1;
            }
           hold[i] = random;
           qDebug() << random;
        }
        //Bubble Sorting randmon number array
            int temp;
               int size = 10;
               for(int i = 0; i < size; ++i){
                   for(int j=0; j < size-i-1; ++j){
                       if(hold[j]>hold[j+1]){
                           temp = hold[j];
                           hold[j]= hold[j+1];
                           hold[j+1]=temp;
                       }
                   }
               }
               //Converts the randmon int array to a vector array
                   QVector<QString> holder;
                   QString num;
                   for(int i = 0; i < 10; i++){
                       num = QString::number(hold[i],10);
                       holder.push_back(num);
                   }
                   //printout(holder);
return holder;
}

                        // print(hold);

void science::Read(QString list) {
     QFile file ("C:/Users/Delano/Documents/Project/Science.txt"); //You need to change the locatating to where your questions are located
     if (file.open(QIODevice::ReadOnly | QIODevice::Text)){      //This can stay the same

        QTextStream stream (&file);                     //Creating a textstream object
        QString line;                                   //This is used to parse through the file



            QString temp= list;                      //This grabs a number that we will use to try and find in the file

                do{
                    line = stream.readLine();
                    if(line.contains(temp)){
                        //qDebug() << line;
                        ui->questionLabel->setText(line);//Displays the question on the screen
                        //So this line grabs the question, you need to put this in a dialog box


                            //qDebug() << line;

                            //This now a line that grabs the choices 4 times, look at loop, you
                            //need to take each line and put it in the same dialog box but sepearted like


                             line= stream.readLine();
                            ui->answer1->setText(line);

                            line= stream.readLine();
                            ui->answer2->setText(line);

                            line= stream.readLine();
                             ui->answer3->setText(line);

                             line= stream.readLine();
                             ui->answer4->setText(line);

                            //b
                            //c
                            //d
                        break;
                    }

                }while(!line.isNull());

}


        file.close();
        //qDebug() << "File Read";
    }


void science::on_pushButton_clicked()
{
    QString answer = "answer2";
    QString list;
    list="1";
    Read(list);

    if(ui->answer1->isChecked())
    {
        ui->pushButton->setEnabled(false);
        on_answer1_clicked(answer);
       ui->pushButton->setChecked(false);
       ui->answer1->setAutoExclusive(false);
       ui->answer1->setChecked(false);
       ui->answer1->setAutoExclusive(true);
    }

    else if(ui->answer2->isChecked())
    {
        ui->pushButton->setEnabled(false);
       on_answer2_clicked(answer);
       ui->pushButton->setChecked(false);
       ui->answer2->setAutoExclusive(false);
       ui->answer2->setChecked(false);
       ui->answer2->setAutoExclusive(true);

    }

    else if(ui->answer3->isChecked())
    {
         on_answer3_clicked(answer);
         ui->pushButton->setEnabled(false);
         ui->pushButton->setChecked(false);
         ui->answer3->setAutoExclusive(false);
         ui->answer3->setChecked(false);
         ui->answer3->setAutoExclusive(true);
    }

    else if(ui->answer4->isChecked())
    {
         on_answer4_clicked(answer);
        ui->pushButton->setEnabled(false);
        ui->pushButton->setChecked(false);
        ui->answer4->setAutoExclusive(false);
        ui->answer4->setChecked(false);
        ui->answer4->setAutoExclusive(true);
    }
}

    //on_answer1_clicked();
   // on_answer2_clicked(answer);


void science::on_pushButton_2_clicked()
{
    QString list;
    QString answer = "answer2";
    list="7";
    Read(list);

    if(ui->answer1->isChecked())
    {
        ui->pushButton_2->setEnabled(false);
       on_answer1_clicked(answer);
       ui->answer1->setAutoExclusive(false);
       ui->answer1->setChecked(false);
       ui->answer1->setAutoExclusive(true);

    }

    else if(ui->answer2->isChecked())
    {
        ui->pushButton_2->setEnabled(false);

       on_answer2_clicked(answer);
       ui->answer2->setAutoExclusive(false);
       ui->answer2->setChecked(false);
       ui->answer2->setAutoExclusive(true);
    }

    else if(ui->answer3->isChecked())
    {
         on_answer3_clicked(answer);
         ui->pushButton_2->setEnabled(false);
         ui->answer3->setAutoExclusive(false);
         ui->answer3->setChecked(false);
         ui->answer3->setAutoExclusive(true);
    }

    else if(ui->answer4->isChecked())
    {
         on_answer4_clicked(answer);
        ui->pushButton_2->setEnabled(false);
        ui->answer4->setAutoExclusive(false);
        ui->answer4->setChecked(false);
        ui->answer4->setAutoExclusive(true);
    }

}

void science::on_pushButton_3_clicked()
{
    QString list;
    QString answer = "answer4";
    list="8";
    Read(list);

    if(ui->answer1->isChecked())
    {
        ui->pushButton_3->setEnabled(false);
       on_answer1_clicked(answer);
       ui->answer1->setAutoExclusive(false);
       ui->answer1->setChecked(false);
       ui->answer1->setAutoExclusive(true);

    }

    else if(ui->answer2->isChecked())
    {
        ui->pushButton_3->setEnabled(false);

       on_answer2_clicked(answer);
       ui->answer2->setAutoExclusive(false);
       ui->answer2->setChecked(false);
       ui->answer2->setAutoExclusive(true);
    }

    else if(ui->answer3->isChecked())
    {
         on_answer3_clicked(answer);
         ui->pushButton_3->setEnabled(false);
         ui->answer3->setAutoExclusive(false);
         ui->answer3->setChecked(false);
         ui->answer3->setAutoExclusive(true);
    }

    else if(ui->answer4->isChecked())
    {
         on_answer4_clicked(answer);
        ui->pushButton_3->setEnabled(false);
        ui->answer4->setAutoExclusive(false);
        ui->answer4->setChecked(false);
        ui->answer4->setAutoExclusive(true);
    }
}

void science::on_pushButton_4_clicked()
{
    QString list;
    QString answer = "answer1";
    list="0";
    Read(list);

    if(ui->answer1->isChecked())
    {
        ui->pushButton_4->setEnabled(false);
       on_answer1_clicked(answer);

       ui->answer1->setAutoExclusive(false);
       ui->answer1->setChecked(false);
       ui->answer1->setAutoExclusive(true);
    }

    else if(ui->answer2->isChecked())
    {
        ui->pushButton_4->setEnabled(false);

       on_answer2_clicked(answer);
       ui->answer2->setAutoExclusive(false);
       ui->answer2->setChecked(false);
       ui->answer2->setAutoExclusive(true);
    }

    else if(ui->answer3->isChecked())
    {
         on_answer3_clicked(answer);
         ui->pushButton_4->setEnabled(false);
         ui->answer3->setAutoExclusive(false);
         ui->answer3->setChecked(false);
         ui->answer3->setAutoExclusive(true);
    }

    else if(ui->answer4->isChecked())
    {
         on_answer4_clicked(answer);
        ui->pushButton_4->setEnabled(false);
        ui->answer4->setAutoExclusive(false);
        ui->answer4->setChecked(false);
        ui->answer4->setAutoExclusive(true);
    }
}
void science::on_pushButton_5_clicked()
{
    QString list;
    QString answer = "answer1";
    list="17";
    Read(list);

    if(ui->answer1->isChecked())
    {
        ui->pushButton_5->setEnabled(false);
       on_answer1_clicked(answer);
       ui->answer1->setAutoExclusive(false);
       ui->answer1->setChecked(false);
       ui->answer1->setAutoExclusive(true);

    }

    else if(ui->answer2->isChecked())
    {
        ui->pushButton_5->setEnabled(false);

       on_answer2_clicked(answer);
       ui->answer2->setAutoExclusive(false);
       ui->answer2->setChecked(false);
       ui->answer2->setAutoExclusive(true);
    }

    else if(ui->answer3->isChecked())
    {
         on_answer3_clicked(answer);
         ui->pushButton_5->setEnabled(false);
         ui->answer3->setAutoExclusive(false);
         ui->answer3->setChecked(false);
         ui->answer3->setAutoExclusive(true);
    }

    else if(ui->answer4->isChecked())
    {
         on_answer4_clicked(answer);
        ui->pushButton_5->setEnabled(false);
        ui->answer4->setAutoExclusive(false);
        ui->answer4->setChecked(false);
        ui->answer4->setAutoExclusive(true);
    }
}
void science::on_pushButton_6_clicked()
{
    QString list;
    QString answer = "answer2";
    list="3";
    Read(list);

    if(ui->answer1->isChecked())
    {
        ui->pushButton_6->setEnabled(false);
       on_answer1_clicked(answer);

       ui->answer1->setAutoExclusive(false);
       ui->answer1->setChecked(false);
       ui->answer1->setAutoExclusive(true);
    }

    else if(ui->answer2->isChecked())
    {
        ui->pushButton_6->setEnabled(false);

       on_answer2_clicked(answer);
       ui->answer2->setAutoExclusive(false);
       ui->answer2->setChecked(false);
       ui->answer2->setAutoExclusive(true);
    }

    else if(ui->answer3->isChecked())
    {
         on_answer3_clicked(answer);
         ui->pushButton_6->setEnabled(false);
         ui->answer3->setAutoExclusive(false);
         ui->answer3->setChecked(false);
         ui->answer3->setAutoExclusive(true);
    }

    else if(ui->answer4->isChecked())
    {
         on_answer4_clicked(answer);
        ui->pushButton_6->setEnabled(false);
        ui->answer4->setAutoExclusive(false);
        ui->answer4->setChecked(false);
        ui->answer4->setAutoExclusive(true);
    }
}
void science::on_pushButton_7_clicked()
{
    QString list;
    QString answer = "answer3";
    list="5";
    Read(list);

    if(ui->answer1->isChecked())
    {
        ui->pushButton_7->setEnabled(false);
       on_answer1_clicked(answer);

       ui->answer1->setAutoExclusive(false);
       ui->answer1->setChecked(false);
       ui->answer1->setAutoExclusive(true);
    }

    else if(ui->answer2->isChecked())
    {
        ui->pushButton_7->setEnabled(false);

       on_answer2_clicked(answer);
       ui->answer2->setAutoExclusive(false);
       ui->answer2->setChecked(false);
       ui->answer2->setAutoExclusive(true);
    }

    else if(ui->answer3->isChecked())
    {
         on_answer3_clicked(answer);
         ui->pushButton_7->setEnabled(false);
         ui->answer3->setAutoExclusive(false);
         ui->answer3->setChecked(false);
         ui->answer3->setAutoExclusive(true);
    }

    else if(ui->answer4->isChecked())
    {
         on_answer4_clicked(answer);
        ui->pushButton_7->setEnabled(false);
        ui->answer4->setAutoExclusive(false);
        ui->answer4->setChecked(false);
        ui->answer4->setAutoExclusive(true);
    }
}
void science::on_pushButton_8_clicked()
{
    QString list;
    QString answer = "answer1";
    list="16";
    Read(list);

    if(ui->answer1->isChecked())
    {
        ui->pushButton_8->setEnabled(false);
       on_answer1_clicked(answer);

       ui->answer1->setAutoExclusive(false);
       ui->answer1->setChecked(false);
       ui->answer1->setAutoExclusive(true);
    }

    else if(ui->answer2->isChecked())
    {
        ui->pushButton_8->setEnabled(false);

       on_answer2_clicked(answer);
       ui->answer2->setAutoExclusive(false);
       ui->answer2->setChecked(false);
       ui->answer2->setAutoExclusive(true);
    }

    else if(ui->answer3->isChecked())
    {
         on_answer3_clicked(answer);
         ui->pushButton_8->setEnabled(false);
         ui->answer3->setAutoExclusive(false);
         ui->answer3->setChecked(false);
         ui->answer3->setAutoExclusive(true);
    }

    else if(ui->answer4->isChecked())
    {
         on_answer4_clicked(answer);
        ui->pushButton_8->setEnabled(false);
        ui->answer4->setAutoExclusive(false);
        ui->answer4->setChecked(false);
        ui->answer4->setAutoExclusive(true);
    }
}
void science::on_pushButton_9_clicked()
{
    QString list;
    QString answer = "answer1";
    list="9";
    Read(list);

    if(ui->answer1->isChecked())
    {
        ui->pushButton_9->setEnabled(false);
       on_answer1_clicked(answer);
       ui->answer1->setAutoExclusive(false);
       ui->answer1->setChecked(false);
       ui->answer1->setAutoExclusive(true);

    }

    else if(ui->answer2->isChecked())
    {
        ui->pushButton_9->setEnabled(false);

       on_answer2_clicked(answer);
       ui->answer2->setAutoExclusive(false);
       ui->answer2->setChecked(false);
       ui->answer2->setAutoExclusive(true);
    }

    else if(ui->answer3->isChecked())
    {
         on_answer3_clicked(answer);
         ui->pushButton_9->setEnabled(false);
         ui->answer3->setAutoExclusive(false);
         ui->answer3->setChecked(false);
         ui->answer3->setAutoExclusive(true);
    }

    else if(ui->answer4->isChecked())
    {
         on_answer4_clicked(answer);
        ui->pushButton_9->setEnabled(false);
        ui->answer4->setAutoExclusive(false);
        ui->answer4->setChecked(false);
        ui->answer4->setAutoExclusive(true);
    }
}
void science::on_pushButton_10_clicked()
{
    QString list;
    QString answer = "answer2";
    list="13";
    Read(list);

    if(ui->answer1->isChecked())
    {
        ui->pushButton_10->setEnabled(false);
       on_answer1_clicked(answer);
       ui->answer1->setAutoExclusive(false);
       ui->answer1->setChecked(false);
       ui->answer1->setAutoExclusive(true);

    }

    else if(ui->answer2->isChecked())
    {
        ui->pushButton_10->setEnabled(false);

       on_answer2_clicked(answer);
       ui->answer2->setAutoExclusive(false);
       ui->answer2->setChecked(false);
       ui->answer2->setAutoExclusive(true);
    }

    else if(ui->answer3->isChecked())
    {
         on_answer3_clicked(answer);
         ui->pushButton_10->setEnabled(false);
         ui->answer3->setAutoExclusive(false);
         ui->answer3->setChecked(false);
         ui->answer3->setAutoExclusive(true);
    }

    else if(ui->answer4->isChecked())
    {
         on_answer4_clicked(answer);
        ui->pushButton_10->setEnabled(false);
        ui->answer4->setAutoExclusive(false);
        ui->answer4->setChecked(false);
        ui->answer4->setAutoExclusive(true);
    }
}

void science::on_answer1_clicked(QString answer)
{
    if (answer=="answer1"){
        QMessageBox msgBox;
        msgBox.setText("This is a right");
        msgBox.exec();

     }
    else {
        QMessageBox msgBox;
        msgBox.setText("This is a wrong");
        msgBox.exec();
    }
}



void science::on_answer2_clicked(QString answer)
{
    if (answer=="answer2"){
        QMessageBox msgBox;
        msgBox.setText("This is a right");
        msgBox.exec();
     }
    else {

        QMessageBox msgBox;
        msgBox.setText("This is a wrong");
        msgBox.exec();
    }

}

void science::on_answer3_clicked(QString answer)
{
    if (answer=="answer3"){

        QMessageBox msgBox;
        msgBox.setText("This is a right");
        msgBox.exec();
     }
    else {
        QMessageBox msgBox;
        msgBox.setText("This is a wrong");
        msgBox.exec();
    }

}

void science::on_answer4_clicked(QString answer)
{
    if (answer=="answer4"){

        QMessageBox msgBox;
        msgBox.setText("This is a right");
        msgBox.exec();
     }
    else {

        QMessageBox msgBox;
        msgBox.setText("This is a wrong");
        msgBox.exec();
    }

}

