/*
  ==============================================================================

    SoundBank.h
    Created: 14 Aug 2020 5:09:55pm
    Author:  ll

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>


namespace SoundBank {


    class AudioSamples {

    public:

        std::unique_ptr<juce::AudioFormatReader>  play(int AudioRaw, int AudioSize) {


            std::unique_ptr<juce::AudioFormatReader> AudioFile(wavFormat.createReaderFor(new juce::MemoryInputStream(audioData[AudioRaw], audioSize[AudioSize], false),
                true));
            
            delete (audioData);
            delete (audioSize);
            return AudioFile;
        }



    private:
        //juce::WavAudioFormat wavFormat;
        juce::OggVorbisAudioFormat wavFormat;
        const char* audioData[5] = {
            BinaryData::file_ogg, BinaryData::file2_ogg, BinaryData::file3_ogg, BinaryData::file4_ogg, BinaryData::file5_ogg,
            /* BinaryData::file6_ogg,
             BinaryData::file7_ogg, BinaryData::file8_ogg, BinaryData::file9_ogg, BinaryData::file10_ogg,BinaryData::file11_ogg, BinaryData::file12_ogg,
            BinaryData::file13_ogg,BinaryData::file14_ogg,BinaryData::file15_ogg, BinaryData::file16_ogg, BinaryData::file17_ogg, BinaryData::file18_ogg,
            BinaryData::file19_ogg, BinaryData::file20_ogg, BinaryData::file21_ogg,BinaryData::file22_ogg, BinaryData::file23_ogg, BinaryData::file24_ogg,
            BinaryData::file25_ogg, BinaryData::file26_ogg, BinaryData::file27_ogg, BinaryData::file28_ogg, BinaryData::file29_ogg,BinaryData::file30_ogg,
            BinaryData::file31_ogg, BinaryData::file32_ogg, BinaryData::file33_ogg, BinaryData::file34_ogg,BinaryData::file35_ogg,BinaryData::file36_ogg,
            BinaryData::file37_ogg,BinaryData::file38_ogg,BinaryData::file39_ogg, BinaryData::file40_ogg, BinaryData::file41_ogg, BinaryData::file42_ogg,
            BinaryData::file43_ogg, BinaryData::file44_ogg, BinaryData::file45_ogg,BinaryData::file46_ogg, BinaryData::file47_ogg, BinaryData::file48_ogg,
            BinaryData::file49_ogg, BinaryData::file50_ogg, BinaryData::file51_ogg, BinaryData::file52_ogg, BinaryData::file53_ogg,BinaryData::file54_ogg,
            BinaryData::file55_ogg, BinaryData::file56_ogg, BinaryData::file57_ogg, BinaryData::file58_ogg, BinaryData::file59_ogg,BinaryData::file60_ogg*/

        };

        int audioSize[5] = {
            BinaryData::file_oggSize,  BinaryData::file2_oggSize,  BinaryData::file3_oggSize,  BinaryData::file4_oggSize, BinaryData::file5_oggSize,
            /* BinaryData::file6_oggSize,  BinaryData::file7_oggSize,  BinaryData::file8_oggSize,  BinaryData::file9_oggSize,BinaryData::file10_oggSize,
            BinaryData::file11_oggSize,  BinaryData::file12_oggSize, BinaryData::file13_oggSize,BinaryData::file14_oggSize , BinaryData::file15_oggSize,
            BinaryData::file16_oggSize,  BinaryData::file17_oggSize,  BinaryData::file18_oggSize, BinaryData::file19_oggSize,  BinaryData::file20_oggSize,
            BinaryData::file21_oggSize,  BinaryData::file22_oggSize,  BinaryData::file23_oggSize, BinaryData::file24_oggSize, BinaryData::file25_oggSize,
         
            BinaryData::file26_oggSize,  BinaryData::file27_oggSize,  BinaryData::file28_oggSize,BinaryData::file29_oggSize, BinaryData::file30_oggSize,
           BinaryData::file31_oggSize,  BinaryData::file32_oggSize,  BinaryData::file33_oggSize,BinaryData::file34_oggSize,  BinaryData::file35_oggSize,
            BinaryData::file36_oggSize, BinaryData::file37_oggSize,BinaryData::file38_oggSize , BinaryData::file39_oggSize,BinaryData::file40_oggSize,
            BinaryData::file41_oggSize,  BinaryData::file42_oggSize, BinaryData::file43_oggSize,  BinaryData::file44_oggSize,BinaryData::file45_oggSize,
            BinaryData::file46_oggSize,  BinaryData::file47_oggSize, BinaryData::file49_oggSize, BinaryData::file50_oggSize, BinaryData::file51_oggSize,
            BinaryData::file52_oggSize,  BinaryData::file53_oggSize,  BinaryData::file54_oggSize, BinaryData::file55_oggSize, BinaryData::file56_oggSize,
            BinaryData::file57_oggSize,  BinaryData::file58_oggSize,  BinaryData::file59_oggSize,  BinaryData::file60_oggSize*/
        };


    };

};










