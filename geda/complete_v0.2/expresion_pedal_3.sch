v 20130925 2
C 37600 46700 1 270 0 pot-bourns.sym
{
T 38500 45900 5 10 0 0 270 0 1
device=VARIABLE_RESISTOR
T 38000 46100 5 10 1 1 270 0 1
refdes=R?
T 37600 46700 5 10 0 0 0 0 1
footprint=JUMPER3
}
C 37600 45200 1 0 0 gnd-1.sym
N 37700 45800 37700 45500 4
N 38500 46200 38200 46200 4
C 37500 47000 1 0 0 vcc-1.sym
N 37700 47000 37700 46700 4
C 32300 41700 0 0 0 title-A4.sym
T 37000 42400 9 10 1 0 0 0 1
expresion pedal 3
T 37000 42100 9 10 1 0 0 0 1
expresion_pedal_3.sch
T 37000 41800 9 10 1 0 0 0 1
8
T 38500 41800 9 10 1 0 0 0 1
11
T 40800 42100 9 10 1 0 0 0 1
v0.1
T 40800 41800 9 8 1 0 0 0 1
Benjamin Horvat | http://horvat-elektronika.hr
C 38500 46100 1 0 0 output-2.sym
{
T 39400 46300 5 10 0 1 0 0 1
net=exped3:1
T 38700 46100 5 7 1 1 0 0 1
device=EXPED3
T 39400 46200 5 10 0 1 0 1 1
value=OUTPUT
}
