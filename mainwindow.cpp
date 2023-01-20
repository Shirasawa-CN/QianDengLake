#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "AboutQianDengLake.h"
#include "thanks.h"
#include "changlog.h"
#include "QianDengLakeProject/QianDengLakeProject.h"
#include "Preferences/qiandenglakeconfigset.h"
#include "notepad/notepad.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    setWindowTitle("QianDeng Lake");
    setCentralWidget(ui->centralwidget);

    ui->editorTabWidget->setTabsClosable(true);
    notepad *defualt_editor = new notepad;
    defualt_editor->load_lexer(Language::Cpp);
    ui->editorTabWidget->addTab(defualt_editor,"new");
    ui->editorTabWidget->setMovable(true);

    //check config
    QFile config;
    //if()

    //set textEditor_font
    textEditor_font = ui->editorTabWidget->font();
    textEditor_font.setPointSize(14);
    textEditor_font.setFamily("Fira Code");
    ui->editorTabWidget->setFont(textEditor_font);

    //connect
    connect(ui->actionAbout_QianDeng_Lake, &QAction::triggered, this, &MainWindow::about_QianDeng_Lake);
    connect(ui->actionThanks, &QAction::triggered, this, &MainWindow::thanks);
    connect(ui->actionChange_Log, &QAction::triggered, this, &MainWindow::changLog);
    connect(ui->actionPreferences,&QAction::triggered,this,&MainWindow::qianDengLakeConfigSet);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::about_QianDeng_Lake() {
    AboutQianDengLake *about_QianDeng_Lake = new AboutQianDengLake;
    about_QianDeng_Lake->show();
}

void MainWindow::thanks() {
    Thanks *thanks = new Thanks;
    thanks->show();
}

void MainWindow::changLog() {
    ChangLog *p = new ChangLog;
    p->show();
}

void MainWindow::qianDengLakeConfigSet() {
    QianDengLakeConfigSet *p = new QianDengLakeConfigSet;
    p->show();
}

void MainWindow::loadPreferences(){
}
