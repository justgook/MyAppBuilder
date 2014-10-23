/*
  ==============================================================================

    DataSaver.h
    Created: 1 Sep 2014 12:57:08pm
    Author:  Roman Potashow

  ==============================================================================
*/

#ifndef DATASAVER_H_INCLUDED
#define DATASAVER_H_INCLUDED

#include "../../juce/JuceLibraryCode/JuceHeader.h"
class DataSaver{
    DataSaver();
    var readFile(String name);
    bool wrireFile(var data);
};



#endif  // DATASAVER_H_INCLUDED
