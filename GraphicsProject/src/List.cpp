#include "List.hpp"
#include "Logger.hpp"

List::List(int x, int y, int sx, int sy) :
    Widget(x,y,sx,sy)
{
    screenRange = _size_y / 22;
    if(_size_x < 55) _size_x = 55;
    elementWidth = (_size_x) / 10;
}

List::List(int x, int y, int sx, int sy, vector<string> newElements) :
    Widget(x,y,sx,sy),
    elements(newElements)
{
    screenRange = _size_y / 22;
    if(_size_x < 55) _size_x = 55;
    elementWidth = (_size_x) / 10;
    slideSize = (double)screenRange / (double)elements.size();
}

void List::draw() const
{
    gout << move_to(_x, _y) << color(63,63,70) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(45,45,48) << box(_size_x-4, _size_y-4);

    //draw elements
    for(unsigned int i = 0; i < screenRange && i < elements.size(); i++)
    {
        if(current == i + visible)
        {
            gout << move_to(_x+2, _y+7+(i*20)) << color(255,255,255) << box_to(_x+_size_x-15, _y+22+(i*20));
            gout << move_to(_x+4, _y+20+(i*20)) << color(45,45,48) << text(getElement(i));
        }
        else
            gout << move_to(_x+4, _y+20+(i*20)) << color(255,255,255) << text(getElement(i));
    }

    //vertical line
    gout << move_to(_x+_size_x-14, _y+2) << color(113,113,113)
         << line_to(_x+_size_x-14,(_y+_size_y)-2);
    //horizontal line
    gout << move_to(_x+_size_x-14, _y+13)
         << line_to(_x+_size_x-2, _y+13);
    gout << move_to(_x+_size_x-14, _y+_size_y-13)
         << line_to(_x+_size_x-2, _y+_size_y-13);
    //slide
    int sizeOfSlideField = (_y+_size_y-13) - (_y+13);
    int slidePosEnd = sizeOfSlideField * slideSize;
    int slidePosBegin = visible * (sizeOfSlideField / (double)elements.size());
    gout << move_to(_x+_size_x-14, _y+13+slidePosBegin)
         << box(14, slidePosEnd);
    //up arrow
    gout << move_to(_x+_size_x-14, _y+13)
         << line_to((_x+_size_x-7), _y+2);
    gout << move_to(_x+_size_x-2, _y+13)
         << line_to((_x+_size_x-7), _y+2);
    //down arrow
    gout << move_to(_x+_size_x-14,  _y+_size_y-13)
         << line_to((_x+_size_x-7),  _y+_size_y-2);
    gout << move_to(_x+_size_x-2,  _y+_size_y-13)
         << line_to((_x+_size_x-7),  _y+_size_y-2);
}

void List::handle(event ev)
{
    if(ev.keycode == key_up)
    {
        if(current > 0) current--;
        if(current < visible) visible = current;
    }
    if(ev.keycode == key_down)
    {
        if(current < elements.size() - 1) current++;
        if(current >= visible + screenRange) visible++;
    }
    if(ev.button==btn_left &&
        ev.pos_x>_x+_size_x-14 &&
        ev.pos_x<_x+_size_x-2 &&
        ev.pos_y>_y+2 &&
        ev.pos_y<_y+14)
    {
        if(visible > 0) visible--;
    }
    if(ev.button==btn_left &&
        ev.pos_x>_x+_size_x-14 &&
        ev.pos_x<_x+_size_x-2 &&
        ev.pos_y>_y+_size_y-14 &&
        ev.pos_y<_y+_size_y-2)
    {
        if(visible <  elements.size() - screenRange) visible++;
    }
    if(ev.button==btn_left &&
        ev.pos_x>_x+2 &&
        ev.pos_x<_x+_size_x-14 &&
        ev.pos_y>_y+2 &&
        ev.pos_y<_y+_size_y-2)
    {
        current = visible + (ev.pos_y - _y) / 20;
        if(current >= elements.size()) current = elements.size()-1;
    }



}

string List::getElement(int i) const
{
    string temp = elements.at(i + visible);
    if(elements.at(i + visible).length() > elementWidth)
    {
        temp = temp.substr(0,elementWidth-3);
        temp += "...";
    }
    return temp;
}

void List::addElement(string newElemnet)
{
    elements.push_back(newElemnet);
    slideSize = (double)screenRange / (double)elements.size();
}

string List::getData() const
{
    return elements.at(current);
}
