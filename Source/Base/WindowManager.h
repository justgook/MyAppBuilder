/*
  ==============================================================================

    WindowManager.h
    Created: 18 Jul 2014 4:39:38pm
    Author:  Roman Potashow

  ==============================================================================
*/


#ifndef __WindowManager_H_
#define __WindowManager_H_

#include "../JuceLibraryCode/JuceHeader.h"
#include "ApplicationWindow.h"
#include "MenuManager.h"


class WindowManager {
public:
    WindowManager(ApplicationCommandManager *cm, MenuManager *mm);

    ~WindowManager();


    ApplicationWindow *createAppWindow(const String &name, Component *content);
    int getApplicationWindowCount();

    DialogWindow *createDialogWindow();

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
