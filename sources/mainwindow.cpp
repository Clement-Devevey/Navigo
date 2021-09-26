#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    toolBarSetup();
    statusBarSetup();
    tabSetup();
    layoutSetup();
    ShowHistory();
    connectionSetup();

}

void MainWindow::toolBarSetup()
{
    /* Setup tool bar */
    /* Next/Prev page */
    ui->actionPrevious_page->setIcon(QIcon(QDir::currentPath()+"/previous.ico"));
    ui->toolBar->addAction(ui->actionPrevious_page);
    ui->actionNext_page->setIcon(QIcon(QDir::currentPath()+"/next.ico"));
    ui->toolBar->addAction(ui->actionNext_page);
    ui->toolBar->addSeparator();

    /* TAB */
    ui->actionNew_tab->setIcon(QIcon(QDir::currentPath()+"/addTab.ico"));
    ui->toolBar->addAction(ui->actionNew_tab);
    ui->actionClose_tab->setIcon(QIcon(QDir::currentPath()+"/closeTab.ico"));
    ui->toolBar->addAction(ui->actionClose_tab);
    ui->toolBar->addSeparator();
    ui->actionHistory->setIcon(QIcon(QDir::currentPath()+"/history.ico"));
    ui->toolBar->addAction(ui->actionHistory);

    /* home refresh stop loading */
    ui->actionHome->setIcon(QIcon(QDir::currentPath()+"/home.ico"));
    ui->toolBar->addAction(ui->actionHome);
    ui->actionRefresh->setIcon(QIcon(QDir::currentPath()+"/refresh.ico"));
    ui->toolBar->addAction(ui->actionRefresh);
    ui->actionStop_loading->setIcon(QIcon(QDir::currentPath()+"/cancelLoading.ico"));
    ui->toolBar->addAction(ui->actionStop_loading);
    ui->toolBar->addSeparator();

    /* ABOUT PART */
    ui->actionAbout->setIcon(QIcon(QDir::currentPath()+"/help_about.ico"));
    ui->toolBar->addAction(ui->actionAbout);
    ui->actionAbout_QT->setIcon(QIcon(QDir::currentPath()+"/about_QT.png"));
    ui->toolBar->addAction(ui->actionAbout_QT);

    /* Quit */

    ui->actionQuit->setIcon(QIcon(QDir::currentPath()+"/door_in.ico"));
    ui->toolBar->addAction(ui->actionQuit);

}

void MainWindow::connectionSetup()
{
    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(close()));
    connect(tab, SIGNAL(tabCloseRequested(int)), this, SLOT(slotCloseTab(int)));
    connect(listTab[0], SIGNAL(loadProgress(int)), loadingBar, SLOT(setValue(int)));
    connect(listTab[0], SIGNAL(loadFinished(bool)), this, SLOT(slotSetAddressText()));
    connect(tab, SIGNAL(currentChanged(int)), this, SLOT(slotSetAddressText(int)));
    connect(address, SIGNAL(returnPressed()), this, SLOT(slotNewUrl()));
}

MainWindow& MainWindow::tabSetup()
{
    /* Init the vector to contain the homepage */
    listTab.push_back(new QWebEngineView);
    tab = new QTabWidget;

    listTab[0]->setUrl(QUrl("https://www.ciose.fr/"));
    tab->addTab(listTab[0], "Home");
    tab->setTabsClosable(true);
    //this->setCentralWidget(tab);
    return *this;
}

MainWindow& MainWindow::statusBarSetup()
{
    //setStatusBar(ui->statusbar);
    loadingBar = new QProgressBar;
    loadingBar->setTextVisible(true);
    return *this;
}

