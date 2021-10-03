#include "winhistory.h"

winHistory::winHistory(const QStringList& text, std::vector<QWebEngineView*> *pages, QTabWidget* tab) : QDialog()
{
    this->pages = pages;

    this->tab =tab;

    model = new QStringListModel();
    model->setStringList(text);
    viewListHistory = new QListView();
    viewListHistory->setModel(model);


    history_layout = new QVBoxLayout;
    buttons_layout = new QHBoxLayout;
    quit = new QPushButton("quit");
    load = new QPushButton("load");
    buttons_layout->addWidget(load);
    buttons_layout->addWidget(quit);

    history_layout->addWidget(viewListHistory);
    history_layout->addLayout(buttons_layout);

    setLayout(history_layout);
    setWindowTitle("History");
    setWindowIcon(QIcon(QDir::currentPath()+"/history.ico"));
    resize(500,500);
    connect(load, SIGNAL(clicked()), this, SLOT(load_url()));
    connect(quit, SIGNAL(clicked()), this, SLOT(accept()));
}

void winHistory::load_url()
{
    //Get the selected item and then load the url
    QVariant selectedItem = model->data(viewListHistory->selectionModel()->currentIndex(), Qt::DisplayRole);
    (*pages)[tab->currentIndex()]->load(QUrl(selectedItem.toString().split(" ")[0]));
    accept();
}
