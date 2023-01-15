#include "enviroment.h"
#include "ui_enviroment.h"

Enviroment::Enviroment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Enviroment)
{
    ui->setupUi(this);
}

Enviroment::~Enviroment()
{
    delete ui;
}
