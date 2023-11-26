#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include "phonedirectory.h"

class MainWindow : public QWidget
{
    Q_OBJECT

    QGridLayout *layout;

    QPushButton *load_button;
    QPushButton *save_button;
    QLineEdit *filename_line;

    QPushButton *add_row_button;
    QPushButton *del_row_button;

    QLineEdit *search_line;
    QPushButton *search_button;

    PhoneDirectory *main_table;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void loadTable();
    void saveTable();
    void search();
};
#endif // MAINWINDOW_H
