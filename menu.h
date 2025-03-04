#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "chooes.h"
#include "flashcardinput.h"
#include "ApesTypegame.h"
#include "ApesTypegame.h"


namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_BtnToGameChoose_clicked();  // ปุ่มเปิดเกม
    void on_BtnToGameFlashcard_clicked();
    void on_BtnToGameApestype_clicked();

private:
    Ui::Menu *ui;
    Chooes *chooesGame;
    FlashcardInput *FlashcardGame;
    ApesTypegame *ApesTypeGame;

};

#endif // MENU_H
