#ifndef CHOOES_H
#define CHOOES_H

#include <QMainWindow>
#include <QVector>
#include <QString>
#include <QTimer>
#include <QPixmap>

// Define a struct to hold vocabulary data with a chance field.
struct VocabularyEntry {
    QString word;
    QString meaning;
    int chance; // value between 0 and 100
};

QT_BEGIN_NAMESPACE
namespace Ui { class Chooes; }
QT_END_NAMESPACE

struct Question {
    QString meaning;         // The meaning to display
    QVector<QString> options; // The four options (words)
    int correctIndex;        // Position of the correct answer
};

class Chooes : public QMainWindow {
    Q_OBJECT

public:
    Chooes(QWidget *parent = nullptr);
    ~Chooes();

private slots:
    void loadQuestionsFromCSV(); // Load vocabulary from CSV
    void generateQuestion();     // Generate a new weighted question
    void checkAnswer();          // Check the chosen answer
    void nextQuestion();         // Go to the next question
    void updateTimer();          // Update countdown timer
    void closeGame();            // Close the game

private:
    Ui::Chooes *ui;
    QVector<VocabularyEntry> vocabularyList; // Vocabulary list with chance info
    Question currentQuestion;                // Current question details
    VocabularyEntry currentEntry;            // The entry used as the correct answer
    int wrongAnswersCount;                   // Count of wrong answers
    QTimer *quizTimer;                       // Timer for the quiz
    int timeRemaining;                       // Remaining time in seconds

    // Function to update the CSV file with new chance values
    void updateCSV();
};

#endif // CHOOES_H
