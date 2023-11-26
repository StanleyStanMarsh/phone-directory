#include "dateitem.h"

void DateItem::setDate(QDate date) {
    this->setText(date.toString("yyyy-MM-dd"));
}
