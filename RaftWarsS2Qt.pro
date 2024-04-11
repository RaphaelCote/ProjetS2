TEMPLATE     = vcapp
TARGET       = RaftWarsS2Qt
CONFIG      += warn_on qt debug windows console
HEADERS     += \
	#---------PC---------#
	PC/raftWars.h \
	PC/tests.h \
	PC/vecteur.h \
	#------Affichage------#
	PC/Affichage/AffichageConsole.h \
	PC/Affichage/GameWindow.h \
	PC/Affichage/MenuButton.h \	
	PC/Affichage/GenericMenu.h \
	PC/Affichage/MainMenuQt.h \
	PC/Affichage/PauseMenuQt.h \
	PC/Affichage/EndGameMenuQt.h \
	PC/Affichage/ShopMenuQt.h \
	PC/Affichage/LevelMenu.h \
	PC/Affichage/GameWidget.h \
	PC/Affichage/ShowContentEvent.h \
	PC/Affichage/UpdateValuesEvent.h \
	PC/Affichage/Pixmaps.h \
	PC/Affichage/Global.h \
	PC/Affichage/GlobalTwo.h \	
	#------Controls------#
	PC/Controls/controllerControls.h \
	PC/Controls/controls.h \
	PC/Controls/EventListener.h \
	PC/Controls/EventManager.h \
	PC/Controls/EventParameters.h \
	PC/Controls/keyboardControls.h \
	PC/Controls/keyboardControlsRedirect.h \
	PC/Controls/SoundManager.h \
	#---------Game---------#
	PC/Game/character.h \
    	PC/Game/enemyCharacter.h \
    	PC/Game/gameloader.h \
    	PC/Game/grenade.h \
    	PC/Game/inventory.h \
    	PC/Game/levelGetter.h \
    	PC/Game/niveau.h \
    	PC/Game/playerCharacter.h \
    	PC/Game/projectile.h \
    	PC/Game/rocket.h \
    	PC/Game/utility.h \
    	PC/Game/Boat.h \
    	PC/Game/canonball.h \
	#-------include-------#
	PC/include/json.hpp \
	#----include/serial----#
	PC/include/serial/SerialPort.hpp \
	#--------levels--------#
	#--------Scenes--------#
	PC/Scenes/game.h \
    	PC/Scenes/LevelSelectionMenu.h \
    	PC/Scenes/mainMenu.h \
    	PC/Scenes/menu.h \
    	PC/Scenes/PauseMenu.h \
    	PC/Scenes/scene.h \
    	PC/Scenes/shopMenu.h \
    	PC/Scenes/EndGameMenu.h
	#----------lib----------#
SOURCES     += \
	#---------PC---------#
	PC/raftWars.cpp \
	PC/tests.cpp \
	#------Affichage------#
	PC/Affichage/AffichageConsole.cpp \
	PC/Affichage/GameWindow.cpp \
	PC/Affichage/MenuButton.cpp \
	PC/Affichage/GenericMenu.cpp \
	PC/Affichage/MainMenuQt.cpp \
	PC/Affichage/PauseMenuQt.cpp \
	PC/Affichage/EndGameMenuQt.cpp \
	PC/Affichage/ShopMenuQt.cpp \
	PC/Affichage/LevelMenu.cpp \
	PC/Affichage/GameWidget.cpp \
	PC/Affichage/ShowContentEvent.cpp \
	PC/Affichage/UpdateValuesEvent.cpp \
	#------Controls------#
	PC/Controls/controllerControls.cpp \
	PC/Controls/controls.cpp \
	PC/Controls/keyboardControls.cpp \
	PC/Controls/keyboardControlsRedirect.cpp \
	PC/Controls/SoundManager.cpp\
	#---------Game---------#
	PC/Game/grenade.cpp \
    	PC/Game/inventory.cpp \
    	PC/Game/levelGetter.cpp \
    	PC/Game/niveau.cpp \
    	PC/Game/playerCharacter.cpp \
    	PC/Game/projectile.cpp \
    	PC/Game/rocket.cpp \
    	PC/Game/utility.cpp \
    	PC/Game/Boat.cpp \
    	PC/Game/canonball.cpp \
    	PC/Game/character.cpp \
    	PC/Game/enemyCharacter.cpp \
    	PC/Game/gameloader.cpp \
	#----include/serial----#
	PC/include/serial/SerialPort.cpp \
	#--------levels--------#
	#--------Scenes--------#
	PC/Scenes/game.cpp \
    	PC/Scenes/LevelSelectionMenu.cpp \
    	PC/Scenes/mainMenu.cpp \
    	PC/Scenes/menu.cpp \
    	PC/Scenes/PauseMenu.cpp \
    	PC/Scenes/scene.cpp \
    	PC/Scenes/shopMenu.cpp \
    	PC/Scenes/EndGameMenu.cpp 
INCLUDEPATH += \
	PC \
	PC/Affichage \
	PC/Controls \
	PC/Game \
	PC/include \
	PC/include/serial \
	PC/levels \
	PC/lib \
	PC/Scenes \
	Arduino \
	Arduino/include \
	Arduino/src
QT          += \
	widgets \
	multimedia
