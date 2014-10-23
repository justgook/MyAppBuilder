/*
  ==============================================================================

    SettingsManagerInterface.h
    Created: 1 Sep 2014 3:05:15pm
    Author:  Roman Potashow

  ==============================================================================
*/

#ifndef SETTINGSMANAGERINTERFACE_H_INCLUDED
#define SETTINGSMANAGERINTERFACE_H_INCLUDED

#include "../../juce/JuceLibraryCode/JuceHeader.h"
#include "SettingsSet.h"
#include "PluginSettings.h"

//TODO find better name
class SettingsManagerInterface {
public:
    virtual KeyPressMappingSet *getKeyMappings() = 0;

    virtual StringPairArray getSettingsList() = 0;
    virtual PluginSettings getSettingsFor(String name) = 0;
    virtual void setProjectSettingsFor(String name, PluginSettings settings) =0;

    //Name can be just name, of some global property or dot separated for some naming, plugin_name.setting_name
//    virtual var getSettingsFor(String name) = 0;
    virtual ~SettingsManagerInterface() {
    };

};


#endif  // SETTINGSMANAGERINTERFACE_H_INCLUDED
