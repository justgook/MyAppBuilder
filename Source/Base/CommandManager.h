/*
  ==============================================================================

    CommandManager.h
    Created: 30 Jul 2014 2:14:31pm
    Author:  Roman Potashow

  ==============================================================================
*/

#ifndef COMMANDMANAGER_H_INCLUDED
#define COMMANDMANAGER_H_INCLUDED
#include "../../juce/JuceLibraryCode/JuceHeader.h"

class CommandManager : public ApplicationCommandManager {
public:
    CommandManager();
    CommandID getCommandId(const String &commandName);
    void registerManager(ApplicationCommandTarget *target);
    ApplicationCommandTarget*getNextRegisteredManager(ApplicationCommandTarget *target);
private:
    Array<ApplicationCommandTarget*> managers;
    CommandID lastCommandID = 0x2101;
    HashMap<String, CommandID> commandsMapping;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CommandManager);

};


#endif  // COMMANDMANAGER_H_INCLUDED
