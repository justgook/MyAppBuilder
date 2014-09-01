/*
  ==============================================================================

    PluginManager.h
    Created: 22 Jul 2014 6:13:34pm
    Author:  Roman Potashow

  ==============================================================================
*/

#include "WindowManager.h"
#include "CommandManager.h"
#include "LayoutManager.h"
#include "Plugin.h"

#ifndef PLUGINMANAGER_H_INCLUDED
#define PLUGINMANAGER_H_INCLUDED
class PluginManager {
public:
    PluginManager(CommandManager *commandManager, MenuManager *menuManager, LayoutManager* layoutManager);
    ~PluginManager();
    Plugin* getPluginByName(String name);
private:
    OwnedArray<Plugin, CriticalSection> ProjectPlugins;
};

#endif  // PLUGINMANAGER_H_INCLUDED
