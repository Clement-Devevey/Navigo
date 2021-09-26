#ifndef WINHISTORY_H
#define WINHISTORY_H

#include <QDialog>
#include<QBoxLayout>
#include<QTextEdit>
#include<QPushButton>
#include <QWidget>
#include<QDir>
class winHistory : public QDialog
{
public:
    winHistory(const QString& text);
protected:
    QVBoxLayout *history_layout;
    QTextEdit *history_text;
    QPushButton *quit;
};

#endif // WINHISTORY_H
