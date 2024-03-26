#ifndef RAFTWARS_H
#define RAFTWARS_H

#include "Controls/EventManager.h"
#include "Controls/Controls.h"
#include "tests.h"
#include "Scenes/menu.h"
#include "Scenes/game.h"
#include "vecteur.h"
#include "./Scenes/scene.h"
#include "Game/inventory.h"

extern EventManager *eventManager;
extern Controls *controls;
extern Tests *tests;
extern Vecteur<Scene *> *scenes;
extern Inventory *inventory;
extern int activeScene;
extern LevelGetter *levelGetter;
extern AffichageConsole *cons;
extern std::chrono::duration<double, std::milli> elapsed;

#endif