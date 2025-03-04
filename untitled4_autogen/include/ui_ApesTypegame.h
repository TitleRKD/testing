/********************************************************************************
** Form generated from reading UI file 'ApesTypegame.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APESTYPEGAME_H
#define UI_APESTYPEGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_ApesTypegame
{
public:
    QPushButton *startButton;
    QLabel *textDisplay;
    QLabel *timerDisplay_2;
    QLabel *resultDisplay;
    QLineEdit *inputField;
    QLabel *label;
    QLabel *accuracyDisplay;
    QSpinBox *timeSelector;
    QLabel *label_2;

    void setupUi(QDialog *ApesTypegame)
    {
        if (ApesTypegame->objectName().isEmpty())
            ApesTypegame->setObjectName("ApesTypegame");
        ApesTypegame->resize(1200, 800);
        startButton = new QPushButton(ApesTypegame);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(480, 710, 311, 61));
        startButton->setStyleSheet(QString::fromUtf8("font: 700 15pt \"Courier New\";\n"
"background-color: rgb(6, 122, 123);\n"
"color: rgb(255, 255, 255);"));
        textDisplay = new QLabel(ApesTypegame);
        textDisplay->setObjectName("textDisplay");
        textDisplay->setGeometry(QRect(320, 230, 701, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Courier New")});
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(false);
        textDisplay->setFont(font);
        textDisplay->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 20pt \"Courier New\";"));
        textDisplay->setAlignment(Qt::AlignmentFlag::AlignCenter);
        timerDisplay_2 = new QLabel(ApesTypegame);
        timerDisplay_2->setObjectName("timerDisplay_2");
        timerDisplay_2->setGeometry(QRect(570, 380, 231, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Courier New")});
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setItalic(false);
        timerDisplay_2->setFont(font1);
        timerDisplay_2->setStyleSheet(QString::fromUtf8("font: 700 15pt \"Courier New\";\n"
"color: rgb(0, 0, 0);"));
        timerDisplay_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        resultDisplay = new QLabel(ApesTypegame);
        resultDisplay->setObjectName("resultDisplay");
        resultDisplay->setGeometry(QRect(40, 680, 381, 91));
        resultDisplay->setFont(font1);
        resultDisplay->setStyleSheet(QString::fromUtf8("font: 700 15pt \"Courier New\";"));
        resultDisplay->setAlignment(Qt::AlignmentFlag::AlignCenter);
        inputField = new QLineEdit(ApesTypegame);
        inputField->setObjectName("inputField");
        inputField->setGeometry(QRect(270, 440, 791, 111));
        inputField->setFont(font);
        inputField->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 221, 221);\n"
"font: 700 20pt \"Courier New\";"));
        inputField->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label = new QLabel(ApesTypegame);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1200, 800));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/bgapestype/apes.png);"));
        accuracyDisplay = new QLabel(ApesTypegame);
        accuracyDisplay->setObjectName("accuracyDisplay");
        accuracyDisplay->setGeometry(QRect(110, 650, 241, 61));
        accuracyDisplay->setStyleSheet(QString::fromUtf8("font: 700 15pt \"Courier New\";\n"
"color: rgb(0, 0, 0);"));
        accuracyDisplay->setAlignment(Qt::AlignmentFlag::AlignCenter);
        timeSelector = new QSpinBox(ApesTypegame);
        timeSelector->setObjectName("timeSelector");
        timeSelector->setGeometry(QRect(650, 660, 141, 41));
        QFont font2;
        font2.setPointSize(12);
        timeSelector->setFont(font2);
        label_2 = new QLabel(ApesTypegame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(490, 670, 161, 31));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("font: 700 15pt \"Courier New\";\n"
"color: rgb(0, 0, 0);"));
        label->raise();
        startButton->raise();
        textDisplay->raise();
        timerDisplay_2->raise();
        resultDisplay->raise();
        inputField->raise();
        accuracyDisplay->raise();
        timeSelector->raise();
        label_2->raise();

        retranslateUi(ApesTypegame);

        QMetaObject::connectSlotsByName(ApesTypegame);
    } // setupUi

    void retranslateUi(QDialog *ApesTypegame)
    {
        ApesTypegame->setWindowTitle(QCoreApplication::translate("ApesTypegame", "Dialog", nullptr));
        startButton->setText(QCoreApplication::translate("ApesTypegame", "press enter to start", nullptr));
        textDisplay->setText(QString());
        timerDisplay_2->setText(QString());
        resultDisplay->setText(QString());
        label->setText(QString());
        accuracyDisplay->setText(QString());
        label_2->setText(QCoreApplication::translate("ApesTypegame", "select time: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ApesTypegame: public Ui_ApesTypegame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APESTYPEGAME_H
