/*
  ==============================================================================

    DataSaver.cpp
    Created: 1 Sep 2014 12:57:08pm
    Author:  Roman Potashow

  ==============================================================================
*/

#include "DataSaver.h"

DataSaver::DataSaver() {

}

var DataSaver::readFile(String name) {
    DBG("DataSaver::readFile");
    return JSON::parse (File(name));
}

bool DataSaver::wrireFile(var data) {
    DBG("DataSaver::wrireFile");
    return false;
}
