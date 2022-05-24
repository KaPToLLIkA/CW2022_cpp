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
    while(ui->emplTable->rowCount() > 0) {
        ui->emplTable->removeRow(0);
    }

    for (int i = 0; i < curOffice->employees_count(); ++i) {
        iemployee* x = curOffice->get_employee_at(i);

        ui->emplTable->insertRow(ui->emplTable->rowCount());

        ui->emplTable->setItem(ui->emplTable->rowCount() - 1, 0,
                              new QTableWidgetItem(x->get_post()));
        ui->emplTable->setItem(ui->emplTable->rowCount() - 1, 1,
                              new QTableWidgetItem(x->get_name()));
        ui->emplTable->setItem(ui->emplTable->rowCount() - 1, 2,
                              new QTableWidgetItem(x->get_surname()));
        ui->emplTable->setItem(ui->emplTable->rowCount() - 1, 3,
                              new QTableWidgetItem(x->get_patronymic()));
        QString salary = "";
        salary.setNum(x->get_salary());
        ui->emplTable->setItem(ui->emplTable->rowCount() - 1, 4,
                              new QTableWidgetItem(salary));
        ui->emplTable->setItem(ui->emplTable->rowCount() - 1, 5,
                              new QTableWidgetItem(x->get_birth_day().toString()));

        if (auto a = dynamic_cast<teacher*>(x)) {
            ui->emplTable->setItem(ui->emplTable->rowCount() - 1, 7,
                                  new QTableWidgetItem(a->get_education()));
            ui->emplTable->setItem(ui->emplTable->rowCount() - 1, 8,
                                  new QTableWidgetItem(a->get_subject()));
        }

        if (auto a = dynamic_cast<director*>(x)) {
            ui->emplTable->setItem(ui->emplTable->rowCount() - 1, 9,
                                  new QTableWidgetItem(a->get_phone()));
        }

        if (auto a = dynamic_cast<security*>(x)) {
            ui->emplTable->setItem(ui->emplTable->rowCount() - 1, 6,
                                  new QTableWidgetItem(a->get_sec_organization()));
        }
    }
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

bool MainWindow::is_valid_office_input()
{
    return true;
}

void MainWindow::update_empl_table_after_search(QString name, QString surname, QString patr, int salary)
{
    while(ui->emplTable->rowCount() > 0) {
        ui->emplTable->removeRow(0);
    }

    for (int i = 0; i < curOffice->employees_count(); ++i) {
        iemployee* x = curOffice->get_employee_at(i);

        if (x->get_name().contains(name)
                && x->get_surname().contains(surname)
                && x->get_patronymic().contains(patr)
                && x->get_salary() > salary) {

            ui->emplTable->insertRow(ui->emplTable->rowCount());

            ui->emplTable->setItem(ui->emplTable->rowCount() - 1, 0,
                                  new QTableWidgetItem(x->get_post()));
            ui->emplTable->setItem(ui->emplTable->rowCount() - 1, 1,
                                  new QTableWidgetItem(x->get_name()));
            ui->emplTable->setItem(ui->emplTable->rowCount() - 1, 2,
                                  new QTableWidgetItem(x->get_surname()));
            ui->emplTable->setItem(ui->emplTable->rowCount() - 1, 3,
                                  new QTableWidgetItem(x->get_patronymic()));
            QString salary = "";
            salary.setNum(x->get_salary());
            ui->emplTable->setItem(ui->emplTable->rowCount() - 1, 4,
                                  new QTableWidgetItem(salary));
            ui->emplTable->setItem(ui->emplTable->rowCount() - 1, 5,
                                  new QTableWidgetItem(x->get_birth_day().toString()));

            if (auto a = dynamic_cast<teacher*>(x)) {
                ui->emplTable->setItem(ui->emplTable->rowCount() - 1, 7,
                                      new QTableWidgetItem(a->get_education()));
                ui->emplTable->setItem(ui->emplTable->rowCount() - 1, 8,
                                      new QTableWidgetItem(a->get_subject()));
            }

            if (auto a = dynamic_cast<director*>(x)) {
                ui->emplTable->setItem(ui->emplTable->rowCount() - 1, 9,
                                      new QTableWidgetItem(a->get_phone()));
            }

            if (auto a = dynamic_cast<security*>(x)) {
                ui->emplTable->setItem(ui->emplTable->rowCount() - 1, 6,
                                      new QTableWidgetItem(a->get_sec_organization()));
            }
        }
    }
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
    if (!searchMode) {
        emplCell = { column, row };
        ui->emplRemove->setEnabled(true);
        ui->emplRedo->setEnabled(true);
        ui->emplSearch->setEnabled(true);
    }
}


