#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

#include "JuceHeader.h"
#include "CommandManager.h"
#include "WindowManager.h"
#include "SettingsPanel.h"

class SettingsManager : public ApplicationCommandTarget {
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
private:
    ScopedPointer<SettingsPanel> settingsPanel;
    // Pointer to applicationCommandManager that is created and deleted in main application - here it is to ba able to point to it.
    CommandManager *commandManager;
    WindowManager *windowManager;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SettingsManager)
};


#endif   // SETTINGS_H_INCLUDED
