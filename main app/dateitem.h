#ifndef DATEITEM_H
#define DATEITEM_H

#include <QTableWidgetItem>
#include <QObject>
#include <QDate>

class DateItem : public QObject, public QTableWidgetItem
{
    Q_OBJECT
public:
    DateItem() : QTableWidgetItem() {}
public slots:
    void setDate(QDate date);
};

#endif // DATEITEM_H
