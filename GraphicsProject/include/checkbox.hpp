#ifndef CHECKBOX_HPP_INCLUDED
#define CHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class CheckBox : public Widget {
protected:
    bool _checked;
public:
    CheckBox(int x, int y, int sx, int sy);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    virtual bool is_checked() const ;
};


#endif // CHECKBOX_HPP_INCLUDED