MainWindow& MainWindow::layoutSetup()
{
    address = new QLineEdit;
    VLayout = new QVBoxLayout;
    address->setText(listTab[0]->url().toDisplayString());
    VLayout->addWidget(address,0);
    VLayout->addWidget(tab,1);
    VLayout->addWidget(loadingBar,2);

    centerWidget = new QWidget;
    centerWidget->setLayout(VLayout);
    setCentralWidget(centerWidget);
    return *this;
}
void MainWindow::writeHistory (const QString& url)
{
    /* History is written from the oldest URL to the most recent one */

    f_history = new QFile(QDir::currentPath()+"/history.txt");
    if ((!f_history->open(QIODevice::WriteOnly | QIODevice::Append))) //Append allows us to store the new content at the end of the file
    {
        delete f_history;
        return;
    }

    QTextStream stream(f_history);

    /* Writing current web page */
    stream << url + " " + QDateTime::currentDateTime().toString() + "\n";

    delete f_history;
}

void MainWindow::ShowHistory()
{
    ui->menuHistory->clear();
    ui->menuHistory->addAction(ui->actionHistory);

    f_history = new QFile(QDir::currentPath()+"/history.txt");
    if ((!f_history->open(QIODevice::ReadOnly )))
    {
        delete f_history;
        return;
    }

    QTextStream* stream = new QTextStream(f_history);
    vector<QString>* listHistory = new vector<QString>;

    while (!(stream->atEnd()))
    {
        listHistory->push_back(stream->readLine());
    }

    for (int i = 1 ; i<6 && i<=listHistory->size() ; i++)
    {
        ui->menuHistory->addAction((*listHistory)[listHistory->size()-i]);
    }

    delete listHistory;
    delete stream;
    delete f_history;
}

void MainWindow::slotCloseTab(int index)
{
    if (index == -1)
    {
        QMessageBox::critical(this, "Attention", "There is no tab to remove !");
        return;
    }

    if (tab->count()==1) //Obligé d'utiliser count(), sinon quand on ferme l'onglet de gauche, il croit que c'est le dernier élément
    {
        address->setVisible(false);
    }
    tab->removeTab(index);
    listTab.erase(listTab.begin() + index);

    if(listTab.size() == 0)
    {
        return;
    }

    QStringList* list1 = new QStringList(listTab[tab->currentIndex()]->url().toDisplayString().split(QLatin1Char('.')));
    if(listTab[tab->currentIndex()]->url().toDisplayString().contains("www"))
    {
        tab->setTabText(tab->currentIndex(), (*list1)[1]);
    }

    else
    {
        tab->setTabText(tab->currentIndex(), (*list1)[0]);
    }

    address->setText(listTab[tab->currentIndex()]->url().toDisplayString());
    delete list1;
}

void MainWindow::slotSetAddressText()
{
    if(listTab.size() == 0)
    {
        return;
    }
    writeHistory(listTab[tab->currentIndex()]->url().toDisplayString());
    ShowHistory();
    QStringList* list1 = new QStringList(listTab[tab->currentIndex()]->url().toDisplayString().split(QLatin1Char('.')));
    if(listTab[tab->currentIndex()]->url().toDisplayString().contains("www"))
    {
        tab->setTabText(tab->currentIndex(), (*list1)[1]);
    }

    else
    {
        tab->setTabText(tab->currentIndex(), (*list1)[0]);
    }

    address->setText(listTab[tab->currentIndex()]->url().toDisplayString());
    delete list1;
}

void MainWindow::slotSetAddressText(int index)
{
    if (index == -1)
    {
        return;
    }
    address->setText(listTab[index]->url().toDisplayString());
}

void MainWindow::slotNewUrl()
{
    if (!(address->text().contains("http://")) && !(address->text().contains("https://")))
    {
        /* Si on entre juste des mots clefs, on va lancer une recherche google */
        QString* temp = new QString;
        *temp = "https://www.google.com/search?q=";
        *temp += address->text().replace(" ", "+");
        address->setText(*temp);
        delete temp;
    }
    listTab[tab->currentIndex()]->load(QUrl(address->text()));
}

void MainWindow::on_actionAbout_QT_triggered()
{
    QMessageBox::aboutQt(this, "About QT");
}

