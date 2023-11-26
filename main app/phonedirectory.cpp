#include "phonedirectory.h"

PhoneDirectory::PhoneDirectory(QWidget *parent) : QTableWidget(parent)
{
    this->setColumnCount(7);
    QStringList headers;
    headers << "Фамилия" << "Имя" << "Отчество" << "Адрес" << "Дата рождения" << "Email" << "Номер телефона";
    this->setHorizontalHeaderLabels(headers);

    this->setSortingEnabled(true);
}

void PhoneDirectory::addRowsFromCsv(QFile& file) {
    for (int r = 0; r < this->rowCount(); r++)
        for (int c = 0; c < this->columnCount(); c++)
            delete this->item(r, c);

    QTextStream stream(&file);
    while (!stream.atEnd()) {
        this->addRow();
        QStringList row = stream.readLine().split(';');
        this->fillLastRow(row);
    }
}

void PhoneDirectory::writeRowsToCsv(QFile& file) {
    QTextStream stream(&file);
    for (int r = 0; r < this->rowCount(); r++) {
        for (int c = 0; c < this->columnCount() - 1; c++)
        {
            this->item(r, c) ?
                        (stream << this->item(r, c)->text() << ';') : (stream << ';');
        }
        this->item(r, this->columnCount() - 1) ?
                    (stream << this->item(r, this->columnCount() - 1)->text() << '\n') : (stream << '\n');
    }
}

void PhoneDirectory::fillLastRow(QStringList str_list) {
    QVector<QString> str_vec;
    foreach( QString str, str_list) {
        str_vec.push_back(str);
//        qDebug() << str;
    }

    int last_row = this->rowCount()-1;
    for (int c = 0; c < this->columnCount(); c++) {
        if (c == 4) {
            QDate date = QDate::fromString(str_vec[c], "yyyy-MM-dd");
            DateItem* item = dynamic_cast<DateItem*>(this->item(last_row, c));
            item->setDate(date);
            dynamic_cast<QDateEdit*>(this->cellWidget(last_row, c))->setDate(date);
        }
        else
//            qDebug() << str_vec[c];
            this->item(last_row, c)->setText(str_vec[c]);
    }
}

void PhoneDirectory::addRow() {
    this->insertRow(this->rowCount());

    for (int i = 0; i < 3; i++)
        this->setItem(this->rowCount()-1, i, new NameLine);

    this->setItem(this->rowCount()-1, 3, new QTableWidgetItem);

    this->setItem(this->rowCount()-1, 5, new EmailLine);

    this->setItem(this->rowCount()-1, 6, new PhoneLine);

    QDateEdit *date = new QDateEdit();
    this->setCellWidget(this->rowCount()-1, 4, date);

    DateItem* date_item = new DateItem();
    this->setItem(this->rowCount()-1, 4, date_item);
    connect(date, SIGNAL(dateChanged(QDate)), date_item, SLOT(setDate(QDate)));

    connect(this, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(handleItem(QTableWidgetItem*)));
}

void PhoneDirectory::delRow() {
    int row = this->currentRow();
    if (row > -1) {
        for (int i = 0; i < this->columnCount(); i++)
            delete this->item(row, i);
        this->removeRow(row);
    }
}

void PhoneDirectory::handleItem(QTableWidgetItem* item) {
    switch (item->column()) {
    case 0:
        dynamic_cast<NameLine*>(item)->handleText(item->text());
        break;
    case 1:
        dynamic_cast<NameLine*>(item)->handleText(item->text());
        break;
    case 2:
        dynamic_cast<NameLine*>(item)->handleText(item->text());
        break;
    case 5:
        dynamic_cast<EmailLine*>(item)->handleText(item->text());
        break;
    case 6:
        dynamic_cast<PhoneLine*>(item)->handleText(item->text());
        break;
    default:
        break;
    }
}

PhoneDirectory::~PhoneDirectory() {
    for (int r = 0; r < this->rowCount(); r++)
        for (int c = 0; c < this->columnCount(); c++)
            delete this->item(r, c);
}

