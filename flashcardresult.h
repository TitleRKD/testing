#ifndef FLASHCARDRESULT_H
#define FLASHCARDRESULT_H

#include <QWidget>

namespace Ui {
class FlashcardResult;
}

class FlashcardResult : public QWidget
{
    Q_OBJECT

public:
    explicit FlashcardResult(int correct, int wrong, QWidget *parent = nullptr);
    ~FlashcardResult();

private slots:
    void on_menuButton_clicked();
    //void on_nextGameButton_clicked();

private:
    Ui::FlashcardResult *ui;
};

#endif // FLASHCARDRESULT_H
