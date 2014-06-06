#!/usr/bin/python3
import sys
from mididings import *

def organ_stops(n):
  #using the YAPPI method
  if n <= 63:
    #non-mixer
    #cmdstring = "oscsend localhost 12345 /strip/{0}/Gain/Gain%20\(dB\) f 0.9211".format(n-2)

    #jackminimix for both stereo chanels
    cmdstring1 = "oscsend localhost 12345 /mixer/channel/set_gain if {0} 0.9211".format(n*2-1)
    cmdstring2 = "oscsend localhost 12345 /mixer/channel/set_gain if {0} 0.9211".format(n*2)

    #for debug purposes
    cmdstring3 = "echo \"stop on %s\"" % (n)
    return System(cmdstring1 + ";" + cmdstring2 + ";" + cmdstring3)
  elif n == 64:
    cmdstring = "echo \"general cancel %s\"" % (n)
    #return System(cmdstring)
  elif n >= 65:
    n = n-64
    #non-mixer
    #cmdstring = "oscsend localhost 12345 /strip/{0}/Gain/Gain%20\(dB\) f 0".format(n-2)

    #jackminimix
    cmdstring1 = "oscsend localhost 12345 /mixer/channel/set_gain if {0} -90".format(n*2-1)
    cmdstring2 = "oscsend localhost 12345 /mixer/channel/set_gain if {0} -90".format(n*2)

    #for debug purposes
    cmdstring3 = "echo \"stop off %s\"" % (n)
    return System(cmdstring1 + ";" + cmdstring2 + ";" + cmdstring3)


print("Mididings started.")

run(
  [
    Filter(NOTE) >> ChannelSplit({
      #if note is played on first channel play it on all others too
      1: [Channel(1), Channel(2), Channel(3), Channel(4), Channel(5), Channel(6), Channel(7), Channel(8)],
      2: [Channel(9), Channel(10), Channel(11), Channel(12), Channel(13), Channel(14), Channel(15)],
      3: [Channel(16), Channel(17), Channel(18), Channel(19), Channel(20)],
      4: [Channel(21), Channel(22), Channel(23), Channel(24), Channel(25), Channel(26), Channel(27), Channel(28)],
    }),
    Filter(PROGRAM) >> ProgramSplit({
      #turn organ stop on
      1 : organ_stops( 1 ) >> Filter(NONE),
      2 : organ_stops( 2 ) >> Filter(NONE),
      3 : organ_stops( 3 ) >> Filter(NONE),
      4 : organ_stops( 4 ) >> Filter(NONE),
      5 : organ_stops( 5 ) >> Filter(NONE),
      6 : organ_stops( 6 ) >> Filter(NONE),
      7 : organ_stops( 7 ) >> Filter(NONE),
      8 : organ_stops( 8 ) >> Filter(NONE),
      9 : organ_stops( 9 ) >> Filter(NONE),
      10 : organ_stops( 10 ) >> Filter(NONE),
      11 : organ_stops( 11 ) >> Filter(NONE),
      12 : organ_stops( 12 ) >> Filter(NONE),
      13 : organ_stops( 13 ) >> Filter(NONE),
      14 : organ_stops( 14 ) >> Filter(NONE),
      15 : organ_stops( 15 ) >> Filter(NONE),
      16 : organ_stops( 16 ) >> Filter(NONE),
      17 : organ_stops( 17 ) >> Filter(NONE),
      18 : organ_stops( 18 ) >> Filter(NONE),
      19 : organ_stops( 19 ) >> Filter(NONE),
      20 : organ_stops( 20 ) >> Filter(NONE),
      21 : organ_stops( 21 ) >> Filter(NONE),
      22 : organ_stops( 22 ) >> Filter(NONE),
      23 : organ_stops( 23 ) >> Filter(NONE),
      24 : organ_stops( 24 ) >> Filter(NONE),
      25 : organ_stops( 25 ) >> Filter(NONE),
      26 : organ_stops( 26 ) >> Filter(NONE),
      27 : organ_stops( 27 ) >> Filter(NONE),
      28 : organ_stops( 28 ) >> Filter(NONE),
      #29 : organ_stops( 29 ) >> Filter(NONE),
      
      #64 : organ_stops( 64 ) >> Filter(NONE),
      
      #turn organ stops off
      65 : organ_stops( 65 ) >> Filter(NONE),
      66 : organ_stops( 66 ) >> Filter(NONE),
      67 : organ_stops( 67 ) >> Filter(NONE),
      68 : organ_stops( 68 ) >> Filter(NONE),
      69 : organ_stops( 69 ) >> Filter(NONE),
      70 : organ_stops( 70 ) >> Filter(NONE),
      71 : organ_stops( 71 ) >> Filter(NONE),
      72 : organ_stops( 72 ) >> Filter(NONE),
      73 : organ_stops( 73 ) >> Filter(NONE),
      74 : organ_stops( 74 ) >> Filter(NONE),
      75 : organ_stops( 75 ) >> Filter(NONE),
      76 : organ_stops( 76 ) >> Filter(NONE),
      77 : organ_stops( 77 ) >> Filter(NONE),
      78 : organ_stops( 78 ) >> Filter(NONE),
      79 : organ_stops( 79 ) >> Filter(NONE),
      80 : organ_stops( 80 ) >> Filter(NONE),
      81 : organ_stops( 81 ) >> Filter(NONE),
      82 : organ_stops( 82 ) >> Filter(NONE),
      83 : organ_stops( 83 ) >> Filter(NONE),
      84 : organ_stops( 84 ) >> Filter(NONE),
      85 : organ_stops( 85 ) >> Filter(NONE),
      86 : organ_stops( 86 ) >> Filter(NONE),
      87 : organ_stops( 87 ) >> Filter(NONE),
      88 : organ_stops( 88 ) >> Filter(NONE),
      89 : organ_stops( 89 ) >> Filter(NONE),
      90 : organ_stops( 90 ) >> Filter(NONE),
      91 : organ_stops( 91 ) >> Filter(NONE),
      92 : organ_stops( 92 ) >> Filter(NONE),
      #93 : organ_stops( 93 ) >> Filter(NONE), 
    })
  ]
)
