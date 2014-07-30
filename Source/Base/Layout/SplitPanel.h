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

class SplitPanel : public Component, public ApplicationCommandTarget/*, public DragAndDropTarget*/ {
public:
    SplitPanel();

    ~SplitPanel();


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
    ScopedPointer<StretchableLayoutResizerBar> resizerBar;
    ScopedPointer<StretchableLayoutManager> layoutManager;
};


#endif  // SPLITPANEL_H_INCLUDED