void MainWindow::on_actionAbout_triggered()
{
    QString* textAbout = new QString;
    *textAbout += "Navigo is a web browser developped with QT by Clément Devevey. More information about QT available by clicking About QT button. You can have a look at <a href='https://github.com/Clement-Devevey'>my github</a>.";
    *textAbout += "\n";
    *textAbout += "Icons are from <a href='https://www.softicons.com/web-icons/web-development-icons-4-by-icojoy'>here</a>.";
    QMessageBox::information(this,"About Navigo", *textAbout);
    delete textAbout;
}

void MainWindow::on_actionNew_tab_triggered()
{
    if (listTab.size() == 0)
    {
        address->setVisible(true);
    }
    listTab.push_back( new QWebEngineView);
    listTab[listTab.size()-1]->setUrl(QUrl("https://www.google.fr/"));
    tab->insertTab(tab->count(), listTab[listTab.size()-1], "newTab");
    tab->setCurrentIndex(tab->count() - 1);

    /* Gestion progress bar */
    loadingBar->setValue(0);
    connect(listTab[listTab.size()-1], SIGNAL(loadProgress(int)), loadingBar, SLOT(setValue(int)));
    connect(listTab[listTab.size()-1], SIGNAL(loadFinished(bool)), this, SLOT(slotSetAddressText()));
    connect(tab, SIGNAL(currentChanged(int)), this, SLOT(slotSetAddressText(int)));
}

void MainWindow::on_actionClose_tab_triggered()
{
    if (listTab.size() == 0)
    {
        QMessageBox::critical(this, "Attention", "There is no tab to remove !");
        return;
    }

    if (listTab.size() == 1)
    {
        address->setVisible(false);
    }
    tab->removeTab(tab->currentIndex());
    listTab.erase(listTab.begin() + tab->currentIndex());
    this->slotSetAddressText();
}

void MainWindow::on_actionHome_triggered()
{
    if (listTab.size() == 0)
    {
        QMessageBox::critical(this, "Attention", "There is no tab!");
        return;
    }
    listTab[tab->currentIndex()]->load(QUrl("https://www.qt.io/"));
    this->slotSetAddressText();
}

void MainWindow::on_actionRefresh_triggered()
{
    if (listTab.size() == 0)
    {
        QMessageBox::critical(this, "Attention", "There is no tab!");
        return;
    }
    listTab[tab->currentIndex()]->page()->triggerAction(QWebEnginePage::Reload);
}

void MainWindow::on_actionStop_loading_triggered()
{
    if (listTab.size() == 0)
    {
        QMessageBox::critical(this, "Attention", "There is no tab!");
        return;
    }
    listTab[tab->currentIndex()]->page()->triggerAction(QWebEnginePage::Stop);
}

void MainWindow::on_actionPrevious_page_triggered()
{
    if (listTab.size() == 0)
    {
        QMessageBox::critical(this, "Attention", "There is no tab !");
        return;
    }
    listTab[tab->currentIndex()]->page()->triggerAction(QWebEnginePage::Back);
}

void MainWindow::on_actionNext_page_triggered()
{
    if (listTab.size() == 0)
    {
        QMessageBox::critical(this, "Attention", "There is no tab !");
        return;
    }
    listTab[tab->currentIndex()]->page()->triggerAction(QWebEnginePage::Forward);
}

void MainWindow::on_actionHistory_triggered()
{

    f_history = new QFile(QDir::currentPath()+"/history.txt");
    if ((!f_history->open(QIODevice::ReadOnly )))
    {
        delete f_history;
        return;
    }

    QTextStream* stream = new QTextStream(f_history);
    vector<QString>* listHistory = new vector<QString>;

    while (!(stream->atEnd()))
    {
        listHistory->push_back(stream->readLine());
    }

    QString historyText;
    for (size_t i = listHistory->size() ; i>0 ; i--)
    {
        historyText += (*listHistory)[i-1] + "\n";
    }
    winHistory(historyText).exec();
    delete listHistory;
    delete stream;
    delete f_history;
}

MainWindow::~MainWindow()
{

    for (int i = 0; i< listTab.size();i++)
    {
        listTab[i]->close();
        delete listTab[i];
    }
    delete ui;
}
