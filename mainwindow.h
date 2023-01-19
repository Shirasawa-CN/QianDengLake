#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QString>
#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QFontDialog>
#include <QFontDatabase>
#include <QByteArray>
#include <QAction>
#include <QLabel>
#include <vector>
#include <QFileInfo>
#include <fstream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    void about_QianDeng_Lake();

    void thanks();

    void changLog();

    void qianDengLakeConfigSet();

    void loadPreferences();

private:
    Ui::MainWindow *ui;
    QFont textEditor_font;
    QString filePath;
    std::vector<QString> filePathArray;
    unsigned long long filePathArrayPointer;

    void setEditorFont();
};

#endif // MAINWINDOW_H
