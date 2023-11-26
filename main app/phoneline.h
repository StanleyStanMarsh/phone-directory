#ifndef PHONELINE_H
#define PHONELINE_H

#include <QTableWidgetItem>
#include <QObject>

class PhoneLine : public QObject, public QTableWidgetItem
{
    Q_OBJECT
public:
    PhoneLine(): QTableWidgetItem() {}
    bool isCorrect(QString phone);
public slots:
    void handleText(QString phone);
};

#endif // PHONELINE_H
