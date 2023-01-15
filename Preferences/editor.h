#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>
#include <QFont>
#include <QFontDialog>

namespace Ui {
class Editor;
}

class Editor : public QWidget
{
    Q_OBJECT

public:
    explicit Editor(QWidget *parent = nullptr);
    ~Editor();
    QFont font;

private slots:

    void on_setFontButton_clicked();

private:
    Ui::Editor *ui;
    bool ok = true;
};

#endif // EDITOR_H
