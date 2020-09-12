/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class SoundOfwarAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SoundOfwarAudioProcessorEditor (SoundOfwarAudioProcessor&);
    ~SoundOfwarAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::MidiKeyboardComponent* keyboardComponent;
    juce::MidiKeyboardState keyboardState;
    juce::MidiMessageCollector midiCollector;
    SoundOfwarAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SoundOfwarAudioProcessorEditor)
};
