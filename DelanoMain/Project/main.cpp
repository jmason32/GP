#include "mainwindow.h"
#include "loginplayer1.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QFileInfo>
#include <string>
//Before importing, MAKE SURE TO CHANGE THE PATH OF THE PROJECT
//TO THE LOCAL PROJECT
void makeNewFile(){
    QFile file("loginID.txt");
    if(file.open(QFile::Append | QIODevice::ReadWrite | QIODevice::Text)){
        QTextStream stream(&file);
        stream << "placeholder" <<'\n';
        stream << "placeholder" <<'\n';
        stream << "0";
    }
    QTextStream out(&file);

    // optional, as QFile destructor will already do it:
    file.close();
}
bool fileExists(QString path) {
    QFileInfo check_file(path);
    // check if file exists and if yes: Is it really a file and no directory?
    if (check_file.exists() && check_file.isFile()) {
        return true;
    } else {
        makeNewFile();
        return false;
    }
}
int main(int argc, char *argv[])
{
    QString path = "loginID.txt";
    //Create the File
    fileExists(path);

    QApplication a(argc, argv);
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap("C:/Users/Delano/Desktop/6vfIYsF.jpg"));
    splash->show();


    loginPlayer1 w;
    QTimer::singleShot(3000, splash, SLOT(close()) );
    QTimer::singleShot(3000, &w, SLOT(show()) );

    return a.exec();
}
