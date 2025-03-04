#ifndef APESTYPEGAME_H
#define APESTYPEGAME_H

#include <QTimer>
#include <QStringList>
#include <QKeyEvent>
#include <QDialog>

namespace Ui {
class ApesTypegame;
}

class ApesTypegame : public QDialog {
    Q_OBJECT

public:
    explicit ApesTypegame(QWidget *parent = nullptr);
    ~ApesTypegame();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void startGame();
    void checkInput(const QString &text);
    void updateTimer();
    void endGame();
    void updateAccuracy();


private:
    Ui::ApesTypegame *ui;
    QTimer *timer;
    QStringList texts;
    QString currentText;
    int countdownTime;
    int mistakeCount;
    int correctChars;
    int incorrectChars;
    int totalTypedChars;
    int sessionTotalTyped;
    int sessionCorrect;
    int prevInputLength;
};

#endif // APESTYPEGAME_H
