/*
  ==============================================================================

    PanelManer.cpp
    Created: 22 Jul 2014 6:13:15pm
    Author:  Roman Potashow

  ==============================================================================
*/

#include "SplitPanelManager.h"
#include "TabbedSplitPanel.h"
#include "CommandIDs.h"


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

    SplitPanel *layout = new TabbedSplitPanel(nullptr, false);
    commandManager->registerAllCommandsForTarget(this);

    topLevelPanels.add(layout); //holds top level panels, for each window
    wm->createAppWindow("From SplitPanelManager", layout);

//    Component::getCurrentlyFocusedComponent();
//    getParentComponent ()

}


void SplitPanelManager::childAdded(SplitPanel *panel) {

}

ApplicationCommandTarget *SplitPanelManager::getNextCommandTarget() {
    return nullptr;
}

void SplitPanelManager::getAllCommands(Array<CommandID> &commands) {
    const CommandID ids[] = {CommandIDs::addPanel};
    commands.addArray(ids, numElementsInArray(ids));
}

void SplitPanelManager::getCommandInfo(CommandID commandID, ApplicationCommandInfo &result) {
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

bool SplitPanelManager::perform(ApplicationCommandTarget::InvocationInfo const &info) {
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
