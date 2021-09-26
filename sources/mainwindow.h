#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMessageBox>
#include <QWebEngineView>
#include <vector>
#include<QDebug>
#include<QProgressBar>
#include<QLineEdit>


#include "winhistory.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void toolBarSetup();
    void connectionSetup();
    MainWindow& tabSetup();
    MainWindow& statusBarSetup();
    MainWindow& layoutSetup();
    void writeHistory (const QString& url);
    void ShowHistory();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTabWidget* tab;
    std::vector<QWebEngineView*> listTab;
    QProgressBar* loadingBar;
    QVBoxLayout* VLayout;
    QWidget* centerWidget;
    QLineEdit* address;

    QFile* f_history;

private slots:
    void slotCloseTab(int index);
    void slotSetAddressText();
    void slotSetAddressText(int index);
    void slotNewUrl();


    void on_actionAbout_QT_triggered();
    void on_actionAbout_triggered();
    void on_actionNew_tab_triggered();
    void on_actionClose_tab_triggered();
    void on_actionHome_triggered();
    void on_actionRefresh_triggered();
    void on_actionStop_loading_triggered();
    void on_actionPrevious_page_triggered();
    void on_actionNext_page_triggered();
    void on_actionHistory_triggered();







};

#endif // MAINWINDOW_H
