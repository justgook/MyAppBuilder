/*
  ==============================================================================

    SettingsTreeViewItem.h
    Created: 2 Sep 2014 4:57:20pm
    Author:  Roman Potashow

  ==============================================================================
*/

#ifndef SETTINGSTREEVIEWITEM_H_INCLUDED
#define SETTINGSTREEVIEWITEM_H_INCLUDED

#include "../../juce/JuceLibraryCode/JuceHeader.h"
#include "SettingsSet.h"
#include <iostream>
#import <sstream>

//int SettingsTreeViewItemCounter = 0;
class SettingsTreeViewItem : public TreeViewItem {
public:

    ~SettingsTreeViewItem() {
        selectedItemId.referTo(Value());
    }

    SettingsTreeViewItem(const StringPairArray itemsList, Value &valueToControl) {
        id = "root";
        StringArray names = itemsList.getAllValues();
        StringArray keys = itemsList.getAllKeys();
        for (int i = 0; i < itemsList.size(); ++i) {
            addSubItem(new SettingsTreeViewItem(keys[i], names[i], valueToControl));
        }
    }

    /** Returns a string to uniquely identify this item.

    If you're planning on using the TreeView::getOpennessState() method, then
    these strings will be used to identify which nodes are open. The string
    should be unique amongst the item's sibling items, but it's ok for there
    to be duplicates at other levels of the tree.

    If you're not going to store the state, then it's ok not to bother implementing
    this method.
    */
    String getUniqueName() const override {
        return id.toString();
    }

    bool mightContainSubItems() override {
        return false;
    }

    void paintItem(Graphics &g, int width, int height) override {
        // if this item is selected, fill it with a background colour..
        if (isSelected())
            g.fillAll(Colours::blue.withAlpha(0.3f));

        g.setColour(Colours::black);
        g.setFont(height * 0.7f);

        // draw the element's tag name..
        g.drawText(getText(),
                4, 0, width - 4, height,
                Justification::centredLeft, true);
    }

    void itemOpennessChanged(bool isNowOpen) override {
        if (isNowOpen) {
//            for (int i = 0; i < itemsList->getChilds().size(); ++i) {
//                addSubItem(new SettingsTreeViewItem(itemsList->getChild(i)));
//            }
        } else {
            clearSubItems();
        }
    }

    void itemSelectionChanged(bool isNowSelected) {
        if (isNowSelected) {
            selectedItemId.setValue(getOwnerView()->getSelectedItem(0)->getUniqueName());
        }
    }

private:
    SettingsTreeViewItem(const Identifier id_, const String name_, Value &valueToControl) {
        id = id_;
        name = name_;
        selectedItemId.referTo(valueToControl);
    }
    Identifier id;
    String name;
    Value selectedItemId;

    /** Returns the text to display in the tree.
    This is a little more complex for JSON than XML as nodes can be strings, objects or arrays.
    */
    String getText() const {
        return name;//itemsList->getSettingName();
    }
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SettingsTreeViewItem)

};

#endif  // SETTINGSTREEVIEWITEM_H_INCLUDED
