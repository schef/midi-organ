#!/bin/bash

PROGRAM=/root/fluidsynth/jackd.sh
LOG="/tmp/jackd.log"
PATTERN="ALSA: use 2 periods for playback"
rm -f $LOG
touch $LOG

sleep 1000 &
jackd -d alsa -d hw:0 >> $LOG &
#./sleep.sh >> $LOG &
until ( grep -q "$PATTERN" "$LOG" && echo $? ); do
  sleep 1
done
echo JACK STARTED
echo `pidof jackd`
systemd-notify --ready --status="STARTED"
#while : ;do
#  read a < $LOG
#  systemd-notify --status="$a"
#done
