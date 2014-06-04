v 20130925 2
N 46000 50900 45700 50900 4
N 45700 49100 45700 51200 4
N 45700 49100 46000 49100 4
C 45500 51200 1 0 0 vcc-1.sym
N 46000 50600 44800 50600 4
N 46000 48800 44800 48800 4
C 43400 50500 1 0 0 input-2.sym
{
T 43400 50700 5 10 0 0 0 0 1
net=data_164:1
T 44000 50500 5 6 1 1 0 0 1
device=DATA_164
T 43900 50600 5 10 0 1 0 7 1
value=INPUT
}
C 43400 48700 1 0 0 input-2.sym
{
T 43400 48900 5 10 0 0 0 0 1
net=clk_164:1
T 44000 48700 5 6 1 1 0 0 1
device=CLK_164
T 43900 48800 5 10 0 1 0 7 1
value=INPUT
}
C 49500 48200 1 0 0 header_1x8.sym
{
T 49550 47150 5 10 0 1 0 0 1
device=HEADER8
T 49900 51500 5 10 1 1 0 0 1
refdes=J6
T 49500 48200 5 10 0 0 0 0 1
footprint=SIP8
}
N 49500 50000 48000 50000 4
N 49500 49600 49200 49600 4
N 49200 49600 49200 49700 4
N 49200 49700 48000 49700 4
N 49500 50400 49200 50400 4
N 49200 50400 49200 50300 4
N 49200 50300 48000 50300 4
N 49500 50800 48900 50800 4
N 48900 50800 48900 50600 4
N 48900 50600 48000 50600 4
N 49500 51200 48600 51200 4
N 48600 51200 48600 50900 4
N 48600 50900 48000 50900 4
N 48000 49400 48900 49400 4
N 48900 49400 48900 49200 4
N 48900 49200 49500 49200 4
N 48000 49100 48600 49100 4
N 48600 49100 48600 48800 4
N 48600 48800 49500 48800 4
N 48000 48800 48300 48800 4
N 48300 48800 48300 48400 4
N 48300 48400 49500 48400 4
C 41500 45300 0 0 0 title-A4.sym
T 50000 45700 9 10 1 0 0 0 1
v0.1
T 50000 45400 9 8 1 0 0 0 1
Benjamin Horvat | http://horvat-elektronika.hr/
T 46200 45400 9 10 1 0 0 0 1
1
T 47700 45400 9 10 1 0 0 0 1
1
T 46200 46000 9 10 1 0 0 0 1
74hc164
T 46200 45700 9 10 1 0 0 0 1
74hc164.sch
C 46000 48600 1 0 0 74164-1_vcc-gnd.sym
{
T 46300 51850 5 10 0 0 0 0 1
device=74164
T 47700 51300 5 10 1 1 0 6 1
refdes=U9
T 46300 52050 5 10 0 0 0 0 1
footprint=DIP14
}
C 45600 49400 1 90 0 capacitor-1.sym
{
T 44900 49600 5 10 0 0 90 0 1
device=CAPACITOR
T 45300 50100 5 10 1 1 180 0 1
refdes=C9
T 44700 49600 5 10 0 0 90 0 1
symversion=0.1
T 45600 49400 5 10 0 0 0 0 1
footprint=ACY200
T 44900 49600 5 10 1 1 0 0 1
value=0.1uF
}
N 46000 50300 45700 50300 4
N 46000 49400 45400 49400 4
N 45400 49400 45400 48500 4
N 45700 50300 45400 50300 4
C 45300 48200 1 0 0 gnd-1.sym
