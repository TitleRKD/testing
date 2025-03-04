/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QLabel *label_4;
    QLineEdit *username;
    QLineEdit *password;
    QLabel *label;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(455, 187);
        Dialog->setStyleSheet(QString::fromUtf8(""));
        btnOK = new QPushButton(Dialog);
        btnOK->setObjectName("btnOK");
        btnOK->setGeometry(QRect(250, 150, 79, 21));
        btnOK->setStyleSheet(QString::fromUtf8("background-image: url(:/bgdialog/Screenshot 2025-02-24 184437.png);"));
        btnCancel = new QPushButton(Dialog);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(150, 150, 78, 21));
        btnCancel->setStyleSheet(QString::fromUtf8("background-image: url(:/bgdialog/Screenshot 2025-02-24 184451.png);"));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 0, 455, 192));
        label_4->setStyleSheet(QString::fromUtf8("background-image: url(:/bgdialog/editeddialog.png);"));
        username = new QLineEdit(Dialog);
        username->setObjectName("username");
        username->setGeometry(QRect(150, 70, 181, 21));
        username->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        password = new QLineEdit(Dialog);
        password->setObjectName("password");
        password->setGeometry(QRect(150, 100, 181, 21));
        password->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        password->setEchoMode(QLineEdit::EchoMode::Password);
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 130, 177, 15));
        label->setStyleSheet(QString::fromUtf8("color: rgb(106, 106, 106);\n"
"font: 8pt \"MS PGothic\";\n"
""));
        label_4->raise();
        btnOK->raise();
        btnCancel->raise();
        username->raise();
        password->raise();
        label->raise();

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        btnOK->setText(QString());
        btnCancel->setText(QString());
        label_4->setText(QString());
        password->setText(QString());
        label->setText(QCoreApplication::translate("Dialog", "Password must contain only numbers", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
