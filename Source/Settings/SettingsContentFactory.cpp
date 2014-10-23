/*
  ==============================================================================

    SettingsContentFactory.cpp
    Created: 1 Sep 2014 1:53:43pm
    Author:  Roman Potashow

  ==============================================================================
*/

#include "SettingsContentFactory.h"

SettingsContentFactory::SettingsContentFactory(SettingsManagerInterface *settingsManager_)
        : settingsManager(settingsManager_) {
}


void SettingsContentFactory::resized() {
    FormBuilder::resized();
    if (getIndexOfChildComponent(keyMappingEditor) >= 0) {
        keyMappingEditor->setBounds(getLocalBounds().reduced(4));
    }
}


void SettingsContentFactory::updateContentFor(String name) {
    if (name == "keyMapEdtitor") {
        keyMappingEditor = new KeyMappingEditorComponent(*settingsManager->getKeyMappings(), true);
        removeChildComponent(&propertyPanel);
        addAndMakeVisible(keyMappingEditor);
        resized();
    } else {
        PluginSettings itemsList = settingsManager->getSettingsFor(name);
        Array<String> keys = itemsList.getAllKeys();
        for (int i = 0; i < itemsList.size(); ++i) {
            switch (itemsList.getType(i)) {

                case PluginSettings::BOOL:
                    addBoolField(itemsList[keys[i]], keys[i]);

                    break;
                case PluginSettings::INT:
                    addIntField(itemsList[keys[i]], keys[i]);
                    break;
                case PluginSettings::DOUBLE:
                    addDoubleField(itemsList[keys[i]], keys[i]);
                    break;
                case PluginSettings::STRING:
                    addTextField(itemsList[keys[i]], keys[i]);
                    break;
            }

        }
        renderContent();
        removeChildComponent(keyMappingEditor);
        addAndMakeVisible(&propertyPanel);
    }
}