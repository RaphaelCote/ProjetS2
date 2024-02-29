#ifndef RAFTWARS_H
#define RAFTWARS_H

#include "Controls/EventManager.h"
#include "Controls/Controls.h"
#include "tests.h"
#include "Scenes/menu.h"
#include "Scenes/game.h"

extern EventManager *eventManager;
extern Controls *controls;
extern Tests *tests;
extern Menu *activeMenu;
extern Game *game;

#endif