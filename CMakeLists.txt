cmake_minimum_required(VERSION 3.21)

project(KY8 VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch JUCE automatically if it's not present locally
include(FetchContent)
FetchContent_Declare(
    juce
    GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
    GIT_TAG 8.0.2
)
FetchContent_MakeAvailable(juce)

# Define your plugin/application
juce_add_plugin(KY8
    PRODUCT_NAME "KY8"
    COMPANY_NAME "ky8"
    IS_SYNTH FALSE
    IS_MIDI_EFFECT FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT_SYNTH FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS FALSE
    COPY_PLUGIN_AFTER_BUILD TRUE
    PLUGIN_MANUFACTURER_CODE "KY8"
    PLUGIN_CODE "KY8!"
    FORMATS VST3 AU Standalone
    LV2_URI_EXTENSION ".KY8"
)

# Enforce C++17 on the target
target_compile_features(KY8 PRIVATE cxx_std_17)

# Add source files
target_sources(KY8 PRIVATE
    main.cpp
    # Add other source files here
)

# Link JUCE modules
target_link_libraries(KY8 PRIVATE
    juce::juce_audio_basics
    juce::juce_audio_devices
    juce::juce_audio_formats
    juce::juce_audio_processors
    juce::juce_audio_utils
    juce::juce_core
    juce::juce_data_structures
    juce::juce_dsp
    juce::juce_events
    juce::juce_graphics
    juce::juce_gui_basics
    juce::juce_gui_extra
)

# Compiler-specific settings
if(MSVC)
    target_compile_options(KY8 PRIVATE /W4)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(KY8 PRIVATE -Wall -Wextra -Wpedantic)
endif()