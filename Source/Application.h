//
// Created by Roman Potashow on 17.07.2014.
//


#ifndef __Application_H_
#define __Application_H_

#include "../JuceLibraryCode/JuceHeader.h"
#include "WindowManager.h"
#include "DarkTheme.h"
#include "LayoutManager.h"


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
    ScopedPointer<ApplicationCommandManager> commandManager;
    ScopedPointer<MenuManager> menuManager;
    //object that hold all instances of Window attached to desktop, but have same other logic... (for not to duplicate instances of any useless listeners - command Manager, keys..)
    ScopedPointer<WindowManager> windowManager;
    ScopedPointer<LayoutManager> panelManager;
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Application);

    SplashScreen *splash;

    void showSplash();
};

#endif //__Application_H_
