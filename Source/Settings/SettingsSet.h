/*
  ==============================================================================

    SettingsSet.h
    Created: 4 Sep 2014 4:07:08pm
    Author:  Roman Potashow

  ==============================================================================
*/

#ifndef SETTINGSSET_H_INCLUDED
#define SETTINGSSET_H_INCLUDED

#include "../../juce/JuceLibraryCode/JuceHeader.h"

class SettingsSet {

public:
    SettingsSet();

    ~SettingsSet();

//    Array<String> getSettingsListOfPluginId(); // Used in SettingsPanel to display tree of settings configuration

    bool parsePluginSettings(String pluginName, const File &targetLocation);
//    bool setProjectSettingsFor(String pluginName, PropertySet properties);
    PropertySet getSettingsFor(String name);

private:
    //TODO settings must be grouped by plugins / categories
//    PropertySet resultSettings;
//
//    PropertySet *getProjcetSettings(); // diff of project set
//    bool loadProjcetSettings(const File &targetLocation);
//
//    PropertySet projectSettings;
//
//    PropertySet *getUserSettings(); // diff of userSet settings
//    bool loadUserSettings(const File &targetLocation);
//
//    PropertySet userSettings;
//
//    PropertySet *getCommonSettings(); //list of possible settings
//    PropertySet commonSettings;
    //Named settings list, where name is plugin/addon name
    //addons uses dot (".") to show to what plugin is this addon
    HashMap<String, PropertySet> settings;
    HashMap<String, PropertySet> projectSettings;



    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SettingsSet);


};


#endif  // SETTINGSSET_H_INCLUDED
