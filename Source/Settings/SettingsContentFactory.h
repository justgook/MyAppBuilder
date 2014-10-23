/*
  ==============================================================================

    SettingsContentFactory.h
    Created: 1 Sep 2014 1:53:43pm
    Author:  Roman Potashow

  ==============================================================================
*/

#ifndef SETTINGSCONTENTFACTORY_H_INCLUDED
#define SETTINGSCONTENTFACTORY_H_INCLUDED
#include "../../juce/JuceLibraryCode/JuceHeader.h"
#include "../Base/FormBuilder.h"
#include "SettingsManagerInterface.h"

class SettingsContentFactory: public FormBuilder{
public:
    SettingsContentFactory(SettingsManagerInterface *settingsManager);
    void updateContentFor(String name);
    void resized() override;
private:
    ScopedPointer<KeyMappingEditorComponent> keyMappingEditor;
    SettingsManagerInterface *settingsManager;
//    void resized() override {
//        propertyPanel.setBounds(getLocalBounds().reduced(4));
//    }
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SettingsContentFactory);

};




#endif  // SETTINGSCONTENTFACTORY_H_INCLUDED
