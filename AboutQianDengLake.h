#ifndef ABOUTQIANDENGLAKE_H
#define ABOUTQIANDENGLAKE_H

#include <QWidget>
#include <QFile>

namespace Ui {
    class AboutQianDengLake;
}

class AboutQianDengLake : public QWidget {
Q_OBJECT

public:
    explicit AboutQianDengLake(QWidget *parent = nullptr);

    ~AboutQianDengLake();

private:
    Ui::AboutQianDengLake *ui;
};

#endif // ABOUTQIANDENGLAKE_H
