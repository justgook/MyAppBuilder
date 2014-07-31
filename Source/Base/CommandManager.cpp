/*
  ==============================================================================

    CommandManager.cpp
    Created: 30 Jul 2014 2:14:31pm
    Author:  Roman Potashow

  ==============================================================================
*/

#include "CommandManager.h"


CommandManager::CommandManager():ApplicationCommandManager() {}


const CommandID CommandManager::getNextCommandID(const String &commandName) {
    if (!commandsMapping.contains(commandName)) {
        commandsMapping.set(commandName, ++lastCommandID);
    }
    return commandsMapping[commandName];
}


