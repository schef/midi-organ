#!/bin/bash

PROGRAM=/root/fluidsynth/fluidsynth.sh
LOG="/tmp/fluidsynth.log"
PATTERN="ID 28"
rm -f $LOG
touch $LOG

sh $PROGRAM >> $LOG &
#./sleep.sh >> $LOG &
until ( grep -q "$PATTERN" "$LOG" && echo $? ); do
  sleep 1
done
echo STARTED
systemd-notify --ready --status="STARTED"
sleep 1000
