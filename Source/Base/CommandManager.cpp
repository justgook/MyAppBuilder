/*
  ==============================================================================

    CommandManager.cpp
    Created: 30 Jul 2014 2:14:31pm
    Author:  Roman Potashow

  ==============================================================================
*/

#include "CommandManager.h"


CommandManager::CommandManager():ApplicationCommandManager() {}


CommandID CommandManager::getCommandId(const String &commandName) {
    if (!commandsMapping.contains(commandName)) {
        commandsMapping.set(commandName, ++lastCommandID);
    }
    return commandsMapping[commandName];
}


ApplicationCommandTarget *CommandManager::getNextRegisteredManager(ApplicationCommandTarget *target) {
    return managers[managers.indexOf(target) + 1];
}

void CommandManager::registerManager(ApplicationCommandTarget *target) {
    ApplicationCommandManager::registerAllCommandsForTarget(target);
    managers.insert(0, target);
    setFirstCommandTarget(target);
}
