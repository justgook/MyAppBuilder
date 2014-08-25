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

PopupMenu MainMenu::getMenuForIndex(int topLevelMenuIndex, const String &menuName) {
//    DBG("get menus");
    PopupMenu m;
    m.addItem (1, "item 1");
    m.addItem (2, "item 2");
//    const int result = m.show();
//    if (result == 0)
//    {
//        // user dismissed the menu without picking anything
//    }
//    else if (result == 1)
//    {
//        // user picked item 1
//    }
//    else if (result == 2)
//    {
//        // user picked item 2
//    }
    return m;
}

void MainMenu::menuItemSelected(int menuItemID, int topLevelMenuIndex) {

}
