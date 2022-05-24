#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::activate_fields(QString post)
{
    if (post == "Учитель") {
        for (int i = 0; i < allFields.count(); ++i) {
            allFields[i]->setEnabled(false);
        }
        for (int i = 0; i < teacherFields.count(); ++i) {
            teacherFields[i]->setEnabled(true);
        }
    }

    if (post == "Директор") {
        for (int i = 0; i < allFields.count(); ++i) {
            allFields[i]->setEnabled(false);
        }
        for (int i = 0; i < directorFields.count(); ++i) {
            directorFields[i]->setEnabled(true);
        }
    }

    if (post == "Охранник") {
        for (int i = 0; i < allFields.count(); ++i) {
            allFields[i]->setEnabled(false);
        }
        for (int i = 0; i < securityFields.count(); ++i) {
            securityFields[i]->setEnabled(true);
        }
    }
}

void MainWindow::update_offices_table()
{
    while(ui->orgTable->rowCount() > 0) {
        ui->orgTable->removeRow(0);
    }

    for (int i = 0; i < data_base::i()->offices_count(); ++i) {
        office *x = data_base::i()->get_office_at(i);

        ui->orgTable->insertRow(ui->orgTable->rowCount());

        ui->orgTable->setItem(ui->orgTable->rowCount() - 1, 0,
                              new QTableWidgetItem(x->get_name()));
        ui->orgTable->setItem(ui->orgTable->rowCount() - 1, 1,
                              new QTableWidgetItem(x->get_address()));
        ui->orgTable->setItem(ui->orgTable->rowCount() - 1, 2,
                              new QTableWidgetItem(x->get_phone()));
    }
}

void MainWindow::update_empl_table()
{

}

void MainWindow::disable_all_empl_buttons()
{
    ui->emplSearchReset->setEnabled(false);
    ui->emplSearch->setEnabled(false);
    ui->emplAdd->setEnabled(false);
    ui->emplApply->setEnabled(false);
    ui->emplRemove->setEnabled(false);
    ui->emplRedo->setEnabled(false);
}

void MainWindow::disable_all_office_buttons()
{
    ui->orgRemove->setEnabled(false);
    ui->orgRedo->setEnabled(false);
    ui->orgApply->setEnabled(false);
    ui->orgAdd->setEnabled(false);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    disable_all_office_buttons();
    disable_all_empl_buttons();

     ui->orgAdd->setEnabled(true);

    ui->orgTable->setEditTriggers(nullptr);
    ui->emplTable->setEditTriggers(nullptr);

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

    activate_fields(ui->emplPostBox->currentText());
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
    curOffice = data_base::i()->get_office_at(row);
    ui->orgRedo->setEnabled(true);
    ui->orgRemove->setEnabled(true);
    ui->emplAdd->setEnabled(true);
    update_empl_table();
}


void MainWindow::on_emplPostBox_currentIndexChanged(int index)
{
    activate_fields(ui->emplPostBox->currentText());
}


void MainWindow::on_orgAdd_clicked()
{
    QString name = ui->orgName->text();
    QString address = ui->orgAddress->text();
    QString phone = ui->orgPhone->text();

    office* o = new office(name, address, phone);

    data_base::i()->add_office(o);
    curOffice = o;

    update_offices_table();
    update_empl_table();
}


void MainWindow::on_orgRemove_clicked()
{
    if (orgCell.y() >= 0
            && orgCell.y() < data_base::i()->offices_count()) {
        curOffice = data_base::i()->get_office_at(orgCell.y());
        data_base::i()->remove_office(curOffice);
        update_offices_table();
    }

    if (data_base::i()->offices_count() == 0) {
        disable_all_office_buttons();
        disable_all_empl_buttons();
    }
}


void MainWindow::on_orgRedo_clicked()
{
    if (orgCell.y() >= 0
            && orgCell.y() < data_base::i()->offices_count()) {
        curOffice = data_base::i()->get_office_at(orgCell.y());

        disable_all_office_buttons();
        disable_all_empl_buttons();

        ui->orgApply->setEnabled(true);
        ui->orgTable->setEnabled(false);

        ui->orgName->setText(curOffice->get_name());
        ui->orgAddress->setText(curOffice->get_address());
        ui->orgPhone->setText(curOffice->get_phone());
    }
}


void MainWindow::on_orgApply_clicked()
{
    // check

    QString name = ui->orgName->text();
    QString address = ui->orgAddress->text();
    QString phone = ui->orgPhone->text();

    curOffice->set_name(name);
    curOffice->set_address(address);
    curOffice->set_phone(phone);

    ui->orgApply->setEnabled(false);
    ui->orgTable->setEnabled(true);
    ui->orgAdd->setEnabled(true);
    ui->emplAdd->setEnabled(true);

    update_offices_table();
}

