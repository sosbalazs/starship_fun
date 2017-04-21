#include "MainWindow.hpp"

MainWindow::MainWindow()
{
    gout.open(600,400);
    gout << color(37,37,38) << move_to(0,0) << box_to(599,399);
    file.open("widgets.log");
}

MainWindow::MainWindow(int w, int h)
{
    gout.open(w,h);
    gout << color(37,37,38) << move_to(0,0) << box_to(w-1,h-1);
    file.open("widgets.log");
}

void MainWindow::addWidget(Widget* widget)
{
    widgets.push_back(widget);
}

Widget* MainWindow::getWidget(int i)
{
    return widgets.at(i);
}

void MainWindow::startLoop()
{
    event ev;
    int focus = -1;
    while(gin >> ev && ev.keycode != key_escape) {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
                }
            }
        }
        if(ev.keycode == key_space)
        {
            logData();
        }
        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }
        for (size_t i=0;i<widgets.size();i++) {
            widgets[i]->draw();
        }
        gout << refresh;
    }
    file.close();
}

void MainWindow::logData()
{
    file << "=====================================\n";
    for(unsigned int i = 0; i < widgets.size(); i++)
    {
        file << "Data of " << i+1 << ". widget: " << widgets.at(i)->getData() << "\n";
    }
}
