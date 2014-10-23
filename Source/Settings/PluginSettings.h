/*
  ==============================================================================

    PluginSettings.h
    Created: 8 Sep 2014 5:46:52pm
    Author:  Roman Potashow

  ==============================================================================
*/

#ifndef PLUGINSETTINGS_H_INCLUDED
#define PLUGINSETTINGS_H_INCLUDED

#include "../../juce/JuceLibraryCode/JuceHeader.h"

class PluginSettings {
public:
    enum Type {
        BOOL,
        INT,
        DOUBLE,
        STRING
    };

    static Type getTypeFromVar(var item);
    //==============================================================================
    /** Creates an empty string array */
    PluginSettings() noexcept;

    PluginSettings(const PluginSettings &);

    PluginSettings &operator=(PluginSettings const &param);


    const Value &operator[](int index) const;

    const Value &operator[](String key) const;

    int indexOf(StringRef stringToLookFor, const bool ignoreCase = false, int i = -1) const;

    void set(const String &key, const Value &value, Type type = Type::STRING);

    void addArray(const PluginSettings &other);

    const Array<String> &getAllKeys() const noexcept {
        return keys;
    }


    Type getType(int index) const;

    Type getType(StringRef key) const;

    int getIntValue(StringRef keyName) const;

    double getDoubleValue(StringRef keyName) const;

    bool getBoolValue(StringRef keyName) const;

    String getStringValue(StringRef keyName) const;


    void clear();

    void remove(int index);

    void remove(StringRef key);

    inline int size() const noexcept {
        return keys.size();
    };
private:
    Array<String> keys;
    Array<Value> values;
    Array<PluginSettings::Type> types;

    JUCE_LEAK_DETECTOR(PluginSettings);


};


#endif  // PLUGINSETTINGS_H_INCLUDED
