#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QtXml>
#include <QFile>
#include <QMessageBox>
#include "graphview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void GraphUpdate();

private slots:
    void on_btn_review_clicked();

    void on_btn_open_clicked();


private:
    Ui::MainWindow *ui;

    GraphView * graphView;


};

#endif // MAINWINDOW_H
