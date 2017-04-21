#ifndef LIST_H
#define LIST_H

#include "widgets.hpp"
#include "graphics.hpp"
#include <vector>
#include <stdarg.h>

using namespace std;
using namespace genv;

class List : public Widget
{
    public:
        List(int x, int y, int sx, int sy);
        List(int x, int y, int sx, int sy, vector<string> newElements);

        void addElement(string newElement);

        virtual void draw() const ;
        virtual void handle(event ev);
        virtual string getData() const;

    protected:
        vector<string> elements;
        unsigned int current = 0;
        unsigned int visible = 0; //first visible element
        unsigned int screenRange = 0;
        unsigned int elementWidth = 3;
        double slideSize = 0;

        string getElement(int i) const;

};

#endif // LIST_H
