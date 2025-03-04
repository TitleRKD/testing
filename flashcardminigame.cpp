#include "flashcardminigame.h"
#include "ui_flashcardminigame.h"
#include "flashcardresult.h"
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QTimer>
#include <QPushButton>
#include "dialog.h"

FlashcardMiniGame::FlashcardMiniGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::flashcardminigame),
    currentRound(0),
    correctCount(0),
    wrongCount(0)
{
    ui->setupUi(this);
    setFixedSize(1200, 800);
    this->setWindowModality(Qt::ApplicationModal);
    loadFlashcards();
    if (flashcards.isEmpty()) {
        QMessageBox::critical(this, "Error", "No flashcards available. Please add some words first.");
        close();
        return;
    }
    connect(ui->NextButton, &QPushButton::clicked, this, &FlashcardMiniGame::handleNext);
    setupRound();
}

FlashcardMiniGame::~FlashcardMiniGame()
{
    delete ui;
}

void FlashcardMiniGame::loadFlashcards()
{
    QString filePath = QCoreApplication::applicationDirPath() + "/DataUser/" + Dialog::loggedInUser + ".csv";
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    bool firstLine = true;
    flashcards.clear();
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (firstLine) {
            firstLine = false;
            continue;
        }
        if (line.isEmpty())
            continue;

        QStringList parts = line.split(",");
        if (parts.size() >= 2) {
            // ใช้ FlashcardVocabularyEntry แทน
            FlashcardVocabularyEntry entry;
            entry.word = parts[0].trimmed();
            entry.meaning = parts[1].trimmed();
            if (parts.size() >= 3)
                entry.chance = parts[2].trimmed().toInt();
            else
                entry.chance = 0;

            flashcards.append(entry);
        }
    }
    file.close();
}

void FlashcardMiniGame::setupRound()
{
    ui->gameProgress->setText(QString("Round %1 of %2").arg(currentRound + 1).arg(totalRounds));

    // Weighted selection
    int totalWeight = 0;
    for (const auto &entry : flashcards) {
        int weight = 1 + (entry.chance / 20);
        totalWeight += weight;
    }
    int randomValue = QRandomGenerator::global()->bounded(totalWeight);
    int cumulative = 0;
    int selectedIndex = 0;
    for (int i = 0; i < flashcards.size(); i++) {
        int weight = 1 + (flashcards[i].chance / 20);
        cumulative += weight;
        if (randomValue < cumulative) {
            selectedIndex = i;
            break;
        }
    }

    currentEntry = flashcards[selectedIndex];
    ui->meaningLabel->setText(currentEntry.meaning);
    ui->Writethisline->clear();
    ui->feedbackLabel->clear();
}

void FlashcardMiniGame::handleNext()
{
    ui->NextButton->setEnabled(false);
    QString userAnswer = ui->Writethisline->text().trimmed();
    bool isCorrect = (userAnswer.compare(currentEntry.word, Qt::CaseInsensitive) == 0);

    if (isCorrect) {
        correctCount++;
        ui->feedbackLabel->setText("✔ Correct!");
        currentEntry.chance = qMax(0, currentEntry.chance - 20);
    } else {
        wrongCount++;
        ui->feedbackLabel->setText("✘ Incorrect! Correct answer: " + currentEntry.word);
        currentEntry.chance = qMin(100, currentEntry.chance + 20);
    }

    // อัปเดตกลับเข้า QList
    for (int i = 0; i < flashcards.size(); i++) {
        if (flashcards[i].word == currentEntry.word && flashcards[i].meaning == currentEntry.meaning) {
            flashcards[i].chance = currentEntry.chance;
            break;
        }
    }
    updateCSV();

    currentRound++;
    QTimer::singleShot(1000, this, [this]() {
        if (currentRound >= totalRounds) {
            FlashcardResult *result = new FlashcardResult(correctCount, wrongCount);
            result->show();
            this->close();
        } else {
            setupRound();
            ui->NextButton->setEnabled(true);
        }
    });
}

void FlashcardMiniGame::updateCSV()
{
    QString filePath = QCoreApplication::applicationDirPath() + "/DataUser/" + Dialog::loggedInUser + ".csv";
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "ไม่สามารถเขียนลงไฟล์ได้!");
        return;
    }
    QTextStream out(&file);
    out << "word,meaning,chance\n";
    for (const auto &entry : flashcards) {
        out << entry.word << "," << entry.meaning << "," << entry.chance << "\n";
    }
    file.close();
}
