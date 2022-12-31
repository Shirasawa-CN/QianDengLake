#include "changlog.h"
#include "ui_changlog.h"

ChangLog::ChangLog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangLog)
{
    ui->setupUi(this);
    QFile file(":/Project Info/Change Log.txt");
    file.open(QIODevice::ReadOnly);
    QByteArray value = file.readAll();
    ui->plainTextEdit->setPlainText(value);
    ui->plainTextEdit->setReadOnly(true);
    file.close();
    setWindowTitle("Chang Log");
}

ChangLog::~ChangLog()
{
    delete ui;
}
