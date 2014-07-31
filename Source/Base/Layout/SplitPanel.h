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
#include "SplitPanelManager.h"

class SplitPanel : public Component, public ApplicationCommandTarget/*, public DragAndDropTarget*/ {
public:
    enum AddTo {
        Bottom,
        Left,
        Right
    };
    const int resizeBarSize = 10;

    //TODO remove CommandManager, and move it to SplitPanelManager
    SplitPanel( SplitPanel *parent = nullptr, bool isVertical = true);

    ~SplitPanel();

    bool getIsVertical();

    Component *getContent();

    SplitPanel *getParent();
    StretchableLayoutManager *getLayoutManager();

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

//    //TODO find correct minimum size
    const double minimumSize = 100;
    const double maximumSize = -1;
    const double preferredSize = -0.5;
    void resized();

protected:

    //TODO refactor next two methods..
    void addChild(AddTo position, Component *content = nullptr);
    void appendChild(AddTo position);
    SplitPanel *findParentToAdd(AddTo position);

private:
    bool isVertical;
    ScopedPointer<Component> content;
//    ScopedPointer<StretchableLayoutResizerBar> resizerBar;
    ScopedPointer<StretchableLayoutManager> layoutManager;
//    OwnedArray<SplitPanel, CriticalSection> childs;
    OwnedArray<Component, CriticalSection> childs;
    SplitPanel* parent;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SplitPanel);

};


#endif  // SPLITPANEL_H_INCLUDED
