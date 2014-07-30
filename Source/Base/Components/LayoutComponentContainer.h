/*
  ==============================================================================

    Panel.h
    Created: 22 Jul 2014 6:17:08pm
    Author:  Roman Potashow

  ==============================================================================
*/

#ifndef PANEL_H_INCLUDED
#define PANEL_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class LayoutComponentContainer : public Component {

public:
    LayoutComponentContainer();

    ~LayoutComponentContainer();

    String getName();

    Image *getIcon(); //TODO change to return some Image based on "pluginSettings"
    MenuBarModel *getSettingsMenu();

    // Dragging Component
//    ComponentDragger myDragger;
//    void mouseDown (const MouseEvent& e)
//    {
//        myDragger.startDraggingComponent (this, e);
//    }
//    void mouseDrag (const MouseEvent& e)
//    {
//        myDragger.dragComponent (this, e, nullptr);
//    }


private:
//    ScopedPointer<TabbedComponent> tabbedButtonBar;
//    ComboBox* myComp1;
//    ComboBox* myComp2;
//    StretchableLayoutManager myLayout;
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LayoutComponentContainer)

};


#endif  // PANEL_H_INCLUDED
