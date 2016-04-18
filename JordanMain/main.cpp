#include <QCoreApplication>
#include <QDebug>
#include <QtCore>
#include <cstdlib>
#include <algorithm>
//You would also create more pagaes just like this but with the different categories.
void Read(QString list[10]){
     QFile file ("C:/Users/Jordan/Documents/Stream/Science.txt"); //You need to change the locatating to where your questions are located
     if (file.open(QIODevice::ReadOnly | QIODevice::Text)){      //This can stay the same

        QTextStream stream (&file);                     //Creating a textstream object
        QString line;                                   //This is used to parse through the file

        for(int i=0; i<10; i++){
            QString temp= list[i];                      //This grabs a number that we will use to try and find in the file

                do{
                    line = stream.readLine();
                    if(line.contains(temp)){
                        qDebug() << line;
                        //So this line grabs the question, you need to put this in a dialog box

                        for(int j=0; j< 4; j++){
                            line= stream.readLine();
                            qDebug() << line;
                            //This now a line that grabs the choices 4 times, look at loop, you
                            //need to take each line and put it in the same dialog box but sepearted like:
                            //A
                            //b
                            //c
                            //d
                        }
                        break;
                    }

                }while(!line.isNull());

        }



        file.close();
        //qDebug() << "File Read";
    }

}

bool check(int* question_list, int r){ //Making sure there arent any repeats
    bool repeat= false;
    for(int i=0; i<10; i++){
        if (r==question_list[i]){
            repeat=true;
        }
    }
    return repeat;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int* question_list= new int [10];
       question_list[0]=5;
       question_list[1]=6;
       question_list[2]=7;
       question_list[3]=8;
       question_list[4]=10;
       question_list[5]=12;
       question_list[6]=13;
       question_list[7]=14;
       question_list[8]=15;
       question_list[9]=16;

       /*int r= rand() % 20 + 1;
        question_list[0]=r;
    for (int i=1; i<10; i++){
        int r= rand() % 20 + 1;
        while (check(question_list,r)){
            r= rand() % 20 + 1;
        }
        question_list[i]=r;

    }

    int temp;
    int size = 10;
    for(int i = 0; i < size; ++i){
        for(int j=1; j<size-i-1; ++j){
            if(question_list[j]>question_list[j+1]){
                temp = question_list[j];
                question_list[j]=question_list[j+1];
                question_list[j+1]=temp;
            }
        }
    }
    for(int i=0; i<10;i++){
        qDebug() << question_list[i];
    }*/

       //This converts the numbers into QString
    QString list[10];
    for(int i=0; i<10; i++){
        list[i]=QString::number(question_list[i]);

    }

  /*  for(int i=0; i<10;i++){
        qDebug() << question_list[i];
    }*/

    //Calls the read function,
    //You can take it out of a method if you like, it may or maynot benfit you JUST A HINT.
    Read(list);

    return a.exec();
}
