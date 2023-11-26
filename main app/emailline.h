#ifndef EMAILLINE_H
#define EMAILLINE_H

#include <QTableWidgetItem>
#include <QObject>

class EmailLine : public QObject, public QTableWidgetItem
{
    Q_OBJECT
public:
    EmailLine() : QTableWidgetItem() {}
    bool isCorrect(QString email);
public slots:
    void handleText(QString email);
};

#endif // EMAILLINE_H
