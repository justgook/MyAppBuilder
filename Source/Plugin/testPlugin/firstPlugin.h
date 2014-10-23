/*
  ==============================================================================

    firstPlugin.h
    Created: 26 Aug 2014 2:05:45pm
    Author:  Roman Potashow

  ==============================================================================
*/



#ifndef FIRSTPLUGIN_H_INCLUDED
#define FIRSTPLUGIN_H_INCLUDED

#include "../../juce/JuceLibraryCode/JuceHeader.h"

#include "../api/Plugin.h"

class firstPlugin : public Plugin {

public:
    firstPlugin(ApplicationPluginCommunication *communication) : Plugin(communication) {
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (firstPlugin);

};


#endif  // FIRSTPLUGIN_H_INCLUDED
