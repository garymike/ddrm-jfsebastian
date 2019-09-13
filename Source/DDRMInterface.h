//
//  DDRMInterface.h
//  DDRMTimbreSpace
//
//  Created by Frederic Font Corbera on 22/02/2019.
//  Copyright © 2019 Rita&AuroraAudio. All rights reserved.
//


#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "DDRMSynthControl.h"
#include "DDRMPresetBank.h"
#include "DDRMToneSelectorPresets.h"
#include "defines.h"

class DDRMInterface: public ActionBroadcaster

{
public:
    DDRMInterface ()
    {
        selectedToneSelectorRow1 = String(EMPTY_TONE_SELECTOR_NAME);
        selectedToneSelectorRow2 = String(EMPTY_TONE_SELECTOR_NAME);
    }
    
    ~DDRMInterface ()
    {
        // De-register action listeners
        removeAllActionListeners();
    }
    
    void loadSynthControlObjects() {
        // Add DDRMSynthControl objects to the synthControls vector
        // --> Start auto-generated code A
        synthControls.push_back(DDRMSynthControl("DDRM_SPEED_VCO_1", "Ch I: PWM Speed", 40, 0, 0, 1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_PWM_VCO_1", "Ch I: PWM Amount", 41, 1, 1, 1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_PW_VCO_1", "Ch I: PW", 42, 2, 2, 1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_SQR_VCO_1", "Ch I: Square", 43, 73, 24, 1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_SAW_VCO_1", "Ch I: Sawtooth", 44, 74, 25, 1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_NOISE_VCO_1", "Ch I: Noise", 45, 3, 3, 1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_HPF_VCF_1", "Ch I: HPF", 46, 4, 4, 1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_RESh_VCF_1", "Ch I: RESh", 47, 5, 5, 1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_LPF_VCF_1", "Ch I: LPF", 48, 6, 6, 1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_RESl_VCF_1", "Ch I: RESl", 49, 7, 7, 1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_IL_VCF_1", "Ch I: IL", 50, 8, 8, 1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_AL_VCF_1", "Ch I: AL", 51, 9, 9, 1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_A_VCF_1", "Ch I: A", 52, 10, 10, 1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_D_VCF_1", "Ch I: D", 53, 11, 11, 1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_R_VCF_1", "Ch I: R", 54, 12, 12, 1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_VCF_VCA_1", "Ch I: VCF Level", 55, 13, 13, 1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_SINE__VCA_1", "Ch I: Sine Level", 56, 14, 14, 1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_A_VCA_1", "Ch I: A", 57, 15, 15, 1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_D_VCA_1", "Ch I: D", 58, 16, 16, 1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_S_VCA_1", "Ch I: S", 59, 17, 17, 1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_R_VCA_1", "Ch I: R", 60, 18, 18, 1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_LEVEL_VCA_1", "Ch I: Channel Level", 61, 19, 19, 1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_INIT_BR_TOUCH_1", "Ch I: Initial Brilliance", 62, 20, 20, 1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_INIT_LEV_TOUCH_1", "Ch I: Initial Level", 63, 21, 21, 1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_AT_BR_TOUCH_1", "Ch I: After Brilliance", 65, 22, 22, 1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_AT_LEV_TOUCH_1", "Ch I: After Level", 66, 23, 23, 1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_SPEED_VCO_2", "Ch II: PWM Speed", 67, 30, 0, 2, true));
        synthControls.push_back(DDRMSynthControl("DDRM_PWM_VCO_2", "Ch II: PWM Amount", 68, 31, 1, 2, true));
        synthControls.push_back(DDRMSynthControl("DDRM_PW_VCO_2", "Ch II: PW", 69, 32, 2, 2, true));
        synthControls.push_back(DDRMSynthControl("DDRM_SQR_VCO_2", "Ch II: Square", 70, 76, 24, 2, true));
        synthControls.push_back(DDRMSynthControl("DDRM_SAW_VCO_2", "Ch II: Sawtooth", 71, 75, 25, 2, true));
        synthControls.push_back(DDRMSynthControl("DDRM_NOISE_VCO_2", "Ch II: Noise", 72, 33, 3, 2, true));
        synthControls.push_back(DDRMSynthControl("DDRM_HPF_VCF_2", "Ch II: HPF", 73, 34, 4, 2, true));
        synthControls.push_back(DDRMSynthControl("DDRM_RESh_VCF_2", "Ch II: RESh", 119, 35, 5, 2, true));
        synthControls.push_back(DDRMSynthControl("DDRM_LPF_VCF_2", "Ch II: LPF", 75, 36, 6, 2, true));
        synthControls.push_back(DDRMSynthControl("DDRM_RESl_VCF_2", "Ch II: RESl", 76, 37, 7, 2, true));
        synthControls.push_back(DDRMSynthControl("DDRM_IL_VCF_2", "Ch II: IL", 77, 38, 8, 2, true));
        synthControls.push_back(DDRMSynthControl("DDRM_AL_VCF_2", "Ch II: AL", 78, 39, 9, 2, true));
        synthControls.push_back(DDRMSynthControl("DDRM_A_VCF_2", "Ch II: A", 79, 24, 10, 2, true));
        synthControls.push_back(DDRMSynthControl("DDRM_D_VCF_2", "Ch II: D", 80, 25, 11, 2, true));
        synthControls.push_back(DDRMSynthControl("DDRM_R_VCF_2", "Ch II: R", 81, 26, 12, 2, true));
        synthControls.push_back(DDRMSynthControl("DDRM_VCF_VCA_2", "Ch II: VCF Level", 82, 27, 13, 2, true));
        synthControls.push_back(DDRMSynthControl("DDRM_SINE__VCA_2", "Ch II: Sine Level", 83, 28, 14, 2, true));
        synthControls.push_back(DDRMSynthControl("DDRM_A_VCA_2", "Ch II: A", 84, 29, 15, 2, true));
        synthControls.push_back(DDRMSynthControl("DDRM_D_VCA_2", "Ch II: D", 85, 40, 16, 2, true));
        synthControls.push_back(DDRMSynthControl("DDRM_S_VCA_2", "Ch II: S", 86, 41, 17, 2, true));
        synthControls.push_back(DDRMSynthControl("DDRM_R_VCA_2", "Ch II: R", 87, 42, 18, 2, true));
        synthControls.push_back(DDRMSynthControl("DDRM_LEVEL_VCA_2", "Ch II: Channel Level", 88, 43, 19, 2, true));
        synthControls.push_back(DDRMSynthControl("DDRM_INIT_BR_TOUCH_2", "Ch II: Initial Brilliance", 89, 44, 20, 2, true));
        synthControls.push_back(DDRMSynthControl("DDRM_INIT_LEV_TOUCH_2", "Ch II: Initial Level", 90, 45, 21, 2, true));
        synthControls.push_back(DDRMSynthControl("DDRM_AT_BR_TOUCH_2", "Ch II: After Brilliance", 91, 46, 22, 2, true));
        synthControls.push_back(DDRMSynthControl("DDRM_AT_LEV_TOUCH_2", "Ch II: After Level", 92, 47, 23, 2, true));
        synthControls.push_back(DDRMSynthControl("DDRM_COARSE_PITCH", "Pitch Coarse", 93, 77, -1, -1, false));
        synthControls.push_back(DDRMSynthControl("DDRM_FINE_PITCH", "Pitch Fine", 94, 78, -1, -1, false));
        synthControls.push_back(DDRMSynthControl("DDRM_DETUNE_CH2_PITCH", "Detune Ch II", 95, 79, -1, -1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_FEET_1_FEET", "Feet I", 102, 48, -1, -1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_FEET_2_FEET", "Feet II", 103, 49, -1, -1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_FUNCTION_SUB_OSC", "Sub Osc Function", 104, 50, -1, -1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_SPEED_SUB_OSC", "Sub Osc Speed", 105, 51, -1, -1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_VCO_SUB_OSC", "Sub Osc VCO Amount", 106, 52, -1, -1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_VCF_SUB_OSC", "Sub Osc VCF Amount", 107, 53, -1, -1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_VCA_SUB_OSC", "Sub Osc VCA Amount", 108, 54, -1, -1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_MIX", "Mix", 8, 55, -1, -1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_BRILL", "Brilliance", 109, 56, -1, -1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_RESSO", "Ressonance", 110, 57, -1, -1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_INITIAL_TOUCH", "Initial Pitch Bend", 111, 58, -1, -1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_SPEED_TOUCH", "Touch Response Sub Osc Speed", 112, 59, -1, -1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_VCO_TOUCH", "Touch Response Sub Osc VCO Amount", 113, 60, -1, -1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_VCF_TOUCH", "Touch Response Sub Osc VCF Amount", 114, 61, -1, -1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_BR_LOW_KBRD", "Brilliance Low", 115, 62, -1, -1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_BR_HIGH_KBRD", "Brilliance High", 116, 63, -1, -1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_LEV_LOW_KBRD", "Level Low", 117, 64, -1, -1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_LEV_HIGH_KBRD", "Level High", 118, 65, -1, -1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_GLIDE_MODE_GLIDE", "Glide Mode", 39, -1, -1, -1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_GLIDE_TIME_GLIDE", "Glide Time", 5, 66, -1, -1, true));
        synthControls.push_back(DDRMSynthControl("DDRM_SUSTAIN_MODE", "Sustain Mode", 9, -1, -1, -1, false));
        synthControls.push_back(DDRMSynthControl("DDRM_SUSTAIN_TIME", "Sustain Time", 11, -1, -1, -1, false));
        // --> End auto-generated code A
        
        #if JUCE_DEBUG
            logMessage(String::formatted("Loaded %i DDRM controls", synthControls.size()));
        #endif
    }
    
