//
// Created by Roman Potashow on 17.07.2014.
//

#include "Application.h"

Application::Application() {

}


void Application::systemRequestedQuit() {
    // This is called when the app is being asked to quit: you can ignore this
    // request and let the app carry on running, or call quit() to allow the app to close.
    quit();
}

void Application::anotherInstanceStarted(const String &commandLine) {
    // When another instance of the app is launched while this one is running,
    // this method is invoked, and the commandLine parameter tells you what
    // the other instance's command-line arguments were.
    DBG("Crating new instance of Application with CLI args (" << commandLine <<")");
    //TODO change name based on some Build Settings
//    windowManager->createAppWindow(<#initializer#>, nullptr);
}

const String Application::getApplicationName() {
    return String();
}

const String Application::getApplicationVersion() {
    return String();
}

bool Application::moreThanOneInstanceAllowed() {
    return false;
}

//TODO update me to something nice width image / text and loading data
void Application::showSplash() {
// create a transparent 500x500 image..
    Image myImage (Image::RGB, 500, 500, true);
    Graphics g (myImage);
    g.setColour(Colours::red);
    g.fillEllipse(20, 20, 300, 200);
    splash = new SplashScreen ("Welcome to my app!",
            myImage,
//            ImageFileFormat::loadFrom (File ("/foobar/splash.jpg")),
            true);

    splash->deleteAfterDelay(RelativeTime::seconds(1), true);

}

void Application::initialise(const String &commandLine) {

    showSplash();


    commandManager = new CommandManager();

    LookAndFeel::setDefaultLookAndFeel(&darkTheme);


    commandManager->registerAllCommandsForTarget(this);
//    DBG(commandManager->getNumCommands());

    menuManager = new MenuManager(commandManager);

    windowManager = new WindowManager(commandManager, menuManager);

    panelManager = new SplitPanelManager(windowManager, commandManager, menuManager);


}

void Application::shutdown() {

    LookAndFeel::setDefaultLookAndFeel(nullptr);

}

void Application::unhandledException(const std::exception *e, const String &sourceFilename, int lineNumber) {
    //If any unhandled exceptions make it through to the message dispatch loop, this callback will be triggered, in case you want to log them or do some other type of error-handling.
    //If the type of exception is derived from the std::exception class, the pointer passed-in will be valid. If the exception is of unknown type, this pointer will be null.
}


START_JUCE_APPLICATION (Application)


