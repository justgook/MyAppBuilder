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

//TODO hold all panels when they ar moving form one to other position
class LayoutManager {
public:

    LayoutManager(WindowManager *wm, ApplicationCommandManager *cm, MenuManager *mm);

    ~LayoutManager();

    LayoutComponentContainer *addTestPanel(const String &name);
      //TODO add way to be able close itself ant check if there is need to close window
//    bool tryToCloseDocument(Component *component);

private:
//    OwnedArray<ApplicationWindow, CriticalSection> appWindows;

    //TODO check do i need it att all
    OwnedArray<LayoutComponentContainer, CriticalSection> panels;

    //TODO find solution how that move to some subclass when it will grow

    OwnedArray<Component, CriticalSection> layouts;

    OwnedArray<StretchableLayoutResizerBar, CriticalSection> layoutBars;
    OwnedArray<StretchableLayoutManager, CriticalSection> layoutManagers;

    //TODO looks like it must be some custom class with custom tabBar not default TabbedComponent
    OwnedArray<DraggableTabbedComponent, CriticalSection> layoutTabPanelHolder;





private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LayoutManager)
};


#endif  // PANELMANER_H_INCLUDED
