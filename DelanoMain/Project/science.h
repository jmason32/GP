#ifndef SCIENCE_H
#define SCIENCE_H
#include <QString>
#include <QDialog>
#include <QVector>

namespace Ui {
class science;
}

class science : public QDialog
{
    Q_OBJECT

public:
    explicit science(QWidget *parent = 0);
    ~science();

private:
    Ui::science *ui;
private slots:
    QVector <QString> vector();
    void on_pushButton_clicked();
    void Read(QString list);
    //QVector <QString> on_pushButton_2_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();

    void on_pushButton_3_clicked();
    void on_answer1_clicked(QString answer);
    void on_answer2_clicked(QString answer);
    void on_answer3_clicked(QString answer);
    void on_answer4_clicked(QString answer);
};

#endif // SCIENCE_H


