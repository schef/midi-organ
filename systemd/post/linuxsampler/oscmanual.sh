#!/bin/bash

if [ $1 == 1 ]; then
  GAIN="0.9211"
elif [ $1 == 0 ]; then
  GAIN="-90"
fi

for i in {1..28}; do
  #non-mixer
  #oscsend localhost 12345 /strip/$i/Gain/Gain%20\(dB\) f $GAIN

  #jackminimix
  oscsend 127.0.0.1 12345 /mixer/channel/set_gain if $i $GAIN
  oscsend 127.0.0.1 12346 /mixer/channel/set_gain if $i $GAIN
done
