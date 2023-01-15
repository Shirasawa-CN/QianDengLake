#ifndef ENVIROMENT_H
#define ENVIROMENT_H

#include <QWidget>

namespace Ui {
class Enviroment;
}

class Enviroment : public QWidget
{
    Q_OBJECT

public:
    explicit Enviroment(QWidget *parent = nullptr);
    ~Enviroment();

private:
    Ui::Enviroment *ui;
};

#endif // ENVIROMENT_H
