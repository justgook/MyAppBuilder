/*
  ==============================================================================

    MainMenu.cpp
    Created: 21 Jul 2014 2:51:23pm
    Author:  Roman Potashow

  ==============================================================================
*/

#include "MainMenu.h"

MainMenu::MainMenu(ApplicationCommandManager *cm) {
#if JUCE_MAC
    String about = TRANS("About ");
//    about << juceIDEApplication::getApp().getApplicationName();
    extraAppleMenuItems.addItem (1, about);
    extraAppleMenuItems.addItem (1, TRANS("Check for Updates..."));
    extraAppleMenuItems.addSeparator();
    extraAppleMenuItems.addItem (2, TRANS("Preferences..."));
#endif
    setApplicationCommandManagerToWatch (cm);
}

MainMenu::~MainMenu() {

}

StringArray MainMenu::getMenuBarNames() {
    const char* const names[] = { "File", "Edit", "View",  "Tools", "Window", "Help", nullptr };
    return StringArray (names);
}

PopupMenu MainMenu::getMenuForIndex(int i, const String &menuName) {
    return PopupMenu();
}

void MainMenu::menuItemSelected(int menuItemID, int i) {

}