    std::vector<String> getDDRMSynthControlIDs (){
        // Returns a vector with all synth control IDs
        std::vector<String> synthControlIDS;
        for (int i=0; i < synthControls.size(); i++){
            synthControlIDS.push_back(synthControls[i].getID());
        }
        return synthControlIDS;
    }
    
    std::vector<String> getDDRMSynthControlIDsForChannel (int channel){
        // Returns a vector with all synth control IDs for a specific channel
        std::vector<String> synthControlIDS;
        for (int i=0; i < synthControls.size(); i++){
            if (synthControls[i].getChannelNumber() == channel){
                synthControlIDS.push_back(synthControls[i].getID());
            }
        }
        return synthControlIDS;
    }
    
    std::vector<String> getDDRMSynthControlIDsForTimbreSpace (){
        // Returns a vector with all synth control IDs to be included in the timbre space
        std::vector<String> synthControlIDS;
        for (int i=0; i < synthControls.size(); i++){
            if (synthControls[i].shouldBeIncludedInTimbreSpace()){
                synthControlIDS.push_back(synthControls[i].getID());
            }
        }
        return synthControlIDS;
    }
    
    DDRMSynthControl* getDDRMSynthControlWithID(const String& synthControlID)
    {
        // Returns a reference to a DDRMSynthControl with the requested ID
        // Throws an exception if no DDRMSynthControl exists with such ID
        for (int i=0; i < synthControls.size(); i++){
            if (synthControls[i].getID() == synthControlID){
                return &synthControls[i];
            }
        }
        throw std::invalid_argument("No DDRMSynthConrol with ID \"" + synthControlID.toStdString() + "\"");
    }
    
