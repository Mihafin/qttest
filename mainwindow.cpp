#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QStringListModel>
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    qDebug() << "open from menu";
    this->open_files();
}

void MainWindow::on_btnOpen_clicked()
{
    qDebug() << "open by button";
    this->open_files();
}

void MainWindow::on_btnProcess_clicked()
{
    qDebug() << "process!";
}

void MainWindow::open_files()
{
    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setNameFilter(trUtf8("Images (*.jpg *.png)"));
    QStringList fileNames;
    if (dialog.exec())
        fileNames = dialog.selectedFiles();

    qDebug() << "process!" << fileNames.length();
    if (fileNames.length() > 0){
        this->show_file_list(fileNames);
    }
}

void MainWindow::show_file_list(QStringList &fileNames)
{
    ui->lstFiles->reset();

    QStringListModel *model = new QStringListModel(this);
    model->setStringList(fileNames);
    ui->lstFiles->setModel(model);
}

void MainWindow::on_saveMap_clicked()
{
    qDebug() << "save!";
}

// ******************* MODELS ********************
//    QDirModel *model = new QDirModel(this);//fileNames, QDir::AllDirs, QDir::SortByMask);

//    QStandardItemModel *model = new QStandardItemModel(this);
//    for (int i = 0; i < fileNames.length(); i++)
//    {
//        QString file = fileNames[i];
//        QStandardItem *it = new QStandardItem(QIcon(fileNames[i]), QFileInfo(fileNames[i]).baseName());
//        model->appendRow(it);
//        qDebug() << file;
//    }


//    QPixmap image;
//    image.load(fileNames[0]);
//    image.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation);
//    ui->pixLabel->setPixmap(image);

//    ui->scrollArea->setWidget(ui->pixLabel);
//    ui->pixLabel->
//    image.loadFromData(record(item.row()).value(1).toByteArray()); // column 1 contains BLOB data


// ******************* OPEN DIR ******************
//    QString _dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
//                                                 "/home", //QDir::homePath()
//                                                 QFileDialog::ShowDirsOnly
//                                                 | QFileDialog::DontResolveSymlinks);
//    QDir dir(_dir);
//    QFileInfoList files = dir.entryInfoList();
//    for (int i = 0; i < files.length(); i++)
//    {
//        QFileInfo file = files[i];
//        qDebug() << file.baseName();
//    }
//    qDebug() << "process!" << _dir << files.length();


