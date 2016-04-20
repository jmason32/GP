#ifndef LOGINPLAYER1_H
#define LOGINPLAYER1_H
#include <global.h>
#include <QString>
#include <QDialog>
using namespace std;


namespace Ui {
class loginPlayer1;
}

class loginPlayer1 : public QDialog
{
    Q_OBJECT

public:
    explicit loginPlayer1(QWidget *parent = 0);
    ~loginPlayer1();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::loginPlayer1 *ui;
};

#endif // LOGINPLAYER1_H
