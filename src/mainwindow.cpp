#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextCursor>
#include <QtDebug>

const char *fileName="/Users/mbidewell/Programming/GUITail/testfile.txt";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(&fileWatcher, &QFileSystemWatcher::fileChanged, this, &MainWindow::updateView);
}

MainWindow::~MainWindow()
{
    watchedFiles.clear();
    delete ui;
}

void MainWindow::updateView(const QString &path)
{
    TailFileInfo& file = watchedFiles[path];
    QFile watchFile(file.absoluteFilePath());

    watchFile.open(QIODevice::ReadOnly);

    QTextStream stream(&watchFile);
    stream.seek(file.position());

    QTextCursor cursor(ui->textBrowser->document());
    while(!stream.atEnd())
    {
        QString line = stream.readLine();
        cursor.movePosition(QTextCursor::End);
        if(line != NULL)
        {
            cursor.insertText(line + "\n");
        }
    }
    cursor.movePosition(QTextCursor::End);
    ui->textBrowser->setTextCursor(cursor);
    file.set_position(stream.pos());
}

void MainWindow::setTailFile(const QString& file)
{
    TailFileInfo fileInfo(file);
    QString fullPath = fileInfo.absoluteFilePath();
    fileWatcher.addPath(fullPath);
    watchedFiles.insert(fullPath, fileInfo);

    this->setWindowTitle(QString("GUITail - ") + fileInfo.fileName());
    updateView(fullPath);
}
