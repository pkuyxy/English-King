#include "wordlib.h"
#include <QTextStream>
#include<QDebug>
#include<QRandomGenerator>
#include<QDir>
#include<QApplication>
QString getWordLibraryPath2(int difficulty,int mode=0) {
    QString basePath = QCoreApplication::applicationDirPath()+"/data"; // 获取可执行文件所在目录
    QString fileName;
    if(mode!=2){
        switch(difficulty) {
        case 0: fileName = "英语词库(1).txt"; break;
        case 1: fileName = "英语词库(2).txt"; break;
        case 2: fileName = "英语词库(3).txt"; break;
        case 3: fileName = "英语词库(4).txt"; break;
        default: fileName = "英语词库(1).txt";
        }
    }
    else{
        fileName="英语词库(5).txt";
    }
    return QDir(basePath).filePath(fileName); // 构建完整路径
}
WordEntry WordLibrary::loadFromFile(const QString& filePath,int mode) {
    if(mode!=2){
        WordEntry entry={"",0,QRandomGenerator::global()->bounded(6, 11),nullptr,nullptr,0};
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "打开文件失败";
            return entry;
        }
        QTextStream in(&file);
        int totalLines = 0;
        while (!in.atEnd()) {
            QString line=in.readLine().trimmed();
            if(!line.isEmpty())totalLines++;
        }
    loop1:
        // 随机选择一行
        int targetLine = QRandomGenerator::global()->bounded(0, totalLines);
        file.seek(0); // 重置文件指针
        in.seek(0);
        in.reset();

        // 第二次遍历：读取目标行
        int currentLine = 0;
        while(!in.atEnd()){
            if(currentLine==targetLine){
                in>>entry.self;
                in>>entry.word;
                in>>entry.num;
                entry.answers=new QString[entry.num];

                for(int i=0;i<entry.num;i++){
                    in>>entry.answers[i];
                }
                QString line = in.readLine().trimmed();
                if(entry.self==1&&mode!=3){
                    goto loop1;
                }
            }
            else{
                QString line = in.readLine().trimmed();
            }
            currentLine++;
        }
        if (entry.numrec > entry.num) {
            entry.notanswers = new QString[entry.numrec - entry.num];
            int wrongCount = 0;

            // 生成不重复的随机行号（排除正确答案行）
            QList<int> randomLines;
            while (randomLines.size() < entry.numrec - entry.num) {
                int randLine = QRandomGenerator::global()->bounded(0, totalLines);
                if (randLine != targetLine && !randomLines.contains(randLine)) {
                    randomLines.append(randLine);
                    qDebug()<<randLine;
                }
            }

            // 根据随机行号读取错误答案
            file.seek(0);
            in.seek(0);
            in.reset();
            currentLine = 0;

            while (!in.atEnd() && wrongCount < randomLines.size()) {
                if (randomLines.contains(currentLine)) {
                    WordEntry k;
                    in>>k.self;
                    in>>k.word;
                    in>>k.num;
                    int ansCount = k.num;
                    k.answers=new QString[k.num];
                    // 随机选择该行的某个答案作为干扰项
                    int randIndex = QRandomGenerator::global()->bounded(0, ansCount);
                    for(int i=0;i<k.num;i++){
                        in>>k.answers[i];
                    }
                    entry.notanswers[wrongCount++]=k.answers[randIndex];
                    QString line = in.readLine().trimmed();
                }
                else{
                    QString line = in.readLine().trimmed();
                }
                currentLine++;
            }
            file.close();
        }
        return entry;
    }
    else{
        WordEntry entry={"",0,QRandomGenerator::global()->bounded(6, 11),nullptr,nullptr,0};
        QFile file(filePath);

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "打开文件失败";
            return entry;
        }
        QTextStream in(&file);
        QFile file2(getWordLibraryPath2(QRandomGenerator::global()->bounded(0,4)));
        if (!file2.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "打开文件失败";
            return entry;
        }
        QTextStream in2(&file2);
        int totalLines=0;
        int totalLines2=0;
        while (!in.atEnd()) {
            QString line=in.readLine().trimmed();
            if(!line.isEmpty())totalLines++;
        }
        while (!in2.atEnd()) {
            QString line=in2.readLine().trimmed();
            if(!line.isEmpty())totalLines2++;
        }
    loop2:
        // 随机选择一行
        int targetLine = QRandomGenerator::global()->bounded(0, totalLines);
        file.seek(0); // 重置文件指针
        in.seek(0);
        in.reset();
        file2.seek(0); // 重置文件指针
        in2.seek(0);
        in2.reset();
        // 第二次遍历：读取目标行
        int currentLine = 0;
        while(!in.atEnd()){
            if(currentLine==targetLine){
                in>>entry.self;
                in>>entry.word;
                in>>entry.num;
                entry.answers=new QString[entry.num];

                for(int i=0;i<entry.num;i++){
                    in>>entry.answers[i];
                }
                QString line = in.readLine().trimmed();
                if(entry.self==1&&mode!=3){
                    goto loop2;
                }
            }
            else{
                QString line = in.readLine().trimmed();
            }
            currentLine++;
        }
        if (entry.numrec > entry.num) {
            entry.notanswers = new QString[entry.numrec - entry.num];
            int wrongCount = 0;

            // 生成不重复的随机行号（排除正确答案行）
            QList<int> randomLines;
            while (randomLines.size() < entry.numrec - entry.num) {
                int randLine = QRandomGenerator::global()->bounded(0, totalLines2);
                if (!randomLines.contains(randLine)) {
                    randomLines.append(randLine);
                    qDebug()<<randLine;
                }
            }
            currentLine = 0;
            file.seek(0); // 重置文件指针
            in.seek(0);
            in.reset();
            file2.seek(0); // 重置文件指针
            in2.seek(0);
            in2.reset();
            while (!in.atEnd() && wrongCount < randomLines.size()) {
                if (randomLines.contains(currentLine)) {
                    WordEntry k;
                    in2>>k.self;
                    in2>>k.word;
                    in2>>k.num;
                    int ansCount = k.num;
                    k.answers=new QString[k.num];
                    // 随机选择该行的某个答案作为干扰项
                    int randIndex = QRandomGenerator::global()->bounded(0, ansCount);
                    for(int i=0;i<k.num;i++){
                        in2>>k.answers[i];
                    }
                    entry.notanswers[wrongCount++]=k.answers[randIndex];
                    QString line = in2.readLine().trimmed();
                }
                else{
                    QString line = in2.readLine().trimmed();
                }
                currentLine++;
            }
            file.close();
            file2.close();
        }
        return entry;
    }
}

