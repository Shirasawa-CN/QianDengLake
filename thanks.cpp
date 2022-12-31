#include "thanks.h"
#include "ui_thanks.h"

Thanks::Thanks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Thanks)
{
    ui->setupUi(this);
    ui->plainTextEdit->setReadOnly(true);
    setWindowTitle("Thanks");
}

Thanks::~Thanks()
{
    delete ui;
}
