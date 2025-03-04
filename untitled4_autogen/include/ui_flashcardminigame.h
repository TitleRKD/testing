/********************************************************************************
** Form generated from reading UI file 'flashcardminigame.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLASHCARDMINIGAME_H
#define UI_FLASHCARDMINIGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_flashcardminigame
{
public:
    QLabel *gameProgress;
    QLabel *meaningLabel;
    QLabel *feedbackLabel;
    QLineEdit *Writethisline;
    QPushButton *NextButton;
    QLabel *label;

    void setupUi(QWidget *flashcardminigame)
    {
        if (flashcardminigame->objectName().isEmpty())
            flashcardminigame->setObjectName("flashcardminigame");
        flashcardminigame->resize(1200, 800);
        gameProgress = new QLabel(flashcardminigame);
        gameProgress->setObjectName("gameProgress");
        gameProgress->setGeometry(QRect(630, 140, 291, 51));
        gameProgress->setStyleSheet(QString::fromUtf8("color: rgb(216, 216, 216);\n"
"font:  700 16pt \"Courier New\";"));
        gameProgress->setAlignment(Qt::AlignmentFlag::AlignCenter);
        meaningLabel = new QLabel(flashcardminigame);
        meaningLabel->setObjectName("meaningLabel");
        meaningLabel->setGeometry(QRect(480, 210, 551, 91));
        meaningLabel->setStyleSheet(QString::fromUtf8("font: 700 15pt \"8514oem\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(204, 204, 204);\n"
"\n"
""));
        meaningLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        feedbackLabel = new QLabel(flashcardminigame);
        feedbackLabel->setObjectName("feedbackLabel");
        feedbackLabel->setGeometry(QRect(90, 720, 691, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Courier New")});
        font.setPointSize(15);
        font.setBold(true);
        font.setItalic(false);
        feedbackLabel->setFont(font);
        feedbackLabel->setStyleSheet(QString::fromUtf8("\n"
"font: 700 15pt \"Courier New\";"));
        Writethisline = new QLineEdit(flashcardminigame);
        Writethisline->setObjectName("Writethisline");
        Writethisline->setGeometry(QRect(380, 570, 411, 61));
        Writethisline->setStyleSheet(QString::fromUtf8("background-color: rgb(204, 204, 204);\n"
"color: rgb(0, 0, 0);\n"
"font: 700 15pt \"8514oem\";\n"
""));
        Writethisline->setAlignment(Qt::AlignmentFlag::AlignCenter);
        NextButton = new QPushButton(flashcardminigame);
        NextButton->setObjectName("NextButton");
        NextButton->setGeometry(QRect(840, 670, 266, 77));
        NextButton->setStyleSheet(QString::fromUtf8("background-image: url(:/bgflashc/btnnextresized2.png);\n"
""));
        label = new QLabel(flashcardminigame);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1200, 800));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/bgflashc/newbgflash.png);"));
        label->raise();
        gameProgress->raise();
        meaningLabel->raise();
        feedbackLabel->raise();
        Writethisline->raise();
        NextButton->raise();

        retranslateUi(flashcardminigame);

        QMetaObject::connectSlotsByName(flashcardminigame);
    } // setupUi

    void retranslateUi(QWidget *flashcardminigame)
    {
        flashcardminigame->setWindowTitle(QCoreApplication::translate("flashcardminigame", "Form", nullptr));
        gameProgress->setText(QCoreApplication::translate("flashcardminigame", "GameProgress", nullptr));
        meaningLabel->setText(QCoreApplication::translate("flashcardminigame", "WordLabel", nullptr));
        feedbackLabel->setText(QCoreApplication::translate("flashcardminigame", "FeedBack", nullptr));
        NextButton->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class flashcardminigame: public Ui_flashcardminigame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLASHCARDMINIGAME_H
