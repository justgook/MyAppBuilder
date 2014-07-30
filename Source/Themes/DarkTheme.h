/*
  ==============================================================================

    DarkTheme.h
    Created: 22 Jul 2014 12:48:42am
    Author:  Roman Potashow

  ==============================================================================
*/

#ifndef DARKTHEME_H_INCLUDED
#define DARKTHEME_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class DarkTheme : public LookAndFeel_V3 {
public:
    DarkTheme();
    ~DarkTheme();


private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DarkTheme);

    Button *createTabBarExtrasButton();

    void drawDraggableTabCloseButton(TabBarButton &, Graphics &, bool isMouseOver, bool isMouseDown);

};


#endif  // DARKTHEME_H_INCLUDED
