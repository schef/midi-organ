#!/bin/bash
#/usr/local/bin/jackminimix -c 28 -p 12345 -v
#/usr/bin/jackmixdesk -p /root -f .mixdeskrc
#/usr/bin/jackmixdesk -c 58 -e 2
DISPLAY=:0 /usr/bin/non-mixer --osc-port 16000 /root/linuxsampler/non/mixer
