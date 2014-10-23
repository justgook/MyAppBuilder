//
// Created by Roman Potashow on 17.07.2014.
//

#include "ApplicationWindow.h"
//#include "LayoutComponentContainer.h"

ApplicationWindow::ApplicationWindow(String const &name, Component *content)
        : DocumentWindow(name, Colours::lightgrey,  DocumentWindow::allButtons, true) {


    //delete set background color to be able set it as fallback to default one (defined in FeelAndLook)
    removeColour(ResizableWindow::ColourIds::backgroundColourId);

    setContentOwned(content, true);

    setUsingNativeTitleBar(true);
    centreWithSize(getWidth(), getHeight());
    setVisible(true);
    setResizable(true, true);

}

ApplicationWindow::~ApplicationWindow() {

}

void ApplicationWindow::closeButtonPressed() {
    // This is called when the user tries to close this window. Here, we'll just
    // ask the app to quit when this happens, but you can change this to do
    // whatever you need.
    //TODO find how to close only this window not all
    //wm.removeObject(this)
    JUCEApplication::getInstance()->systemRequestedQuit();
}
