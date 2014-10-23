/*
  ==============================================================================

    PanelManer.cpp
    Created: 22 Jul 2014 6:13:15pm
    Author:  Roman Potashow

  ==============================================================================
*/

#include "LayoutManager.h"
#include "TabbedSplitPanel.h"
#include "../Base/CommandIDs.h"


LayoutManager::~LayoutManager() {

}

//bool LayoutManager::tryToCloseDocument(Component *component) {
//    return false;
//}

LayoutManager::LayoutManager(WindowManager *wm, CommandManager *commandManager_, MenuManager *manager): commandManager(commandManager_) {

    if (wm->getApplicationWindowCount()) {
        //Try initalize layout manger when program already running or trere already is some window created
        DBG("SOMETHIG GOES REALLY WROMG (TODO ADD SOME KIND OF ERROR DISPLAY / REPPORT)");
    }

    SplitPanel *layout = new TabbedSplitPanel(nullptr, false);
    commandManager->registerManager(this);

    topLevelPanels.add(layout); //holds top level panels, for each window
    wm->createAppWindow("From LayoutManager", layout);

//    Component::getCurrentlyFocusedComponent();
//    getParentComponent ()

}


void LayoutManager::childAdded(SplitPanel *panel) {

}

ApplicationCommandTarget *LayoutManager::getNextCommandTarget() {
//    DBG("LayoutManager::getNextCommandTarget");
    return commandManager->getNextRegisteredManager(this);
}

void LayoutManager::getAllCommands(Array<CommandID> &commands) {
    const CommandID ids[] = {CommandIDs::addPanel};
    commands.addArray(ids, numElementsInArray(ids));
}

void LayoutManager::getCommandInfo(CommandID commandID, ApplicationCommandInfo &result) {
//    DBG("LayoutManager::getCommandInfo");
    switch (commandID) {
        case CommandIDs::addPanel:
            result.setInfo(TRANS ("Split horizontally"), TRANS ("Splits current panel in two parts horizontally"), CommandCategories::edit, 0);
            result.setActive(true);
            result.defaultKeypresses.add(KeyPress('h', ModifierKeys::noModifiers, 0));
        default:
            break;
    }
//        case CommandIDs::splitBottom:
//            result.setInfo(TRANS ("Split horizontally"), TRANS ("Splits current panel in two parts horizontally"), CommandCategories::edit, 0);
//            result.setActive(true);
//            result.defaultKeypresses.add(KeyPress('h', ModifierKeys::noModifiers, 0));
//            break;
//        case CommandIDs::splitLeft:
//            result.setInfo(TRANS ("Split vertically (left)"), TRANS ("Splits current panel in two parts vertically (new to left)"), CommandCategories::edit, 0);
//            result.setActive(true);
//            result.defaultKeypresses.add(KeyPress('l', ModifierKeys::noModifiers, 0));
//            break;
//        case CommandIDs::splitRight:
//            result.setInfo(TRANS ("Split vertically (right)"), TRANS ("Splits current panel in two parts vertically (new to right)"), CommandCategories::edit, 0);
//            result.setActive(true);
//            result.defaultKeypresses.add(KeyPress('r', ModifierKeys::noModifiers, 0));
//            break;
//        default:
//            break;
//    }
}

bool LayoutManager::perform(ApplicationCommandTarget::InvocationInfo const &info) {
    DBG("LayoutManager::perform");
    switch (info.commandID) {
        case CommandIDs::addPanel:
            DBG("URAAA");
//            addChild(SplitPanel::AddTo::Bottom);
            break;
//        case CommandIDs::splitRight:
//            addChild(SplitPanel::AddTo::Right);
//            break;
//        case CommandIDs::splitLeft:
//            addChild(SplitPanel::AddTo::Left);
//            break;
        default:
            return false;
    }
    return true;
}
