//
// Created by Roman Potashow on 17.07.2014.
//


#ifndef __Application_H_
#define __Application_H_

#include "../juce/JuceLibraryCode/JuceHeader.h"
#include "Themes/DarkTheme.h"

#include "Base/CommandManager.h"
#include "Menu/MenuManager.h"
#include "Window/WindowManager.h"
#include "Layout/LayoutManager.h"
#include "Settings/SettingsManager.h"
#include "Plugin/PluginManager.h"
#include "Project/ProjectManager.h"

class Application : public JUCEApplication {

public:

//==============================================================================
    Application();
//    ~Application();

    const String getApplicationName();

    const String getApplicationVersion();

    bool moreThanOneInstanceAllowed();

    //==============================================================================
    void initialise(const String &commandLine);

    void shutdown();

    //==============================================================================
    void systemRequestedQuit();

    void anotherInstanceStarted(const String &commandLine);

    void unhandledException(const std::exception *e, const String &sourceFilename, int lineNumber);

private:
    //DarkTheme
    DarkTheme darkTheme;

    // those pointers and objects will be cleared automatically
    ScopedPointer<CommandManager> commandManager;
    ScopedPointer<MenuManager> menuManager;
    ScopedPointer<WindowManager> windowManager;
    ScopedPointer<LayoutManager> layoutManager;
    ScopedPointer<PluginManager> pluginManager;
    ScopedPointer<SettingsManager> settingsManager;

    ScopedPointer<ProjectManager> projectManager;


private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Application);

    SplashScreen *splash;

    void showSplash();
};

#endif //__Application_H_
