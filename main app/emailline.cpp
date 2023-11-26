#include "emailline.h"

void EmailLine::handleText(QString email) {
    if (!isCorrect(email))
        this->setText("");
    else this->setText(email.trimmed());
}

bool EmailLine::isCorrect(QString email) {
    email = email.trimmed();
    QRegularExpression pttrn(R"([A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,})");
    return pttrn.match(email).hasMatch();
}
