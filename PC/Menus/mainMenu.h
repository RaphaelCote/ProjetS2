#ifndef MAINMENU_H
#define MAINMENU_H
#include <iostream>
#include <string>
using namespace std;


class Menu {

public:
    void afficherMenu();
    void menuPause();
    void menuFin();

private:
    int choix = 0;
};









#endif