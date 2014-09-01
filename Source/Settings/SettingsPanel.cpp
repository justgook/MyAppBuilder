/*
  ==============================================================================

    SettingsPanel.cpp
    Created: 27 Aug 2014 11:12:28am
    Author:  Roman Potashow

  ==============================================================================
*/

#include "SettingsPanel.h"
#include "JsonTreeItem.h"

//class SettingsTreeViewItem : public TreeViewItem {
//
//    bool mightContainSubItems() {
//        return true;
//    }
//};

class SettingsPanel::SearchInput : public TextEditor {
public:
    SearchInput() {
        setMultiLine(false);
        setScrollbarsShown(false);
        setPopupMenuEnabled(false);
        setSelectAllWhenFocused(true);
//    searchInput->addListener(this);
        setBounds(0, 0, 100, 25);
    };
};

SettingsPanel::SettingsPanel() {
    DBG("SettingsPanel::SettingsPanel");
    layoutManager = new StretchableLayoutManager();
    setSize(100, 100);
    layoutManager->setItemLayout(0, 100, -1, -0.5);
    layoutManager->setItemLayout(1, resizeBarSize, resizeBarSize, resizeBarSize);
    layoutManager->setItemLayout(2, 100, -1, -0.5);

    leftPanel = new Component();
    resizerBar = new StretchableLayoutResizerBar(layoutManager, 1, true);
    rightPanel = new FormBuilder();

    searchInput = new SearchInput();

    leftPanel->addAndMakeVisible(searchInput);
    searchInput->setBounds("0, 0, parent.width - 100, 25");



    /** Parses the editors contects as JSON. */
    var parsedJson;
    Result result = JSON::parse("{\"test\":[\"a\"]}", parsedJson);

//        if (! result.wasOk())
//        {
//            return nullptr;
//        }

    resultsTree.setRootItem(new JsonTreeItem(Identifier(), parsedJson));
    resultsTree.setBounds("0, 25, parent.width , parent.height - 25");

    leftPanel->addAndMakeVisible(&resultsTree);
    rightPanel->setSize(100, 100);
    resultsTree.setColour(TreeView::backgroundColourId, Colours::white);
    resultsTree.setRootItemVisible(false);
    resultsTree.setBounds(0, 25, 200, 200);
//    resultsTree.setDefaultOpenness (true);

    TextPropertyComponent *text = new TextPropertyComponent(Value("This is a single-line Text Property"), "Text 1", 200, false);
    rightPanel->addAndMakeVisible(text);
    addAndMakeVisible(leftPanel);
    addAndMakeVisible(resizerBar);
    addAndMakeVisible(rightPanel);
}

void SettingsPanel::resized() {
    Component *comps[] = {leftPanel, resizerBar, rightPanel};
    layoutManager->layOutComponents(comps, 3, 0, 0, getWidth(), getHeight(), false, true);
}

SettingsPanel::~SettingsPanel() {
    delete leftPanel;
    delete resizerBar;
    delete rightPanel;
    delete searchInput;
}