    DDRMSynthControl* getDDRMSynthControlWithCCNumber(int ccNumber)
    {
        // Returns a reference to a DDRMSynthControl with the requested Control Change number
        // Throws an exception if no DDRMSynthControl exists with such Control Change number
        for (int i=0; i < synthControls.size(); i++){
            if (synthControls[i].getCCNumber() == ccNumber){
                return &synthControls[i];
            }
        }
        throw std::invalid_argument("No DDRMSynthConrol with CC number \"" + std::to_string(ccNumber) + "\"");
    }
    
    int getCCNumberForParameterID (const String &parameterID)
    {
        // Gets the correspoding MIDI Control Change number for a given parameterID
        // Parameter IDs should have a 1-1 relationship with DDRMSynthControl IDs
        // Throws an exception if no DDRMSynthControl exists with parameterID
        return getDDRMSynthControlWithID(parameterID)->getCCNumber();
    }
    
    int getChannelNumberForParameterID (const String &parameterID)
    {
        // Gets the correspoding DDRM channel number (1 or 2) for a given parameterID
        // Parameter IDs should have a 1-1 relationship with DDRMSynthControl IDs
        // Throws an exception if no DDRMSynthControl exists with parameterID
        return getDDRMSynthControlWithID(parameterID)->getChannelNumber();
    }
    
