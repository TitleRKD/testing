#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>  // เพิ่มเพื่อให้แน่ใจว่า QString ถูก include

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

signals:
    void loginSuccess();

private slots:
    void registerUser();
    bool loginUser();
    void on_btnOK_clicked();

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    static QString loggedInUser;

private:
    Ui::Dialog *ui;
    QString getFilePath();
    int userExist(const QString &username, const QString &password);
};

#endif // DIALOG_H
