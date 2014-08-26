/*
  ==============================================================================

    Plugin.h
    Created: 26 Aug 2014 2:06:21pm
    Author:  Roman Potashow

  ==============================================================================
*/

#ifndef PLUGIN_H_INCLUDED
#define PLUGIN_H_INCLUDED

class Plugin {
public:
    virtual ~Plugin() {}
    virtual void getPanel() = 0;
};



#endif  // PLUGIN_H_INCLUDED
