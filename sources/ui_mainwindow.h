/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionPrevious_page;
    QAction *actionNext_page;
    QAction *actionRefresh;
    QAction *actionStop_loading;
    QAction *actionNew_tab;
    QAction *actionClose_tab;
    QAction *actionQuit;
    QAction *actionAbout;
    QAction *actionAbout_QT;
    QAction *actionHome;
    QAction *actionHistory;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuBrowsing;
    QMenu *menuHistory;
    QMenu *about;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionPrevious_page = new QAction(MainWindow);
        actionPrevious_page->setObjectName(QString::fromUtf8("actionPrevious_page"));
        actionNext_page = new QAction(MainWindow);
        actionNext_page->setObjectName(QString::fromUtf8("actionNext_page"));
        actionRefresh = new QAction(MainWindow);
        actionRefresh->setObjectName(QString::fromUtf8("actionRefresh"));
        actionStop_loading = new QAction(MainWindow);
        actionStop_loading->setObjectName(QString::fromUtf8("actionStop_loading"));
        actionNew_tab = new QAction(MainWindow);
        actionNew_tab->setObjectName(QString::fromUtf8("actionNew_tab"));
        actionClose_tab = new QAction(MainWindow);
        actionClose_tab->setObjectName(QString::fromUtf8("actionClose_tab"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_QT = new QAction(MainWindow);
        actionAbout_QT->setObjectName(QString::fromUtf8("actionAbout_QT"));
        actionHome = new QAction(MainWindow);
        actionHome->setObjectName(QString::fromUtf8("actionHome"));
        actionHistory = new QAction(MainWindow);
        actionHistory->setObjectName(QString::fromUtf8("actionHistory"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuBrowsing = new QMenu(menubar);
        menuBrowsing->setObjectName(QString::fromUtf8("menuBrowsing"));
        menuHistory = new QMenu(menuBrowsing);
        menuHistory->setObjectName(QString::fromUtf8("menuHistory"));
        about = new QMenu(menubar);
        about->setObjectName(QString::fromUtf8("about"));
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuBrowsing->menuAction());
        menubar->addAction(about->menuAction());
        menuFile->addAction(actionNew_tab);
        menuFile->addAction(actionClose_tab);
        menuFile->addAction(actionQuit);
        menuBrowsing->addAction(actionPrevious_page);
        menuBrowsing->addAction(actionNext_page);
        menuBrowsing->addAction(actionRefresh);
        menuBrowsing->addAction(actionStop_loading);
        menuBrowsing->addAction(actionHome);
        menuBrowsing->addAction(menuHistory->menuAction());
        menuHistory->addAction(actionHistory);
        about->addAction(actionAbout);
        about->addAction(actionAbout_QT);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Navigo by Cl\303\251ment Devevey", nullptr));
        actionPrevious_page->setText(QCoreApplication::translate("MainWindow", "Previous page", nullptr));
#if QT_CONFIG(shortcut)
        actionPrevious_page->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Left", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNext_page->setText(QCoreApplication::translate("MainWindow", "Next page", nullptr));
        actionRefresh->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
#if QT_CONFIG(shortcut)
        actionRefresh->setShortcut(QCoreApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        actionStop_loading->setText(QCoreApplication::translate("MainWindow", "Stop loading", nullptr));
#if QT_CONFIG(shortcut)
        actionStop_loading->setShortcut(QCoreApplication::translate("MainWindow", "F4", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNew_tab->setText(QCoreApplication::translate("MainWindow", "New tab", nullptr));
        actionClose_tab->setText(QCoreApplication::translate("MainWindow", "Close tab", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
#if QT_CONFIG(shortcut)
        actionQuit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionAbout_QT->setText(QCoreApplication::translate("MainWindow", "About QT", nullptr));
        actionHome->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        actionHistory->setText(QCoreApplication::translate("MainWindow", "History", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuBrowsing->setTitle(QCoreApplication::translate("MainWindow", "Browsing", nullptr));
        menuHistory->setTitle(QCoreApplication::translate("MainWindow", "History", nullptr));
        about->setTitle(QCoreApplication::translate("MainWindow", "?", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
