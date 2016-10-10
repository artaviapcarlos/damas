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
    int colorOpos;
    bool corona;

public:

    Ficha(int);
    int getColor() const;
    void setColor(int);
    int getColorOpos() const;
    void resetColorOpos();
    bool getCorona() const;
    void setCorona(bool);
    void coronar();
    string toString();
};


#endif //DAMAS_FICHA_H
