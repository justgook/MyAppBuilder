//
// Created by Roman Potashow on 17.07.2014.
//


#ifndef __Application_H_
#define __Application_H_

#include "../JuceLibraryCode/JuceHeader.h"

class Application  : public JUCEApplication {
public:
//    bool isRunningCommandLine;
//==============================================================================
    Application();
    const String getApplicationName();
    const String getApplicationVersion();
    bool moreThanOneInstanceAllowed();

    //==============================================================================
    void initialise (const String& commandLine);

    void shutdown();

    //==============================================================================
    void systemRequestedQuit();

    void anotherInstanceStarted (const String& commandLine);

    void unhandledException (const std::exception *e, const String &sourceFilename, int lineNumber);

};

#endif //__Application_H_
