//
// Created by Roman Potashow on 17.07.2014.
//


#ifndef __Window_H_
#define __Window_H_


#include "../JuceLibraryCode/JuceHeader.h"

//TODO Look To - MultiDocumentPanelWindow
class ApplicationWindow : public DocumentWindow/*, public ApplicationCommandTarget*/ {
public:
    ApplicationWindow(String const &name, Component *content);

    //    Window(String const &name, Colour const &backgroundColour, int requiredButtons);
    ~ApplicationWindow();

    void closeButtonPressed();
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ApplicationWindow);
};


#endif //__Window_H_
