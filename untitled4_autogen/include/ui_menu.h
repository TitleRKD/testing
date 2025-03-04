/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QPushButton *BtnToGameFlashcard;
    QPushButton *BtnToGameChoose;
    QPushButton *BtnToGameApestype;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName("Menu");
        Menu->resize(1200, 800);
        Menu->setStyleSheet(QString::fromUtf8(""));
        BtnToGameFlashcard = new QPushButton(Menu);
        BtnToGameFlashcard->setObjectName("BtnToGameFlashcard");
        BtnToGameFlashcard->setGeometry(QRect(70, 420, 312, 157));
        QFont font;
        font.setFamilies({QString::fromUtf8("Leelawadee UI")});
        font.setPointSize(18);
        font.setBold(true);
        font.setItalic(false);
        BtnToGameFlashcard->setFont(font);
        BtnToGameFlashcard->setStyleSheet(QString::fromUtf8("background-image: url(:/bgmenu/btnfresized.png);\n"
"font: 700 18pt \"Leelawadee UI\";"));
        BtnToGameChoose = new QPushButton(Menu);
        BtnToGameChoose->setObjectName("BtnToGameChoose");
        BtnToGameChoose->setGeometry(QRect(440, 420, 311, 157));
        BtnToGameChoose->setStyleSheet(QString::fromUtf8("font: 700 18pt \"Leelawadee UI\";\n"
"background-image: url(:/bgmenu/btnchoresized.png);"));
        BtnToGameApestype = new QPushButton(Menu);
        BtnToGameApestype->setObjectName("BtnToGameApestype");
        BtnToGameApestype->setGeometry(QRect(800, 420, 312, 157));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Courier New")});
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setItalic(false);
        BtnToGameApestype->setFont(font1);
        BtnToGameApestype->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Courier New\";\n"
"background-image: url(:/bgmenu/2btnapes.png);"));
        label = new QLabel(Menu);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 1200, 800));
        label->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/bgmenu/bgmenuedit.png);"));
        label_2 = new QLabel(Menu);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 380, 308, 154));
        label_2->setStyleSheet(QString::fromUtf8("background-image: url(:/bgmenu/btnwindowresized.png);"));
        label_3 = new QLabel(Menu);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(410, 380, 308, 154));
        label_3->setStyleSheet(QString::fromUtf8("background-image: url(:/bgmenu/btnwindowresized.png);"));
        label_4 = new QLabel(Menu);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(790, 380, 308, 154));
        label_4->setStyleSheet(QString::fromUtf8("background-image: url(:/bgmenu/btnwindowresized.png);"));
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        BtnToGameFlashcard->raise();
        BtnToGameChoose->raise();
        BtnToGameApestype->raise();

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QWidget *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "Form", nullptr));
        BtnToGameFlashcard->setText(QString());
        BtnToGameChoose->setText(QString());
        BtnToGameApestype->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
