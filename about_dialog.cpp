#include "about_dialog.h"
#include "ui_about_dialog.h"

about_dialog::about_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about_dialog)
{
    ui->setupUi(this);
    setWindowTitle("О программе");
}

about_dialog::~about_dialog()
{
    delete ui;
}

void about_dialog::on_pushButton_clicked()
{
    this->close();
}

