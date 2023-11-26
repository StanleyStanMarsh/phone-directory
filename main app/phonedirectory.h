#ifndef PHONEDIRECTORY_H
#define PHONEDIRECTORY_H

#include <QTableWidget>
#include <QWidget>
#include <QObject>
#include <QDebug>
#include <QDateEdit>
#include <QFile>
#include <QTextStream>
#include "nameline.h"
#include "phoneline.h"
#include "emailline.h"
#include "dateitem.h"

class PhoneDirectory : public QTableWidget
{
    Q_OBJECT
public:
    PhoneDirectory(QWidget *parent = nullptr);
    ~PhoneDirectory();
    void addRowsFromCsv(QFile& file);
    void writeRowsToCsv(QFile& file);
private:
    void fillLastRow(QStringList str_list);
public slots:
    void addRow();
    void delRow();

    void handleItem(QTableWidgetItem* item);
};

#endif // PHONEDIRECTORY_H
