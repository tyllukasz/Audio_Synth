/*
  ==============================================================================

    SynthVoice.h
    Created: 10 Oct 2021 12:19:34pm
    Author:  User

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "SynthSound.h"

class SynthVoice : public juce::SynthesiserVoice
{
public:
    bool canPlaySound(juce::SynthesiserSound* sound) override;
    void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition) override;
    void stopNote(float velocity, bool allowTailOff) override;
    void pitchWheelMoved(int newPitchWheelValue) override;
    void controllerMoved(int controllerNumber, int newControllerValue) override;
    void prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels);
    void renderNextBlock(juce::AudioBuffer< float >& outputBuffer, int startSample, int numSamples) override;

private:

    juce::ADSR adsr;
    juce::ADSR::Parameters adsrParams;

    //oscillator
    juce::dsp::Oscillator<float> osc{ [](float x) {return std::sin(x); } }; //oscillator definition + waveform (here with lambda expression)
    juce::dsp::Gain<float> gain;
    bool isPrepared{ false };


};