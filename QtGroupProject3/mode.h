#ifndef MODE_H
#define MODE_H
#include<QDialog>
#include<QButtonGroup>
#include<QComboBox>
#include<QPushButton>

class mode:public QDialog{
    Q_OBJECT
private:
    int model;
    int difficulty;
    QComboBox* modecombo;
    QComboBox* diffcombo;
    QPushButton* backButton;
signals:
    void backToHome();
public:
    explicit mode(QWidget *parent=nullptr);
    int getmode()const{return model;}
    int getdifficulty() const {return difficulty;}
    void onconfirm();
};

#endif // MODE_H
