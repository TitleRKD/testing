#include "chooes.h"
#include "ui_chooes.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QTimer>
#include <QDialog>
#include <QPointer>
#include <QInputDialog>
#include "dialog.h"
// Chooes::Chooes(QWidget *parent)
//     : QMainWindow(parent)
//     , ui(new Ui::Chooes)
//     , wrongAnswersCount(0)
// {
//     ui->setupUi(this);
//     setFixedSize(1200, 800);
//     this->setWindowModality(Qt::ApplicationModal);
//     // รับเวลาจากผู้ใช้
//     bool ok;
//     int userTime = QInputDialog::getInt(this, "ตั้งเวลา", "ระบุเวลาทั้งหมด (วินาที):", 30, 10, 300, 1, &ok);
//     if (!ok) {
//         close();           // ปิดหน้าต่าง
//         deleteLater();     // กำหนดให้ลบวัตถุในภายหลัง
//         return;            // ออกจาก constructor ทันที
//     }
//     timeRemaining = userTime;

Chooes::Chooes(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Chooes)
    , wrongAnswersCount(0)
{

    qDebug() << "Chooes constructor called";  // เช็คว่ามันถูกเรียกกี่ครั้ง
    ui->setupUi(this);
    setFixedSize(1200, 800);
    this->setWindowModality(Qt::ApplicationModal);
    // Get total time from user input

    bool ok;
    int userTime = QInputDialog::getInt(this, "ตั้งเวลา", "ระบุเวลาทั้งหมด (วินาที):", 30, 10, 300, 1, &ok); //30 คือค่าเริ่มต้น 10คือค่าต่ำสุดที่รับ 300 คือค่าสูงสุดที่รับ 1 คือstep &ok
    if (!ok){
        qDebug() << "User canceled timer";
        close();
        deleteLater();
        return;
    }
    timeRemaining = userTime;


    // Initialize and start timer
    quizTimer = new QTimer(this);
    connect(quizTimer, &QTimer::timeout, this, &Chooes::updateTimer);
    quizTimer->start(1000);

    loadQuestionsFromCSV(); // load the vocabulary file (DataUser/<username>.csv)
    generateQuestion();      // generate the first question

    // Connect option buttons to answer checking
    connect(ui->btnOption1, &QPushButton::clicked, this, &Chooes::checkAnswer);
    connect(ui->btnOption2, &QPushButton::clicked, this, &Chooes::checkAnswer);
    connect(ui->btnOption3, &QPushButton::clicked, this, &Chooes::checkAnswer);
    connect(ui->btnOption4, &QPushButton::clicked, this, &Chooes::checkAnswer);
}

Chooes::~Chooes()
{
    delete ui;
}

void Chooes::loadQuestionsFromCSV() {
    // Build file path using the logged-in user name.
    QString filePath = QCoreApplication::applicationDirPath() + "/DataUser/" + Dialog::loggedInUser + ".csv";
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "ไม่สามารถเปิดไฟล์ vocabulary.csv ได้!");
        return;
    }
    QTextStream in(&file);
    bool firstLine = true;
    vocabularyList.clear();
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (firstLine) { // Skip header if present
            firstLine = false;
            continue;
        }
        QStringList parts = line.split(',');
        if (parts.size() >= 2) {
            VocabularyEntry entry;
            entry.word = parts[0].trimmed();
            entry.meaning = parts[1].trimmed();
            // If a third column exists, use it; otherwise default to 0.
            if (parts.size() >= 3)
                entry.chance = parts[2].trimmed().toInt();
            else
                entry.chance = 0;
            vocabularyList.append(entry);
        }
    }
    file.close();
}

void Chooes::generateQuestion() {
    if (vocabularyList.size() < 4) {
        QMessageBox::warning(this, "Error", "Not enough words in vocabulary.csv");
        return;
    }
    // Weighted selection: each entry gets a base weight of 1 plus extra for chance.
    int totalWeight = 0;
    for (const auto &entry : vocabularyList) {
        int weight = 1 + (entry.chance / 20);
        totalWeight += weight;
    }
    int randomValue = QRandomGenerator::global()->bounded(totalWeight);
    int cumulative = 0;
    int selectedIndex = 0;
    for (int i = 0; i < vocabularyList.size(); i++) {
        int weight = 1 + (vocabularyList[i].chance / 20);
        cumulative += weight;
        if (randomValue < cumulative) {
            selectedIndex = i;
            break;
        }
    }
    currentEntry = vocabularyList[selectedIndex];
    currentQuestion.meaning = currentEntry.meaning;
    currentQuestion.options.clear();

    // Choose three distractor words (using uniform selection)
    QVector<int> usedIndices;
    usedIndices.append(selectedIndex);
    while (currentQuestion.options.size() < 3) {
        int randIdx = QRandomGenerator::global()->bounded(vocabularyList.size());
        if (!usedIndices.contains(randIdx)) {
            currentQuestion.options.append(vocabularyList[randIdx].word);
            usedIndices.append(randIdx);
        }
    }
    // Insert the correct answer at a random position
    int correctPosition = QRandomGenerator::global()->bounded(4);
    currentQuestion.correctIndex = correctPosition;
    currentQuestion.options.insert(correctPosition, currentEntry.word);

    // Update UI elements
    ui->lblQuestion->setText(currentQuestion.meaning);
    ui->btnOption1->setText(currentQuestion.options[0]);
    ui->btnOption2->setText(currentQuestion.options[1]);
    ui->btnOption3->setText(currentQuestion.options[2]);
    ui->btnOption4->setText(currentQuestion.options[3]);
    ui->lblResult->clear();
}

