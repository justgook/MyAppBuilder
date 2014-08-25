/*
  ==============================================================================

    SplitPanel.cpp
    Created: 30 Jul 2014 11:24:25am
    Author:  Roman Potashow

  ==============================================================================
*/

#include "SplitPanel.h"


SplitPanel::SplitPanel(Component *content_, SplitPanel *parent_, bool isVertical_)
        : content(content_), isVertical(isVertical_), parent(parent_) {
    setSize(100, 100);
    addAndMakeVisible(content);
}

SplitPanel::~SplitPanel() {
    if (!childs.size()) {
        delete content;
    }
}

bool SplitPanel::getIsVertical() {
    return isVertical;
}


SplitPanel *SplitPanel::getParent() {
    return parent;
}


void SplitPanel::addChild(SplitPanel::AddTo position, Component *content) {
    SplitPanel *master = findParentToAdd(position);
    if (master != this) {
        master->appendChild(content, position, master->childs.indexOf(this));
    } else {
        master->appendChild(content, position, 0);
    }
}


SplitPanel *SplitPanel::findParentToAdd(SplitPanel::AddTo position) {
    SplitPanel *parent = this;
    SplitPanel *prevParent = this;
    bool isVertical_ = SplitPanel::AddTo::Bottom == position;
    while (parent->getParent() != nullptr && parent->getIsVertical() == isVertical_) {
        prevParent = parent;
        parent = parent->getParent();
    }
    if (parent->getParent() == nullptr && parent->getIsVertical() == isVertical_) {
        return parent;
    }
    return prevParent;

}

//Will Be used for delete
void SplitPanel::reorderLayoutManager() {
    layoutManager->clearAllItems();
    for (int i = 0; i < childs.size(); i++) {
        if (i % 2) {
            //TODO remove resizeBars from childs
            StretchableLayoutResizerBar *resizeBar = new StretchableLayoutResizerBar(layoutManager, i, !isVertical);
            childs.set(i, resizeBar, true);
            addAndMakeVisible(resizeBar);
            layoutManager->setItemLayout(i, resizeBarSize, resizeBarSize, resizeBarSize);
        } else {
            layoutManager->setItemLayout(i, minimumSize, maximumSize, preferredSize);
        }
    }
}

void SplitPanel::appendChild(Component *content_, SplitPanel::AddTo position, int index) {
    if (childs.size() == 0) {
        removeAllChildren();
        isVertical = SplitPanel::AddTo::Bottom == position;
        layoutManager = new StretchableLayoutManager();
        layoutManager->setItemLayout(childs.size(), minimumSize, maximumSize, preferredSize);
        SplitPanel *child = getChildInstance(content, this, isVertical);
        childs.add(child);
        addAndMakeVisible(child);
    }
    //TODO find way how to update Item index (argument[1])
    //TODO remove resizeBars from childs
    StretchableLayoutResizerBar *resizeBar = new StretchableLayoutResizerBar(layoutManager, childs.size(), !isVertical);
    SplitPanel *child = getChildInstance(content_, this, isVertical);

    switch (position) {
        case Right:
        case Bottom:
            if (index >= 0 && index != childs.size() - 1) {
                //TODO remove resizeBars from childs
                childs.insert(index + 1, resizeBar);
                childs.insert(index + 2, child);
            } else {
                //TODO remove resizeBars from childs
                childs.add(resizeBar);
                childs.add(child);
            }
            break;
        case Left:
            childs.insert(index, resizeBar);
            childs.insert(index, child);
            break;
    }
    reorderLayoutManager();
//    layoutManager->setItemLayout(childs.size() - 2, resizeBarSize, resizeBarSize, resizeBarSize);
//    layoutManager->setItemLayout(childs.size() - 1, minimumSize, maximumSize, preferredSize);
//    addAndMakeVisible(resizeBar);
    addAndMakeVisible(child);
    resized();
}

void SplitPanel::resized() {
    if (childs.size() > 0) {
        //TODO remove resizeBars from childs
        layoutManager->layOutComponents(childs.getRawDataPointer(), childs.size(), 0, 0, getWidth(), getHeight(), isVertical, true);
    } else {
        content->setBounds(0, 0, getWidth(), getHeight());
    }
}

void SplitPanel::removeChild(SplitPanel *child) {
    reorderLayoutManager();
}

SplitPanel *SplitPanel::getChildInstance(Component *content_, SplitPanel *parent_, bool isVertical_) {
    return new SplitPanel(content_, parent_, isVertical_);
}
