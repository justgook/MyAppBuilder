/*
  ==============================================================================

    PanelManer.cpp
    Created: 22 Jul 2014 6:13:15pm
    Author:  Roman Potashow

  ==============================================================================
*/

#include "SplitPanelManager.h"
#include "SplitPanel.h"


SplitPanelManager::~SplitPanelManager() {

}

//bool SplitPanelManager::tryToCloseDocument(Component *component) {
//    return false;
//}

SplitPanelManager::SplitPanelManager(WindowManager *wm, CommandManager *commandManager, MenuManager *manager) {

    if (wm->getApplicationWindowCount()) {
        //Try initalize layout manger when program already running or trere already is some window created
        DBG("SOMETHIG GOES REALLY WROMG (TODO ADD SOME KIND OF ERROR DISPLAY / REPPORT)");
    }

    SplitPanel *layout = new SplitPanel(nullptr, false);
    commandManager->registerAllCommandsForTarget(layout);
//    layoutManagers.add(new StretchableLayoutManager());

    topLevelPanels.add(layout); //holds top level panels, for each window

    //TODO replace it with some custom class that will hold all that staff and create custom menu at the end of tabBar
//    TabbedComponent *tabsHolder = new DraggableTabbedComponent(TabbedButtonBar::Orientation::TabsAtTop);
//    tabsHolder->addTab("1", Colours::red, new Label("a1","vsdv"), true, -1);
//    tabsHolder->addTab("2dasdas2dasdas2dasdas2dasdas2dasdas2dasdas2dasdas", Colours::beige, new Label("a1","dcaxsvv"), true, -1);
//    tabsHolder->addTab("3dasdas", Colours::bisque, new Label("a1","vcv cx "), true, -1);
//    tabsHolder->addTab("4dasdas", Colours::rosybrown, new Label("a1","vxcvcx xxc "), true, -1);
//    tabsHolder->addTab("5dasdas", Colours::black, new Label("a1","zvzx sc edsf2ewdv"), true, -1);
//    tabsHolder->addTab("6dasdas", Colours::blue, new Label("a1","dsvx dczv eds "), true, -1);
//    tabsHolder->addTab("7dasdas", Colours::firebrick, new Label("a1","sfxdsxvcds dv esv edfc efd"), true, -1);
//
//
//    TabbedComponent *tabsHolder2 = new DraggableTabbedComponent(TabbedButtonBar::Orientation::TabsAtTop);
//    tabsHolder2->addTab("1", Colours::red, new Label("a1","vsdv"), true, -1);
//    tabsHolder2->setBounds(700, 0, 500, 500);
////    layout->addAndMakeVisible(tabsHolder2);

    wm->createAppWindow("From SplitPanelManager", layout);

}

StretchableLayoutManager *SplitPanelManager::getLayoutManagers(SplitPanel &panel) {
    return nullptr;
}

void SplitPanelManager::childAdded(SplitPanel *panel) {
    SplitPanel *parent = panel;
    while(parent != nullptr && parent->getIsVertical() != panel->getIsVertical()) {
        parent = panel->getParent();
    }
//    topLevelPanels.add(panel);
}
