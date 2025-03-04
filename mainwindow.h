#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"  // เพิ่มคลาส Dialog
#include "menu.h"
//#include <QMediaPlayer>
//#include <QAudioOutput>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();  // สล็อตสำหรับการคลิกปุ่ม

public slots: //ใช้private ไม่ได้ ส่งsignal ไม่ไป
    void openMenu();

private:
    Ui::MainWindow *ui;
    Dialog *dialog;  // เพิ่มตัวแปรสำหรับ Dialog
    //QMediaPlayer *bgtrack;
    //QAudioOutput *audioOutput;
};


#endif // MAINWINDOW_H
