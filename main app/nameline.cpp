#include "nameline.h"

void NameLine::handleText(QString full_name) {
    if (!isCorrect(full_name))
        this->setText("");
    else this->setText(full_name.trimmed());
}

bool NameLine::isCorrect(QString full_name) {
    full_name = full_name.trimmed();
    QRegularExpression pttrn("^[A-Za-zА-Яа-яЁё]+[- ]?[A-Za-zА-Яа-яЁё0-9]*$");
    return pttrn.match(full_name).hasMatch();
}
