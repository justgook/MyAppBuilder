/*
  ==============================================================================

    Callback.cpp
    Created: 28 Aug 2014 6:54:57pm
    Author:  Roman Potashow

  ==============================================================================
*/

#include "api/ApplicationPluginCommunication.h"

bool ApplicationPluginCommunication::saveProjectData() {
    return true;
}

bool ApplicationPluginCommunication::saveApplicationData() {
    return true;
}

void ApplicationPluginCommunication::forceRestartApplication() {

}

bool ApplicationPluginCommunication::saveProjectFile() {
    return true;
}

int ApplicationPluginCommunication::addProgressBar() {
    return 0;
}

void ApplicationPluginCommunication::updateProgressBar(int id, int progress) {

}

void ApplicationPluginCommunication::createWindow(ApplicationPluginCommunication::WindowTypes types) {

}
