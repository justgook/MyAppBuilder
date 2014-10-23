/*
  ==============================================================================

    MenuManager.h
    Created: 21 Jul 2014 2:12:41pm
    Author:  Roman Potashow

  ==============================================================================
*/



#ifndef MENUMANAGER_H_INCLUDED
#define MENUMANAGER_H_INCLUDED

#include "../../juce/JuceLibraryCode/JuceHeader.h"
#include "menus/MainMenu.h"
#include "../Base/CommandManager.h"


class MenuManager {
public:
    MenuManager(CommandManager *cm);

    ~MenuManager();

    MainMenu *createApplicationMenu();

private:

    // Pointer to applicationCommandManager that is created and deleted in main application - here it is to ba able to point to it.
    CommandManager *commandManager;

    //this will be added to each application window,
    //in mac it will switch menu for each applicationWindow, for Win/linux it will be added on top of applicationWindow
    OwnedArray<MainMenu, CriticalSection> applicationMainMenus;
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MenuManager);


};

#endif  // MENUMANAGER_H_INCLUDED
