#!/bin/bash
/usr/bin/jackd -d alsa -d hw:0 -n 3 -r 44100 -p 128
