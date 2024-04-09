#ifndef RAFTWARS_H
#define RAFTWARS_H

#include "Controls/Controls.h"
#include "Controls/EventManager.h"
#include "tests.h"
#include "Scenes/scene.h"
#include "Game/inventory.h"
#include "Affichage/AffichageConsole.h"
#include "Controls/SoundManager.h"
#include <vector>

extern EventManager *eventManager;
extern Controls *controls;
extern SoundManager* soundManager;
extern Tests *tests;
extern std::vector<Scene *> *scenes;
extern Inventory *inventory;
extern int activeScene;
extern LevelGetter *levelGetter;
extern AffichageConsole *cons;

#endif