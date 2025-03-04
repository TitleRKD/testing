#include "ApesTypegame.h"
#include "ui_ApesTypegame.h"
#include <QCoreApplication>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <QFile>
#include <QKeyEvent>

ApesTypegame::ApesTypegame(QWidget *parent) : QDialog(parent),
    ui(new Ui::ApesTypegame)
{
    ui->setupUi(this);
    this->setWindowModality(Qt::ApplicationModal);
    setFixedSize(1200, 800);
    srand(time(0));
    countdownTime = 30;
    ui->inputField->setEnabled(false);  // ปิดการใช้งานจนกว่าจะเริ่มเกม

    // อ่านคำศัพท์จากไฟล์ CSV
    QString filePath = QCoreApplication::applicationDirPath() + "/vocabulary_list.csv";
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            texts << in.readLine();
        }
        file.close();
    } else {
        QMessageBox::warning(this, tr("Error"), tr("Failed to open CSV file!"));
    }
    connect(ui->startButton, &QPushButton::clicked, this, &ApesTypegame::startGame);
    connect(ui->inputField, &QLineEdit::textChanged, this, &ApesTypegame::checkInput);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ApesTypegame::updateTimer);
}

ApesTypegame::~ApesTypegame() {
    delete ui;
}

void ApesTypegame::startGame() {
    if (texts.isEmpty()) {
        QMessageBox::warning(this, tr("Error"), tr("No words available!"));
        return;
    }
    // ตรวจสอบว่าเลือกเวลาหรือยัง
    int selectedTime = ui->timeSelector->value();
    if (selectedTime <= 0) {
        QMessageBox::warning(this, tr("Error"), tr("Please select a time before starting!"));
        return;
    }

    // รับค่าจาก timeSelector และตั้งค่าถอยหลัง
    countdownTime = ui->timeSelector->value();
    ui->timerDisplay_2->setText(QString("Time: %1s").arg(countdownTime));

    // เริ่มต้นด้วยคำแรกจาก texts
    int randomIndex = rand() % texts.size();
    currentText = texts[randomIndex];
    ui->textDisplay->setText(currentText);
    ui->inputField->setText("");
    ui->inputField->setEnabled(true);
    ui->inputField->setFocus();
    ui->resultDisplay->clear();
    ui->accuracyDisplay->clear();

    mistakeCount = 0;
    correctChars = 0;
    prevInputLength = 0;
    totalTypedChars =0;
    // ปิดปุ่ม Start เมื่อเกมเริ่ม
    ui->startButton->setEnabled(false);

    // เปิดช่องกรอกข้อความเมื่อเกมเริ่ม
    ui->inputField->setEnabled(true);  // เปิดให้พิมพ์เมื่อเริ่มเกม

    timer->start(1000); // เริ่มจับเวลา
}

void ApesTypegame::checkInput(const QString &text) {
    if (text.isEmpty()) {
        prevInputLength = 0;
        updateAccuracy();
        return;
    }

    int currentLength = text.length();
    int newChars = currentLength - prevInputLength;

    if (newChars < 0) {  // ผู้ใช้กด backspace
        prevInputLength = currentLength;
        if (text == currentText.left(currentLength))
            ui->inputField->setStyleSheet("color: green;");
        else
            ui->inputField->setStyleSheet("color: red;");
        updateAccuracy();
        return;
    }

    totalTypedChars += newChars; // เพิ่มตัวอักษรที่พิมพ์ทั้งหมด

    if (text == currentText) {  // พิมพ์ถูกต้องทั้งหมด
        ui->inputField->setStyleSheet("color: green;");
        correctChars += newChars;

        // สุ่มโจทย์ใหม่
        int randomIndex = rand() % texts.size();
        currentText = texts[randomIndex];
        ui->textDisplay->setText(currentText);
        ui->inputField->setText("");
        ui->inputField->setFocus();
        prevInputLength = 0;
    } else {
        if (currentText.startsWith(text)) {
            ui->inputField->setStyleSheet("color: green;");
            correctChars = text.length();  // นับตัวอักษรถูกต้องเท่าที่พิมพ์ไป
        } else {
            ui->inputField->setStyleSheet("color: red;");
            mistakeCount += newChars;  // นับตัวอักษรผิดที่พิมพ์เพิ่มเข้ามา
        }
        prevInputLength = currentLength;
    }

    updateAccuracy();
}

void ApesTypegame::updateAccuracy() {
    // ใช้สูตร Accuracy แบบ Monkeytype
    double acc = (totalTypedChars > 0) ? (1.0 - ((double)mistakeCount / totalTypedChars)) * 100 : 0;
    if (acc > 100.0) acc = 100.0;
    ui->accuracyDisplay->setText(QString("Accuracy: %1%").arg(acc, 0, 'f', 2));
}


void ApesTypegame::endGame() {
    timer->stop();
    ui->inputField->setEnabled(false);
    ui->startButton->setEnabled(true);  // เปิดปุ่ม Start

    // คำนวณ Accuracy แบบ Monkeytype
    double acc = (totalTypedChars > 0) ? (1.0 - ((double)mistakeCount / totalTypedChars)) * 100 : 0;
    if (acc > 100.0) acc = 100.0;

    ui->resultDisplay->setText(QString("Game Over!\nMistakes: %1").arg(mistakeCount));
    ui->accuracyDisplay->setText(QString("Final Accuracy: %1%").arg(acc, 0, 'f', 2));
}


void ApesTypegame::updateTimer() {
    countdownTime--;
    ui->timerDisplay_2->setText(QString("Time: %1s").arg(countdownTime));
    if (countdownTime <= 0) {
        endGame();
    }
}

void ApesTypegame::closeEvent(QCloseEvent *event) {
    if (timer->isActive()) {
        timer->stop();
    }
    event->accept();
    deleteLater();  // ทำลาย instance หลังจากปิดหน้าต่าง
}
