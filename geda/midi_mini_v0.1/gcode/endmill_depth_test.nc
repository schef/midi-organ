( Made using CamBam - http://www.cambam.co.uk )
( endmill_depth_test 8/21/2014 2:18:03 AM )
( T0 : 0.0 )
G21 G90 G64 G40
G0 Z3.0
( T0 : 0.0 )
T0 M6
( Engrave1 )
G17
M3 S1000
G0 X0.0 Y0.0
G0 Z1.3
G1 F300.0 Z-0.1
G1 F80.0 Y30.0
( Engrave2 )
S1000
G0 Z3.0
G0 X5.0 Y0.0
G0 Z1.285
G1 F300.0 Z-0.115
G1 F80.0 Y30.0
( Engrave3 )
S1000
G0 Z3.0
G0 X10.0 Y0.0
G0 Z1.275
G1 F300.0 Z-0.125
G1 F80.0 Y30.0
( Engrave4 )
S1000
G0 Z3.0
G0 X15.0 Y0.0
G0 Z1.25
G1 F300.0 Z-0.15
G1 F80.0 Y30.0
G0 Z3.0
M5
M30
