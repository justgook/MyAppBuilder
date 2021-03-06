/*
  ==============================================================================

    DarkTheme.h
    Created: 22 Jul 2014 12:48:42am
    Author:  Roman Potashow

  ==============================================================================
*/

#ifndef DARKTHEME_H_INCLUDED
#define DARKTHEME_H_INCLUDED

#include "../../juce/JuceLibraryCode/JuceHeader.h"

class DarkTheme : public LookAndFeel_V3 {
public:
    DarkTheme();
    ~DarkTheme();

    Button *createTabBarExtrasButton();

    void drawDraggableTabCloseButton(TabBarButton &, Graphics &, bool isMouseOver, bool isMouseDown);
    void drawStretchableLayoutResizerBar (Graphics&, int w, int h, bool isVerticalBar, bool isMouseOver, bool isMouseDragging);

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DarkTheme);




};


#endif  // DARKTHEME_H_INCLUDED
