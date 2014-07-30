/*
  ==============================================================================

    KeyMappingPanel.cpp
    Created: 22 Jul 2014 12:19:54am
    Author:  Roman Potashow

  ==============================================================================
*/

#include "KeyMappingPanel.h"


//==============================================================================
//class KeyMappingsDemo   : public Component
//{
//public:
//    KeyMappingsDemo()
//        : keyMappingEditor (*MainAppWindow::getApplicationCommandManager().getKeyMappings(), true)
//    {
//        setOpaque (true);
//        addAndMakeVisible (keyMappingEditor);
//    }
//
//    void paint (Graphics& g) override
//    {
//        g.fillAll (Colour::greyLevel (0.93f));
//    }
//
//    void resized() override
//    {
//        keyMappingEditor.setBounds (getLocalBounds().reduced (4));
//    }
//
//private:
//    KeyMappingEditorComponent keyMappingEditor;
//
//    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KeyMappingsDemo);
//};
//
//
//// This static object will register this demo type in a global list of demos..
//static JuceDemoType<KeyMappingsDemo> demo ("01 Shortcut Keys");