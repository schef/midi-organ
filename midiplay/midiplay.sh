#!/bin/bash
#midiplay is the name of this script
#it is hosted at 
#script that uses patched rtmidi[v2.0.1]-cmidiin STDOUT to capture midi commands and parse it for midi record and playback
#the patch is cmidiin-midiplay.patch

APLAYMIDI=0 #variable that toggles midiplay on the same button
ARECORDMIDI=0
APLAYMIDI_COMMAND=144:48:100 # command:note:velocity
ARECORDMIDI_COMMAD=144:49:100
CMIDIIN_MIDIPLAY="./cmidiin"
MIDI_FILE="~/skrabl.mid"
while read line
	do
	echo $line
	if [ $(echo "$line" | grep -E "^$APLAYMIDI_COMMAND:.*$") ] && [ $ARECORDMIDI -eq 0 ]; then
		if [ $APLAYMIDI -eq 0 ]; then
			echo "aplaymidi"
			#aplaymidi skrabl.mid
			#pmidi -p 128:0 ~/Downloads/me-intro.mid &
			pmidi -p 128:0 $MIDI_FILE & #i used pmidi couse when i kill aplaymidi notes keep hanging
			APLAYMIDI=1
		else
			echo "kill aplaymidi"
			kill -INT `pidof pmidi`
			APLAYMIDI=0
		fi
	#elif [ $(echo "$line" | grep -E "^144:60:100:.*$") ]; then
	elif [ $(echo "$line" | grep -E "^$ARECORDMIDI_COMMAD:.*$") ] && [ $APLAYMIDI -eq 0 ]; then
		if [ $ARECORDMIDI -eq 0 ]; then
			echo "amidirecord"
			arecordmidi -p 129:0 $MIDI_FILE &
			ARECORDMIDI=1
		else
			echo "kill arecordmidi"
			kill -INT `pidof arecordmidi`
			ARECORDMIDI=0
		fi
	#elif [ $(echo "$line" | grep -E "^144:61:100:.*$") ]; then
	fi
	done < <($CMIDIIN-PATCHED)
