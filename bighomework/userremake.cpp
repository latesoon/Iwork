#include "userremake.h"
#include "ui_userremake.h"
#include "admin.h"
#include <QMessagebox>
#include<QDateTime>
#include<QTimer>
#include<QtSql>
void userremake::time(){
    QDateTime dateTime= QDateTime::currentDateTime();
    QString tt=dateTime.toString("yyyy-MM-dd hh:mm:ss");
    ui->tstr->setText(tt);
}
userremake::userremake(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::userremake)
{
    ui->setupUi(this);
    this->setWindowTitle("Iwork Admin");
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(time()));
    timer->start(1000);
}

userremake::~userremake()
{
    delete ui;
}

void userremake::on_pushButton_clicked()
{
    admin* ad=new admin;
    this->close();
    ad->show();
}


void userremake::on_dl_clicked()
{
    bool c1;
    int val=ui->u1->text().toInt(&c1);
    if(!c1){
        QMessageBox::critical(NULL,"错误","输入的用户ID不是数字，删除失败！");
        return;
    }
    QSqlQuery query;
    query.prepare("DELETE FROM employee WHERE employeeID = :value");
    query.bindValue(":value", val);
    if (!query.exec()) {
        QMessageBox::critical(NULL,"错误","删除失败，请检查并更改");
    } else {
        QMessageBox::information(NULL,"操作完成","操作完成！");
    }
}


void userremake::on_xg_clicked()
{
    bool c1;
    int val=ui->u1->text().toInt(&c1);
    if(!c1){
        QMessageBox::critical(NULL,"错误","输入的用户ID不是数字，修改失败！");
        return;
    }
    if(!ui->u2->text().isEmpty()){
        QSqlQuery query;
        query.prepare("UPDATE employee SET employname = :value1 WHERE employeeID = :value2");
        query.bindValue(":value1",ui->u2->text());
        query.bindValue(":value2", val);
        if (!query.exec()) {
            QMessageBox::critical(NULL,"错误","姓名修改失败，请检查输入！");
            return;
        }
    }
    if(!ui->u3->text().isEmpty()){
        bool c2;
        int val2=ui->u3->text().toInt(&c2);
        if(!c2 || (val2!=1 && val2!=0)){
            QMessageBox::critical(NULL,"错误","输入的用户性别不合法，修改失败！");
        }
        else{
            QSqlQuery query2;
            query2.prepare("UPDATE employee SET sex = :value1 WHERE employeeID = :value2");
            if(val2==1)query2.bindValue(":value1", true);
            else query2.bindValue(":value1", false);
            query2.bindValue(":value2", val);
            if (!query2.exec()) {
                QMessageBox::critical(NULL,"错误","用户性别修改失败！");
            }
        }
    }
    if(ui->cb4->isChecked()){
        QSqlQuery query;
        query.prepare("UPDATE employee SET enrollmentdate= :value1 WHERE employeeID = :value2");
        query.bindValue(":value1", NULL);
        query.bindValue(":value2", val);
        if(!query.exec())
            QMessageBox::critical(NULL,"错误","入职时间修改失败！");
    }
    else if(!ui->u4->text().isEmpty()){
        QSqlQuery query1;
        query1.prepare("UPDATE employee SET enrollmentdate = :value1 WHERE employeeID = :value2");
        query1.bindValue(":value1", ui->u4->text());
        query1.bindValue(":value2", val);
        if (!query1.exec()) {
            QMessageBox::critical(NULL,"错误","入职时间修改失败！");
        }
    }
    if(ui->cb5->isChecked()){
        QSqlQuery query;
        query.prepare("UPDATE employee SET job= :value1 WHERE employeeID = :value2");
        query.bindValue(":value1", NULL);
        query.bindValue(":value2", val);
        if(!query.exec())
            QMessageBox::critical(NULL,"错误","职务修改失败！");
    }
    else if(!ui->u5->text().isEmpty()){
        QSqlQuery query1;
        query1.prepare("UPDATE employee SET job = :value1 WHERE employeeID = :value2");
        query1.bindValue(":value1", ui->u5->text());
        query1.bindValue(":value2", val);
        if (!query1.exec()) {
            QMessageBox::critical(NULL,"错误","职务修改失败！");
        }
    }
    if(ui->cb6->isChecked()){
        QSqlQuery query;
        query.prepare("UPDATE employee SET departmentID= :value1 WHERE employeeID = :value2");
        query.bindValue(":value1", 0);
        query.bindValue(":value2", val);
        if(!query.exec())
            QMessageBox::critical(NULL,"错误","部门ID修改失败！");
    }
    else if(!ui->u6->text().isEmpty()){
        bool c2;
        int val2=ui->u6->text().toInt(&c2);
        if(!c2){
            QMessageBox::critical(NULL,"错误","输入的部门ID不是数字！");
        }
        else{
            QSqlQuery query2;
            query2.prepare("UPDATE employee SET departmentID = :value1 WHERE employeeID = :value2");
            query2.bindValue(":value1", val2);
            query2.bindValue(":value2", val);
            if (!query2.exec()) {
                QMessageBox::critical(NULL,"错误","部门ID修改失败！");
            }
        }
    }
    if(ui->cb7->isChecked()){
        QSqlQuery query;
        query.prepare("DELETE FROM technicist WHERE employeeID = :value");
        query.bindValue(":value", val);
        if(!query.exec())
            QMessageBox::critical(NULL,"错误","技术职级修改失败！");
    }
    else if(!ui->u7->text().isEmpty()){
        bool c2;
        int val2=ui->u7->text().toInt(&c2);
        if(!c2){
            QMessageBox::critical(NULL,"错误","输入的技术职级不是数字！");
        }
        else{
            QSqlQuery query;
            query.prepare("DELETE FROM technicist WHERE employeeID = :value");
            query.bindValue(":value", val);
            query.exec();
            QSqlQuery query2;
            query2.prepare("INSERT INTO technicist (employeeID,techlevel) VALUES (:value1,:value2)");
            query2.bindValue(":value1", val);
            query2.bindValue(":value2", val2);
            if (!query2.exec()) {
                QMessageBox::critical(NULL,"错误","用户技术职级修改失败！");
            }
        }
    }
    if(ui->cb8->isChecked()){
        QSqlQuery query;
        query.prepare("DELETE FROM management WHERE employeeID = :value");
        query.bindValue(":value", val);
        if(!query.exec())
            QMessageBox::critical(NULL,"错误","管理职级修改失败！");
    }
    else if(!ui->u8->text().isEmpty()){
        bool c2;
        int val2=ui->u8->text().toInt(&c2);
        if(!c2){
            QMessageBox::critical(NULL,"错误","输入的管理职级不是数字！");
        }
        else{
            QSqlQuery query;
            query.prepare("DELETE FROM management WHERE employeeID = :value");
            query.bindValue(":value", val);
            query.exec();
            QSqlQuery query2;
            query2.prepare("INSERT INTO management (employeeID,managelevel) VALUES (:value1,:value2)");
            query2.bindValue(":value1", val);
            query2.bindValue(":value2", val2);
            if (!query2.exec()) {
                QMessageBox::critical(NULL,"错误","管理职级修改失败！");
            }
        }
    }
    QMessageBox::information(NULL,"操作完成","操作完成！");
}

