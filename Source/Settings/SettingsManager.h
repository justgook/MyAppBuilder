#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

#include "../../juce/JuceLibraryCode/JuceHeader.h"
#include "../Base/CommandManager.h"
#include "../Window/WindowManager.h"
#include "SettingsManagerInterface.h"
#include "SettingsPanel.h"
#include "SettingsSet.h"

class SettingsManager : public ApplicationCommandTarget, public SettingsManagerInterface {
public:
    SettingsManager(CommandManager *commandManager, WindowManager *windowManager);

    ~SettingsManager();
    //==================================================================================================================
    //ApplicationCommandTarget

    //This must return the next target to try after this one.
    ApplicationCommandTarget *getNextCommandTarget();

    //This must return a complete list of commands that this target can handle.
    void getAllCommands(Array<CommandID> &commands);

    //This must provide details about one of the commands that this target can perform.
    void getCommandInfo(CommandID commandID, ApplicationCommandInfo &result);

    //This must actually perform the specified command.
    bool perform(const InvocationInfo &info);

    //==================================================================================================================
    KeyPressMappingSet *getKeyMappings();

    StringPairArray getSettingsList();
    PluginSettings getSettingsFor(String name);
    void setProjectSettingsFor(String name, PluginSettings settings);

//    bool setProjectSettingsFor();


private:
    PluginSettings loadPluginSettings(String name);
    ScopedPointer<SettingsPanel> settingsPanel;



    HashMap<String, PluginSettings> userSettings; // that is specific for current user (application instance)
    HashMap<String, PluginSettings> defaultSettings; // Settings that are loaded from plugins
    HashMap<String, PluginSettings> projectSettings;  // Settings set in project file
//    HashMap<String, PluginSettings> resultSettings;  // Settings that will be used in application (project) runtime


    // Pointer to applicationCommandManager that is created and deleted in main application - here it is to ba able to point to it.
    CommandManager *commandManager;
    WindowManager *windowManager;


    // holds current active settings for current project
    HashMap<String, String> resultKeyMapping;
    HashMap<String, String> userKeyMapping;
    HashMap<String, String> defaultKeyMapping;

//    HashMap <String, String> projcetSettings; // holds current active settings for current project - all manipulation is done based on that (to plugins..)
//    HashMap <String, String> applicationSettings; // User defined settings per Application that will be saved in application (IDE) folder
//    HashMap <String, String> defaultSetings; // all settings as they must look when they is loaded by default application / plugins

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SettingsManager)
};


#endif   // SETTINGS_H_INCLUDED
