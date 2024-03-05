#include "PauseMenu.h"
#include "../raftWars.h"

PauseMenu::PauseMenu()
{}

void PauseMenu::Update()
{
    system("cls");
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Pause" << endl;
    cout << "-" << (choice == 0 ? "O" : "-") << "- Continuer." << endl;
    cout << "-" << (choice == 1 ? "O" : "-") << "- Menu." << endl;
    cout << "-------------------------------------------------------------------" << endl;
    controls->ListenForControls();
}

void PauseMenu::Continu()
{
    activeScene = 1;
}

void PauseMenu::ReturnToMenu()
{
    activeScene = 0;
}