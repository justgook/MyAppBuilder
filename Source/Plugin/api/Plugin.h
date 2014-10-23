/*
  ==============================================================================

    Plugin.h
    Created: 26 Aug 2014 2:06:21pm
    Author:  Roman Potashow

  ==============================================================================
*/

#ifndef PLUGIN_H_INCLUDED
#define PLUGIN_H_INCLUDED

#include "ApplicationPluginCommunication.h"

#include <iostream>

//TODO move to to other file
class PluginString {
};

//class PluginData;
class CommandDescription {
    PluginString small;
    PluginString full;
};

class Plugin {
public:
    Plugin(ApplicationPluginCommunication *communication){};

    virtual ~Plugin() {
    }

    //return true if there is some panel
    virtual bool havePanel() = 0;

    //return panel for view, or specific type (by name) of panel defined somewhere
    virtual void getPanel(std::string name) = 0;

    virtual bool isMultiplyInstancesOfPannelAllowed() = 0;

    // get description for command
    virtual CommandDescription getCommandsDesc(std::string commandName) = 0;

    //Trigger command to plugin uses that to
    virtual void execCommand(std::string event) = 0;

    //========================================================================================
    //MENUS
    //Return Array of
    //Context menu and main menu elements must be defined in JSON formated files
    //========================================================================================


    //========================================================================================
//    settingsPanel
    // all settings must be defined in
    //Todo move that to PluginSettings Class
    enum SettingFieldType {
        Text,
        Password, //
                Bool, //CheckBox
        Select, // select in HTML
        TextArea,
        Range, //Slider
//        TODO thin about absolute and relative path
                File, //File selection
//        Array //Dynamic adding fields
//        CodeEditor,

    };

    virtual SettingFieldType getFieldTypeForSetting(std::string nameOfProperty) = 0;

    virtual bool validateTextField(std::string nameOfProperty, std::string value) = 0;

    //When settingsManager get update those methods are called, return is success or no (or is there at all possibility to set that setting)
    virtual bool setRangeBoolUserSettings(std::string nameOfProperty, bool value) = 0;

    virtual bool setRangeIntUserSettings(std::string nameOfProperty, int value) = 0;

    virtual bool setRangeFloatUserSettings(std::string nameOfProperty, float value) = 0;

    virtual bool setTextUserSettings(std::string nameOfProperty, std::string value) = 0;

    virtual bool setPasswordUserSettings(std::string nameOfProperty, std::string value) = 0;

    virtual bool setFileUserSettings(std::string nameOfProperty, std::string pathToFile) = 0;

//    virtual bool setArrayUserSettings(std::string nameOfProperty, std::string value) = 0;
    //TODO add custom classes for all field types like:
    //getMaxRrange, getMinRange, getTextFieldLength, .. getArrayTypes.. isFileLocationRelative
    //========================================================================================


};


#endif  // PLUGIN_H_INCLUDED
