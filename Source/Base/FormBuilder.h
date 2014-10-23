/*
  ==============================================================================

    FormBuilder.h
    Created: 28 Aug 2014 4:08:18pm
    Author:  Roman Potashow

  ==============================================================================
*/

#ifndef FORMBUILDER_H_INCLUDED
#define FORMBUILDER_H_INCLUDED

#include "../../juce/JuceLibraryCode/JuceHeader.h"

class FormBuilder : public Component {
public:
    void addBoolField(const Value &valueToControl,
            const String &propertyName) {
        childs.add(new BooleanPropertyComponent(valueToControl, propertyName, ""));
    };

    void addIntField(const Value &valueToControl,
            const String &propertyName) {
        childs.add(new SliderPropertyComponent(valueToControl, propertyName, 0, 100, 1));
    };

    void addDoubleField(const Value &valueToControl,
            const String &propertyName) {
        childs.add(new SliderPropertyComponent(valueToControl, propertyName, 0, 10, 0.1));
    };

    void addTextField(const Value &valueToControl,
            const String &propertyName) {
        childs.add(new TextPropertyComponent(valueToControl, propertyName, 128, false));
    };

    void addTextAreaField(const Value &valueToControl,
            const String &propertyName,
            int maxNumChars = 1024) {
        childs.add(new TextPropertyComponent(valueToControl, propertyName, maxNumChars, true));
    };


    FormBuilder() {
        setOpaque(true);
        addAndMakeVisible(&propertyPanel);
    }

//    becouse setOpaque (true); need to reimplement paint function
    void paint(Graphics &g) override {
        g.fillAll(Colour::greyLevel(0.8f));
    }

    void renderContent() {
        propertyPanel.clear();
        if (childs.size() > 0) {
            propertyPanel.addProperties(childs);
            childs.clear();
        }
    }

    void resized() override {
        propertyPanel.setBounds(getLocalBounds().reduced(4));
    }

protected:
    PropertyPanel propertyPanel;

private:
    Array<PropertyComponent *> childs;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FormBuilder);
};


#endif  // FORMBUILDER_H_INCLUDED
