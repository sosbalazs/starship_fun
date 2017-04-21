#include "NumberBox.hpp"
#include "Logger.hpp"

NumberBox::NumberBox(int x, int y, int Max, int Min, int sx, int sy)
    : Widget(x,y,sx,sy),
    max(Max),
    min(Min),
    number(0)
{
    if(min >= max)
    {
        min = -9;
        max = 99;
    }

    std::string s;
    std::stringstream out;
    out << max;
    s = out.str();

    std::string s2;
    std::stringstream out2;
    out2 << min;
    s2 = out2.str();

    int sizeByDigits = s.size() > s2.size() ? s.size()*8 + 21 : s2.size()*8 + 21;
    _size_x = sizeByDigits > _size_x ? sizeByDigits : _size_x;

    if(_size_y < 27) _size_y = 27;
}

void NumberBox::draw() const
{
    gout << move_to(_x, _y) << color(63,63,70) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(45,45,48) << box(_size_x-4, _size_y-4);
    //vertical line
    gout << move_to(_x+_size_x-14, _y+2) << color(113,113,113)
         << line_to(_x+_size_x-14,(_y+_size_y)-2);
    //horizontal line
    gout << move_to(_x+_size_x-14, _y+(_size_y/2))
         << line_to(_x+_size_x-2, _y+(_size_y/2));
    //up arrow
    gout << move_to(_x+_size_x-14, _y+(_size_y/2))
         << line_to((_x+_size_x-7), _y+2);
    gout << move_to(_x+_size_x-2, _y+(_size_y/2))
         << line_to((_x+_size_x-7), _y+2);
    //down arrow
    gout << move_to(_x+_size_x-14, _y+(_size_y/2))
         << line_to((_x+_size_x-7), _y+_size_y-2);
    gout << move_to(_x+_size_x-2, _y+(_size_y/2))
         << line_to((_x+_size_x-7), _y+_size_y-2);
    //number
    gout << move_to(_x+4, _y+(_size_y/2)+4) << color(255,255,255) << text(getNumberAsString());
}

void NumberBox::handle(event ev)
{
    if(ev.keycode >= 48 && ev.keycode <= 57)
    {
        int temp = number * 10;
        if(temp > 0) temp += ev.keycode - 48;
        else temp -= ev.keycode - 48;
        if(temp >= min && temp <= max) number = temp;
    }
    if(ev.keycode == 45)
    {
        int temp = number * -1;
        if(temp >= min  && temp <= max) number = temp;
    }
    if(ev.keycode == key_backspace)
    {
        number /= 10;
    }
    //increment
    if(ev.button==btn_left &&
        ev.pos_x>_x+_size_x-14 &&
        ev.pos_x<_x+_size_x-2 &&
        ev.pos_y>_y+2 &&
        ev.pos_y<_y+(_size_y/2))
    {
        if(number <  max) number++;
    }
    if(ev.keycode == key_up)
    {
        if(number <  max) number++;
    }
    if(ev.keycode == key_pgup)
    {
        number += 10;
        if(number > max) number = max;
    }
    //decrement
    if(ev.button==btn_left &&
        ev.pos_x>_x+_size_x-14 &&
        ev.pos_x<_x+_size_x-2 &&
        ev.pos_y>_y+(_size_y/2) &&
        ev.pos_y<_y+_size_y-2)
    {
        if(number > min) number--;
    }
    if(ev.keycode == key_down)
    {
        if(number >  min) number--;
    }
    if(ev.keycode == key_pgdn)
    {
        number -= 10;
        if(number < min) number = min;
    }
}

string NumberBox::getNumberAsString() const
{
    std::string s;
    std::stringstream out;
    out << number;
    return out.str();
}

string NumberBox::getData() const
{
    return getNumberAsString();
}
