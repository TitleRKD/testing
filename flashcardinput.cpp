#include "flashcardinput.h"
#include "ui_flashcardinput.h"
#include "flashcardminigame.h"
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
#include <QMessageBox>
#include <QPushButton>
#include "dialog.h"


FlashcardInput::FlashcardInput(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::flashcardinput)
{
    ui->setupUi(this);
    setFixedSize(1200, 800);
    // Connect button signals to slots
    connect(ui->saveButton, &QPushButton::clicked, this, &FlashcardInput::on_saveButton_clicked);
    //connect(ui->continueButton, &QPushButton::clicked, this, &FlashcardInput::on_continueButton_clicked);
}

FlashcardInput::~FlashcardInput()
{
    delete ui;
}

void FlashcardInput::on_saveButton_clicked()
{
    QString word = ui->inputWord->text().trimmed();
    QString meaning = ui->inputMeaning->text().trimmed();
    if (word.isEmpty() || meaning.isEmpty()) {
        ui->saveStatus->setText("Please fill both fields.");
        return;
    }
    // Build CSV file path (in the application directory)
    QString filePath = QCoreApplication::applicationDirPath() + "/DataUser/" + Dialog::loggedInUser + ".csv";

    QFile file(filePath);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        ui->saveStatus->setText("Error opening file.");
        return;
    }
    QTextStream out(&file);
    // Write as a CSV row: word,meaning
    out << word << "," << meaning << "\n";
    file.close();
    ui->saveStatus->setText("Saved!");
    ui->inputWord->clear();
    ui->inputMeaning->clear();
}

    void FlashcardInput::on_continueButton_clicked()
{
    // Open the flashcard minigame window
    FlashcardMiniGame *game = new FlashcardMiniGame();
    game->show();
    this->close();
}
