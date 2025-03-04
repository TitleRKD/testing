#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QMessageBox>
#include "menu.h"
#include <Qdebug>
//#include <QMediaPlayer>
//#include <QAudioOutput>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
   // , bgtrack(new QMediaPlayer(this))  // สร้าง QMediaPlayer
   // , audioOutput(new QAudioOutput(this))
{
    ui->setupUi(this);
    setFixedSize(1200, 800);
    dialog = new Dialog(this);
    //bgtrack->setAudioOutput(audioOutput); // เชื่อม AudioOutput
    //bgtrack->setSource(QUrl("qrc:/bgtrack/bgtrack.ogg"));
    //    qDebug() << "Player state: " << bgtrack->mediaStatus(); //debug bgtrack
    //    qDebug() << "playing audio"; //debug bgtrack
    //    bgtrack->play();
    //audioOutput->setVolume(0.3);  // ตั้งระดับเสียง (0.0-1.0)
    //bgtrack->play();         // เล่นทันทีที่เปิดหน้าต่าง

    //เชื่อม Signal-Slot เมื่อ Login สำเร็จ
    bool connected = connect(dialog, &Dialog::loginSuccess, this, &MainWindow::openMenu);
    if (connected){
        qDebug() << "yeah "; //debugการconnect signal
    }else{
        qDebug() << "fail";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    //delete bgtrack;
    //delete audioOutput;
}

void MainWindow::on_pushButton_clicked()
{
    dialog->exec();  //เปิดdialog

}

// เปิดหน้า Menu
void MainWindow::openMenu()
{
    //bgtrack->stop(); // หยุดเพลงพื้นหลัง
    qDebug() << "openMenu() success"; //debug openMenu
    this->hide();  // ซ่อนmain window
    Menu *menu = new Menu(nullptr); //ควรเป็น nullptr แทน this เพราะตอนmainwindowปิด menuปิดไปด้วย ให้ทำงานอิสระ
    menu->show();
}
