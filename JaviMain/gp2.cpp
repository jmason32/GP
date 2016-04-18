#include "gp2.h"
#include "ui_gp2.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
gp2::gp2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gp2)
{
    ui->setupUi(this);
}

gp2::~gp2()
{
    delete ui;
}

