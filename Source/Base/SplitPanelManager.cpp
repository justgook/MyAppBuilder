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

    topLevelPanels.add(layout); //holds top level panels, for each window
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
