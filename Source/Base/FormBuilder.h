/*
  ==============================================================================

    FormBuilder.h
    Created: 28 Aug 2014 4:08:18pm
    Author:  Roman Potashow

  ==============================================================================
*/

#ifndef FORMBUILDER_H_INCLUDED
#define FORMBUILDER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

static Array<PropertyComponent *> createTextEditors() {
    Array<PropertyComponent *> comps;

    comps.add(new BooleanPropertyComponent(Value("This is a single-line Text Property"), "yes", ""));
    comps.add(new TextPropertyComponent(Value("This is a single-line Text Property"), "Text 1", 200, false));
    comps.add(new TextPropertyComponent(Value("Another one"), "Text 2", 200, false));

    comps.add(new TextPropertyComponent(Value(
                    "Lorem ipsum dolor sit amet, cu mei labore admodum facilisi. Iriure iuvaret invenire ea vim, cum quod"
                            "si intellegat delicatissimi an. Cetero recteque ei eos, his an scripta fastidii placerat. Nec et anc"
                            "illae nominati corrumpit. Vis dictas audire accumsan ad, elit fabulas saperet mel eu.\n"
                            "\n"
                            "Dicam utroque ius ne, eum choro phaedrum eu. Ut mel omnes virtute appareat, semper quodsi labitur in"
                            " cum. Est aeque eripuit deleniti in, amet ferri recusabo ea nec. Cu persius maiorum corrumpit mei, i"
                            "n ridens perpetua mea, pri nobis tation inermis an. Vis alii autem cotidieque ut, ius harum salutatu"
                            "s ut. Mel eu purto veniam dissentias, malis doctus bonorum ne vel, mundi aperiam adversarium cu eum."
                            " Mei quando graeci te, dolore accusata mei te."),
            "Multi-line text",
            1000, true));

    return comps;
};


class FormBuilder : public Component {
public:
    FormBuilder() {
        setOpaque(true);

        addAndMakeVisible(&propertyPanel);


        propertyPanel.addProperties(createTextEditors());
        propertyPanel.addSection("Fiew Fields", createTextEditors());
//        propertyPanel.addSection ("Sliders", createSliders (3));
//        propertyPanel.addSection ("Choice Properties", createChoices (6));
//        propertyPanel.addSection ("Buttons & Toggles", createButtons (3));
    }

//    becouse setOpaque (true); need to reimplement paint function
    void paint(Graphics &g) override {
        g.fillAll(Colour::greyLevel(0.8f));
    }

    void resized() override {
        propertyPanel.setBounds(getLocalBounds().reduced(4));
    }

private:
    PropertyPanel propertyPanel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FormBuilder);
};


#endif  // FORMBUILDER_H_INCLUDED
