/********************************************************************************
** Form generated from reading UI file 'flashcardresult.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLASHCARDRESULT_H
#define UI_FLASHCARDRESULT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FlashcardResult
{
public:
    QPushButton *menuButton;
    QLabel *correctLabel;
    QLabel *incorrectLabel;
    QLabel *backsc;

    void setupUi(QWidget *FlashcardResult)
    {
        if (FlashcardResult->objectName().isEmpty())
            FlashcardResult->setObjectName("FlashcardResult");
        FlashcardResult->resize(1200, 800);
        menuButton = new QPushButton(FlashcardResult);
        menuButton->setObjectName("menuButton");
        menuButton->setGeometry(QRect(840, 630, 301, 86));
        menuButton->setStyleSheet(QString::fromUtf8("background-image: url(:/bgflashc/btnmenu.png);\n"
""));
        correctLabel = new QLabel(FlashcardResult);
        correctLabel->setObjectName("correctLabel");
        correctLabel->setGeometry(QRect(520, 270, 381, 81));
        correctLabel->setStyleSheet(QString::fromUtf8("font: 900 30pt \"MS UI Gothic\";"));
        correctLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        incorrectLabel = new QLabel(FlashcardResult);
        incorrectLabel->setObjectName("incorrectLabel");
        incorrectLabel->setGeometry(QRect(510, 440, 381, 31));
        incorrectLabel->setStyleSheet(QString::fromUtf8("\n"
"font: 900 30pt \"MS UI Gothic\";"));
        incorrectLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        backsc = new QLabel(FlashcardResult);
        backsc->setObjectName("backsc");
        backsc->setGeometry(QRect(0, 0, 1200, 800));
        backsc->setStyleSheet(QString::fromUtf8("background-image: url(:/bgflashc/bgscore.png);"));
        backsc->raise();
        menuButton->raise();
        correctLabel->raise();
        incorrectLabel->raise();

        retranslateUi(FlashcardResult);

        QMetaObject::connectSlotsByName(FlashcardResult);
    } // setupUi

    void retranslateUi(QWidget *FlashcardResult)
    {
        FlashcardResult->setWindowTitle(QCoreApplication::translate("FlashcardResult", "Form", nullptr));
        menuButton->setText(QString());
        correctLabel->setText(QCoreApplication::translate("FlashcardResult", "Correct    : X", nullptr));
        incorrectLabel->setText(QCoreApplication::translate("FlashcardResult", "Incorrect    : Y", nullptr));
        backsc->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FlashcardResult: public Ui_FlashcardResult {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLASHCARDRESULT_H
