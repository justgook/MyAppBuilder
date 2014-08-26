/*
  ==============================================================================

    PanelManer.h
    Created: 22 Jul 2014 6:13:15pm
    Author:  Roman Potashow

  ==============================================================================
*/



#ifndef PANELMANER_H_INCLUDED
#define PANELMANER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "WindowManager.h"
#include "LayoutComponentContainer.h"
#include "DraggableTabbedComponent.h"
#include "CommandManager.h"

class SplitPanel;  //TODO finde better solution that recreation of class

class LayoutManager : public ApplicationCommandTarget {
public:

    LayoutManager(WindowManager *wm, CommandManager *cm, MenuManager *mm);

    ~LayoutManager();

    void childAdded(SplitPanel *panel);
    //==================================================================================================================
    //ApplicationCommandTarget

    //This must return the next target to try after this one.
    ApplicationCommandTarget *getNextCommandTarget();

    //This must return a complete list of commands that this target can handle.
    void getAllCommands(Array<CommandID> &commands);

    //This must provide details about one of the commands that this target can perform.
    void getCommandInfo(CommandID commandID, ApplicationCommandInfo &result);

    //This must actually perform the specified command.
    bool perform(const InvocationInfo &info);
    //==================================================================================================================

private:
    CommandManager *commandManager;

//    OwnedArray<ApplicationWindow, CriticalSection> appWindows;

    //TODO check do i need it att all
    OwnedArray<SplitPanel, CriticalSection> topLevelPanels;

    //TODO find solution how that move to some subclass when it will grow

    OwnedArray<StretchableLayoutManager, CriticalSection> layoutManagers;

    //TODO looks like it must be some custom class with custom tabBar not default TabbedComponent
//    OwnedArray<DraggableTabbedComponent, CriticalSection> layoutTabPanelHolder;





private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LayoutManager);

};


#endif  // PANELMANER_H_INCLUDED
