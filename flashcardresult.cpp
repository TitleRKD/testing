#include "flashcardresult.h"
#include "ui_flashcardresult.h"
#include <QApplication>
#include <QPushButton>

FlashcardResult::FlashcardResult(int correct, int wrong, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FlashcardResult)
{
    ui->setupUi(this);
    setFixedSize(1200, 800);
    this->setWindowModality(Qt::ApplicationModal);
    ui->correctLabel->setText(QString("Correct    : %1").arg(correct));
    ui->incorrectLabel->setText(QString("Incorrect : %1").arg(wrong));

    connect(ui->menuButton, &QPushButton::clicked, this, &FlashcardResult::on_menuButton_clicked);
    //connect(ui->nextGameButton, &QPushButton::clicked, this, &FlashcardResult::on_nextGameButton_clicked);
}

FlashcardResult::~FlashcardResult()
{
    delete ui;
}

void FlashcardResult::on_menuButton_clicked()
{
    this->close();
}

