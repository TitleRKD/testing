/********************************************************************************
** Form generated from reading UI file 'chooes.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOES_H
#define UI_CHOOES_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chooes
{
public:
    QWidget *centralwidget;
    QPushButton *btnOption1;
    QPushButton *btnOption2;
    QPushButton *btnOption3;
    QPushButton *btnOption4;
    QLabel *label;
    QLabel *label_2;
    QLabel *lblQuestion;
    QLabel *lblResult;
    QLabel *lblTimeRemaining;

    void setupUi(QMainWindow *Chooes)
    {
        if (Chooes->objectName().isEmpty())
            Chooes->setObjectName("Chooes");
        Chooes->resize(1200, 800);
        centralwidget = new QWidget(Chooes);
        centralwidget->setObjectName("centralwidget");
        btnOption1 = new QPushButton(centralwidget);
        btnOption1->setObjectName("btnOption1");
        btnOption1->setGeometry(QRect(550, 330, 251, 111));
        btnOption1->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 255, 153);\n"
"font: 20pt \"MS Gothic\";\n"
"color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(0, 0, 0);\n"
""));
        btnOption2 = new QPushButton(centralwidget);
        btnOption2->setObjectName("btnOption2");
        btnOption2->setGeometry(QRect(840, 330, 251, 111));
        btnOption2->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 255, 153);\n"
"font: 20pt \"MS Gothic\";\n"
"color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(0, 0, 0);\n"
""));
        btnOption3 = new QPushButton(centralwidget);
        btnOption3->setObjectName("btnOption3");
        btnOption3->setGeometry(QRect(550, 520, 251, 111));
        btnOption3->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 255, 153);\n"
"font: 20pt \"MS Gothic\";\n"
"color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(0, 0, 0);\n"
""));
        btnOption4 = new QPushButton(centralwidget);
        btnOption4->setObjectName("btnOption4");
        btnOption4->setGeometry(QRect(840, 520, 251, 111));
        btnOption4->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 255, 153);\n"
"font: 20pt \"MS Gothic\";\n"
"color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(0, 0, 0);\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1200, 800));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/bgchoose/bgchoose.png);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(-200, 0, 1221, 641));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/res/backgr.jpg);"));
        lblQuestion = new QLabel(centralwidget);
        lblQuestion->setObjectName("lblQuestion");
        lblQuestion->setGeometry(QRect(110, 460, 381, 61));
        lblQuestion->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        lblQuestion->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"text-decoration: underline;\n"
"font: 20pt \"MS Gothic\";"));
        lblQuestion->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblResult = new QLabel(centralwidget);
        lblResult->setObjectName("lblResult");
        lblResult->setGeometry(QRect(50, 680, 421, 81));
        lblResult->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 12pt \"MS Gothic\";"));
        lblResult->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblTimeRemaining = new QLabel(centralwidget);
        lblTimeRemaining->setObjectName("lblTimeRemaining");
        lblTimeRemaining->setGeometry(QRect(700, 240, 231, 41));
        lblTimeRemaining->setStyleSheet(QString::fromUtf8("font: 700 11pt \"MS Gothic\";\n"
"color: rgb(0, 0, 0);\n"
""));
        lblTimeRemaining->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        lblTimeRemaining->setLineWidth(1);
        lblTimeRemaining->setTextFormat(Qt::TextFormat::RichText);
        lblTimeRemaining->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblTimeRemaining->setTextInteractionFlags(Qt::TextInteractionFlag::NoTextInteraction);
        Chooes->setCentralWidget(centralwidget);
        label_2->raise();
        label->raise();
        btnOption1->raise();
        btnOption2->raise();
        btnOption3->raise();
        btnOption4->raise();
        lblQuestion->raise();
        lblResult->raise();
        lblTimeRemaining->raise();

        retranslateUi(Chooes);

        QMetaObject::connectSlotsByName(Chooes);
    } // setupUi

    void retranslateUi(QMainWindow *Chooes)
    {
        Chooes->setWindowTitle(QCoreApplication::translate("Chooes", "MainWindow", nullptr));
        btnOption1->setText(QCoreApplication::translate("Chooes", "Aws1", nullptr));
        btnOption2->setText(QCoreApplication::translate("Chooes", "Aws2", nullptr));
        btnOption3->setText(QCoreApplication::translate("Chooes", "Aws3", nullptr));
        btnOption4->setText(QCoreApplication::translate("Chooes", "Aws4", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        lblQuestion->setText(QString());
        lblResult->setText(QString());
#if QT_CONFIG(statustip)
        lblTimeRemaining->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(accessibility)
        lblTimeRemaining->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        lblTimeRemaining->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        lblTimeRemaining->setText(QCoreApplication::translate("Chooes", "time count", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chooes: public Ui_Chooes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOES_H
