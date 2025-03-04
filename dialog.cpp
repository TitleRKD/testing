#include "dialog.h"
#include "ui_dialog.h"
#include <QCoreApplication>
#include <QDir>
#include <QRegularExpression>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>

QString Dialog::loggedInUser = "";

int regis = 1;
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setFixedSize(455,187);
    ui->username->setStyleSheet("QLineEdit { background: white; color: black; border: 1px solid gray; padding: 4px; }");
    ui->password->setStyleSheet("QLineEdit { background: white; color: black; border: 1px solid gray; padding: 4px; }");

    connect(ui->btnOK, &QPushButton::clicked, this, &Dialog::registerUser);
    connect(ui->btnCancel, &QPushButton::clicked, this, &Dialog::reject);
}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::getFilePath() {
    QString dirPath = QCoreApplication::applicationDirPath() + "/DataUser";
    QDir dir(dirPath);
    if (!dir.exists()) {
        dir.mkpath(".");
    }
    return dirPath + "/users.csv";
}
int Dialog::userExist(const QString &username,const QString &password) {
    QFile file(getFilePath());
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return 0;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");
        if (parts.size() > 1 && parts[0] == username && parts.size() > 1 && parts[1] == password ){
            file.close();
            return 2;
        }
        if (parts.size() > 1 && parts[0] == username) {
            file.close();
            return 1;
        }
    }
    file.close();
    return 0;
}

void Dialog::registerUser() {
    QString filePath = getFilePath();
    QString username = ui->username->text().trimmed();
    QString passwordInput = ui->password->text();
    QString password = passwordInput.trimmed();

    if (regis == 1){
        if (username.isEmpty() || password.isEmpty()) {
            QMessageBox::warning(this, "Error", "Username or password cannot be empty!");
            return;
        }
        if (passwordInput != password) {
            QMessageBox::warning(this, "Error", "Password must not contain spaces!");
            return;
        }

        QRegularExpression regex("^[0-9]+$");
        if (!regex.match(password).hasMatch()) {
            QMessageBox::warning(this, "Error", "Password must contain only numbers!");
            return;
        }

        // Check if user exists
        if (userExist(username,password) == 2) {
            QMessageBox::information(this, "Login", "Welcome!");
            loggedInUser = username; // set logged in user
            regis = 0;
            this->accept();
            return;
        }
        if (userExist(username,password) == 1) {
            QMessageBox::warning(this, "Error", "User already exists!");
            return;
        }

        // Append new user to users.csv
        QFile file(filePath);
        if (!file.open(QIODevice::Append | QIODevice::Text)) {
            QMessageBox::critical(this, "Error", "Failed to open file!");
            return;
        }
        QTextStream out(&file);
        out << username << "," << password << "\n";
        file.close();

        // Copy the vocabulary file and rename it as username.csv in DataUser folder
        QString srcFile = QCoreApplication::applicationDirPath() + "/vocabulary_list.csv";  // adjust if your base file is vocabulary.csv
        QString destDir = QCoreApplication::applicationDirPath() + "/DataUser";
        QDir().mkpath(destDir);  // ensure the DataUser directory exists
        QString destFile = destDir + "/" + username + ".csv";
        if (!QFile::copy(srcFile, destFile)) {
            QMessageBox::warning(this, "Error", "Failed to create user vocabulary file!");
        } else {
            QMessageBox::information(this, "Success", "User registered successfully!");
        }
        loggedInUser = username; // update logged in user
        regis = 0;
        this->accept();
    }
}


bool Dialog::loginUser() {
    QString filePath = getFilePath();
    QString username = ui->username->text().trimmed();
    QString password = ui->password->text().trimmed();

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Failed to open file!");
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");
        if (parts.size() > 1 && parts[0] == username && parts[1] == password) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void Dialog::on_btnOK_clicked() {
    if (regis == 0){
        if (loginUser()) {
            qDebug() << "signals success"; // ผ่านแล้ว แต่ตอนนี้ปิดฟังก์ชั่นเช็คซ้ำทั้งหมดแล้ว
            //QMessageBox::information(this, "Login Success", "Welcome!");
            regis = 1;
            //if (loginUser()) {
            //    QMessageBox::information(this, "Login Success", "Welcome!");
            emit loginSuccess();  // ส่งสัญญาณไปยัง MainWindow
            this->accept();  //ปิด Dialog
        } else {
            QMessageBox::warning(this, "Login Failed", "Invalid username or password!");
            qDebug() << "signals fail";
        }
    }
}