void MainWindow::on_orgTable_cellClicked(int row, int column)
{
    orgCell = { column, row };
    curOffice = data_base::i()->get_office_at(row);
    ui->orgRedo->setEnabled(true);
    ui->orgRemove->setEnabled(true);
    ui->emplAdd->setEnabled(true);
    disable_all_empl_buttons();
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
        disable_all_empl_buttons();
        update_offices_table();
    }

    if (data_base::i()->offices_count() == 0) {
        disable_all_office_buttons();
        disable_all_empl_buttons();
        ui->orgAdd->setEnabled(true);
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


void MainWindow::on_emplAdd_clicked()
{
    if (orgCell.y() >= 0 && orgCell.y() < data_base::i()->offices_count()) {
        QString post = ui->emplPostBox->currentText();

        curOffice = data_base::i()->get_office_at(orgCell.y());

        QString name = ui->emplName->text();
        QString surname = ui->emplSurname->text();
        QString patr = ui->emplPatron->text();
        QDate birhtDay = ui->emplBirthDay->date();
        int salary = ui->emplSalary->value();

        if (name.isEmpty() || surname.isEmpty() || patr.isEmpty()
                || birhtDay > QDate::currentDate()) {
            QMessageBox::warning(this, "Внимание!", "Введены некорректные данные");
            return;
        }

        if (post == "Учитель") {
            QString subject = ui->emplSubject->text();
            QString education = ui->emplEducation->text();

            if (subject.isEmpty() || education.isEmpty()) {
                QMessageBox::warning(this, "Внимание!", "Введены некорректные данные");
                return;
            }

            curOffice->add_employee(
                        new teacher(name,
                                    surname, patr,
                                    birhtDay, salary,
                                    education, subject));
            update_empl_table();
            ui->emplSearch->setEnabled(true);
        }

        if (post == "Директор") {
            QString phone = ui->emplPhone->text();

            if (phone.isEmpty()) {
                QMessageBox::warning(this, "Внимание!", "Введены некорректные данные");
                return;
            }

            curOffice->add_employee(
                        new director(name,
                                    surname, patr,
                                    birhtDay, salary,
                                    phone));

            update_empl_table();
            ui->emplSearch->setEnabled(true);
        }

        if (post == "Охранник") {
            QString org = ui->emplOrganization->text();

            if (org.isEmpty()) {
                QMessageBox::warning(this, "Внимание!", "Введены некорректные данные");
                return;
            }

            curOffice->add_employee(
                        new security(name,
                                    surname, patr,
                                    birhtDay, salary,
                                    org));

            update_empl_table();
            ui->emplSearch->setEnabled(true);
        }
    }
}


void MainWindow::on_emplRemove_clicked()
{
    if (orgCell.y() >= 0
            && orgCell.y() < data_base::i()->offices_count()
            && emplCell.y() >= 0
            && emplCell.y() < data_base::i()->get_office_at(orgCell.y())->employees_count()) {

        auto x = data_base::i()->get_office_at(orgCell.y())->get_employee_at(emplCell.y());
        data_base::i()->get_office_at(orgCell.y())->remove_employee(x);

        update_empl_table();
    }
}




void MainWindow::on_emplRedo_clicked()
{
    if (orgCell.y() >= 0
            && orgCell.y() < data_base::i()->offices_count()
            && emplCell.y() >= 0
            && emplCell.y() < data_base::i()->get_office_at(orgCell.y())->employees_count()) {

        disable_all_empl_buttons();
        ui->emplApply->setEnabled(true);
        ui->emplTable->setEnabled(false);

        auto x = data_base::i()->get_office_at(orgCell.y())->get_employee_at(emplCell.y());

        ui->emplName->setText(x->get_name());
        ui->emplSurname->setText(x->get_surname());
        ui->emplBirthDay->setDate(x->get_birth_day());
        ui->emplPatron->setText(x->get_patronymic());
        ui->emplSalary->setValue(x->get_salary());

        if (x->get_post() == "teacher") {
            activate_fields("Учитель");

            auto p = dynamic_cast<teacher*>(x);

            ui->emplEducation->setText(p->get_education());
            ui->emplSubject->setText(p->get_subject());
        }

        if (x->get_post() == "director") {
            activate_fields("Директор");

            auto p = dynamic_cast<director*>(x);

            ui->emplPhone->setText(p->get_phone());
        }

        if (x->get_post() == "security") {
            activate_fields("Охранник");

            auto p = dynamic_cast<security*>(x);

            ui->emplOrganization->setText(p->get_sec_organization());
        }
    }
}


void MainWindow::on_emplApply_clicked()
{
    auto x = data_base::i()->get_office_at(orgCell.y())->get_employee_at(emplCell.y());

    QString name = ui->emplName->text();
    QString surname = ui->emplSurname->text();
    QString patr = ui->emplPatron->text();
    QDate birhtDay = ui->emplBirthDay->date();
    int salary = ui->emplSalary->value();

    if (name.isEmpty() || surname.isEmpty() || patr.isEmpty()
            || birhtDay > QDate::currentDate()) {
        QMessageBox::warning(this, "Внимание!", "Введены некорректные данные");
        return;
    }

    if (x->get_post() == "teacher") {
        QString subject = ui->emplSubject->text();
        QString education = ui->emplEducation->text();

        if (subject.isEmpty() || education.isEmpty()) {
            QMessageBox::warning(this, "Внимание!", "Введены некорректные данные");
            return;
        }

        auto p = dynamic_cast<teacher*>(x);

        p->set_name(name);
        p->set_surname(surname);
        p->set_patronymic(patr);
        p->set_birth_day(birhtDay);
        p->set_salary(salary);
        p->set_education(education);
        p->set_subject(subject);

    }

    if (x->get_post() == "director") {
        QString phone = ui->emplPhone->text();

        if (phone.isEmpty()) {
            QMessageBox::warning(this, "Внимание!", "Введены некорректные данные");
            return;
        }

        auto p = dynamic_cast<director*>(x);

        p->set_name(name);
        p->set_surname(surname);
        p->set_patronymic(patr);
        p->set_birth_day(birhtDay);
        p->set_salary(salary);
        p->set_phone(phone);

    }

    if (x->get_post() == "security") {
        QString org = ui->emplOrganization->text();

        if (org.isEmpty()) {
            QMessageBox::warning(this, "Внимание!", "Введены некорректные данные");
            return;
        }

        auto p = dynamic_cast<security*>(x);

        p->set_name(name);
        p->set_surname(surname);
        p->set_patronymic(patr);
        p->set_birth_day(birhtDay);
        p->set_salary(salary);
        p->set_sec_organization(org);
    }

    update_empl_table();
    disable_all_empl_buttons();
    ui->emplTable->setEnabled(true);
    ui->emplAdd->setEnabled(true);
    ui->emplSearch->setEnabled(true);
}

void MainWindow::on_emplSearch_clicked()
{
    searchMode = true;
    disable_all_office_buttons();
    disable_all_empl_buttons();

    for (int i = 0; i < allFields.count(); ++i) {
        allFields[i]->setEnabled(false);
    }

    ui->emplName->setEnabled(true);
    ui->emplSurname->setEnabled(true);
    ui->emplPatron->setEnabled(true);
    ui->emplSalary->setEnabled(true);
    ui->emplPostBox->setEnabled(false);

    ui->emplSearch->setEnabled(true);
    ui->emplSearchReset->setEnabled(true);

    ui->orgTable->setEnabled(false);

    QString name = ui->emplName->text();
    QString surname = ui->emplSurname->text();
    QString patr = ui->emplPatron->text();
    int salary = ui->emplSalary->value();

    update_empl_table_after_search(name, surname, patr, salary);
}


void MainWindow::on_emplSearchReset_clicked()
{
    searchMode = false;
    activate_fields(ui->emplPostBox->currentText());
    ui->emplPostBox->setEnabled(true);

    ui->orgAdd->setEnabled(true);
    disable_all_empl_buttons();
    ui->emplAdd->setEnabled(true);
    ui->orgTable->setEnabled(true);

    update_empl_table();
}


void MainWindow::on_action_save_triggered()
{
    if (path.isEmpty()) {
        on_action_save_as_triggered();
    } else {
        data_base::i()->unload_to_file(path);
    }
}


void MainWindow::on_action_save_as_triggered()
{
    path = QFileDialog::getSaveFileName(this, "Save as...", "", "*.txt");
    if(path.isEmpty()) return;

    data_base::i()->unload_to_file(path);
    fileWasOpened = true;
}



void MainWindow::on_action_open_triggered()
{
    path = QFileDialog::getOpenFileName(this, "Open...", "", "*.txt");
    if(path.isEmpty()) return;

    data_base::i()->load_from_file(path);
    fileWasOpened = true;

    update_offices_table();

    disable_all_empl_buttons();
    disable_all_office_buttons();

    ui->emplAdd->setEnabled(true);
    ui->orgAdd->setEnabled(true);
}


void MainWindow::on_action_about_triggered()
{

}


void MainWindow::on_action_help_triggered()
{

}

