#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpressionValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabWidget->setTabText(0,"Phone Number");
    ui->tabWidget->setTabText(1,"Text Browser");
    ui->tabWidget->setTabText(2,"Container");

    QRegularExpressionValidator* areaValidator = new QRegularExpressionValidator(QRegularExpression("[0-9]{1,3}"),ui->areaLineEdit);
    ui->areaLineEdit->setValidator(areaValidator);

    QRegularExpressionValidator* preValidator = new QRegularExpressionValidator(QRegularExpression("[0-9]{1,3}"),ui->prefixLineEdit);
    ui->prefixLineEdit->setValidator(preValidator);

    QRegularExpressionValidator* subValidator = new QRegularExpressionValidator(QRegularExpression("[0-9]{1,4}"),ui->subLineEdit);
    ui->subLineEdit->setValidator(subValidator);

    QRegularExpressionValidator* letterValidator = new QRegularExpressionValidator(QRegularExpression("[A-Z]{1}[a-z]{1}[A-Z]{1}[a-z]{1}[A-Z]{1}[a-z]{1}"),ui->letterLineEdit);
    ui->letterLineEdit->setValidator(letterValidator);

    areaAction = new QAction(QIcon(":/images/red.png"),"Default Area Code", this);
    preAction = new QAction(QIcon(":/images/green.png"),"Default Prefix", this);
    subAction = new QAction(QIcon(":/images/blue.png"),"Default Subscriber", this);

    toolBar = ui->mainToolBar;
    toolBar->addAction(areaAction);
    toolBar->addAction(preAction);
    toolBar->addAction(subAction);
    toolBar->setIconSize(QSize(25,25));

    actionsMenu = menuBar()->addMenu("&Actions");
    actionsMenu->addAction(areaAction);
    actionsMenu->addSeparator();
    actionsMenu->addAction(preAction);
    actionsMenu->addSeparator();
    actionsMenu->addAction(subAction);

    ui->textBrowser->setHtml("<p>Hello.</p><p></p><p>This is a QTextBrowser widget. It may hold formatted text, URLs, and images.</p>");

    ui->lengthButton->click();

    statusLabel = new QLabel("Ready");
    statusBar()->addWidget(statusLabel);

    connect(areaAction, &QAction::triggered, this, &MainWindow::InsertArea);
    connect(preAction, &QAction::triggered, this, &MainWindow::InsertPrefix);
    connect(subAction, &QAction::triggered, this, &MainWindow::InsertSub);

    connect(ui->dialButton, &QPushButton::clicked, this, &MainWindow::Dial);
    connect(ui->clearButton, &QPushButton::clicked, ui->areaLineEdit, &QLineEdit::clear);
    connect(ui->clearButton, &QPushButton::clicked, ui->prefixLineEdit, &QLineEdit::clear);
    connect(ui->clearButton, &QPushButton::clicked, ui->subLineEdit, &QLineEdit::clear);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InsertArea(){
    ui->areaLineEdit->setText("999");
}
void MainWindow::InsertPrefix(){
    ui->prefixLineEdit->setText("999");
}
void MainWindow::InsertSub(){
    ui->subLineEdit->setText("9999");
}

void MainWindow::Dial() {
    QString number = ui->areaLineEdit->text() + "-" +
            ui->prefixLineEdit->text() + "-" +
            ui->subLineEdit->text();
    statusLabel->setText(number);
}
