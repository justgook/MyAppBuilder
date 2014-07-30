/*
  ==============================================================================

    PanelManer.cpp
    Created: 22 Jul 2014 6:13:15pm
    Author:  Roman Potashow

  ==============================================================================
*/

//#import <WebKit/WebKit.h>
#include "LayoutManager.h"
#include "SplitPanel.h"

LayoutComponentContainer *LayoutManager::addTestPanel(const String &name) {
    LayoutComponentContainer *holder = new LayoutComponentContainer();

    return holder;
}


LayoutManager::~LayoutManager() {

}

//bool LayoutManager::tryToCloseDocument(Component *component) {
//    return false;
//}

LayoutManager::LayoutManager(WindowManager *wm, ApplicationCommandManager *cm, MenuManager *manager) {

    if (wm->getApplicationWindowCount()) {
        //Try initalize layout manger when program already running or trere already is some window created
        DBG("SOMETHIG GOES REALLY WROMG (TODO ADD SOME KIND OF ERROR DISPLAY / REPPORT)");
    }

    SplitPanel *layout = new SplitPanel();

    layouts.add(layout); //TODO check do i need it at all!
    layout->setSize(1400, 700);

    //TODO replace it with some custom class that will hold all that staff and create custom menu at the end of tabBar
    TabbedComponent *tabsHolder = new DraggableTabbedComponent(TabbedButtonBar::Orientation::TabsAtTop);
//    layoutTabPanelHolder.add(tabsHolder); // TODO check do i need it at all or move it just to commandManager level




    layout->addAndMakeVisible(tabsHolder);

    tabsHolder->addTab("1", Colours::red, new Label("a1","vsdv"), true, -1);
    tabsHolder->addTab("2dasdas2dasdas2dasdas2dasdas2dasdas2dasdas2dasdas", Colours::beige, new Label("a1","dcaxsvv"), true, -1);
    tabsHolder->addTab("3dasdas", Colours::bisque, new Label("a1","vcv cx "), true, -1);
    tabsHolder->addTab("4dasdas", Colours::rosybrown, new Label("a1","vxcvcx xxc "), true, -1);
    tabsHolder->addTab("5dasdas", Colours::black, new Label("a1","zvzx sc edsf2ewdv"), true, -1);
    tabsHolder->addTab("6dasdas", Colours::blue, new Label("a1","dsvx dczv eds "), true, -1);
    tabsHolder->addTab("7dasdas", Colours::firebrick, new Label("a1","sfxdsxvcds dv esv edfc efd"), true, -1);


    TabbedComponent *tabsHolder2 = new DraggableTabbedComponent(TabbedButtonBar::Orientation::TabsAtTop);
    tabsHolder2->addTab("1", Colours::red, new Label("a1","vsdv"), true, -1);
    tabsHolder2->setBounds(700, 0, 500, 500);
    layout->addAndMakeVisible(tabsHolder2);

    wm->createAppWindow("From LayoutManager", layout);

}
