#include "SettingsManager.h"


SettingsManager::SettingsManager(CommandManager *commandManager_, WindowManager *windowManager_)
        : commandManager(commandManager_), windowManager(windowManager_) {
    commandManager->registerManager(this);
    //TODO make it lazy loading
//    settingsPanel = new SettingsPanel();
}

SettingsManager::~SettingsManager() {
    delete settingsPanel;
}

ApplicationCommandTarget *SettingsManager::getNextCommandTarget() {
    DBG("SettingsManager::getNextCommandTarget");
    return commandManager->getNextRegisteredManager(this);
}

void SettingsManager::getAllCommands(Array<CommandID> &commands) {
    const CommandID ids[] = {commandManager->getCommandId("open settings")};
    commands.addArray(ids, numElementsInArray(ids));
}

void SettingsManager::getCommandInfo(CommandID commandID, ApplicationCommandInfo &result) {
    DBG("SettingsManager::getCommandInfo");
    if (commandID == commandManager->getCommandId("open settings")) {
        result.setInfo(TRANS ("Open Settings dialog"), TRANS ("Open Settings dialog"), "superPuper", 0);
        result.setActive(true);

#if !JUCE_MAC
    result.defaultKeypresses.add(KeyPress('s', ModifierKeys::ctrlModifier | ModifierKeys::altModifier , 0));
#endif
#if JUCE_MAC
        result.defaultKeypresses.add(KeyPress(',', ModifierKeys::commandModifier, 0));
#endif

    }
}

bool SettingsManager::perform(ApplicationCommandTarget::InvocationInfo const &info) {
    DBG("SettingsManager::perform");
    if (info.commandID == commandManager->getCommandId("open settings")) {
        windowManager->createDialogWindow(new SettingsPanel());
        DBG("info.commandID == commandManager->getCommandId(\"open settings\")");
        return true;
    } else {
        return false;
    }
}

