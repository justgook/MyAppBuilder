/*
  ==============================================================================

    SplitPanel.h
    Created: 30 Jul 2014 11:24:25am
    Author:  Roman Potashow

  ==============================================================================
*/

#ifndef SPLITPANEL_H_INCLUDED
#define SPLITPANEL_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class SplitPanel : public Component {
public:

    enum AddTo {
        Bottom,
        Left,
        Right
    };

    SplitPanel(Component *content, SplitPanel *parent = nullptr, bool isVertical = true);

    ~SplitPanel();

    bool getIsVertical();

    SplitPanel *getParent();

//    //TODO find correct minimum size

    const int resizeBarSize = 10;
    const double minimumSize = 100;
    const double maximumSize = -1;
    const double preferredSize = -0.5;

    void resized();

protected:

    //TODO refactor next two methods..
    void addChild(AddTo position, Component *content = nullptr);
    void appendChild(Component *content_, SplitPanel::AddTo position, int index);

    void removeChild(SplitPanel* child);
    virtual SplitPanel *getChildInstance(Component *content, SplitPanel *parent, bool isVertical);

    SplitPanel *findParentToAdd(AddTo position);
    Component* content;


private:
    bool isVertical;
    ScopedPointer<StretchableLayoutManager> layoutManager;
    OwnedArray<Component, CriticalSection> childs;
    SplitPanel *parent;
    void reorderLayoutManager();
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SplitPanel);

};


#endif  // SPLITPANEL_H_INCLUDED
