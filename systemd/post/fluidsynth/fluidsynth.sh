#!/bin/bash

/usr/bin/fluidsynth -a jack -m alsa_seq --portname=fs -s -g 1 -o audio.jack.id=fs -L 28 -K 32 -f /root/fluidsynth/fs_load.txt -s
