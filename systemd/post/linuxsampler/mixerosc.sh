#!/bin/bash

#set gain of master to 0
oscsend 127.0.0.1 16000 /mixer/output/gain_set if 1 0
#set gain of swell to 0
oscsend 127.0.0.1 16000 /mixer/output/gain_set if 2 0

#set gain of swell master to -90 and send to 0
for i in {17..30}; do
oscsend 127.0.0.1 16000 /mixer/channel/send/gain_set iif $i 1 0
done

#set mute
