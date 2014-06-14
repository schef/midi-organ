#!/bin/bash
while [ ! -d /sys/class/sound/card0 ]; do echo wait; sleep 0.5; done
