#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <array>
#include <qvector.h>

#include "model/office.h"
#include "model/teacher.h"
#include "model/director.h"
#include "model/security.h"
#include "model/data_base.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QPoint emplCell = {-1, -1};
    QPoint orgCell = {-1, -1};

    QVector<QWidget*> allFields;
    QVector<QWidget*> teacherFields;
    QVector<QWidget*> directorFields;
    QVector<QWidget*> securityFields;

    office* curOffice;

    void activate_fields(QString post);
    void update_offices_table();
    void update_empl_table();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_emplTable_cellClicked(int row, int column);

    void on_orgTable_cellClicked(int row, int column);

    void on_emplPostBox_currentIndexChanged(int index);

    void on_orgAdd_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
