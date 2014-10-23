/*
  ==============================================================================

    SettingsPanel.h
    Created: 27 Aug 2014 11:12:28am
    Author:  Roman Potashow

  ==============================================================================
*/

#ifndef SETTINGSPANEL_H_INCLUDED
#define SETTINGSPANEL_H_INCLUDED

#include "../../juce/JuceLibraryCode/JuceHeader.h"
#include "SettingsContentFactory.h"
#include "SettingsManagerInterface.h"

class SettingsPanel : public Component {

public:
    SettingsPanel(SettingsManagerInterface *settingsManager);

    ~SettingsPanel();

    void resized();

protected:

    TreeViewItem *treeRootItem;

private:
    class SearchInput;

    const int resizeBarSize = 10;

    class ContentChangerListener : public Value::Listener {
    public:
        ContentChangerListener(SettingsContentFactory *rightPanel_) : rightPanel(rightPanel_) {
        }
        void valueChanged(Value &value) {
            rightPanel->updateContentFor(value.toString());
        }

    private:
        SettingsContentFactory *rightPanel;
    };


    SettingsManagerInterface *settingsManager;
    ScopedPointer<StretchableLayoutManager> layoutManager;
    SearchInput *searchInput;
//    FormBuilder* settingsDisplay;
    TreeView resultsTree;
    //    TextEditor* searchInput;
    Component *leftPanel;
    StretchableLayoutResizerBar *resizerBar;
    SettingsContentFactory *rightPanel;
    Value selectedPlugin;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SettingsPanel);

};

#endif  // SETTINGSPANEL_H_INCLUDED
