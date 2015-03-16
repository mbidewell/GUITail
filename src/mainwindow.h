#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemWatcher>
#include <QFile>
#include <QMap>

#include "tailfileinfo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setTailFile(const QString& file);

private:
    Ui::MainWindow *ui;
    QFileSystemWatcher fileWatcher;
    QMap<QString, TailFileInfo> watchedFiles;

private slots:
    void updateView(const QString &path);
};

#endif // MAINWINDOW_H
