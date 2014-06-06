#!/bin/bash
/usr/bin/linuxsampler &
sleep 1
/root/linuxsampler/lscp.sh /root/linuxsampler/pmi.lscp
