/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "defines.h"
#include "DDRMInterface.h"
#include "TimbreSpaceEngine.h"


//==============================================================================
/**
*/
class DdrmtimbreSpaceAudioProcessor  : public AudioProcessor,
                                       private AudioProcessorValueTreeState::Listener,
                                       public ActionBroadcaster,
                                       public ActionListener,
                                       public MidiInputCallback
{
public:
    //==============================================================================
    DdrmtimbreSpaceAudioProcessor();
    ~DdrmtimbreSpaceAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void parameterChanged (const String& parameterID, float newValue) override;
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    void setDefaultState ();
    void setStateFromXml (XmlElement* xmlState);
    bool isLoadingFromState = false;
    bool needsToLoadDefaultState = true;
    
    // Parameters tree
    AudioProcessorValueTreeState parameters;
    
    // MIDI input/output
    std::unique_ptr<MidiOutput> midiOutput;
    std::unique_ptr<MidiInput> midiInput;
    int midiOutputChannel;  // Range 1-16
    int midiInputChannel;  // Range 1-16
    void handleIncomingMidiMessage(MidiInput* source,const MidiMessage& m) override;
    void setMidiInputDevice (int index);
    void setMidiInputDeviceByName (const String& deviceName);
    void setMidiOutputDevice (int index);
    void setMidiOutputDeviceByName (const String& deviceName);
    void setMidiInputChannel (int channel);
    void setMidiOutputChannel (int channel);
    bool isReceivingFromMidiInput = false;  // To distinguish when a parameter is changed from the onscren Slider or from MIDI input
    
    // Presetting
    void loadBankFile (File* bankFile);
    int currentPreset;
    bool currentPresetOutOfSyncWithSliders;
    void nextPreset();
    void previousPreset();
    void savePresetToBankLocation (int bankLocation);
    void saveBankFile ();
    void loadPresetAtIndex (int index);
    void loadToneSelectorPreset (const String& toneSelectorPresetName, int ddrmChannel);
    void setParametersFromSynthControlIdValuePairs (SynthControlIdValuePairs idValuePairs);
    bool isChangingFromPresetLoader = false;
    
    // DDRM Interface
    DDRMInterface* ddrmInterface;
    bool isChangingFromToneSelector = false;  // To distinguish when a parameter is changed because a button in tone selector has been pressed
    
    // Actions from DDRM control panel menu
    void copyDDRMChannel1ToChannel2 ();
    void copyDDRMChannel2ToChannel1 ();
    void swapDDRMChannels ();
    void sendControlsToSynth (int channelFilter);
    void randomizeControlValues (int channelFilter, float amount);
    void importFromPatchFile ();
    void importFromVoiceFile (int channelTo);
    void saveToPatchFile ();
    void saveToVoiceFile (int channelFrom);
    
    // Timbre Space Engine
    void computeTimbreSpace ();
    TimbreSpaceEngine* timbreSpaceEngine;
    void updateSpacePointAudioParametersFromMouseEvent(float x, float y);
    bool isChangingFromTimbreSpace = false;  // To distinguish when a parameter is changed from the onscren Slider or from MIDI input
    
    // Logging code
    void logMessage (const String& message);
    
    // Action listener
    void actionListenerCallback (const String &message) override;
    
    // Other
    File getDirectoryForFileSaveLoad ();
    void setLastUserDirectoryForFileSaveLoad (File file);
    File lastUsedDirectoryForFileIO;
    TimestampsLastCCSent timestampsLastCCSent;

private:    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DdrmtimbreSpaceAudioProcessor)
};