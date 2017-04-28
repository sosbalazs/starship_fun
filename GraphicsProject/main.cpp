#include "MainWindow.hpp"

int main()
{
    MainWindow window(800,600);
    window.addWidget(new NumberBox(10,10,99999999,-999));
    window.addWidget(new NumberBox(10,40,-999,999));

    vector<string> elements = { "alpha", "beta", "gamma", "delta", "harcsa paprikas",
                                "2134","423424","word","2343","5468",
                                "egy","ketto","harom"};

    vector<string> elements2 = { "fwafe", "aw;eofijaw;oeifja;oweifja;woe", "wefawef", "aowekfpw"};

    window.addWidget(new List(150,10,200,200,elements));

    List* l = new List(400,30,100,100,elements2);
    window.addWidget(l);
    l->addElement("foka moka");

    window.startLoop();
    return 0;
}
