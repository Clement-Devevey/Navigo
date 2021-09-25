#include "mainwindow.h"
#include<QApplication>
#include<QWidget>

int main(int arc, char* arv[])
{
    QApplication myApp(arc, arv);
    MainWindow myMainWindow;
    myMainWindow.show();
    return myApp.exec();

}
