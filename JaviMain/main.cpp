#include "gp2.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QtCore>
#include <QDebug>
#include <string>
#include <ctime>

using namespace std;
//Prints out vector string
void printout(QVector<QString> input) {
    int filesize = input.size();
   for (int i = 0; i < filesize; i++) {
        qDebug() << input.at(i);
    }
}

//Prints out int array for randnum
void print(int inputs[10]) {
   for (int i = 0; i < 10; i++) {
        qDebug() << inputs[i];
    }
}

//Checks to see randmon number is not the same
bool check(int question_list[10], int r){
    bool repeat= false;
    for(int i = 0; i<10; i++){
        if (r == question_list[i]){
            repeat = true;
        }
    }
    return repeat;
}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   //gp2 w;
  // w.show();

    //Creating the randmon number array and checking that numbers aren't the same
    int random;
    int hold[10];
    srand(time(NULL));
    for(int i=0; i<10; i++){
        random = qrand()%20 +1;
        while(check(hold,random)){
            random = qrand() % 18 +1;
        }
       hold[i] = random;
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
                // print(hold);

    //Converts the randmon int array to a vector array
    QVector<QString> list;\
    QString num;
    for(int i = 0; i < 10; i++){
        num = QString::number(hold[i]);
        list.push_back(num);
    }
    printout(list);


    //Taking the specific file and store it to a vector called question
    QFile file ("C:/Users/Javier/Documents/Science.txt");
    QString line;
    QVector<QString> question;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
       while(!file.atEnd()){
           line = file.readLine();
           question.push_back(line);
       }
        file.close();
    }else{
        cout<<"Error"<<endl;
    }
                     //printout(question);

   return a.exec();
}