    const String getParameterIDFromCCNumber (int ccNumber)
    {
        // Gets the Parameter ID that corresponds to a synth control assigned to the given control change number
        // If more than one DDRMSynthControl objects exist with the same CC number, only the first one in the vector will be returned
        // Parameter IDs should have a 1-1 relationship with DDRMSynthControl IDs
        // Throws an exception if no DDRMSynthControl exists with assigned ccNumber
        return getDDRMSynthControlWithCCNumber(ccNumber)->getID();
    }
    
    const String getSynthControlDisaplayNameFromParameterID (const String& parameterID)
    {
        // Gets the synth control name that corresponds to a synth control assigned to the given parameterID
        // Parameter IDs should have a 1-1 relationship with DDRMSynthControl IDs
        // Throws an exception if no DDRMSynthControl exists with assigned parameterID
        return getDDRMSynthControlWithID(parameterID)->getDisplayName();
    }
    
    SynthControlIdValuePairs getSynthControlIdValuePairsForPresetBytesArray(DDRMPresetBytes& presetBytes)
    {
        // Returns a list of pairs of DDRMSynthControl and the value they should take to load a specific presetBytes
        SynthControlIdValuePairs idValuePairs;
        for (int i=0; i < synthControls.size(); i++){
            DDRMSynthControl synthControl = synthControls[i];
            idValuePairs.emplace_back(synthControl.getID(), synthControl.getNormValueFromPresetByteArray(presetBytes));
        }
        return idValuePairs;
    }
    
    SynthControlIdValuePairs getSynthControlIdValuePairsForVoiceBytesArray(DDRMVoiceBytes& voiceBytes, int channelTo)
    {
        // Returns a list of pairs of DDRMSynthControl and the value they should take to load a specific voiceBytes
        std::vector<String> channelControlIDs = getDDRMSynthControlIDsForChannel(channelTo);
        SynthControlIdValuePairs idValuePairs;
        for (int i=0; i<channelControlIDs.size(); i++){
            String controlID = channelControlIDs[i];
            DDRMSynthControl* synthControl =  getDDRMSynthControlWithID(controlID);
            double value = synthControl->getNormValueFromVoiceByteArray(voiceBytes);
            idValuePairs.emplace_back(controlID, value);
        }
        return idValuePairs;
    }
    
    SynthControlIdValuePairs getSynthControlIdValuePairsForPresetAtIndex(int index)
    {
        // Returns a list of pairs of DDRMSynthControl and the value they should take to load a specific preset
        DDRMPresetBytes& presetBytes = presetBank.getPresetBytesAtIndex(index);
        return getSynthControlIdValuePairsForPresetBytesArray(presetBytes);
    }
    
    SynthControlIdValuePairs getSynthControlIdValuePairsForInterpolatedPresets(PresetDistancePairsToInterpolate interpolationData)
    {
        // Returns a list of pairs of DDRMSynthControl and the value they should take to load a new preset which is
        // created after the interpolation of N presets and distances.
        // Interpolation is done by computing a weight for each preset (based on distance) and linearly summing the
        // each synth control vlaue of the preset multiplied by the weight.
        
        // Calculate total distance and pre-fetch preset bytes
        float totalDistance = 0.0;
        std::vector<DDRMPresetBytes> presetsBytes;
        for (int i=0;i<interpolationData.size(); i++){
            totalDistance += interpolationData[i].presetDist;
            presetsBytes.push_back(presetBank.getPresetBytesAtIndex(interpolationData[i].presetIdx));
        }
        
        // Interpolate synth control values
        SynthControlIdValuePairs idValuePairs;
        std::vector<String> controlIDs = getDDRMSynthControlIDsForTimbreSpace();
        for (int i=0; i < controlIDs.size(); i++){
            DDRMSynthControl* synthControl = getDDRMSynthControlWithID(controlIDs[i]);
            double newValue = 0.0;
            for (int j=0;j<interpolationData.size(); j++){
                double normValuePreset = (double)synthControl->getNormValueFromPresetByteArray(presetsBytes[j]);
                newValue += normValuePreset * (double)(interpolationData[j].presetDist/totalDistance);
            }
            idValuePairs.emplace_back(synthControl->getID(), newValue);
        }
        return idValuePairs;
    }
    
