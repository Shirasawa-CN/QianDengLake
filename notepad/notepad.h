#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QWidget>

#include <Qsci/qsciscintilla.h>
#include <Qsci/qscicommand.h>
#include <Qsci/qscicommand.h>
#include <Qsci/qscilexer.h>
#include <Qsci/qscilexercpp.h>

namespace Ui {
  class notepad;
}

class notepad : public QWidget
{
  Q_OBJECT

public:
  explicit notepad(QWidget *parent = nullptr);
  ~notepad();

private:
  Ui::notepad *ui;
};

#endif // NOTEPAD_H
