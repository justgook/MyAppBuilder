/*
  ==============================================================================

    Panel.cpp
    Created: 22 Jul 2014 6:17:08pm
    Author:  Roman Potashow

  ==============================================================================
*/

#include "LayoutComponentContainer.h"

LayoutComponentContainer::LayoutComponentContainer() {}

LayoutComponentContainer::~LayoutComponentContainer() {}

String LayoutComponentContainer::getName() {
    return String();
}

Image *LayoutComponentContainer::getIcon() {
    return nullptr;
}

MenuBarModel *LayoutComponentContainer::getSettingsMenu() {
    return nullptr;
}
