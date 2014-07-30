/*
  ==============================================================================

    DraggableTabbedComponent.cpp
    Created: 22 Jul 2014 11:19:04pm
    Author:  Roman Potashow

  ==============================================================================
*/

#include "DraggableTabbedComponent.h"


//==============================================================================
//class DraggableTabbedComponent::DraggableButtonBar  : public TabbedButtonBar
//{
//public:
//    DraggableButtonBar (TabbedComponent& owner_, const TabbedButtonBar::Orientation orientation_)
//            : TabbedButtonBar (orientation_),
//              owner (owner_)
//    {
//    }
//
////    void currentTabChanged (int newCurrentTabIndex, const String& newTabName)
////    {
////        owner.changeCallback (newCurrentTabIndex, newTabName);
////    }
//
//    void popupMenuClickOnTab (int tabIndex, const String& tabName)
//    {
//        owner.popupMenuClickOnTab (tabIndex, tabName);
//    }
////
////    Colour getTabBackgroundColour (const int tabIndex)
////    {
////        return owner.tabs->getTabBackgroundColour (tabIndex);
////    }
////
////    TabBarButton* createTabButton (const String& tabName, int tabIndex)
////    {
////        return owner.createTabButton (tabName, tabIndex);
////    }
//
//private:
//    TabbedComponent& owner;
//
//    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DraggableButtonBar)
//};


//==============================================================================



DraggableTabbedComponent::DraggableTabbedComponent(TabbedButtonBar::Orientation const &orientation)
        : TabbedComponent(orientation) {
    setSize(700, 700);
//    addAndMakeVisible (tabs = new DraggableButtonBar (*this, orientation));
}


//new type of button

class DraggableTabbedComponent::DraggableTabBarButton
        : public TabBarButton, public DragAndDropContainer, public DragAndDropTarget {

    const char *const draggableTabBarButtonDragDescriptor = "__draggableTabBarButton__";

public:

    DraggableTabBarButton(String const &name, TabbedButtonBar &ownerBar) : TabBarButton(name, ownerBar) {
        TabBarButton::setExtraComponent(new CloseButton(*this), TabBarButton::afterText);
    }
    DraggableTabbedComponent *getTabbedComponent() { // update * to &
        return dynamic_cast <DraggableTabbedComponent *>(owner.getParentComponent());

    }


    bool isInterestedInDragSource(const SourceDetails &dragSourceDetails) {
        return dragSourceDetails.description == draggableTabBarButtonDragDescriptor;
    }

    void itemDropped(const SourceDetails &dragSourceDetails) {
        if (DraggableTabbedComponent::DraggableTabBarButton *const sourceButton = dynamic_cast <DraggableTabbedComponent::DraggableTabBarButton *> (dragSourceDetails.sourceComponent.get())) {
            if (getTabbedButtonBar().indexOfTabButton(sourceButton) > -1) {
                getTabbedButtonBar().moveTab(sourceButton->getIndex(), getIndex(), true);
            } else {
//TODO optimize this call to use real data, and prevent useless function calls
                getTabbedComponent()->addTab(
                        sourceButton->getName(),
                        sourceButton->getTabBackgroundColour(),
                        sourceButton->getTabbedComponent()->getTabContentComponent(sourceButton->getIndex()),
                        true);
                sourceButton->getTabbedButtonBar().removeTab(sourceButton->getIndex());
            }
        }
    }

    //TODO find solution to update tab position by draging it
    void itemDragEnter(const SourceDetails &dragSourceDetails) {

    }

    void mouseDrag(const MouseEvent &e) {
        if (!isDragging) {
            //TODO create image for dragging
            startDragging(draggableTabBarButtonDragDescriptor, this, Image::null, true);
            isDragging = true;
        }
    }

    void mouseUp(const MouseEvent &e) {
        if (isDragging) {
            isDragging = false;
        } else {
            TabBarButton::mouseUp(e);
        }
    }

//    bool shouldDropFilesWhenDraggedExternally(const DragAndDropTarget::SourceDetails &sourceDetails, StringArray &files, bool &canMoveFiles) {
//        DBG("shouldDropFilesWhenDraggedExternally");
//        return true;
//    }




private:
    bool isDragging = false;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DraggableTabBarButton);


    class CloseButton : public Component {
    public:
        CloseButton(DraggableTabBarButton &ownerButton_)
                : ownerButton(ownerButton_) {
            setSize(20, 20);
        }


        void paint(Graphics &g) override {
//            getLookAndFeel().drawDraggableTabCloseButton(*this, g, false, false);
            Path star = Drawable::parseSVGPath("M74.966,437.013c-99.97-99.97-99.97-262.065,0-362.037c100.002-99.97,262.066-99.97,362.067,0  c99.971,99.971,99.971,262.067,0,362.037C337.032,536.998,174.968,536.998,74.966,437.013z M391.782,120.227  c-75.001-74.985-196.564-74.985-271.534,0c-75.001,74.985-75.001,196.55,0,271.535c74.97,74.986,196.533,74.986,271.534,0  C466.754,316.775,466.754,195.212,391.782,120.227z M188.124,369.137l-45.251-45.266l67.876-67.877l-67.876-67.876l45.251-45.267  L256,210.743l67.877-67.892l45.25,45.267l-67.876,67.876l67.876,67.877l-45.25,45.266L256,301.245L188.124,369.137z");
            g.setColour(Colours::green);
            g.fillPath(star, star.getTransformToScaleToFit(getLocalBounds().reduced(2).toFloat(), true));
        }

//
        void mouseUp(const MouseEvent &) override {
            ownerButton.getTabbedButtonBar().removeTab(ownerButton.getIndex());
        }

    private:
        DraggableTabBarButton &ownerButton;
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CloseButton);
    };


};


TabBarButton *DraggableTabbedComponent::createTabButton(const String &tabName, int const tabIndex) {
    return new DraggableTabBarButton (tabName, *tabs);
}

//bool DraggableTabbedComponent::isInterestedInDragSource(DragAndDropTarget::SourceDetails const &dragSourceDetails) {
//    return true;
//}
//
//void DraggableTabbedComponent::itemDropped(DragAndDropTarget::SourceDetails const &dragSourceDetails) {
//           DBG("DROPPED ON COMPONENT!!!")
//}
