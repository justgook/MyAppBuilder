/*
  ==============================================================================

    DraggableTabbedComponent.h
    Created: 22 Jul 2014 11:19:04pm
    Author:  Roman Potashow

  ==============================================================================
*/

#ifndef DRAGGABLETABBEDCOMPONENT_H_INCLUDED
#define DRAGGABLETABBEDCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


class DraggableTabbedComponent : public TabbedComponent/*, public DragAndDropTarget*/ {

public:
    DraggableTabbedComponent(TabbedButtonBar::Orientation const &orientation);
//    bool isInterestedInDragSource(const SourceDetails &dragSourceDetails);
//    void itemDropped(const SourceDetails &dragSourceDetails);

    TabBarButton* createTabButton (const String& tabName, const int /*tabIndex*/);



//    struct JUCE_API LookAndFeelMethods {
//        virtual ~LookAndFeelMethods() {
//        }
//
//        virtual void drawDraggableTabCloseButton(TabBarButton &, Graphics &, bool isMouseOver, bool isMouseDown) = 0;
//
//    };
private:

//    class DraggableButtonBar;
//    friend class DraggableButtonBar;


    class DraggableTabBarButton;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DraggableTabbedComponent);

};


#endif  // DRAGGABLETABBEDCOMPONENT_H_INCLUDED
