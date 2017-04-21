#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <fstream>
#include "graphics.hpp"
#include "widgets.hpp"
#include "checkbox.hpp"
#include "NumberBox.hpp"
#include "List.hpp"
#include "Logger.hpp"

using namespace std;
using namespace genv;

class MainWindow
{
    public:
        MainWindow();
        MainWindow(int w, int h);

        void startLoop();
        void addWidget(Widget* widget);

        Widget* getWidget(int i);

        void logData();

    protected:

    private:
    vector<Widget*> widgets;
    ofstream file;
};

#endif // MAINWINDOW_H
