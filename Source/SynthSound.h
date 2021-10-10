/*
  ==============================================================================

    SynthSound.h
    Created: 10 Oct 2021 12:19:47pm
    Author:  Lukasz Tyl

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound
{
public:

    bool appliesToNote(int midiNoteNumber) override { return true; };
    bool appliesToChannel(int midiChannel) override { return true; };


};