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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    enum EditorStatus{
        Normal,
        Insert,
        Visual,
    };
    Q_ENUM(EditorStatus);

private slots:
    void about_QianDeng_Lake();
    void openFile();
    void saveFile();
    void thanks();
    void newFile();
    void changLog();

private:
    Ui::MainWindow *ui;
    QFont textEditor_font;
    QString filePath;
    std::vector<QString> filePathArray;
    unsigned long long filePathArrayPointer;

    void setEditorFont();
    QString setEditorStatus(EditorStatus p);
};
#endif // MAINWINDOW_H
