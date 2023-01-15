#include "editor.h"
#include "ui_editor.h"


Editor::Editor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);

    connect(ui->setFontButton,&QPushButton::pressed,this,&Editor::on_setFontButton_clicked);
}

Editor::~Editor()
{
    delete ui;
}

void Editor::on_setFontButton_clicked()
{
    font = QFontDialog::getFont(&ok,this);
}

