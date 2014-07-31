/*
  ==============================================================================

    WindowManager.cpp
    Created: 18 Jul 2014 4:39:38pm
    Author:  Roman Potashow

  ==============================================================================
*/

#include "WindowManager.h"

WindowManager::WindowManager(ApplicationCommandManager *cm, MenuManager *mm) {
    commandManager = cm;
    menuManager = mm;
}

WindowManager::~WindowManager() {
//#if !JUCE_MAC
//    setMenuBar (nullptr);
//#endif
//#if JUCE_MAC
//    MenuBarModel::setMacMainMenu(nullptr);
//#endif
}


ApplicationWindow *WindowManager::createAppWindow(const String &name, Component *content) {


    //TODO pair menu with application - to be able switch / update based on focused window!
    ApplicationWindow *newAppWindow = new ApplicationWindow(name, content);

    MainMenu *menu = menuManager->createApplicationMenu();

    newAppWindow->addKeyListener(commandManager->getKeyMappings());

//    #if !JUCE_MAC
    newAppWindow->setMenuBar(menu);
//    #endif
//    #if JUCE_MAC
//        MenuBarModel::setMacMainMenu(menu, &menu->extraAppleMenuItems, "Open Recent");
//    #endif

//    content
    appWindows.add(newAppWindow);

    return newAppWindow;
}


DialogWindow *WindowManager::createDialogWindow() {
    DialogWindow::LaunchOptions options;
//    options.content.setOwned (valueTreesDemo);
    options.dialogTitle = "Dialog Window";
//    options.dialogBackgroundColour        = Colour (0xff0e345a);
    options.escapeKeyTriggersCloseButton = false;
    options.useNativeTitleBar = true;
    options.resizable = true;

//    const RectanglePlacement placement (RectanglePlacement::xRight + RectanglePlacement::yBottom + RectanglePlacement::doNotResize);

    DialogWindow *dw = options.launchAsync();
    dw->centreWithSize(800, 600);
    return dw;
}

int WindowManager::getApplicationWindowCount() {
    return appWindows.size();
}
