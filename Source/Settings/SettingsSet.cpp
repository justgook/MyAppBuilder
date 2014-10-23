/*
  ==============================================================================

    SettingsSet.cpp
    Created: 4 Sep 2014 4:07:08pm
    Author:  Roman Potashow

  ==============================================================================
*/

#include "SettingsSet.h"

SettingsSet::SettingsSet() {
    PropertySet p;
    p.setValue("testPtopInt3", 3);
    settings.set("plugin1", p);
    settings.set("plugin2", p);
    settings.set("plugin3", p);
    settings.set("plugin4", p);
}

SettingsSet::~SettingsSet() {

}

bool SettingsSet::parsePluginSettings(String pluginName, const File &targetLocation) {
    return false;
}


//Array<String> SettingsSet::getSettingsListOfPluginId() {
//    Array<String> results;
//    // This iterates the map, printing all of its key -> value pairs..
//    for (HashMap<String, PropertySet>::Iterator i(settings); i.next();) {
//        results.add(i.getKey());
//    }
//    return results;
//}

PropertySet SettingsSet::getSettingsFor(String name) {
    return settings[name];
}