    // Function to return SynthControlIdValuePairs for tone selector presets
    // --> Start auto-generated code B
    SynthControlIdValuePairs getSynthControlIdValuePairsForToneSelectorPreset(const String& toneSelectorPresetName, int ddrmChannel)
    {
        // Returns a list of pairs of DDRMSynthControl and the value they should take to load a specific tone selector preset in one DDRM channel
        SynthControlIdValuePairs auxValuePairs;
        if (toneSelectorPresetName == "bass"){
                auxValuePairs = ddrmToneSelectorPresets.bassIdValuePairs;
            }
            else if (toneSelectorPresetName == "brass1"){
                auxValuePairs = ddrmToneSelectorPresets.brass1IdValuePairs;
            }
            else if (toneSelectorPresetName == "brass2"){
                auxValuePairs = ddrmToneSelectorPresets.brass2IdValuePairs;
            }
            else if (toneSelectorPresetName == "brass3"){
                auxValuePairs = ddrmToneSelectorPresets.brass3IdValuePairs;
            }
            else if (toneSelectorPresetName == "clav1"){
                auxValuePairs = ddrmToneSelectorPresets.clav1IdValuePairs;
            }
            else if (toneSelectorPresetName == "clav2"){
                auxValuePairs = ddrmToneSelectorPresets.clav2IdValuePairs;
            }
            else if (toneSelectorPresetName == "epiano"){
                auxValuePairs = ddrmToneSelectorPresets.epianoIdValuePairs;
            }
            else if (toneSelectorPresetName == "flute"){
                auxValuePairs = ddrmToneSelectorPresets.fluteIdValuePairs;
            }
            else if (toneSelectorPresetName == "funky1"){
                auxValuePairs = ddrmToneSelectorPresets.funky1IdValuePairs;
            }
            else if (toneSelectorPresetName == "funky2"){
                auxValuePairs = ddrmToneSelectorPresets.funky2IdValuePairs;
            }
            else if (toneSelectorPresetName == "funky3"){
                auxValuePairs = ddrmToneSelectorPresets.funky3IdValuePairs;
            }
            else if (toneSelectorPresetName == "guitar1"){
                auxValuePairs = ddrmToneSelectorPresets.guitar1IdValuePairs;
            }
            else if (toneSelectorPresetName == "guitar2"){
                auxValuePairs = ddrmToneSelectorPresets.guitar2IdValuePairs;
            }
            else if (toneSelectorPresetName == "harpsi1"){
                auxValuePairs = ddrmToneSelectorPresets.harpsi1IdValuePairs;
            }
            else if (toneSelectorPresetName == "harpsi2"){
                auxValuePairs = ddrmToneSelectorPresets.harpsi2IdValuePairs;
            }
            else if (toneSelectorPresetName == "organ1"){
                auxValuePairs = ddrmToneSelectorPresets.organ1IdValuePairs;
            }
            else if (toneSelectorPresetName == "organ2"){
                auxValuePairs = ddrmToneSelectorPresets.organ2IdValuePairs;
            }
            else if (toneSelectorPresetName == "string1"){
                auxValuePairs = ddrmToneSelectorPresets.string1IdValuePairs;
            }
            else if (toneSelectorPresetName == "string2"){
                auxValuePairs = ddrmToneSelectorPresets.string2IdValuePairs;
            }
            else if (toneSelectorPresetName == "string3"){
                auxValuePairs = ddrmToneSelectorPresets.string3IdValuePairs;
            }
            else if (toneSelectorPresetName == "string4"){
                auxValuePairs = ddrmToneSelectorPresets.string4IdValuePairs;
            }
            
        // Add channel id to control IDs and return updated SynthControlIdValuePairs ready for loading to DDRM
        SynthControlIdValuePairs idValuePairs;
        for (int i=0; i < auxValuePairs.size(); i++){
            idValuePairs.emplace_back(auxValuePairs[i].first + String(ddrmChannel), auxValuePairs[i].second);
        }
        return idValuePairs;
    }
    // --> End auto-generated code B
    
