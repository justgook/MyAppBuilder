/*
  ==============================================================================

    SplitPanel.cpp
    Created: 30 Jul 2014 11:24:25am
    Author:  Roman Potashow

  ==============================================================================
*/

#include "SplitPanel.h"
#include "CommandIDs.h"

class SplitPanel::OverlayComponent : public Component {
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
            switch (_position) {
                case Left:
//                    Desktop::getInstance().getAnimator().animateComponent(this, Rectangle<int> (0, 0, getParentWidth() / 2, getParentHeight()), 1, 200, false, 100, 1000);
                    setBounds("0, 0, parent.width / 2, parent.height");
                    break;
                case Right:
//                    Desktop::getInstance().getAnimator().animateComponent(this, Rectangle<int> (getParentWidth() / 2, 0, getParentWidth(), getParentHeight()), 1, 200, false, 100, 1000);
                    setBounds("parent.width / 2, 0, parent.width, parent.height");
                    break;
                case Bottom:
//                    Desktop::getInstance().getAnimator().animateComponent(this, Rectangle<int> (0, getParentHeight() / 2, getParentWidth(), getParentHeight()), 1, 200, false, 100, 1000);
                    setBounds("0, parent.height / 2, parent.width, parent.height");
                    break;
            }

//            getAnimator();
//            Desktop.getAnimator().animateComponent();
            position = _position;
        }
    }
};

SplitPanel::SplitPanel(SplitPanel *parent_, bool isVertical_)
        : isVertical(isVertical_), parent(parent_) {
    setSize(100, 100);



    //TODO REMOVE TEST DATA

    TabbedComponent *tabsHolder = new DraggableTabbedComponent(TabbedButtonBar::Orientation::TabsAtTop);
//    tabsHolder->addTab("1", Colours::red, new Label("a1", "vsdv"), true, -1);
    tabsHolder->addTab("4567899", Colours::beige, new Label("a1", "dcaxsvv"), true, -1);
    tabsHolder->addTab("3dasdas", Colours::bisque, new Label("a1", "vcv cx "), true, -1);
    tabsHolder->addTab("4dasdas", Colours::rosybrown, new Label("a1", "vxcvcx xxc "), true, -1);
    tabsHolder->addTab("5dasdas", Colours::black, new Label("a1", "zvzx sc edsf2ewdv"), true, -1);
    tabsHolder->addTab("6dasdas", Colours::blue, new Label("a1", "dsvx dczv eds "), true, -1);
    tabsHolder->addTab("7dasdas", Colours::firebrick, new Label("a1", "sfxdsxvcds dv esv edfc efd"), true, -1);
    content = tabsHolder;
    content->setWantsKeyboardFocus(true);
    addAndMakeVisible(content);
    content->setBounds("0, 0, parent.width, parent.height");

    overlay = new OverlayComponent();
    content->addChildComponent(overlay);
//    content->addAndMakeVisible(overlay);
//
}

SplitPanel::~SplitPanel() {
}

bool SplitPanel::getIsVertical() {
    return isVertical;
}


//This must return the next target to try after this one.
ApplicationCommandTarget *SplitPanel::getNextCommandTarget() {
    return nullptr;
}


//This must return a complete list of commands that this target can handle.
void SplitPanel::getAllCommands(Array<CommandID> &commands) {
    const CommandID ids[] = {CommandIDs::splitBottom, CommandIDs::splitLeft, CommandIDs::splitRight};
    commands.addArray(ids, numElementsInArray(ids));
}

