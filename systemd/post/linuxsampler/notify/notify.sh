#!/bin/bash

PROGRAM=/root/linuxsampler/linuxsampler.sh
LOG="/tmp/linuxsampler.log"
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
