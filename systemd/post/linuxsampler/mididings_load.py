#!/usr/bin/python
import sys
from mididings import *

def organ_stops(n):
    if n <= 63:
      #cmdstring = "echo \"stop on %s\"" % (n)
      #cmdstring = "echo \"SET CHANNEL MUTE %s 0\" | nc 127.0.0.1 8888" % (n-2)
      #cmdstring = "echo \"SET CHANNEL MUTE {0} 0\" | nc 127.0.0.1 8888".format((n-2))
      #cmdstring = "echo \"SET CHANNEL VOLUME %s 1\" | nc 127.0.0.1 8888" % (n-2)
      #cmdstring = "/root/organ/set_channel_gain.pl 1 {0}".format(n-2)
      #cmdstring = "oscsend localhost 12345 /strip/{0}/Gain/Gain%20\(dB\) f 0.9211".format(n-2)
      cmdstring = "oscsend localhost 12345 /strip/{0}/Gain/Gain%20\(dB\) f 0.9211".format(n-2)
      return System(cmdstring)
    elif n == 64:
      #cmdstring = "echo \"general cancel %s\"" % (n)
      return System(cmdstring)
    if n >= 65:
      n = n-64
      #cmdstring = "echo \"stop off %s\"" % (n)
      #cmdstring = "echo \"SEND CHANNEL MIDI_DATA CC {0} 123 0; SET CHANNEL MUTE {1} 1\" | nc 127.0.0.1 8888".format((n-2), (n-2))
      #cmdstring = "echo \"SET CHANNEL VOLUME %s 0\" | nc 127.0.0.1 8888" % (n-2)
      #cmdstring = "/root/organ/set_channel_gain.pl 0 {0}".format(n-2)
      #cmdstring = "oscsend localhost 12345 /strip/{0}/Gain/Gain%20\(dB\) f 0".format(n-2)
      cmdstring = "oscsend localhost 12345 /strip/{0}/Gain/Gain%20\(dB\) f 0".format(n-2)
      return System(cmdstring)
print("Mididings started.")
run(
ProgramSplit({
    #turn organ stop on
    1 : organ_stops( 1 ),
    2 : organ_stops( 2 ),
    3 : organ_stops( 3 ),
    4 : organ_stops( 4 ),
    5 : organ_stops( 5 ),
    6 : organ_stops( 6 ),
    7 : organ_stops( 7 ),
    8 : organ_stops( 8 ),
    9 : organ_stops( 9 ),
    10 : organ_stops( 10 ),
    11 : organ_stops( 11 ),
    12 : organ_stops( 12 ),
    13 : organ_stops( 13 ),
    14 : organ_stops( 14 ),
    15 : organ_stops( 15 ),
    16 : organ_stops( 16 ),
    17 : organ_stops( 17 ),
    18 : organ_stops( 18 ),
    19 : organ_stops( 19 ),
    20 : organ_stops( 20 ),
    21 : organ_stops( 21 ),
    22 : organ_stops( 22 ),
    23 : organ_stops( 23 ),
    24 : organ_stops( 24 ),
    25 : organ_stops( 25 ),
    26 : organ_stops( 26 ),
    27 : organ_stops( 27 ),
    28 : organ_stops( 28 ),
    29 : organ_stops( 29 ),

    #64 : organ_stops( 64 ),

    #turn organ stops off
    65 : organ_stops( 65 ),
    66 : organ_stops( 66 ),
    67 : organ_stops( 67 ),
    68 : organ_stops( 68 ),
    69 : organ_stops( 69 ),
    70 : organ_stops( 70 ),
    71 : organ_stops( 71 ),
    72 : organ_stops( 72 ),
    73 : organ_stops( 73 ),
    74 : organ_stops( 74 ),
    75 : organ_stops( 75 ),
    76 : organ_stops( 76 ),
    77 : organ_stops( 77 ),
    78 : organ_stops( 78 ),
    79 : organ_stops( 79 ),
    80 : organ_stops( 80 ),
    81 : organ_stops( 81 ),
    82 : organ_stops( 82 ),
    83 : organ_stops( 83 ),
    84 : organ_stops( 84 ),
    85 : organ_stops( 85 ),
    86 : organ_stops( 86 ),
    87 : organ_stops( 87 ),
    88 : organ_stops( 88 ),
    89 : organ_stops( 89 ),
    90 : organ_stops( 90 ),
    91 : organ_stops( 91 ),
    92 : organ_stops( 92 ),
    93 : organ_stops( 93 ),
    })
)
