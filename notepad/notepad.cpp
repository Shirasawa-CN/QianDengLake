#include "notepad.h"
#include "ui_notepad.h"

notepad::notepad(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::notepad)
{
  ui->setupUi(this);

  ui->textEdit->setAutoIndent(true);
  ui->textEdit->setCaretLineVisible(true);
  ui->textEdit->setCaretLineBackgroundColor(QColor("#808080"));
  // 设置行号区和行号区宽度
  ui->textEdit->setMarginType(0, QsciScintilla::NumberMargin);
  ui->textEdit->setMarginWidth(0, 30);
  // 设置符号区和符号区宽度
  ui->textEdit->setMarginType(1, QsciScintilla::SymbolMargin);
  ui->textEdit->setMarginWidth(1, 20);
  // 编辑器放大
  ui->textEdit->zoomIn(8);
}

notepad::~notepad()
{
  delete ui;
}
