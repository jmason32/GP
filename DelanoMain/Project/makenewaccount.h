#ifndef MAKENEWACCOUNT_H
#define MAKENEWACCOUNT_H

#include <QDialog>

namespace Ui {
class makenewaccount;
}

class makenewaccount : public QDialog
{
    Q_OBJECT

public:
    explicit makenewaccount(QWidget *parent = 0);
    ~makenewaccount();

private slots:
    void on_pushButton_clicked();

private:
    Ui::makenewaccount *ui;
};

#endif // MAKENEWACCOUNT_H
