/*
  ==============================================================================

    PluginManager.cpp
    Created: 22 Jul 2014 6:13:34pm
    Author:  Roman Potashow

  ==============================================================================
*/

#include "PluginManager.h"


PluginManager::~PluginManager() {

}


PluginManager::PluginManager(CommandManager *commandManager, MenuManager *menuManager, LayoutManager *layoutManager) {
//    commandManager->registerAllCommandsForTarget(this);
}

Plugin *PluginManager::getPluginByName(String string) {
    return nullptr;
}
