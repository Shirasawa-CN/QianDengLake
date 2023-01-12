#ifndef THANKS_H
#define THANKS_H

#include <QWidget>
#include <QFile>

namespace Ui {
    class Thanks;
}

class Thanks : public QWidget {
Q_OBJECT

public:
    explicit Thanks(QWidget *parent = nullptr);

    ~Thanks();

private:
    Ui::Thanks *ui;
};

#endif // THANKS_H
