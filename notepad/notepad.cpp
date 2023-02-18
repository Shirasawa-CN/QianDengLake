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
  // 设置字体
}

void notepad::load_lexer(Language whichLanguage){
  switch (whichLanguage){
    case Language::Cpp:
      QsciLexerCPP *lexer = new QsciLexerCPP;
      ui->textEdit->setLexer(lexer);
      apis = new QsciAPIs(lexer);
      apis->load(":/Cpp.txt");
      apis->prepare();
      ui->textEdit->setAutoCompletionSource(QsciScintilla::AcsAll);
      ui->textEdit->setAutoCompletionThreshold(1);
      break;
    /*
    case Language::ASM:
      break;
    case Language::Rust:
      break;
      */
  }
}

notepad::~notepad()
{
  delete ui;
}
