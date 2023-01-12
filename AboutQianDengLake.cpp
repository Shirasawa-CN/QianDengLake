#include "AboutQianDengLake.h"
#include "ui_AboutQianDengLake.h"

AboutQianDengLake::AboutQianDengLake(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::AboutQianDengLake) {
    ui->setupUi(this);
    QFile file(":/Project Info/LICENSE");
    file.open(QIODevice::ReadOnly);
    QByteArray value = file.readAll();
    ui->plainTextEdit->setPlainText(value);
    ui->plainTextEdit->setReadOnly(true);
    setWindowTitle("About QianDeng Lake");
    setMaximumSize(500, 400);
    setMinimumSize(500, 400);
}

AboutQianDengLake::~AboutQianDengLake() {
    delete ui;
}
