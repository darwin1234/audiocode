/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SoundOfwarAudioProcessor::SoundOfwarAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
   
    synth.clearVoices();
    synth.clearSounds();
    for (int i = 0; i < 5; i++) {
        synth.addVoice(new juce::SamplerVoice());
    }
   
    for (int i = 0; i < 5;  i++) {
       note[i].setBit(i);
       synth.addSound(new juce::SamplerSound("Track" + std::to_string(i), *AudioSamples.play(i,i), note[i], 10, 0, 0.1, 10.0));
   }
    

}

SoundOfwarAudioProcessor::~SoundOfwarAudioProcessor()
{
     delete note;
    //delete AudioSamples;
}

//==============================================================================
const juce::String SoundOfwarAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SoundOfwarAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SoundOfwarAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SoundOfwarAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SoundOfwarAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SoundOfwarAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SoundOfwarAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SoundOfwarAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String SoundOfwarAudioProcessor::getProgramName (int index)
{
    return {};
}

void SoundOfwarAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void SoundOfwarAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    juce::ignoreUnused(samplesPerBlock);
    synth.setCurrentPlaybackSampleRate(sampleRate);

  
}

void SoundOfwarAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SoundOfwarAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void SoundOfwarAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    buffer.clear();

    //midiCollector.removeNextBlockOfMessages(midiMessages, buffer.getNumSamples());
    //keyboardState.processNextMidiBuffer(midiMessages, 0, buffer.getNumSamples(), true);
    synth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());

}

//==============================================================================
bool SoundOfwarAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* SoundOfwarAudioProcessor::createEditor()
{
    return new SoundOfwarAudioProcessorEditor (*this);
}

//==============================================================================
void SoundOfwarAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void SoundOfwarAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SoundOfwarAudioProcessor();
}
