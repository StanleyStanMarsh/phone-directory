#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    this->setGeometry(100, 100, 750, 400);

    layout = new QGridLayout(this);

    load_button = new QPushButton("Загрузить таблицу");
    layout->addWidget(load_button, 0, 0);
    connect(load_button, SIGNAL(clicked(bool)), this, SLOT(loadTable()));

    save_button = new QPushButton("Сохранить таблицу");
    layout->addWidget(save_button, 0, 1);
    connect(save_button, SIGNAL(clicked(bool)), this, SLOT(saveTable()));

    filename_line = new QLineEdit();
    filename_line->setPlaceholderText("Введите имя файла");
    layout->addWidget(filename_line, 0, 2, 1, 1);

    add_row_button = new QPushButton("Добавить строку");
    layout->addWidget(add_row_button, 1, 0);

    del_row_button = new QPushButton("Удалить строку");
    layout->addWidget(del_row_button, 1, 1);

    search_line = new QLineEdit();
    search_line->setPlaceholderText("Поиск");
    layout->addWidget(search_line, 1, 2);

    search_button = new QPushButton("Найти");
    layout->addWidget(search_button, 1, 3);
    connect(search_button, SIGNAL(clicked(bool)), this, SLOT(search()));

    main_table = new PhoneDirectory(this);
    layout->addWidget(main_table, 2, 0, 1, 4);

    connect(add_row_button, SIGNAL(clicked(bool)), main_table, SLOT(addRow()));
    connect(del_row_button, SIGNAL(clicked(bool)), main_table, SLOT(delRow()));
}

MainWindow::~MainWindow()
{
    delete load_button;
    delete save_button;
    delete filename_line;
    delete add_row_button;
    delete del_row_button;
    delete main_table;
}

void MainWindow::loadTable(){
    QFile file(filename_line->text() + ".csv");
    if (!file.open(QIODevice::ReadOnly)) {
        filename_line->setText("Error");
    }
    main_table->addRowsFromCsv(file);
    file.close();
}

void MainWindow::saveTable(){
    QFile file(filename_line->text() + ".csv");
    if (!file.open(QIODevice::WriteOnly)) {
        filename_line->setText("Error");
    }
    main_table->writeRowsToCsv(file);
    file.close();
}

void MainWindow::search() {
    QString finding_text = search_line->text();
    QList<QTableWidgetItem *> items_list = main_table->findItems(finding_text, Qt::MatchContains);
    foreach (QTableWidgetItem* item, items_list) {
        item->setSelected(true);
    }
}
