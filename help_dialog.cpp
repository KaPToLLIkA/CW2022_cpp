#include "help_dialog.h"
#include "ui_help_dialog.h"

help_dialog::help_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help_dialog)
{
    ui->setupUi(this);
    setWindowTitle("Помощь");
}

help_dialog::~help_dialog()
{
    delete ui;
}

void help_dialog::on_pushButton_clicked()
{
    this->close();
}

