#ifndef FLASHCARDINPUT_H
#define FLASHCARDINPUT_H

#include <QMainWindow>

namespace Ui {
class flashcardinput;
}

class FlashcardInput : public QMainWindow
{
    Q_OBJECT

public:
    explicit FlashcardInput(QWidget *parent = nullptr);
    ~FlashcardInput();

private slots:
    void on_saveButton_clicked();
    void on_continueButton_clicked();

private:
    Ui::flashcardinput *ui;
};

#endif // FLASHCARDINPUT_H
