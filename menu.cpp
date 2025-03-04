#include "menu.h"
#include "ui_menu.h"
#include <QMessageBox>
#include <QDebug>
#include <QInputDialog>
#include "chooes.h"
#include "ui_chooes.h"

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu),
    chooesGame(nullptr),
    FlashcardGame(nullptr),
    ApesTypeGame(nullptr)
{
    ui->setupUi(this);
    setFixedSize(1200, 800);
    qDebug() << "Menu Created";
    connect(ui->BtnToGameChoose, &QPushButton::clicked, this, &Menu::on_BtnToGameChoose_clicked);
    connect(ui->BtnToGameFlashcard, &QPushButton::clicked, this, &Menu::on_BtnToGameFlashcard_clicked);
    connect(ui->BtnToGameApestype, &QPushButton::clicked, this, &Menu::on_BtnToGameApestype_clicked);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_BtnToGameChoose_clicked()
{
    if (!chooesGame) {
        chooesGame = new Chooes(nullptr); // ไม่มี parent
        chooesGame->setAttribute(Qt::WA_DeleteOnClose); // ปิดแล้วลบทิ้งอัตโนมัติ
        connect(chooesGame, &QObject::destroyed, this, [=]() {
            chooesGame = nullptr;
        });
    }
    chooesGame->show();
}

void Menu::on_BtnToGameFlashcard_clicked()
{
    if (!FlashcardGame) {
        FlashcardGame = new FlashcardInput(nullptr);
        FlashcardGame->setWindowModality(Qt::ApplicationModal);
        connect(FlashcardGame, &FlashcardInput::destroyed, this, [=]() {
            FlashcardGame = nullptr;
        });
    }
    FlashcardGame->show();
}

void Menu::on_BtnToGameApestype_clicked()
{
    if (!ApesTypeGame) {
        ApesTypeGame = new ApesTypegame(this);
        connect(ApesTypeGame, &QObject::destroyed, this, [=]() {
            ApesTypeGame = nullptr;
        });
    }
    ApesTypeGame->show();
}
