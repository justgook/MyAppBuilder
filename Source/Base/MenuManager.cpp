/*
  ==============================================================================

    MenuManager.cpp
    Created: 21 Jul 2014 2:12:41pm
    Author:  Roman Potashow

  ==============================================================================
*/

#include "MenuManager.h"

MenuManager::MenuManager(ApplicationCommandManager *cm) {
    commandManager = cm;
//    setApplicationCommandManagerToWatch(cm);
}

MenuManager::~MenuManager() {
//    applicationMainMenus.clear(true);
}

MainMenu *MenuManager::createApplicationMenu() {
    //TODO add default list of menus.
    MainMenu *mainMenu = new MainMenu(commandManager);
    applicationMainMenus.add(mainMenu);
    return mainMenu;
}

//MainMenu *MenuManager::createApplicationMenu() {
//    //TODO add default list of menus.
//    MainMenu *mainMenu = new MainMenu(commandManager);
//    applicationMainMenus.add(mainMenu);
//    return mainMenu;
//}
