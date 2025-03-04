// vocabularyentry.h
#ifndef VOCABULARYENTRY_H
#define VOCABULARYENTRY_H

#include <QString>

struct VocabularyEntry {
    QString word;
    QString meaning;
    int chance; // 0 to 100
};

#endif // VOCABULARYENTRY_H
