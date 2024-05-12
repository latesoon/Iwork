/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_admin
{
public:
    QLabel *title;
    QLabel *tstr;
    QLabel *inf;

    void setupUi(QDialog *admin)
    {
        if (admin->objectName().isEmpty())
            admin->setObjectName("admin");
        admin->resize(793, 533);
        title = new QLabel(admin);
        title->setObjectName("title");
        title->setGeometry(QRect(0, 0, 801, 91));
        QFont font;
        font.setFamilies({QString::fromUtf8("Cambria Math")});
        font.setPointSize(24);
        title->setFont(font);
        title->setContextMenuPolicy(Qt::CustomContextMenu);
        title->setStyleSheet(QString::fromUtf8("QLabel#title{\n"
"	background-color: #0088ff; \n"
"	color: #ffffff;\n"
"	min-width:30px;\n"
"	min-height:30px;\n"
"}"));
        tstr = new QLabel(admin);
        tstr->setObjectName("tstr");
        tstr->setGeometry(QRect(260, 40, 241, 30));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Cambria Math")});
        font1.setPointSize(14);
        tstr->setFont(font1);
        tstr->setStyleSheet(QString::fromUtf8("QLabel#tstr{\n"
"	background-color: #0088ff; \n"
"	color: #ffffff;\n"
"	min-width:30px;\n"
"	min-height:30px;\n"
"}"));
        tstr->setAlignment(Qt::AlignCenter);
        inf = new QLabel(admin);
        inf->setObjectName("inf");
        inf->setGeometry(QRect(480, 20, 301, 71));
        inf->setFont(font1);
        inf->setLayoutDirection(Qt::RightToLeft);
        inf->setStyleSheet(QString::fromUtf8("QLabel#inf{\n"
"	background-color: #0088ff; \n"
"	color: #ffffff;\n"
"	min-width:30px;\n"
"	min-height:30px;\n"
"}"));
        inf->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(admin);

        QMetaObject::connectSlotsByName(admin);
    } // setupUi

    void retranslateUi(QDialog *admin)
    {
        admin->setWindowTitle(QCoreApplication::translate("admin", "Dialog", nullptr));
        title->setText(QCoreApplication::translate("admin", "  Iwork Admin", nullptr));
        tstr->setText(QCoreApplication::translate("admin", "nowtime", nullptr));
        inf->setText(QCoreApplication::translate("admin", "Welcome: admin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admin: public Ui_admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
