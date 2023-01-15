#include "qiandenglakeconfigset.h"
#include "ui_qiandenglakeconfigset.h"

#include "editor.h"
#include "enviroment.h"

QianDengLakeConfigSet::QianDengLakeConfigSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QianDengLakeConfigSet)
{
    ui->setupUi(this);
    setWindowTitle("Preferences");
    ui->stackedWidget->addWidget(p_Editor);
    ui->stackedWidget->addWidget(p_Enviroment);

    ui->stackedWidget->setCurrentWidget(p_Editor);
    connect(ui->listWidget,&QListView::clicked,this,[this](QModelIndex pos){
        switch(pos.row()){
        case 0:
            QianDengLakeConfigSet::editorSetSlot();
            break;
        case 1:
            QianDengLakeConfigSet::enviromentSetSlot();
            break;
        }
    });
}

void QianDengLakeConfigSet::editorSetSlot(){
    ui->stackedWidget->setCurrentWidget(p_Editor);
    preferencesInfo.font = p_Editor->font;
}

void QianDengLakeConfigSet::enviromentSetSlot(){
    ui->stackedWidget->setCurrentWidget(p_Enviroment);
}

QianDengLakeConfigSet::~QianDengLakeConfigSet()
{
    delete ui;
}
