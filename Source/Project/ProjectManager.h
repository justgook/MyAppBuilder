/*
  ==============================================================================

    ProjectManager.h
    Created: 1 Sep 2014 12:05:42pm
    Author:  Roman Potashow

  ==============================================================================
*/

#ifndef PROJECTMANAGER_H_INCLUDED
#define PROJECTMANAGER_H_INCLUDED

#include "../../juce/JuceLibraryCode/JuceHeader.h"
#include "../Plugin/PluginManager.h"
#include "../Settings/SettingsManager.h"
#include "../Settings/PluginSettings.h"
#include <stdexcept>


class ProjectManager {
public:
    ProjectManager(String projectDir_) : projectDir(projectDir_) {
    }

    ProjectManager(PluginManager *pluginManager_, SettingsManager *settingsManager_)
            : pluginManager(pluginManager_), settingsManager(settingsManager_) {
        //TODO change to something more global  DO NOT USE IT
        File file("/Users/gook/Projects/MyGameBuilder/ide/firstProject/project.json");

//        Parse project file
        //==== Plugins ==================================
        projectData = JSON::parse(file);
        if (!projectData["dependencies"].isObject()) {
            std::runtime_error ex(std::string("Failed: load dependencies from project file"));
            JUCEApplication::sendUnhandledException(&ex, __FILE__, __LINE__);
        }
        NamedValueSet &plugins(projectData["dependencies"].getDynamicObject()->getProperties());


        //==== Settings==================================
        if (!projectData["settings"].isObject()) {
            std::runtime_error ex(std::string("Failed: load settings from project file"));
            JUCEApplication::sendUnhandledException(&ex, __FILE__, __LINE__);
        }

        NamedValueSet &settings(projectData["settings"].getDynamicObject()->getProperties());
        for (int i = 0; i < settings.size(); ++i) {
            const Identifier id(settings.getName(i));
            settingsManager->setProjectSettingsFor(id.toString(), parseSettingsSection(settings[id]));
        }

        ///Enabling plugins that must get settings from Settings manager
        pluginManager->enablePlugin(parsePluginSection(plugins));

    }

    ~ProjectManager() {
    }

//    Array<String> getListOfInstalledPlugins() {
//        Array<String> arr;
//        return arr;
//    };
private:
    const StringPairArray parsePluginSection(NamedValueSet props) {
        StringPairArray arr;
        for (int i = 0; i < props.size(); ++i) {
            const Identifier id(props.getName(i));
            arr.set(id.toString(), props[id].toString());
        }
        return arr;
    };

    const PluginSettings parseSettingsSection(var json) {
        if (!json.isObject()) {
            std::runtime_error ex(std::string("Failed: load settings all plugin settings must be objects, that holdes key/value pair"));
            JUCEApplication::sendUnhandledException(&ex, __FILE__, __LINE__);
        }
        PluginSettings settings;
        DynamicObject *obj = json.getDynamicObject();
        NamedValueSet &props(obj->getProperties());
        for (int i = 0; i < props.size(); ++i) {
            const Identifier id(props.getName(i));
            var item = props.getValueAt(i);
            settings.set(id.toString(), Value(props.getValueAt(i)), PluginSettings::getTypeFromVar(item));
        }
        return settings;

    };

//    getSettings
    PluginManager *pluginManager;
    SettingsManager *settingsManager;
    String projectDir;
    var projectData; // JSON
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ProjectManager);

};

#endif  // PROJECTMANAGER_H_INCLUDED
