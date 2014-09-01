/*
  ==============================================================================

    SettingsPanel.h
    Created: 27 Aug 2014 11:12:28am
    Author:  Roman Potashow

  ==============================================================================
*/

#ifndef SETTINGSPANEL_H_INCLUDED
#define SETTINGSPANEL_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "FormBuilder.h"

class SettingsPanel : public Component {

public:
    SettingsPanel();
    ~SettingsPanel();
    void resized();

//    ~SettingsPanel();
private:
    class SearchInput;
    class ApplicationSettingsTree;
    const int resizeBarSize = 10;
    ScopedPointer<StretchableLayoutManager> layoutManager;
    SearchInput* searchInput;
    FormBuilder* settingsDisplay;
    TreeView resultsTree;

    //    TextEditor* searchInput;
    Component* leftPanel;
    StretchableLayoutResizerBar* resizerBar;
    Component* rightPanel;

//    ScopedPointer<Viewport> leftPanelViewport;
//    ScopedPointer<Viewport> rightPanel;
//    TreeView tree;
//    ScopedPointer<TreeViewItem> treeItem;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SettingsPanel);

};

#endif  // SETTINGSPANEL_H_INCLUDED
