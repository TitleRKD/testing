/********************************************************************************
** Form generated from reading UI file 'flashcardinput.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLASHCARDINPUT_H
#define UI_FLASHCARDINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_flashcardinput
{
public:
    QWidget *centralwidget;
    QLineEdit *inputWord;
    QLineEdit *inputMeaning;
    QPushButton *saveButton;
    QPushButton *continueButton;
    QLabel *label;
    QLabel *saveStatus;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *flashcardinput)
    {
        if (flashcardinput->objectName().isEmpty())
            flashcardinput->setObjectName("flashcardinput");
        flashcardinput->resize(1200, 800);
        centralwidget = new QWidget(flashcardinput);
        centralwidget->setObjectName("centralwidget");
        inputWord = new QLineEdit(centralwidget);
        inputWord->setObjectName("inputWord");
        inputWord->setGeometry(QRect(710, 210, 321, 41));
        inputWord->setStyleSheet(QString::fromUtf8("background-color: rgb(218, 218, 218);\n"
"background-color: rgb(255, 255, 255);"));
        inputMeaning = new QLineEdit(centralwidget);
        inputMeaning->setObjectName("inputMeaning");
        inputMeaning->setGeometry(QRect(530, 490, 321, 41));
        inputMeaning->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(730, 690, 181, 51));
        saveButton->setStyleSheet(QString::fromUtf8("background-image: url(:/bgflashc/btnsave.png);\n"
"\n"
"font: 900 10pt \"Swis721 Blk BT\";\n"
""));
        saveButton->setCheckable(false);
        saveButton->setAutoDefault(false);
        saveButton->setFlat(false);
        continueButton = new QPushButton(centralwidget);
        continueButton->setObjectName("continueButton");
        continueButton->setGeometry(QRect(930, 690, 179, 51));
        continueButton->setStyleSheet(QString::fromUtf8("\n"
"font: 900 10pt \"Swis721 Blk BT\";\n"
"\n"
"background-image: url(:/bgflashc/btncon.png);"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1200, 800));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/bgflashc/bgflashin.png);"));
        saveStatus = new QLabel(centralwidget);
        saveStatus->setObjectName("saveStatus");
        saveStatus->setGeometry(QRect(580, 710, 211, 20));
        saveStatus->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 0, 0);\n"
"font: 12pt \"MS PGothic\";"));
        flashcardinput->setCentralWidget(centralwidget);
        label->raise();
        inputWord->raise();
        inputMeaning->raise();
        saveButton->raise();
        continueButton->raise();
        saveStatus->raise();
        statusbar = new QStatusBar(flashcardinput);
        statusbar->setObjectName("statusbar");
        flashcardinput->setStatusBar(statusbar);

        retranslateUi(flashcardinput);

        saveButton->setDefault(false);


        QMetaObject::connectSlotsByName(flashcardinput);
    } // setupUi

    void retranslateUi(QMainWindow *flashcardinput)
    {
        flashcardinput->setWindowTitle(QCoreApplication::translate("flashcardinput", "flashcardinput", nullptr));
        saveButton->setText(QString());
        continueButton->setText(QString());
        label->setText(QString());
        saveStatus->setText(QCoreApplication::translate("flashcardinput", "saveStatus", nullptr));
    } // retranslateUi

};

namespace Ui {
    class flashcardinput: public Ui_flashcardinput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLASHCARDINPUT_H
