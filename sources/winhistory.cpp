#include "winhistory.h"

winHistory::winHistory(const QString& text) : QDialog()
{
    history_text = new QTextEdit;
    history_layout = new QVBoxLayout;
    quit = new QPushButton("quit");

    history_text->setReadOnly(true);
    history_layout->addWidget(history_text);
    history_layout->addWidget(quit);
    history_text->setText(text);
    setLayout(history_layout);
    setWindowTitle("History");
    setWindowIcon(QIcon(QDir::currentPath()+"/history.ico"));

    connect(quit, SIGNAL(clicked()), this, SLOT(accept()));
}
