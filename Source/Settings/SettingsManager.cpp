#include "SettingsManager.h"


SettingsManager::SettingsManager(CommandManager *commandManager_, WindowManager *windowManager_)
        : commandManager(commandManager_), windowManager(windowManager_) {
    commandManager->registerManager(this);
//    settingsSet = new SettingsSet();
//    userSettings.set();
    //TODO make it lazy loading
//    settingsPanel = new SettingsPanel();
}

SettingsManager::~SettingsManager() {
    delete settingsPanel;
}

ApplicationCommandTarget *SettingsManager::getNextCommandTarget() {
//    DBG("SettingsManager::getNextCommandTarget");
    return commandManager->getNextRegisteredManager(this);
}

void SettingsManager::getAllCommands(Array<CommandID> &commands) {
    const CommandID ids[] = {commandManager->getCommandId("open settings")};
    commands.addArray(ids, numElementsInArray(ids));
}

void SettingsManager::getCommandInfo(CommandID commandID, ApplicationCommandInfo &result) {
//    DBG("SettingsManager::getCommandInfo");
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
//    DBG("SettingsManager::perform");
    if (info.commandID == commandManager->getCommandId("open settings")) {
        windowManager->createDialogWindow(new SettingsPanel(this));
        return true;
    } else {
        return false;
    }
}

KeyPressMappingSet *SettingsManager::getKeyMappings() {
    //TODO update to something real that will be parsed form configs
    return commandManager->getKeyMappings();
}

StringPairArray SettingsManager::getSettingsList() {
    StringPairArray a;
    a.set("keyMapEdtitor", "keyMapEdtitor");
    a.set("pluginName1", "pluginList");
    a.set("plugin1", "plugin1");
    a.set("plugin2", "plugin2");
    return a;
//    return settingsSet->getSettingsListOfPluginId();
}

PluginSettings SettingsManager::getSettingsFor(String name) {
    PluginSettings result;
    if (!defaultSettings.contains(name)) { // Settings is not loaded - so need to load
        result.addArray(loadPluginSettings(name));
    } else { // settings is loaded so push to result
        result.addArray(defaultSettings[name]);
    }
    if (userSettings.contains(name)) {
        result.addArray(userSettings[name]);// Update settings with User set
    }
    if (projectSettings.contains(name)) {
        result.addArray(projectSettings[name]);// Update settings with project set
    }
    return result;
}

void SettingsManager::setProjectSettingsFor(String name, PluginSettings settings) {
    projectSettings.set(name, settings);
}


PluginSettings SettingsManager::loadPluginSettings(String name) {
    PluginSettings result;
    //    TODO push to loaded hasMap
    defaultSettings.set(name, result);
    return result;
}
