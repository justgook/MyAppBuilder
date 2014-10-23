/*
  ==============================================================================

    PluginManager.h
    Created: 22 Jul 2014 6:13:34pm
    Author:  Roman Potashow

  ==============================================================================
*/

#ifndef PLUGINMANAGER_H_INCLUDED
#define PLUGINMANAGER_H_INCLUDED
#include "../../juce/JuceLibraryCode/JuceHeader.h"
#include "PluginWrapper.h"
#include "../Settings/SettingsManager.h"

class PluginManager {
public:
    PluginManager(SettingsManagerInterface *settingsManager);
    ~PluginManager();

    bool enablePlugin(const String name, const String version);
    bool enablePlugin(const StringPairArray names);
    PluginWrapper * getPluginByName(const String name) const;
    StringArray getInstalledPluginList(const String name) const;
private:
    StringArray installedPlugin;

    SettingsManagerInterface *settingsManager;
    HashMap<String, PluginWrapper*> projectPlugins;
    DynamicLibrary loader;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginManager);

};

#endif  // PLUGINMANAGER_H_INCLUDED
