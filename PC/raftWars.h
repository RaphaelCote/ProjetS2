#ifndef RAFTWARS_H
#define RAFTWARS_H

#include "Controls/EventManager.h"
#include "Controls/Controls.h"
#include "tests.h"
#include "Scenes/menu.h"
#include "Scenes/game.h"
#include "Scenes/scene.h"
#include "Game/inventory.h"
#include "Affichage/GameWindow.h"
#include <vector>

extern EventManager *eventManager;
extern Controls *controls;
extern Tests *tests;
extern GameWindow* gameWindow;
extern std::vector<Scene *> *scenes;
extern Inventory *inventory;
extern int activeScene;
extern LevelGetter *levelGetter;
extern AffichageConsole *cons;

#endif