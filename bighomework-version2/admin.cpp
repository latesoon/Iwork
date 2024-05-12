#include "admin.h"
#include "ui_admin.h"
#include <QMessagebox>
#include<QDateTime>
#include<QTimer>
#include<QtSql>
void admin::time(){
    QDateTime dateTime= QDateTime::currentDateTime();
    QString tt=dateTime.toString("yyyy-MM-dd hh:mm:ss");
    ui->tstr->setText(tt);
}
admin::admin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::admin)
{
    ui->setupUi(this);
    this->setWindowTitle("Iwork Admin");
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(time()));
    timer->start(1000);
}

admin::~admin()
{
    delete ui;
}
