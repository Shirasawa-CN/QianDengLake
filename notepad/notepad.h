#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QWidget>

#include <Qsci/qsciscintilla.h>
#include <Qsci/qscicommand.h>
#include <Qsci/qscicommand.h>
#include <Qsci/qscilexer.h>
#include <Qsci/qscilexercpp.h>
#include <Qsci/qscilexercustom.h>
#include <Qsci/qscilexermatlab.h>
#include <Qsci/qsciapis.h>

namespace Ui {
  class notepad;
}

typedef enum Language{
  Cpp,
  Rust,
  ASM,
}Language;

class notepad : public QWidget
{
  Q_OBJECT

public:
  explicit notepad(QWidget *parent = nullptr);
  ~notepad();
  void load_lexer(Language whichLanguage);
private:
  Ui::notepad *ui;
  QsciAPIs *apis;
};

#endif // NOTEPAD_H
