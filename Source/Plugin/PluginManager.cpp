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


PluginManager::PluginManager(SettingsManagerInterface *settingsManager_):settingsManager(settingsManager_) {
//    commandManager->registerAllCommandsForTarget(this);
}

PluginWrapper *PluginManager::getPluginByName(String name) const{
    return projectPlugins[name];
}

StringArray PluginManager::getInstalledPluginList(String name) const{
    return installedPlugin;
}

bool PluginManager::enablePlugin(const String name, const String version) {
    settingsManager->getSettingsFor(name);
//    DBG("Enabling plugin: " << name);
    return true;
}

bool PluginManager::enablePlugin(const StringPairArray names) {
    bool returner = true;
    StringArray keys = names.getAllKeys();
    StringArray values = names.getAllValues();
    for (int i = 0; i < names.size(); ++i) {
        returner = returner && enablePlugin(keys[i],values[i]);
    }
    return returner;
}