    timbreSpaceInputDataMatrix generateBankDataForTimbreSpaceEngine()
    {
        // Generates a matrix of floats with normalized values of the relevant parameters to include
        // as input data for the timbre space. Each row in the matrix corresponds to one preset, each
        // column to the normalized value of one parameter.
        timbreSpaceInputDataMatrix data;
        std::vector<String> controlIDs = getDDRMSynthControlIDsForTimbreSpace();
        for (int i=0; i < presetBank.getNumPresetsInBank(); i++){
            std::vector<float> presetValues;
            DDRMPresetBytes& presetBytes = presetBank.getPresetBytesAtIndex(i);
            for (int j=0; j < controlIDs.size(); j++){
                DDRMSynthControl* synthControl = getDDRMSynthControlWithID(controlIDs[j]);
                float value = (float)synthControl->getNormValueFromPresetByteArray(presetBytes);
                presetValues.push_back(value);
            }
            data.push_back(presetValues);
        }
        return data;
    }
    
    void setSelectedToneSelector(const String& toneName, int row)
    {
        if (row == 1){
            selectedToneSelectorRow1 = toneName;
        } else if (row == 2) {
            selectedToneSelectorRow2 = toneName;
        }
    }
    
    void setSelectedToneSelectorToNone(int row)
    {
        if (row == 1){
            selectedToneSelectorRow1 = String(EMPTY_TONE_SELECTOR_NAME);
        } else if (row == 2) {
            selectedToneSelectorRow2 = String(EMPTY_TONE_SELECTOR_NAME);
        }
    }
    
    String getSelectedToneSelector(int row){
        if (row == 1){
            return selectedToneSelectorRow1;
        } else if (row == 2) {
            return selectedToneSelectorRow2;
        }
        return "";
    }
    
    void setToneSelectorComponentRow1ButtonsToNone()
    {
        sendActionMessage(ACTION_SET_TONE_SELECTOR_BUTTONS_ROW1_OFF);
    }
    
    void setToneSelectorComponentRow2ButtonsToNone()
    {
        sendActionMessage(ACTION_SET_TONE_SELECTOR_BUTTONS_ROW2_OFF);
    }
    
    void setToneSelectorComponentRow1()
    {
        sendActionMessage(ACTION_SET_TONE_SELECTOR_BUTTONS_ROW1);
    }
    
    void setToneSelectorComponentRow2()
    {
        sendActionMessage(ACTION_SET_TONE_SELECTOR_BUTTONS_ROW2);
    }
    
    bool hasPresetsDataLoaded()
    {
        return presetBank.hasDataLoaded();
    }
    
    int getNumLoadedPresets ()
    {
        if (!hasPresetsDataLoaded()){
            return 0;
        } else {
            return presetBank.getNumPresetsInBank();
        }
    }
    
    ValueTree getPresetBankState()
    {
        return presetBank.getState();
    }
    
    void loadPresetBankState(ValueTree state)
    {
        presetBank.loadState(state);
        #if JUCE_DEBUG
            logMessage(String::formatted("Loaded %i presets from ", presetBank.getNumPresetsInBank()) + presetBank.getLoadedFilename());
        #endif
    }
    
    void saveCurrentPresetAtBankIndex(int index, DDRMPresetBytes bytes)
    {
        presetBank.setPresetBytesAtIndex(index, bytes);
    }
    
    String getPresetBankLoadedFilename()
    {
        return presetBank.getLoadedFilename();
    }
    
    void loadPresetBankFromFile(const String& filepath)
    {
        try {
            presetBank.loadFromFile(filepath);
            #if JUCE_DEBUG
                logMessage(String::formatted("Loaded %i presets from ", presetBank.getNumPresetsInBank()) + presetBank.getLoadedFilename());
            #endif
        } catch (...) {
            // TODO: would be nice to catch specific exceptions instead of broad catching
            #if JUCE_DEBUG
                logMessage("Could not load bank file " + filepath);
            #endif
        }
    }
    
