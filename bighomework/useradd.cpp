#include "useradd.h"
#include "ui_useradd.h"
#include "admin.h"
#include <QMessagebox>
#include<QDateTime>
#include<QTimer>
#include<QtSql>
void useradd::time(){
    QDateTime dateTime= QDateTime::currentDateTime();
    QString tt=dateTime.toString("yyyy-MM-dd hh:mm:ss");
    ui->tstr->setText(tt);
}
useradd::useradd(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::useradd)
{
    ui->setupUi(this);
    this->setWindowTitle("Iwork Admin");
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(time()));
    timer->start(1000);
}

useradd::~useradd()
{
    delete ui;
}

void useradd::on_pushButton_clicked()
{
    admin* ad=new admin;
    this->close();
    ad->show();
}


void useradd::on_qd_clicked()
{
    bool c1;
    int val=ui->u1->text().toInt(&c1);
    if(!c1 || ui->u2->text().isEmpty()){
        QMessageBox::critical(NULL,"错误","输入的用户ID不是数字，或用户名为空值，创建失败！");
        return;
    }
    QSqlQuery query;
    query.prepare("INSERT INTO employee (employeeID,employname) VALUES (:value1,:value2)");
    query.bindValue(":value1",val);
    query.bindValue(":value2", ui->u2->text());
    if (!query.exec()) {
        QMessageBox::critical(NULL,"错误","数据库错误，插入失败，请检查输入！");
        return;
    }
    if(!ui->u3->text().isEmpty()){
        bool c2;
        int val2=ui->u3->text().toInt(&c2);
        if(!c2 || (val2!=1 && val2!=0)){
            QMessageBox::critical(NULL,"错误","输入的用户性别不合法，但用户已创建，请检查输入后在用户修改中操作！");
        }
        else{
            QSqlQuery query2;
            query2.prepare("UPDATE employee SET sex = :value1 WHERE employeeID = :value2");
            if(val2==1)query2.bindValue(":value1", true);
            else query2.bindValue(":value1", false);
            query2.bindValue(":value2", val);
            if (!query2.exec()) {
                QMessageBox::critical(NULL,"错误","用户性别插入失败，但用户已创建，请检查输入后在用户修改中操作！");
            }
        }
    }
    if(!ui->u4->text().isEmpty()){
        QSqlQuery query1;
        query1.prepare("UPDATE employee SET enrollmentdate = :value1 WHERE employeeID = :value2");
        query1.bindValue(":value1", ui->u4->text());
        query1.bindValue(":value2", val);
        if (!query1.exec()) {
            QMessageBox::critical(NULL,"错误","插入入职时间失败，但用户已创建，请检查输入后在用户修改中操作！");
        }
    }
    if(!ui->u5->text().isEmpty()){
        QSqlQuery query1;
        query1.prepare("UPDATE employee SET job = :value1 WHERE employeeID = :value2");
        query1.bindValue(":value1", ui->u5->text());
        query1.bindValue(":value2", val);
        if (!query1.exec()) {
            QMessageBox::critical(NULL,"错误","插入职务失败，但用户已创建，请检查输入后在用户修改中操作！");
        }
    }
    if(!ui->u6->text().isEmpty()){
        bool c2;
        int val2=ui->u6->text().toInt(&c2);
        if(!c2){
            QMessageBox::critical(NULL,"错误","输入的部门ID不是数字，但用户已创建，请检查输入后在用户修改中操作！");
        }
        else{
            QSqlQuery query2;
            query2.prepare("UPDATE employee SET departmentID = :value1 WHERE employeeID = :value2");
            query2.bindValue(":value1", val2);
            query2.bindValue(":value2", val);
            if (!query2.exec()) {
                QMessageBox::critical(NULL,"错误","用户部门ID插入失败，但用户已创建，请检查输入后在用户修改中操作！");
            }
        }
    }
    if(!ui->u7->text().isEmpty()){
        bool c2;
        int val2=ui->u7->text().toInt(&c2);
        if(!c2){
            QMessageBox::critical(NULL,"错误","输入的技术职级不是数字，但用户已创建，请检查输入后在用户修改中操作！");
        }
        else{
            QSqlQuery query2;
            query2.prepare("INSERT INTO technicist (employeeID,techlevel) VALUES (:value1,:value2)");
            query2.bindValue(":value1", val);
            query2.bindValue(":value2", val2);
            if (!query2.exec()) {
                QMessageBox::critical(NULL,"错误","用户技术职级插入失败，但用户已创建，请检查输入后在用户修改中操作！");
            }
        }
    }
    if(!ui->u8->text().isEmpty()){
        bool c2;
        int val2=ui->u8->text().toInt(&c2);
        if(!c2){
            QMessageBox::critical(NULL,"错误","输入的管理职级不是数字，但用户已创建，请检查输入后在用户修改中操作！");
        }
        else{
            QSqlQuery query2;
            query2.prepare("INSERT INTO management (employeeID,managelevel) VALUES (:value1,:value2)");
            query2.bindValue(":value1", val);
            query2.bindValue(":value2", val2);
            if (!query2.exec()) {
                QMessageBox::critical(NULL,"错误","用户管理职级插入失败，但用户已创建，请检查输入后在用户修改中操作！");
            }
        }
    }
    QMessageBox::information(NULL,"操作完成","操作完成！");
}

