#!/bin/bash

#=====AUDIO=====#
#use jack_lsp to see all available audio ports
#connect fluidsynth 28 stereo out to jackminimix 28 stereo in
for i in {00..27}; do
	jack_connect fs:l_${i} minimixer:in$((${i##0}+1))_left
	jack_connect fs:r_${i} minimixer:in$((${i##0}+1))_right
done

#if one would want to connect each manual to a separate prefader
##HW 0-7
#	if [ $i -lt 8 ]; then
#		jack_connect fs:l_${i} minimixer:in${i}_left
#		jack_connect fs:r_${i} minimixer:in${i}_right
##PEDAL 8-14
#	elif [ $i -gt 7 ] && [ $i -lt 15 ]; then
#		jack_connect fs:l_${i} minimixer:in${i}_left
#		jack_connect fs:r_${i} minimixer:in${i}_right
##BW 15-19
#	elif [ $i -gt 14 ] && [ $i -lt 20 ]; then
#		jack_connect fs:l_${i} minimixer:in${i}_left
#		jack_connect fs:r_${i} minimixer:in${i}_right
##RP 20-27
#	elif [ $i -gt 19 ]; then
#		jack_connect fs:l_${i} minimixer:in${i}_left
#		jack_connect fs:r_${i} minimixer:in${i}_right
#	fi
#done

#connect jackminimix stereo out to jconvolver stereo in
jack_connect minimixer:out_left jconvolver:input_1 
jack_connect minimixer:out_right jconvolver:input_2 

#connect jconvolver stereo out to system playback stereo in
jack_connect jconvolver:output_1 system:playback_1 
jack_connect jconvolver:output_2 system:playback_2

#=====MIDI=====#
#use aconnect -iol to see all available midi ports
#connect soundcard midi in to soundcard midi out
aconnect 'FastTrack Pro':0 'FastTrack Pro':0
#connect soundcard midi in to mididings in
aconnect 'FastTrack Pro':0 'mididings':0
#connect mididings out to fluidsynth midi in
aconnect 'mididings':1 'fs':0
#for testing purposes connect vmpk to mididings in
aconnect 'VMPK Output':0 'mididings':0

#beep to confirm that the booting is over and happy playing
/usr/bin/beep -l 5000 -f 65
