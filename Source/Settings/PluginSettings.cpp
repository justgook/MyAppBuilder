/*
  ==============================================================================

    PluginSettings.cpp
    Created: 8 Sep 2014 5:46:52pm
    Author:  Roman Potashow

  ==============================================================================
*/

#include "PluginSettings.h"


PluginSettings &PluginSettings::operator=(PluginSettings const &param) {
    keys = param.keys;
    values = param.values;
    types = param.types;
    return *this;
}

PluginSettings::PluginSettings(PluginSettings const &other) : keys(other.keys),
                                                              values(other.values),
                                                              types(other.types) {

}

PluginSettings::PluginSettings() noexcept {

}


int PluginSettings::indexOf(StringRef stringToLookFor, const bool ignoreCase, int i) const {

    if (i < 0)
        i = 0;

    const int numElements = size();

    if (ignoreCase) {
        for (; i < numElements; ++i)
            if (keys.getReference(i).equalsIgnoreCase(stringToLookFor))
                return i;
    }
    else {
        for (; i < numElements; ++i)
            if (stringToLookFor == keys.getReference(i))
                return i;
    }

    return -1;

}


PluginSettings::Type PluginSettings::getType(int index) const {
    return types[index];
}

PluginSettings::Type PluginSettings::getType(StringRef key) const {
    return getType(indexOf(key));
}

int PluginSettings::getIntValue(StringRef keyName) const {
    return 0;
}

double PluginSettings::getDoubleValue(StringRef keyName) const {

    return 0;
}

bool PluginSettings::getBoolValue(StringRef keyName) const {
    return false;
}


String PluginSettings::getStringValue(StringRef keyName) const {
    return "Ffasdfasfasfasfasfa dsa dasd ";
}

const Value &PluginSettings::operator[](const int index) const {
    return values.getReference(index);
}

const Value &PluginSettings::operator[](const String key) const {
    return values.getReference(indexOf(key));
}

void PluginSettings::set(const String &key, const Value &value, PluginSettings::Type type) {
    if (int i = indexOf(key) < 0){
        keys.add(key);
        values.add(value);
        types.add(type);
    } else {
        values.insert(i, value);
        types.insert(i, type);
    }

}

void PluginSettings::clear() {
    keys.clear();
    values.clear();
    types.clear();
}

void PluginSettings::remove(int index) {
    keys.remove(index);
    values.remove(index);
    types.remove(index);
}

void PluginSettings::remove(StringRef key) {
    remove(indexOf(key));
}

PluginSettings::Type PluginSettings::getTypeFromVar(var item) {
    if (item.isBool()) {
        return BOOL;
    } else if (item.isDouble()) {
        return DOUBLE;
    } else if (item.isInt()) {
        return INT;
    }
    return STRING;
}



void PluginSettings::addArray(PluginSettings const &other) {
    for (int i = 0; i < other.size(); ++i)
        set (other.keys[i], other.values[i], other.types[i]);
}
