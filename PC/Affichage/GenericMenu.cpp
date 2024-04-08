#include "GenericMenu.h"
#include "Global.h"
#include "GameWindow.h"

GenericMenu::GenericMenu()
{
	
}

void GenericMenu::CreateButtons(int btnQty) {
	for (int i = 0; i < btnQty; i++) {
		buttons.push_back(new MenuButton("Btn", this));
		buttons[i]->setCheckable(true);
		buttons[i]->installEventFilter(this);
	}

	SetChecked(0);
}

void GenericMenu::SetChecked(int index) {
	for (int i = 0; i < buttons.size(); i++) {
		if (i == index) {
			buttons[i]->setChecked(true);
		}
		else {
			buttons[i]->setChecked(false);
		}
	}
}