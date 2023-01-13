#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "AboutQianDengLake.h"
#include "thanks.h"
#include "changlog.h"
#include "QianDengLakeProject/QianDengLakeProject.h"
#include "Preferences/qiandenglakeconfigset.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowTitle("QianDeng Lake");
    setCentralWidget(ui->textEdit);

    //check config
    QFile config;
    //if()

    //set textEditor_font
    textEditor_font = ui->textEdit->font();
    textEditor_font.setPointSize(14);
    textEditor_font.setFamily("Fira Code");
    ui->textEdit->setFont(textEditor_font);

    //connect
    connect(ui->actionNew_File, &QAction::triggered, this, &MainWindow::newFile);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::saveFile);
    connect(ui->actionOpen_File, &QAction::triggered, this, &MainWindow::openFile);
    connect(ui->actionExit_s, &QAction::triggered, this, &MainWindow::close);
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

void MainWindow::openFile() {
    filePath = QFileDialog::getOpenFileName(this, "Open File", QCoreApplication::applicationFilePath(), "*.*");
    if (filePath.isEmpty() == false) {
        QFile file(filePath);
        file.open(QIODevice::ReadWrite);
        QByteArray value = file.readAll();
        ui->textEdit->setText(QString(value));
        file.close();
    }
}

void MainWindow::saveFile() {
    if (filePath.isEmpty() == true) {
        filePath = QFileDialog::getSaveFileName(this, "Save File", QCoreApplication::applicationFilePath(), "*.*");
    }
    QFile file(filePath);
    file.open(QIODevice::ReadWrite);
    QByteArray value;
    value.append(ui->textEdit->toPlainText().toStdString().c_str());
    file.write(value);
    file.close();
}

QString MainWindow::setEditorStatus(EditorStatus p) {
    QString result;
    switch (p) {
        case Normal:
            result.fromStdString("Normal");
            break;
        case Insert:
            result.fromStdString("Insert");
            break;
        case Visual:
            result.fromStdString("Visual");
    }
    return result;
}

void MainWindow::thanks() {
    Thanks *thanks = new Thanks;
    thanks->show();
}

void MainWindow::newFile() {
    saveFile();
    ui->textEdit->clear();
    filePath.clear();
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
