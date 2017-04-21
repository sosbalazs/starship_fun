#ifndef NUMBERBOX_H
#define NUMBERBOX_H

#include "widgets.hpp"
#include "graphics.hpp"
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;
using namespace genv;

class NumberBox : public Widget
{
protected:
    int maxDigits;
    int max,min;
    int number;

    string getNumberAsString() const;
public:
    NumberBox(int x, int y, int Max = 99, int Min = -9, int sx=0, int sy=0);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    virtual string getData() const;
};

#endif // NUMBERBOX_H
