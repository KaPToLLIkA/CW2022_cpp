#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_emplTable_cellClicked(int row, int column)
{
    emplCell = { column, row };
}


void MainWindow::on_orgTable_cellClicked(int row, int column)
{
    orgCell = { column, row };
}

