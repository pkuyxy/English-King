#ifndef WORDLIB_H
#define WORDLIB_H
#include <QString>
#include <QFile>

struct WordEntry {
    QString word;
    int num;
    int numrec;        // 英文单词
    QString* answers;    // 所有正确答案（支持多义词）
    QString* notanswers;
    int self;
};

class WordLibrary {
public:
    static WordEntry loadFromFile(const QString& filePath,int mode=0);
};
#endif // WORDLIB_H
