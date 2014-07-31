/*
  ==============================================================================

    CommandManager.h
    Created: 30 Jul 2014 2:14:31pm
    Author:  Roman Potashow

  ==============================================================================
*/

#ifndef COMMANDMANAGER_H_INCLUDED
#define COMMANDMANAGER_H_INCLUDED
#include "../JuceLibraryCode/JuceHeader.h"

class CommandManager : public ApplicationCommandManager {
public:
    CommandManager();
    const CommandID getNextCommandID(const String &commandName);
private:

    CommandID lastCommandID = 0;
    HashMap<String, CommandID> commandsMapping;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CommandManager);

};


#endif  // COMMANDMANAGER_H_INCLUDED
