/*
  ==============================================================================

    TabbedSplitPanel.h
    Created: 22 Aug 2014 4:27:37pm
    Author:  Roman Potashow

  ==============================================================================
*/

#ifndef TABBEDSPLITPANEL_H_INCLUDED
#define TABBEDSPLITPANEL_H_INCLUDED

#include "SplitPanel.h"
#include "DraggableTabbedComponent.h"

class TabbedSplitPanel : public SplitPanel, public DragAndDropTarget {
public:
    TabbedSplitPanel(Component *content, SplitPanel *parent, bool isVertical);
    TabbedSplitPanel(SplitPanel *parent, bool isVertical);
    //DragAndDropTarget
    bool isInterestedInDragSource(const SourceDetails &dragSourceDetails);

    void itemDragMove(const SourceDetails &dragSourceDetails);

    void itemDropped(const SourceDetails &dragSourceDetails);

    void itemDragEnter(const SourceDetails &dragSourceDetails);

    void itemDragExit(const SourceDetails &dragSourceDetails);

protected:
    SplitPanel *getChildInstance(Component *content, SplitPanel *parent, bool isVertical) override;
private:
    class OverlayComponent;

    ScopedPointer<OverlayComponent> overlay;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabbedSplitPanel);

};

#endif  // TABBEDSPLITPANEL_H_INCLUDED
