#ifndef QIANDENGLAKECONFIGSET_H
#define QIANDENGLAKECONFIGSET_H

#include "editor.h"
#include "enviroment.h"
#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QFontDialog>

namespace Ui {
class QianDengLakeConfigSet;
}

class QianDengLakeConfigSet : public QWidget
{
    Q_OBJECT

public:
    explicit QianDengLakeConfigSet(QWidget *parent = nullptr);
    ~QianDengLakeConfigSet();
    struct preferencesInfo{
        QFont font;
    }preferencesInfo;

private:
    Ui::QianDengLakeConfigSet *ui;

    void hideAllWidget();
    Editor *p_Editor = new Editor;
    Enviroment *p_Enviroment = new Enviroment;

    void editorSetSlot();
    void enviromentSetSlot();
private slots:

};
#endif // QIANDENGLAKECONFIGSET_H
