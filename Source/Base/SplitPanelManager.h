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

class SplitPanelManager {
public:

    SplitPanelManager(WindowManager *wm, CommandManager *cm, MenuManager *mm);

    ~SplitPanelManager();
    StretchableLayoutManager* getLayoutManagers(SplitPanel &panel);
    void childAdded(SplitPanel *panel);
//    LayoutComponentContainer *addTestPanel(const String &name);
      //TODO add way to be able close itself ant check if there is need to close window
//    bool tryToCloseDocument(Component *component);
private:
//    OwnedArray<ApplicationWindow, CriticalSection> appWindows;

    //TODO check do i need it att all
    OwnedArray<SplitPanel, CriticalSection> topLevelPanels;

    //TODO find solution how that move to some subclass when it will grow

    OwnedArray<StretchableLayoutManager, CriticalSection> layoutManagers;

    //TODO looks like it must be some custom class with custom tabBar not default TabbedComponent
//    OwnedArray<DraggableTabbedComponent, CriticalSection> layoutTabPanelHolder;





private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SplitPanelManager);

};


#endif  // PANELMANER_H_INCLUDED
