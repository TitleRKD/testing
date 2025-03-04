#ifndef FLASHCARDMINIGAME_H
#define FLASHCARDMINIGAME_H

#include <QWidget>
#include <QList>
#include <QString>

namespace Ui {
class flashcardminigame;
}

// แก้ชื่อ struct จาก VocabularyEntry เป็น FlashcardVocabularyEntry
struct FlashcardVocabularyEntry {
    QString word;
    QString meaning;
    int chance; // 0 ถึง 100
};

class FlashcardMiniGame : public QWidget
{
    Q_OBJECT

public:
    explicit FlashcardMiniGame(QWidget *parent = nullptr);
    ~FlashcardMiniGame();

private slots:
    void handleNext();

private:
    Ui::flashcardminigame *ui;
    QList<FlashcardVocabularyEntry> flashcards;  // ใช้ชื่อ struct ใหม่
    int currentRound;
    const int totalRounds = 5;
    int correctCount;
    int wrongCount;

    // currentEntry ก็ต้องเป็น FlashcardVocabularyEntry
    FlashcardVocabularyEntry currentEntry;

    void loadFlashcards();
    void setupRound();
    void updateCSV();
};

#endif // FLASHCARDMINIGAME_H
