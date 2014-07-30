//
// Created by Roman Potashow on 17.07.2014.
//

#include "Application.h"

Application::Application()  {}


void Application::systemRequestedQuit()
{
    // This is called when the app is being asked to quit: you can ignore this
    // request and let the app carry on running, or call quit() to allow the app to close.
    quit();
}

void Application::anotherInstanceStarted (const String& commandLine)
{
    // When another instance of the app is launched while this one is running,
    // this method is invoked, and the commandLine parameter tells you what
    // the other instance's command-line arguments were.
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

void Application::initialise(const String &commandLine) {

}

void Application::shutdown() {

}

void Application::unhandledException(const std::exception *e, const String &sourceFilename, int lineNumber) {
    //If any unhandled exceptions make it through to the message dispatch loop, this callback will be triggered, in case you want to log them or do some other type of error-handling.
    //If the type of exception is derived from the std::exception class, the pointer passed-in will be valid. If the exception is of unknown type, this pointer will be null.
}


START_JUCE_APPLICATION (Application)

