#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <array>
#include <qvector.h>

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
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_emplTable_cellClicked(int row, int column);

    void on_orgTable_cellClicked(int row, int column);

    void on_emplPostBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
