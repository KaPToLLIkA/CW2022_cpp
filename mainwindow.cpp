#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->emplSearchReset->setEnabled(false);
    ui->emplSearch->setEnabled(false);
    ui->emplAdd->setEnabled(false);
    ui->emplApply->setEnabled(false);
    ui->emplRemove->setEnabled(false);
    ui->emplRedo->setEnabled(false);

    allFields.append(ui->emplName);
    allFields.append(ui->emplSurname);
    allFields.append(ui->emplPatron);
    allFields.append(ui->emplBirthDay);
    allFields.append(ui->emplSalary);
    allFields.append(ui->emplEducation);
    allFields.append(ui->emplSubject);
    allFields.append(ui->emplPhone);
    allFields.append(ui->emplOrganization);

    teacherFields.append(ui->emplName);
    teacherFields.append(ui->emplSurname);
    teacherFields.append(ui->emplPatron);
    teacherFields.append(ui->emplBirthDay);
    teacherFields.append(ui->emplSalary);
    teacherFields.append(ui->emplEducation);
    teacherFields.append(ui->emplSubject);

    directorFields.append(ui->emplName);
    directorFields.append(ui->emplSurname);
    directorFields.append(ui->emplPatron);
    directorFields.append(ui->emplBirthDay);
    directorFields.append(ui->emplSalary);
    directorFields.append(ui->emplPhone);

    securityFields.append(ui->emplName);
    securityFields.append(ui->emplSurname);
    securityFields.append(ui->emplPatron);
    securityFields.append(ui->emplBirthDay);
    securityFields.append(ui->emplSalary);
    securityFields.append(ui->emplOrganization);
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


void MainWindow::on_emplPostBox_currentIndexChanged(int index)
{
    if (ui->emplPostBox->currentText() == "Учитель") {
        for (int i = 0; i < allFields.count(); ++i) {
            allFields[i]->setEnabled(false);
        }
        for (int i = 0; i < teacherFields.count(); ++i) {
            teacherFields[i]->setEnabled(true);
        }
    }

    if (ui->emplPostBox->currentText() == "Директор") {
        for (int i = 0; i < allFields.count(); ++i) {
            allFields[i]->setEnabled(false);
        }
        for (int i = 0; i < teacherFields.count(); ++i) {
            teacherFields[i]->setEnabled(true);
        }
    }

    if (ui->emplPostBox->currentText() == "Охранник") {
        for (int i = 0; i < allFields.count(); ++i) {
            allFields[i]->setEnabled(false);
        }
        for (int i = 0; i < teacherFields.count(); ++i) {
            teacherFields[i]->setEnabled(true);
        }
    }
}

