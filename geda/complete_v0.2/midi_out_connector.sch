v 20130925 2
C 45700 53100 1 0 0 Female-DIN-5.sym
{
T 45900 55500 5 10 0 0 0 0 1
device=Female-DIN-5
T 45900 55100 5 10 0 0 0 0 1
footprint=Female_DIN_5_pin
T 46595 54395 5 10 1 1 0 0 1
refdes=CN1
}
C 46300 52500 1 0 0 gnd-1.sym
N 45400 53600 45700 53600 4
N 47100 53600 48400 53600 4
N 46400 53100 46400 52800 4
N 45700 53200 45700 53000 4
N 45700 53000 46400 53000 4
C 42900 48600 0 0 0 title-A4.sym
T 47600 49000 9 10 1 0 0 0 1
midi_out_connector.sch
T 47600 49300 9 10 1 0 0 0 1
midi out connector
T 47600 48700 9 10 1 0 0 0 1
1
T 49100 48700 9 10 1 0 0 0 1
1
T 51400 49000 9 10 1 0 0 0 1
v0.1
T 51400 48700 9 8 1 0 0 0 1
Benjamin Horvat | http://horvat-elektronika.hr
N 45400 52000 45400 53600 4
C 46800 52100 1 180 0 resistor-1.sym
{
T 46500 51700 5 10 0 0 180 0 1
device=RESISTOR
T 46500 51800 5 10 1 1 180 0 1
value=220
T 46800 52100 5 10 0 0 180 0 1
footprint=R025
T 46200 52200 5 10 1 1 0 0 1
refdes=R1
}
N 45400 52000 45900 52000 4
C 47900 52700 1 90 0 diode-1.sym
{
T 47300 53100 5 10 0 0 90 0 1
device=DIODE
T 47400 53000 5 10 1 1 90 0 1
refdes=D1
T 47900 52700 5 10 0 0 0 0 1
footprint=DIODE_LAY 300
}
N 46800 52000 47700 52000 4
N 47700 52000 47700 52700 4
C 48400 52400 1 0 0 4N25-1.sym
{
T 49300 54400 5 10 0 0 0 0 1
device=4N35
T 50200 54200 5 10 1 1 0 6 1
refdes=U1
T 48400 52400 5 10 0 0 0 0 1
footprint=DIP6
}
N 47700 52700 48400 52700 4
C 51200 53600 1 90 0 resistor-1.sym
{
T 50800 53900 5 10 0 0 90 0 1
device=RESISTOR
T 51400 53900 5 10 1 1 90 0 1
value=560
T 51200 53600 5 10 0 0 90 0 1
footprint=R025
T 50900 53900 5 10 1 1 90 0 1
refdes=R2
}
N 50500 53600 51600 53600 4
N 50500 52700 51100 52700 4
C 51000 52400 1 0 0 gnd-1.sym
C 50900 54500 1 0 0 vcc-1.sym
C 53000 53700 1 180 0 input-2.sym
{
T 53000 53500 5 10 1 0 180 0 1
net=midi_out:1
T 52400 53000 5 10 0 0 180 0 1
device=none
T 52500 53600 5 10 1 1 180 7 1
value=Rx
}
C 51800 51400 1 180 0 output-2.sym
{
T 50900 51200 5 10 1 0 180 0 1
net=midi_out:1
T 51600 50700 5 10 0 0 180 0 1
device=none
T 50900 51300 5 10 1 1 180 1 1
value=Rx
}
C 53500 51800 1 180 0 connector3-1.sym
{
T 51700 50900 5 10 0 0 180 0 1
device=CONNECTOR_3
T 53500 50700 5 10 1 1 180 0 1
refdes=CONN1
T 53500 51800 5 10 0 0 0 0 1
footprint=SIP3
}
C 51900 51900 1 180 0 gnd-1.sym
C 52000 51000 1 180 0 vcc-1.sym
