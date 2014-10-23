/*
  ==============================================================================

    PluginWrapper.h
    Created: 4 Sep 2014 3:36:07pm
    Author:  Roman Potashow

  ==============================================================================
*/

#ifndef PLUGINWRAPPER_H_INCLUDED
#define PLUGINWRAPPER_H_INCLUDED

#include "api/Plugin.h"
#include "../../juce/JuceLibraryCode/JuceHeader.h"
#include "../Settings/PluginSettings.h"

class PluginWrapper : public ActionBroadcaster, public ActionListener {
private:
    //ActionListener
    void actionListenerCallback(const String &message);
    PluginSettings* settings;
    Plugin *instance;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginWrapper);

};

#endif  // PLUGINWRAPPER_H_INCLUDED
