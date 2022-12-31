#ifndef CHANGLOG_H
#define CHANGLOG_H

#include <QWidget>
#include <QFile>
#include <QFileDevice>
#include <QFileDialog>

namespace Ui {
class ChangLog;
}

class ChangLog : public QWidget
{
    Q_OBJECT

public:
    explicit ChangLog(QWidget *parent = nullptr);
    ~ChangLog();

private:
    Ui::ChangLog *ui;
};

#endif // CHANGLOG_H
