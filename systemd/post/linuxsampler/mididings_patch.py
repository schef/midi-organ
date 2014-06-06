#!/usr/bin/python3
import sys
from mididings import *

def organ_stops(n):
  #using the YAPPI method
  if n <= 63:
    #non-mixer
    #cmdstring = "oscsend localhost 12345 /strip/{0}/Gain/Gain%20\(dB\) f 0.9211".format(n-2)

    #jackminimix for both stereo chanels
    cmdstring1 = "oscsend localhost 16000 /strip/{0}/Gain/Gain%20\(dB\) f 0.921".format(n)

    #for debug purposes
    cmdstring2 = "echo \"stop on %s\"" % (n)
    return System(cmdstring1 + ";" + cmdstring2)
  elif n == 64:
    cmdstring = "echo \"general cancel %s\"" % (n)
    #return System(cmdstring)
  elif n >= 65:
    n = n-64
    #non-mixer
    #cmdstring = "oscsend localhost 12345 /strip/{0}/Gain/Gain%20\(dB\) f 0".format(n-2)

    #jackminimix
    cmdstring1 = "oscsend localhost 16000 /strip/{0}/Gain/Gain%20\(dB\) f -90".format(n)
    #for debug purposes
    cmdstring2 = "echo \"stop off %s\"" % (n)
    return System(cmdstring1 + ";" + cmdstring2)

def velocityChange(vel):
    if (vel > 30):
      velNumber = float(vel)/1.42
      velNumber = int(velNumber)
      velNumber = velNumber-90
      cmdstring1 = "oscsend localhost 16000 /strip/Swell/Gain/Gain%20\(dB\) f {0}".format(velNumber)
      cmdstring2 = "echo \"velocity %s\"" % (velNumber)
      return System(cmdstring1 + " " + cmdstring2)

print("Mididings started.")

