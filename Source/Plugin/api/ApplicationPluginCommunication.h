/*
  ==============================================================================

    Callback.h
    Created: 28 Aug 2014 6:52:53pm
    Author:  Roman Potashow

  ==============================================================================
*/

#ifndef CALLBACK_H_INCLUDED
#define CALLBACK_H_INCLUDED

//TODO find better name
class ApplicationPluginCommunication {
    enum WindowTypes {
        Dialog,
        Alert
        //...
    };

    bool saveProjectData(/*Data data*/);

    bool saveProjectFile(/*String name, File data*/);

    bool saveApplicationData(/*Data data*/);

    void forceRestartApplication();

    int addProgressBar(); // returns id for update
    //progress is from 1-1000 that is 0.1 - 100%
    void updateProgressBar(int id, int progress /*String text To show*/);

    void createWindow(WindowTypes type);
};


#endif  // CALLBACK_H_INCLUDED
