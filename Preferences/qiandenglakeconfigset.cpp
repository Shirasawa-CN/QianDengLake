#include "qiandenglakeconfigset.h"
#include "ui_qiandenglakeconfigset.h"

QianDengLakeConfigSet::QianDengLakeConfigSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QianDengLakeConfigSet)
{
    ui->setupUi(this);
    setWindowTitle("Preferences");

    connect(ui->listWidget,&QListView::pressed,this,[this](QModelIndex pos){
        switch(pos.row()){
        case 2:
            QianDengLakeConfigSet::getFontSlot();
            break;
        }
    });
}

void QianDengLakeConfigSet::getFontSlot(){
    font = QFontDialog::getFont(&ok,this->ui->frame->);
}

QianDengLakeConfigSet::~QianDengLakeConfigSet()
{
    delete ui;
}
