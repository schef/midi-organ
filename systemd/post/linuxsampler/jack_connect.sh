#!/bin/bash

#=====AUDIO=====#
#use jack_lsp to see all available audio ports
#connect fluidsynth 28 stereo out to jackminimix 28 stereo in
for i in {0..27}; do
	jack_connect "LinuxSampler:$((${i}*2))" "Non-Mixer/$((i+1)):in-1"
	jack_connect "LinuxSampler:$((${i}*2+1))" "Non-Mixer/$((i+1)):in-2"
done
for i in {0..7} {15..27}; do
	jack_connect "Non-Mixer/$((i+1)):out-1" "Non-Mixer/Master:in-1"
	jack_connect "Non-Mixer/$((i+1)):out-2" "Non-Mixer/Master:in-2"
done
for i in {8..14}; do
	jack_connect "Non-Mixer/$((i+1)):out-1" "Non-Mixer/Swell:in-1"
	jack_connect "Non-Mixer/$((i+1)):out-2" "Non-Mixer/Swell:in-2"
done

jack_connect "Non-Mixer/Swell:out-1" "Non-Mixer/Masterin-1"
jack_connect "Non-Mixer/Swell:out-2" "Non-Mixer/Master:in-2"

#connect jconvolver stereo out to system playback stereo in
jack_connect "Non-Mixer/Master:out-1" "system:playback_1"
jack_connect "Non-Mixer/Master:out-2" "system:playback_2"

#=====MIDI=====#
#use aconnect -iol to see all available midi ports
#connect soundcard midi in to soundcard midi out
aconnect 'FastTrack Pro':0 'FastTrack Pro':0
#connect soundcard midi in to mididings in
aconnect 'FastTrack Pro':0 'mididings':0
#connect mididings out to fluidsynth midi in
aconnect 'mididings':1 'LinuxSampler':0
#for testing purposes connect vmpk to mididings in
aconnect 'VMPK Output':0 'mididings':0

#beep to confirm that the booting is over and happy playing
/usr/bin/pport -s 2
sleep 1
/usr/bin/pport -t 2
/usr/bin/beep -l 5000 -f 65
