/*
  ==============================================================================

    WindowManager.h
    Created: 18 Jul 2014 4:39:38pm
    Author:  Roman Potashow

  ==============================================================================
*/


#ifndef __WindowManager_H_
#define __WindowManager_H_

#include "../../juce/JuceLibraryCode/JuceHeader.h"
#include "types/ApplicationWindow.h"
#include "../Menu/MenuManager.h"


class WindowManager {
public:
    WindowManager(ApplicationCommandManager *cm, MenuManager *mm);

    ~WindowManager();


    ApplicationWindow *createAppWindow(const String &name, Component *content);
    int getApplicationWindowCount();

    DialogWindow *createDialogWindow(Component *content);

private:
//    struct Project {
//        ApplicationWindow *window;
//        MainMenu *menu;
//        Project(ApplicationWindow *window,MainMenu *menu)
//                :   window(window), menu(menu){}
//    };
//
////    OwnedArray<Project, CriticalSection> appWindows;

    OwnedArray<ApplicationWindow, CriticalSection> appWindows;
    ApplicationCommandManager *commandManager;
    MenuManager *menuManager;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(WindowManager);
};


#endif  // __WindowManager_H_
