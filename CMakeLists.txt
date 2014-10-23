cmake_minimum_required(VERSION 2.8.4)
project(ideTemplate)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_definitions(-DDEBUG)



set(SOURCE_FILES
    Source/Base/Components/KeyMappingPanel.cpp
    Source/Base/Components/KeyMappingPanel.h
    Source/Base/Components/LayoutComponentContainer.cpp
    Source/Base/Components/LayoutComponentContainer.h
    Source/Base/CommandIDs.h
    Source/Base/CommandManager.cpp
    Source/Base/CommandManager.h
    Source/Base/DataSaver.cpp
    Source/Base/DataSaver.h
    Source/Base/FileSaver.cpp
    Source/Base/FileSaver.h
    Source/Base/FormBuilder.cpp
    Source/Base/FormBuilder.h
    Source/Base/JsonTreeItem.cpp
    Source/Base/JsonTreeItem.h
    Source/Layout/DraggableTabbedComponent.cpp
    Source/Layout/DraggableTabbedComponent.h
    Source/Layout/LayoutManager.cpp
    Source/Layout/LayoutManager.h
    Source/Layout/SplitPanel.cpp
    Source/Layout/SplitPanel.h
    Source/Layout/TabbedSplitPanel.cpp
    Source/Layout/TabbedSplitPanel.h
    Source/Menu/menus/ContextMenu.cpp
    Source/Menu/menus/ContextMenu.h
    Source/Menu/menus/MainMenu.cpp
    Source/Menu/menus/MainMenu.h
    Source/Menu/menus/ToolBarMenu.cpp
    Source/Menu/menus/ToolBarMenu.h
    Source/Menu/MenuManager.cpp
    Source/Menu/MenuManager.h
    Source/Plugin/api/ApplicationPluginCommunication.h
    Source/Plugin/api/Plugin.h
    Source/Plugin/components/NodeGraphEditor.cpp
    Source/Plugin/components/NodeGraphEditor.h
    Source/Plugin/testPlugin/firstPlugin.cpp
    Source/Plugin/testPlugin/firstPlugin.h
    Source/Plugin/ApplicationPluginCommunication.cpp
    Source/Plugin/PluginManager.cpp
    Source/Plugin/PluginManager.h
    Source/Plugin/PluginWrapper.cpp
    Source/Plugin/PluginWrapper.h
    Source/Project/ProjectManager.cpp
    Source/Project/ProjectManager.h
    Source/Settings/PluginSettings.cpp
    Source/Settings/PluginSettings.h
    Source/Settings/SettingsContentFactory.cpp
    Source/Settings/SettingsContentFactory.h
    Source/Settings/SettingsManager.cpp
    Source/Settings/SettingsManager.h
    Source/Settings/SettingsManagerInterface.h
    Source/Settings/SettingsPanel.cpp
    Source/Settings/SettingsPanel.h
    Source/Settings/SettingsSet.cpp
    Source/Settings/SettingsSet.h
    Source/Settings/SettingsTreeViewItem.cpp
    Source/Settings/SettingsTreeViewItem.h
    Source/Themes/DarkTheme.cpp
    Source/Themes/DarkTheme.h
    Source/Window/types/ApplicationWindow.cpp
    Source/Window/types/ApplicationWindow.h
    Source/Window/types/DialogWindow.cpp
    Source/Window/types/DialogWindow.h
    Source/Window/types/SettingsWindow.cpp
    Source/Window/types/SettingsWindow.h
    Source/Window/WindowManager.cpp
    Source/Window/WindowManager.h
    Source/Application.cpp
    Source/Application.h)


add_subdirectory(juce)
include_directories(${JUCE_INCLUDE_DIRS})

add_executable(ideTemplate ${SOURCE_FILES})
target_link_libraries(ideTemplate ${JUCE_LIBRARIES})