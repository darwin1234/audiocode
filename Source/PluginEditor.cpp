/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SoundOfwarAudioProcessorEditor::SoundOfwarAudioProcessorEditor(SoundOfwarAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    keyboardComponent = new juce::MidiKeyboardComponent(keyboardState, juce::MidiKeyboardComponent::horizontalKeyboard);
    addAndMakeVisible(keyboardComponent);
    keyboardState.addListener(keyboardComponent);
    setSize(400, 300);
}

SoundOfwarAudioProcessorEditor::~SoundOfwarAudioProcessorEditor()
{
}

//==============================================================================
void SoundOfwarAudioProcessorEditor::paint(juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

    g.setColour(juce::Colours::white);
    g.setFont(15.0f);
    g.drawFittedText("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void SoundOfwarAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
