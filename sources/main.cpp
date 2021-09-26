#include "mainwindow.h"
#include<QApplication>
#include<QWidget>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MainWindow myMainWindow;
    myMainWindow.show();
    return app.exec();

}