run(
  [
	#Prepusti note na kanalima 1, 2, 3
	Filter(NOTE) >> ChannelFilter(1, 2, 3)
#    Filter(NOTE) >> ChannelSplit({
#      #if note is played on first channel play it on all others too
#      1: [Channel(1), Channel(2), Channel(3), Channel(4), Channel(5), Channel(6), Channel(7), Channel(8)],
#      2: [Channel(9), Channel(10), Channel(11), Channel(12), Channel(13), Channel(14), Channel(15)],
#      3: [Channel(16), Channel(17), Channel(18), Channel(19), Channel(20)],
#      4: [Channel(21), Channel(22), Channel(23), Channel(24), Channel(25), Channel(26), Channel(27), Channel(28)],
#    }),
	,
    #Filtriraj programe i pali i gasi stopove
    Filter(PROGRAM) >> ProgramSplit({

      #turn organ stop on
      #+64 off

      #Manual1
      18 : organ_stops( 1 ) >> Filter(NONE),
      82 : organ_stops( 65 ) >> Filter(NONE),

      19 : organ_stops( 2 ) >> Filter(NONE),
      83 : organ_stops( 66 ) >> Filter(NONE),

      20 : organ_stops( 4 ) >> Filter(NONE),
      84 : organ_stops( 68 ) >> Filter(NONE),

      21 : organ_stops( 5 ) >> Filter(NONE),
      85 : organ_stops( 69 ) >> Filter(NONE),

      22 : organ_stops( 3 ) >> Filter(NONE),
      86 : organ_stops( 67 ) >> Filter(NONE),

      23 : organ_stops( 6 ) >> Filter(NONE),
      87 : organ_stops( 70 ) >> Filter(NONE),

      24 : organ_stops( 7 ) >> Filter(NONE),
      88 : organ_stops( 71 ) >> Filter(NONE),

      25 : organ_stops( 8 ) >> Filter(NONE),
      89 : organ_stops( 72 ) >> Filter(NONE),

      26 : organ_stops( 18 ) >> Filter(NONE),
      90 : organ_stops( 82 ) >> Filter(NONE),

      27 : organ_stops( 17 ) >> Filter(NONE),
      91 : organ_stops( 81 ) >> Filter(NONE),

      28 : organ_stops( 16 ) >> Filter(NONE),
      92 : organ_stops( 80 ) >> Filter(NONE),

      29 : organ_stops( 20 ) >> Filter(NONE),
      93 : organ_stops( 84 ) >> Filter(NONE),

      30 : organ_stops( 19 ) >> Filter(NONE),
      94 : organ_stops( 83 ) >> Filter(NONE),

      #Manual2      
      34 : organ_stops( 23 ) >> Filter(NONE),
      98 : organ_stops( 87 ) >> Filter(NONE),

      35 : organ_stops( 22 ) >> Filter(NONE),
      99 : organ_stops( 86 ) >> Filter(NONE),

      36 : organ_stops( 26 ) >> Filter(NONE),
      100 : organ_stops( 90 ) >> Filter(NONE),

      37 : organ_stops( 21 ) >> Filter(NONE),
      101 : organ_stops( 85 ) >> Filter(NONE),

      38 : organ_stops( 25 ) >> Filter(NONE),
      102 : organ_stops( 89 ) >> Filter(NONE),

      39 : organ_stops( 24 ) >> Filter(NONE),
      103 : organ_stops( 88 ) >> Filter(NONE),

      40 : organ_stops( 28 ) >> Filter(NONE),
      104 : organ_stops( 92 ) >> Filter(NONE),

      41 : organ_stops( 27 ) >> Filter(NONE),
      105 : organ_stops( 91 ) >> Filter(NONE),

      #Pedal
      10 : organ_stops( 9 ) >> Filter(NONE),
      74 : organ_stops( 73 ) >> Filter(NONE),

      11 : organ_stops( 10 ) >> Filter(NONE),
      75 : organ_stops( 74 ) >> Filter(NONE),

      12 : organ_stops( 11 ) >> Filter(NONE),
      76 : organ_stops( 75 ) >> Filter(NONE),

      13 : organ_stops( 12 ) >> Filter(NONE),
      77 : organ_stops( 76 ) >> Filter(NONE),

      14 : organ_stops( 13 ) >> Filter(NONE),
      78 : organ_stops( 77 ) >> Filter(NONE),

      15 : organ_stops( 14 ) >> Filter(NONE),
      79 : organ_stops( 78 ) >> Filter(NONE),

      16 : organ_stops( 15 ) >> Filter(NONE),
      80 : organ_stops( 79 ) >> Filter(NONE),

    }),
    #Velocity za sweel
    Filter(NOTE) >> ChannelFilter(5) >> KeyFilter(1) >> VelocitySplit({
      #ChannelFilter(5) >> VelocitySplit({
      #Filter(NOTE) >> ChannelFilter(5)
#      0 : velocityChange(0),
#      1 : velocityChange(1),
#      2 : velocityChange(2),
#      3 : velocityChange(3),
#      4 : velocityChange(4),
#      5 : velocityChange(5),
#      6 : velocityChange(6),
#      7 : velocityChange(7),
#      8 : velocityChange(8),
#      9 : velocityChange(9),
#      10 : velocityChange(10),
#      11 : velocityChange(11),
#      12 : velocityChange(12),
#      13 : velocityChange(13),
#      14 : velocityChange(14),
#      15 : velocityChange(15),
#      16 : velocityChange(16),
#      17 : velocityChange(17),
#      18 : velocityChange(18),
#      19 : velocityChange(19),
#      20 : velocityChange(20),
#      21 : velocityChange(21),
#      22 : velocityChange(22),
#      23 : velocityChange(23),
#      24 : velocityChange(24),
#      25 : velocityChange(25),
#      26 : velocityChange(26),
#      27 : velocityChange(27),
#      28 : velocityChange(28),
#      29 : velocityChange(29),
#      30 : velocityChange(30),
#      31 : velocityChange(31),
#      32 : velocityChange(32),
#      33 : velocityChange(33),
#      34 : velocityChange(34),
#      35 : velocityChange(35),
#      36 : velocityChange(36),
#      37 : velocityChange(37),
#      38 : velocityChange(38),
#      39 : velocityChange(39),
#      40 : velocityChange(40),
#      41 : velocityChange(41),
#      42 : velocityChange(42),
      43 : velocityChange(43),
      44 : velocityChange(44),
      45 : velocityChange(45),
      46 : velocityChange(46),
      47 : velocityChange(47),
      48 : velocityChange(48),
      49 : velocityChange(49),
      50 : velocityChange(50),
      51 : velocityChange(51),
      52 : velocityChange(52),
      53 : velocityChange(53),
      54 : velocityChange(54),
      55 : velocityChange(55),
      56 : velocityChange(56),
      57 : velocityChange(57),
      58 : velocityChange(58),
      59 : velocityChange(59),
      60 : velocityChange(60),
      61 : velocityChange(61),
      62 : velocityChange(62),
      63 : velocityChange(63),
      64 : velocityChange(64),
      65 : velocityChange(65),
      66 : velocityChange(66),
      67 : velocityChange(67),
      68 : velocityChange(68),
      69 : velocityChange(69),
      70 : velocityChange(70),
      71 : velocityChange(71),
      72 : velocityChange(72),
      73 : velocityChange(73),
      74 : velocityChange(74),
      75 : velocityChange(75),
      76 : velocityChange(76),
      77 : velocityChange(77),
      78 : velocityChange(78),
      79 : velocityChange(79),
      80 : velocityChange(80),
      81 : velocityChange(81),
      82 : velocityChange(82),
      83 : velocityChange(83),
      84 : velocityChange(84),
      85 : velocityChange(85),
      86 : velocityChange(86),
      87 : velocityChange(87),
      88 : velocityChange(88),
      89 : velocityChange(89),
      90 : velocityChange(90),
      91 : velocityChange(91),
      92 : velocityChange(92),
      93 : velocityChange(93),
      94 : velocityChange(94),
      95 : velocityChange(95),
      96 : velocityChange(96),
      97 : velocityChange(97),
      98 : velocityChange(98),
      99 : velocityChange(99),
      100 : velocityChange(100),
      101 : velocityChange(101),
      102 : velocityChange(102),
      103 : velocityChange(103),
      104 : velocityChange(104),
      105 : velocityChange(105),
      106 : velocityChange(106),
      107 : velocityChange(107),
      108 : velocityChange(108),
      109 : velocityChange(109),
      110 : velocityChange(110),
      111 : velocityChange(111),
      112 : velocityChange(112),
      113 : velocityChange(113),
      114 : velocityChange(114),
      115 : velocityChange(115),
      116 : velocityChange(116),
      117 : velocityChange(117),
      118 : velocityChange(118),
      119 : velocityChange(119),
      120 : velocityChange(120),
      121 : velocityChange(121),
      122 : velocityChange(122),
      123 : velocityChange(123),
      124 : velocityChange(124),
      125 : velocityChange(125),
      126 : velocityChange(126),
      127 : velocityChange(127),
      }
      ),
  ]
)
