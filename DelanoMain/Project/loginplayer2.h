#ifndef LOGINPLAYER2_H
#define LOGINPLAYER2_H

#include <QDialog>

namespace Ui {
class loginplayer2;
}

class loginplayer2 : public QDialog
{
    Q_OBJECT

public:
    explicit loginplayer2(QWidget *parent = 0);
    ~loginplayer2();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::loginplayer2 *ui;
};

#endif // LOGINPLAYER2_H
