#include "phoneline.h"

void PhoneLine::handleText(QString phone) {
    if (!isCorrect(phone))
        this->setText("");
    else this->setText(phone.trimmed());
}

bool PhoneLine::isCorrect(QString phone) {
    phone = phone.trimmed();
    QRegularExpression pttrn("^(\\+\\d{1,3}\\(\\d{1,4}\\)\\d{1,4}-\\d{1,9},)+$");
    return pttrn.match(phone).hasMatch();
}
