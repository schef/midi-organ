#!/bin/bash
avrdude -c avrisp -p atmega328p -P /dev/ttyACM* -U flash:w:./.build/atmega328/firmware.hex -b 19200 -v -v -v -v