    SynthControlIdValuePairs getSynthControlIdValuePairsForCopyingChannelFromToChannelTo(AudioProcessorValueTreeState* currentParameters, int channelFrom, int channelTo)
    {
        std::vector<String> controlIDsChannelFrom = getDDRMSynthControlIDsForChannel(channelFrom);
        std::vector<String> controlIDsChannelTo = getDDRMSynthControlIDsForChannel(channelTo);
        SynthControlIdValuePairs idValuePairs;
        
        for (int i=0; i<controlIDsChannelFrom.size(); i++){
            String channelFromControlID = controlIDsChannelFrom[i];
            String genericChannelControlID = channelFromControlID.substring(0, channelFromControlID.length() - 2);
            String channelToControlID = "";
            for (int j=0; j<controlIDsChannelTo.size(); j++){
                if (controlIDsChannelTo[j].startsWith(genericChannelControlID)){
                    channelToControlID = controlIDsChannelTo[j];
                    break;
                }
            }
            if (channelToControlID != ""){
                AudioParameterFloat* audioParameter = (AudioParameterFloat*)currentParameters->getParameter(channelFromControlID);
                double channelFromParameterValueNorm = (double)audioParameter->get() / 127.0;  // Needs normalized value to set
                idValuePairs.emplace_back(channelToControlID, channelFromParameterValueNorm);
            }
        }
        return idValuePairs;
    }
    
    SynthControlIdValuePairs getSynthControlIdValuePairsFromPatchFile(const String& filepath)
    {
        // Reads from DDRM patch file and prepares SynthControlIdValuePairs to update the current preset
        // This function might throw errors if file has not correct format or other problems happen
        // Calls to this function should be prepared for that

        File path (filepath);
        MemoryBlock fileContents;
        path.loadFileAsData(fileContents);
        
        if (fileContents.getSize() != DDRM_PRESET_NUM_BYTES) {
            throw std::invalid_argument("Wrong number of bytes for preset file");
        }
        
        DDRMPresetBytes presetBytes = {0};
        for (int i=0; i<DDRM_PRESET_NUM_BYTES; i++){  // Go byte by byte
            unsigned char byte = fileContents[i];
            uint8 byte_int = uint8(byte);
            presetBytes[i] = byte_int;
        }
        
        return getSynthControlIdValuePairsForPresetBytesArray(presetBytes);
    }
    
    SynthControlIdValuePairs getSynthControlIdValuePairsForChannelFromVoiceFile(const String& filepath, int channelTo)
    {
        // Reads from DDRM voice file and prepares SynthControlIdValuePairs to update the current preset
        // This function might throw errors if file has not correct format or other problems happen
        // Calls to this function should be prepared for that
        
        File path (filepath);
        MemoryBlock fileContents;
        path.loadFileAsData(fileContents);
        
        if (fileContents.getSize() != DDRM_VOICE_NUM_BYTES) {
            throw std::invalid_argument("Wrong number of bytes for voice file");
        }
        
        DDRMVoiceBytes voiceBytes = {0};
        for (int i=0; i<DDRM_VOICE_NUM_BYTES; i++){  // Go byte by byte
            unsigned char byte = fileContents[i];
            uint8 byte_int = uint8(byte);
            voiceBytes[i] = byte_int;
        }
        
        return getSynthControlIdValuePairsForVoiceBytesArray(voiceBytes, channelTo);
    }
    
    DDRMPresetBytes& getLoadedPresetBytesAtIndex(int index)
    {
        return presetBank.getPresetBytesAtIndex(index);
    }
    
private:
    
    std::vector<DDRMSynthControl> synthControls;
    DDRMToneSelectorPresets ddrmToneSelectorPresets;
    String selectedToneSelectorRow1;
    String selectedToneSelectorRow2;
    DDRMPresetBank presetBank;
    
    void logMessage (const String& message)
    {
        // Broadcasts a "LOG:" action with a message that will be received in the editor and printed to the logArea component
        sendActionMessage(ACTION_LOG_PREFIX + message);
    }
    
};