void Chooes::checkAnswer() {
    // Disable buttons temporarily to prevent multiple clicks
    ui->btnOption1->setEnabled(false);
    ui->btnOption2->setEnabled(false);
    ui->btnOption3->setEnabled(false);
    ui->btnOption4->setEnabled(false);

    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    if (!clickedButton) return;

    int selectedIndex = -1;
    if (clickedButton == ui->btnOption1) selectedIndex = 0;
    else if (clickedButton == ui->btnOption2) selectedIndex = 1;
    else if (clickedButton == ui->btnOption3) selectedIndex = 2;
    else if (clickedButton == ui->btnOption4) selectedIndex = 3;

    bool isCorrect = (selectedIndex == currentQuestion.correctIndex);
    if (isCorrect) {
        ui->lblResult->setText("Correct!");
        // Correct answer: decrease chance by 20 (not below 0)
        currentEntry.chance = qMax(0, currentEntry.chance - 20);
    } else {
        ui->lblResult->setText(QString("Wrong! Correct answer: %1")
                                   .arg(currentQuestion.options[currentQuestion.correctIndex]));
        wrongAnswersCount++;
        // Wrong answer: increase chance by 20 (up to 100)
        currentEntry.chance = qMin(100, currentEntry.chance + 20);
    }
    // Update the in-memory list with the new chance for the current word
    for (int i = 0; i < vocabularyList.size(); i++) {
        if (vocabularyList[i].word == currentEntry.word &&
            vocabularyList[i].meaning == currentEntry.meaning) {
            vocabularyList[i].chance = currentEntry.chance;
            break;
        }
    }
    // Write updated chances back to the CSV file.
    updateCSV();

    QTimer::singleShot(1500, this, &Chooes::nextQuestion);
}

void Chooes::nextQuestion() {
    if (timeRemaining <= 0) return;
    generateQuestion();
    ui->btnOption1->setEnabled(true);
    ui->btnOption2->setEnabled(true);
    ui->btnOption3->setEnabled(true);
    ui->btnOption4->setEnabled(true);
}

void Chooes::updateTimer() {
    timeRemaining--;
    ui->lblTimeRemaining->setText(QString("Time Left: %1 sec").arg(timeRemaining));
    if (timeRemaining <= 0) {
        quizTimer->stop();
        // Here you might add a “time’s up” dialog or summary
        QPointer<QDialog> timeUpDialog = new QDialog(this);
        timeUpDialog->setFixedSize(1200, 800);
        timeUpDialog->setWindowTitle("Time's Up!");
        timeUpDialog->setAttribute(Qt::WA_DeleteOnClose);

        // ตั้งค่าภาพพื้นหลัง
        QLabel *backgroundLabel = new QLabel(timeUpDialog);
        QPixmap backgroundPixmap(":/bgflashc/bgscore.png"); // ใส่ path ของภาพที่ต้องการ
        if (backgroundPixmap.isNull()) {
            qDebug() << "❌ ไม่สามารถโหลดภาพพื้นหลังได้!";
        } else {
            qDebug() << "✅ โหลดภาพพื้นหลังสำเร็จ!";
        }
        backgroundLabel->setPixmap(backgroundPixmap);
        backgroundLabel->setScaledContents(true);
        backgroundLabel->setGeometry(0, 0, 1200, 800);

        // สร้าง QLabel สำหรับข้อความแจ้งเตือน
        QLabel *messageLabel = new QLabel(timeUpDialog);
        messageLabel->setText(QString("<h2 style='color:black;'>Time's up</h2>"
                                      "<h2 style='color:black;'>Incorrect : %1 </h2>")
                                  .arg(wrongAnswersCount));
        messageLabel->setAlignment(Qt::AlignCenter);
        messageLabel->setStyleSheet("font-size: 30px; font-weight: bold; font-family: 'Courier New';");
        messageLabel->setGeometry(520, 270, 400, 200);

        // สร้าง QVBoxLayout สำหรับจัดวางปุ่ม
        //messageLabel->setGeometry(520, 270, 400, 200); // ตั้งค่าตำแหน่งและขนาดเอง

        // สร้างปุ่มปิดเกม
        QPushButton *closeButton = new QPushButton("", timeUpDialog);
        closeButton->setStyleSheet(
            "background-image: url(:/bgmenu/btnmenurezied.png);"
            "border: none;"
            "background-repeat: no-repeat;"
            "background-position: center;"
            );

        // กำหนดขนาดของปุ่มให้ตรงกับภาพ
        QPixmap btnPixmap(":/bgmenu/btnmenurezied.png");
        closeButton->setFixedSize(btnPixmap.size());

        //ตำแแหน่งปุ่ม
        closeButton->setGeometry(860, 630, btnPixmap.width(), btnPixmap.height());

        connect(closeButton, &QPushButton::clicked, this, [this, timeUpDialog]() {
            if (timeUpDialog) {
                timeUpDialog->close();
            }
            close(); // ปิดหน้าต่างหลัก
        });

        // เชื่อมต่อปุ่มกับฟังก์ชันปิดเกม
        connect(closeButton, &QPushButton::clicked, this, &Chooes::closeGame);


        // แสดงหน้าต่าง
        timeUpDialog->exec();

    }
}

void Chooes::updateCSV() {
    QString filePath = QCoreApplication::applicationDirPath() + "/DataUser/" + Dialog::loggedInUser + ".csv";
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "ไม่สามารถเขียนลงไฟล์ได้!");
        return;
    }
    QTextStream out(&file);
    // Write a header and then each vocabulary entry with the updated chance
    out << "word,meaning,chance\n";
    for (const auto &entry : vocabularyList) {
        out << entry.word << "," << entry.meaning << "," << entry.chance << "\n";
    }
    file.close();
}


void Chooes::closeGame()
{

    this->close();
}
