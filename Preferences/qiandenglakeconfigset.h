#ifndef QIANDENGLAKECONFIGSET_H
#define QIANDENGLAKECONFIGSET_H

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

private:
    Ui::QianDengLakeConfigSet *ui;
    bool ok = true;
    QFont font;
private slots:
    void getFontSlot();
};
#endif // QIANDENGLAKECONFIGSET_H
