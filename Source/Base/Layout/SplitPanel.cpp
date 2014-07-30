/*
  ==============================================================================

    SplitPanel.cpp
    Created: 30 Jul 2014 11:24:25am
    Author:  Roman Potashow

  ==============================================================================
*/

#include "SplitPanel.h"

SplitPanel::SplitPanel() {

}

SplitPanel::~SplitPanel() {

}


//This must return the next target to try after this one.
ApplicationCommandTarget *SplitPanel::getNextCommandTarget() {
    return nullptr;
}


//This must return a complete list of commands that this target can handle.
void SplitPanel::getAllCommands(Array<CommandID> &commands) {

}

//This must provide details about one of the commands that this target can perform.
void SplitPanel::getCommandInfo(CommandID commandID, ApplicationCommandInfo &result) {

}

//This must actually perform the specified command.
bool SplitPanel::perform(ApplicationCommandTarget::InvocationInfo const &info) {
    return false;
}



