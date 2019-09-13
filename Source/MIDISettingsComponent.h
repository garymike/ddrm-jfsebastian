/*
  ==============================================================================

    MIDISettingsComponent.h
    Created: 13 Jun 2019 8:36:00am
    Author:  Frederic Font Corbera

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "defines.h"

class MIDISettingsComponent: public Component,
                             public ActionListener,
                             public Timer
{
public:
    
    MIDISettingsComponent ()
    {
        addAndMakeVisible (midiInputList);
        addAndMakeVisible (midiOutputList);
        addAndMakeVisible (midiInputChannelList);
        addAndMakeVisible (midiOutputChannelList);
    }
    
    ~MIDISettingsComponent ()
    {
        processor->removeActionListener(this);  // Stop receivng messages from processor
        if (isTimerRunning()){
            stopTimer();
        }
    }
    
    void initialize (DdrmtimbreSpaceAudioProcessor* p)
    {
        // Set processor object
        processor = p;
        
        // Set up listeners
        processor->addActionListener(this);  // Receive messages from processor
        
        // Build UI objects
        currentMidiInDevices = StringArray("-");
        currentMidiOutDevices = StringArray("-");
        buildMidiChannelLists();
        refreshMidiInputOutputLists();
        if (REFRESH_MIDI_DEVICES_TIMER_INTERVAL_MS > 0){
            startTimer(REFRESH_MIDI_DEVICES_TIMER_INTERVAL_MS); // Start timer to check for new MIDI devices
        }
    }
    
    void resized () override
    {
        float deviceSelectorWidth = 150;
        float channelSelectorWidth = 60;
        float unitMargin = 10;
        float inOutSeparator = 30;
        midiInputList.setBounds (0, 0, deviceSelectorWidth, getHeight());
        midiInputChannelList.setBounds (deviceSelectorWidth + unitMargin, 0, channelSelectorWidth, getHeight());
        midiOutputList.setBounds (deviceSelectorWidth + channelSelectorWidth + 2 * unitMargin + inOutSeparator, 0, deviceSelectorWidth, getHeight());
        midiOutputChannelList.setBounds (2 * deviceSelectorWidth + channelSelectorWidth + 3 * unitMargin + inOutSeparator, 0, channelSelectorWidth, getHeight());
    }
    
    void actionListenerCallback (const String &message) override
    {
        if (message.startsWith(String(ACTION_UPDATED_MIDI_DEVICE_SETTINGS)))
        {
            updateSelectedMidiDevices();
        }
        else if (message.startsWith(String(ACTION_REFRESH_MIDI_DEVICE_LISTS)))
        {
            refreshMidiInputOutputLists();
        }
    }
    
    void buildMidiChannelLists ()
    {
        midiInputChannelList.clear(dontSendNotification);
        midiOutputChannelList.clear(dontSendNotification);
        for (int i=1; i<=16; i++){
            midiInputChannelList.addItem((String)i, i);
            midiOutputChannelList.addItem((String)i, i);
        }
        midiInputChannelList.onChange = [this] {  processor->setMidiInputChannel(midiInputChannelList.getSelectedItemIndex() + 1); };
        midiOutputChannelList.onChange = [this] {  processor->setMidiOutputChannel(midiOutputChannelList.getSelectedItemIndex() + 1); };
    }
    
    void refreshMidiInputOutputLists ()
    {
        // Update MIDI in list (if devices changed)
        StringArray midiInDevices = MidiInput::getDevices();
        bool midiInHasChanged = midiInDevices != currentMidiInDevices;
        if (midiInHasChanged){
            currentMidiInDevices = midiInDevices;
            midiInputList.clear(dontSendNotification);
            midiInputList.addItem ("No MIDI input", 1);
            midiInputList.addSeparator();
            
            if (midiInDevices.size() > 0) {
                midiInputList.addItemList (midiInDevices, 2);
                midiInputList.onChange = [this] {  processor->setMidiInputDeviceByName (midiInputList.getItemText(midiInputList.getSelectedItemIndex())); };
            }
        }
        
        // Update MIDI output list (if devices changed)
        StringArray midiOutDevices = MidiOutput::getDevices();
        bool midiOutHasChanged = midiOutDevices != currentMidiOutDevices;
        if (midiOutHasChanged){
            currentMidiOutDevices = midiOutDevices;
            midiOutputList.clear(dontSendNotification);
            midiOutputList.addItem ("No MIDI output", 1);
            midiOutputList.addSeparator();
            
            if (midiOutDevices.size() > 0){
                midiOutputList.addItemList (midiOutDevices, 2);
                midiOutputList.onChange = [this] { processor->setMidiOutputDeviceByName (midiOutputList.getItemText(midiOutputList.getSelectedItemIndex())); };
            }
        }
        
        if (midiInHasChanged || midiOutHasChanged){
            // Update the selected items in the lists (in case the list has changed and devics idxs do not match
            updateSelectedMidiDevices();
        }
    }
    
    void updateSelectedMidiDevices ()
    {
        if (processor->midiInput != nullptr){
            // Find and select the item in the combo box corresponding to the selected device (by name)
            int itemIdx = 0;
            for (int i=0; i<midiInputList.getNumItems(); i++){
                if (processor->midiInput->getName() == midiInputList.getItemText(i)){
                    itemIdx = i;
                }
            }
            if (midiInputList.getSelectedItemIndex() != itemIdx){
                midiInputList.setSelectedItemIndex(itemIdx, dontSendNotification);
            }
        } else {
            if (midiInputList.getSelectedItemIndex() != 0){
                midiInputList.setSelectedItemIndex(0, dontSendNotification); // Update to no device selected
            }
        }
        
        if (processor->midiOutput != nullptr){
            // Find and select the item in the combo box corresponding to the selected device (by name)
            int itemIdx = 0;
            for (int i=0; i<midiOutputList.getNumItems(); i++){
                if (processor->midiOutput->getName() == midiOutputList.getItemText(i)){
                    itemIdx = i;
                }
            }
            if (midiOutputList.getSelectedItemIndex() != itemIdx){
                midiOutputList.setSelectedItemIndex(itemIdx, dontSendNotification);
            }
        } else {
            if (midiOutputList.getSelectedItemIndex() != 0){
                midiOutputList.setSelectedItemIndex(0, dontSendNotification); // Update to no device selected
            }
        }
        
        if (processor->midiInputChannel > -1){
            if (midiInputChannelList.getSelectedId() != processor->midiInputChannel){
                midiInputChannelList.setSelectedId(processor->midiInputChannel, dontSendNotification);
            }
        }
        
        if (processor->midiOutputChannel > -1){
            if (midiOutputChannelList.getSelectedId() != processor->midiOutputChannel){
                midiOutputChannelList.setSelectedId(processor->midiOutputChannel, dontSendNotification);
            }
        }
    }
    
    void timerCallback() override
    {
        refreshMidiInputOutputLists();
    }
    
private:
    DdrmtimbreSpaceAudioProcessor* processor;
    ComboBox midiInputList;
    ComboBox midiOutputList;
    ComboBox midiInputChannelList;
    ComboBox midiOutputChannelList;
    StringArray currentMidiInDevices;
    StringArray currentMidiOutDevices;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MIDISettingsComponent);
};