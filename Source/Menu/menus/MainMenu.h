/*
  ==============================================================================

    MainMenu.h
    Created: 21 Jul 2014 2:51:23pm
    Author:  Roman Potashow

  ==============================================================================
*/

#ifndef MAINMENU_H_INCLUDED
#define MAINMENU_H_INCLUDED

#include "../../../juce/JuceLibraryCode/JuceHeader.h"

class MainMenu : public MenuBarModel {
public:
    MainMenu(ApplicationCommandManager *cm);

    ~MainMenu();
    PopupMenu extraAppleMenuItems;
    StringArray getMenuBarNames();
    PopupMenu getMenuForIndex(int topLevelMenuIndex, const String &menuName);
    void menuItemSelected (int menuItemID, int topLevelMenuIndex);
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainMenu);

};


#endif  // MAINMENU_H_INCLUDED
