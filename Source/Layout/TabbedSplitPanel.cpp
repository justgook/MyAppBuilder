/*
  ==============================================================================

    TabbedSplitPanel.cpp
    Created: 22 Aug 2014 4:27:37pm
    Author:  Roman Potashow

  ==============================================================================
*/

#include "TabbedSplitPanel.h"

Component *mockData() {
    TabbedComponent *tabsHolder = new DraggableTabbedComponent(TabbedButtonBar::Orientation::TabsAtTop);
//    tabsHolder->addTab("1", Colours::red, new Label("a1", "vsdv"), true, -1);
    tabsHolder->addTab("4567899", Colours::beige, new TextEditor("a1"), true, -1);
    tabsHolder->addTab("3dasdas", Colours::bisque, new TextEditor("a1"), true, -1);
    tabsHolder->addTab("4dasdas", Colours::rosybrown, new Label("a1", "vxcvcx xxc "), true, -1);
    tabsHolder->addTab("5dasdas", Colours::black, new Label("a1", "zvzx sc edsf2ewdv"), true, -1);
    tabsHolder->addTab("6dasdas", Colours::blue, new Label("a1", "dsvx dczv eds "), true, -1);
    tabsHolder->addTab("7dasdas", Colours::firebrick, new Label("a1", "sfxdsxvcds dv esv edfc efd"), true, -1);
    tabsHolder->setWantsKeyboardFocus(true);
    return tabsHolder;
};


class TabbedSplitPanel::OverlayComponent : public Component {
public:
    Colour colour = Colour::fromRGBA(0, 0, 0, 100);

    void paint(Graphics &g) {
        g.fillAll(colour);
    }

    void setPointPosition(Point<int> point) {
        int parentWidth = getParentWidth();
        int parentHeight = getParentHeight();
        if (point.y > parentHeight / 2 && point.x > parentWidth / 5 && point.x < parentWidth * 0.8) {
            updatePosition(Bottom);
        } else if (point.x > parentWidth / 2) {
            updatePosition(Right);
        } else {
            updatePosition(Left);
        }

    }

    SplitPanel::AddTo position = Bottom;

private:

    void updatePosition(SplitPanel::AddTo _position) {
        if (position != _position) {
            int parentWidth = getParentWidth();
            int parentHeight = getParentHeight();
            switch (_position) {
                case Left:
//                    Desktop::getInstance().getAnimator().animateComponent(this, Rectangle<int> (0, 0, getParentWidth() / 2, getParentHeight()), 1, 200, false, 100, 1000);
                    setBounds(0, 0, parentWidth / 2, parentHeight);
                    break;
                case Right:
//                    Desktop::getInstance().getAnimator().animateComponent(this, Rectangle<int> (getParentWidth() / 2, 0, getParentWidth(), getParentHeight()), 1, 200, false, 100, 1000);
                    setBounds(parentWidth / 2, 0, parentWidth, parentHeight);
                    break;
                case Bottom:
//                    Desktop::getInstance().getAnimator().animateComponent(this, Rectangle<int> (0, getParentHeight() / 2, getParentWidth(), getParentHeight()), 1, 200, false, 100, 1000);
                    setBounds(0, parentHeight / 2, parentWidth, parentHeight);
                    break;
            }
//            getAnimator();
//            Desktop.getAnimator().animateComponent();
            position = _position;
        }
    }
//    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OverlayComponent);
};


TabbedSplitPanel::TabbedSplitPanel(SplitPanel *parent, bool isVertical): SplitPanel(mockData(), parent, isVertical) {
    overlay = new OverlayComponent();
    addChildComponent(overlay);
}

TabbedSplitPanel::TabbedSplitPanel(Component *content, SplitPanel *parent, bool isVertical): SplitPanel(content, parent, isVertical) {
    overlay = new OverlayComponent();
    addChildComponent(overlay);
}


bool TabbedSplitPanel::isInterestedInDragSource(DragAndDropTarget::SourceDetails const &dragSourceDetails) {
    return true;
}

void TabbedSplitPanel::itemDragMove(DragAndDropTarget::SourceDetails const &dragSourceDetails) {
    DragAndDropTarget::itemDragMove(dragSourceDetails);
    overlay->setPointPosition(dragSourceDetails.localPosition);
}

void TabbedSplitPanel::itemDropped(DragAndDropTarget::SourceDetails const &dragSourceDetails) {
    overlay->setVisible(false);
    //TODO change me to real data!
    addChild(overlay->position, mockData());
    DBG("Item droped to SplitPanel");
}

void TabbedSplitPanel::itemDragEnter(DragAndDropTarget::SourceDetails const &dragSourceDetails) {
    DragAndDropTarget::itemDragEnter(dragSourceDetails);
    overlay->setVisible(true);
}

void TabbedSplitPanel::itemDragExit(DragAndDropTarget::SourceDetails const &dragSourceDetails) {
    DragAndDropTarget::itemDragExit(dragSourceDetails);
    overlay->setVisible(false);
}

SplitPanel *TabbedSplitPanel::getChildInstance(Component *content, SplitPanel *parent, bool isVertical) {
    return new TabbedSplitPanel(content, parent, isVertical);
}

