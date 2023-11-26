#ifndef NAMELINE_H
#define NAMELINE_H

#include <QTableWidgetItem>
#include <QObject>

class NameLine : public QObject, public QTableWidgetItem
{
    Q_OBJECT
public:
    NameLine() : QTableWidgetItem() {}
    bool isCorrect(QString full_name);
public slots:
    void handleText(QString full_name);
};

#endif // NAMELINE_H
