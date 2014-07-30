/*
  ==============================================================================

    DarkTheme.cpp
    Created: 22 Jul 2014 12:48:42am
    Author:  Roman Potashow

  ==============================================================================
*/

#include "DarkTheme.h"

DarkTheme::DarkTheme() {

//    https://raw.githubusercontent.com/audioplastic/Juce-look-and-feel-examples/master/Source/lookandfeel/LookAndFeelCustom.cpp

    setColour(ResizableWindow::ColourIds::backgroundColourId, Colour::fromRGB(32, 32, 32));

    //POPUP menu and main menu
    setColour(PopupMenu::backgroundColourId, Colour::fromRGB(10, 10, 10));      /**< The colour to fill the menu's background with. */
    setColour(PopupMenu::textColourId       , Colour::fromRGB(221, 221, 221)); /**< The colour for normal menu item text, (unless the colour is specified when the item is added). */
    setColour(PopupMenu::highlightedBackgroundColourId  , Colour::fromRGB(87, 87, 87));  /**< The colour to fill the background of the currently highlighted menu item. */
    setColour(PopupMenu::highlightedTextColourId  , Colour::fromRGB(204, 204, 204));     /**< The colour to use for the text of the currently highlighted item. */

}

DarkTheme::~DarkTheme() {

}



Button* DarkTheme::createTabBarExtrasButton()
{
    const float thickness = 7.0f;
    const float indent = 22.0f;

    Path p;
    p.addEllipse (-10.0f, -10.0f, 120.0f, 120.0f);

    DrawablePath ellipse;
    ellipse.setPath (p);
    ellipse.setFill (Colour (0xffff0000));

    p.clear();
    p.addEllipse (0.0f, 0.0f, 100.0f, 100.0f);
    p.addRectangle (indent, 50.0f - thickness, 100.0f - indent * 2.0f, thickness * 2.0f);
    p.addRectangle (50.0f - thickness, indent, thickness * 2.0f, 50.0f - indent - thickness);
    p.addRectangle (50.0f - thickness, 50.0f + thickness, thickness * 2.0f, 50.0f - indent - thickness);
    p.setUsingNonZeroWinding (false);

    DrawablePath dp;
    dp.setPath (p);
    dp.setFill (Colour (0x59000000));

    DrawableComposite normalImage;
    normalImage.addAndMakeVisible (ellipse.createCopy());
    normalImage.addAndMakeVisible (dp.createCopy());

    dp.setFill (Colour (0xcc000000));

    DrawableComposite overImage;
    overImage.addAndMakeVisible (ellipse.createCopy());
    overImage.addAndMakeVisible (dp.createCopy());

    DrawableButton* db = new DrawableButton ("tabs", DrawableButton::ImageFitted);
    db->setImages (&normalImage, &overImage, nullptr);
    return db;
}


void DarkTheme::drawDraggableTabCloseButton (TabBarButton&, Graphics&, bool isMouseOver, bool isMouseDown) {

}

