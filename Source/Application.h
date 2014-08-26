//
// Created by Roman Potashow on 17.07.2014.
//


#ifndef __Application_H_
#define __Application_H_

#include "../JuceLibraryCode/JuceHeader.h"
#include "DarkTheme.h"

#include "CommandManager.h"
#include "MenuManager.h"
#include "WindowManager.h"
#include "LayoutManager.h"
#include "SettingsManager.h"
#include "PluginManager.h"

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
    ScopedPointer<SettingsManager> settingsManager;

    ScopedPointer<PluginManager> pluginManager;
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Application);

    SplashScreen *splash;

    void showSplash();
};

#endif //__Application_H_
