#ifndef WINHISTORY_H
#define WINHISTORY_H

#include <QDialog>
#include<QBoxLayout>
#include<QTextEdit>
#include<QPushButton>
#include <QWidget>
#include<QDir>
#include<QListView>
#include<QStringListModel>
#include<QWebEngineView>
#include<vector>
class winHistory : public QDialog
{
    Q_OBJECT
public:
    winHistory(const QStringList& text, std::vector<QWebEngineView*> *pages, QTabWidget* tab);
protected:
    QVBoxLayout *history_layout;
    QHBoxLayout *buttons_layout;
    QStringListModel *model;
    QListView* viewListHistory;
    QPushButton *quit;
    QPushButton *load;
    //Get properties from mainwindow
    std::vector<QWebEngineView*> *pages;
    QTabWidget* tab;

private slots:
    void load_url();
};

#endif // WINHISTORY_H
