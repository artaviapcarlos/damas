//
// Created by artv23 on 30/09/16.
//

#ifndef DAMAS_FICHA_H
#define DAMAS_FICHA_H

#include <sstream>

using namespace std;

class Ficha {
private:
    int color;
    bool corona;
    int num;

public:

    Ficha(int,int);
    int getColor() const;
    void setColor(int);
    bool getCorona() const;
    void setCorona(bool);
    void coronar();
    int getNum();
    void setNum(int);
    string toString();
};


#endif //DAMAS_FICHA_H