//This must provide details about one of the commands that this target can perform.
void SplitPanel::getCommandInfo(CommandID commandID, ApplicationCommandInfo &result) {
    switch (commandID) {
        case CommandIDs::splitBottom:
            result.setInfo(TRANS ("Split horizontally"), TRANS ("Splits current panel in two parts horizontally"), CommandCategories::edit, 0);
            result.setActive(true);
            result.defaultKeypresses.add(KeyPress('h', ModifierKeys::noModifiers, 0));
            break;
        case CommandIDs::splitLeft:
            result.setInfo(TRANS ("Split vertically (left)"), TRANS ("Splits current panel in two parts vertically (new to left)"), CommandCategories::edit, 0);
            result.setActive(true);
            result.defaultKeypresses.add(KeyPress('l', ModifierKeys::noModifiers, 0));
            break;
        case CommandIDs::splitRight:
            result.setInfo(TRANS ("Split vertically (right)"), TRANS ("Splits current panel in two parts vertically (new to right)"), CommandCategories::edit, 0);
            result.setActive(true);
            result.defaultKeypresses.add(KeyPress('r', ModifierKeys::noModifiers, 0));
            break;
        default:
            break;
    }

}

//This must actually perform the specified command.
bool SplitPanel::perform(ApplicationCommandTarget::InvocationInfo const &info) {
    switch (info.commandID) {
        case CommandIDs::splitBottom:
            addChild(SplitPanel::AddTo::Bottom);
            break;
        case CommandIDs::splitRight:
            addChild(SplitPanel::AddTo::Right);
            break;
        case CommandIDs::splitLeft:
            addChild(SplitPanel::AddTo::Left);
            break;
        default:
            return false;
    }
    return true;
}


SplitPanel *SplitPanel::getParent() {
    return parent;
}


Component *SplitPanel::getContent() {
    return content;
}

void SplitPanel::addChild(SplitPanel::AddTo position, Component *content) {
    SplitPanel *master = findParentToAdd(position);
    master->appendChild(position);
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

void SplitPanel::appendChild(SplitPanel::AddTo position) {
    if (childs.size() == 0) {
        isVertical = SplitPanel::AddTo::Bottom == position;
        removeChildComponent(content);
        content = nullptr;
        layoutManager = new StretchableLayoutManager();

        //TODO find better solution or move it to function (next few lines, because it repeats twice)
        layoutManager->setItemLayout(childs.size(), minimumSize, maximumSize, preferredSize);
        SplitPanel *child = new SplitPanel(this, isVertical);
        childs.add(child);
        addAndMakeVisible(child);
    }

    StretchableLayoutResizerBar *resizeBar = new StretchableLayoutResizerBar(layoutManager, childs.size(), SplitPanel::AddTo::Bottom != position);
    layoutManager->setItemLayout(childs.size(), resizeBarSize, resizeBarSize, resizeBarSize);
    addAndMakeVisible(resizeBar);
    childs.add(resizeBar);

    layoutManager->setItemLayout(childs.size(), minimumSize, maximumSize, preferredSize);
    SplitPanel *child = new SplitPanel(this, isVertical);
    childs.add(child);
    addAndMakeVisible(child);
    resized();
}

void SplitPanel::resized() {
    if (childs.size() > 0) {
        layoutManager->layOutComponents(childs.getRawDataPointer(), childs.size(), 0, 0, getWidth(), getHeight(), isVertical, true);
    }
}

StretchableLayoutManager *SplitPanel::getLayoutManager() {
    return layoutManager;
}

bool SplitPanel::isInterestedInDragSource(DragAndDropTarget::SourceDetails const &dragSourceDetails) {
    return true;
}

void SplitPanel::itemDragMove(DragAndDropTarget::SourceDetails const &dragSourceDetails) {
    DragAndDropTarget::itemDragMove(dragSourceDetails);
    overlay->setPointPosition(dragSourceDetails.localPosition);
}

void SplitPanel::itemDropped(DragAndDropTarget::SourceDetails const &dragSourceDetails) {
    overlay->setVisible(false);
    addChild(overlay->position);
    DBG("Item droped to SplitPanel");
}

void SplitPanel::itemDragEnter(DragAndDropTarget::SourceDetails const &dragSourceDetails) {
    DragAndDropTarget::itemDragEnter(dragSourceDetails);
    overlay->setVisible(true);
}

void SplitPanel::itemDragExit(DragAndDropTarget::SourceDetails const &dragSourceDetails) {
    DragAndDropTarget::itemDragExit(dragSourceDetails);
    overlay->setVisible(false);
}


