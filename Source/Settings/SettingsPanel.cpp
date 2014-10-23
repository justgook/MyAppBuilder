/*
  ==============================================================================

    SettingsPanel.cpp
    Created: 27 Aug 2014 11:12:28am
    Author:  Roman Potashow

  ==============================================================================
*/

#include "SettingsPanel.h"
#include "SettingsTreeViewItem.h"

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

SettingsPanel::SettingsPanel(SettingsManagerInterface *settingsManager_) : settingsManager(settingsManager_) {

//    DBG("SettingsPanel::SettingsPanel");
    layoutManager = new StretchableLayoutManager();
    setSize(100, 100);
    layoutManager->setItemLayout(0, 100, -1, -0.5);
    layoutManager->setItemLayout(1, resizeBarSize, resizeBarSize, resizeBarSize);
    layoutManager->setItemLayout(2, 100, -1, -0.5);

    leftPanel = new Component();
    resizerBar = new StretchableLayoutResizerBar(layoutManager, 1, true);
    rightPanel = new SettingsContentFactory(settingsManager);

    searchInput = new SearchInput();

    leftPanel->addAndMakeVisible(searchInput);
    searchInput->setBounds("0, 0, parent.width, 25");



    //Creare tree
    //========================================================================
//    selectedPlugin = "root";
    selectedPlugin.addListener(new ContentChangerListener(rightPanel));

    treeRootItem = new SettingsTreeViewItem(settingsManager->getSettingsList(), selectedPlugin);

    resultsTree.setRootItem(treeRootItem);
    leftPanel->addAndMakeVisible(&resultsTree);
    resultsTree.setBounds("0, 25, parent.width , parent.height - 25");
    rightPanel->setSize(100, 100);
    resultsTree.setColour(TreeView::backgroundColourId, Colours::white);
    resultsTree.setRootItemVisible(false);
    resultsTree.setBounds(0, 25, 200, 200);
//    resultsTree.setDefaultOpenness (true);
    //========================================================================
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
    delete treeRootItem;
}

