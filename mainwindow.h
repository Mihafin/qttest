#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_btnOpen_clicked();

    void on_btnProcess_clicked();

    void on_saveMap_clicked();

private:
    Ui::MainWindow *ui;
    void open_files();
    void show_file_list(QStringList &fileNames);
};

#endif // MAINWINDOW_H
