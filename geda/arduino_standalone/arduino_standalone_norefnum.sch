v 20130925 2
C 54000 56900 1 0 0 ATmega8-1.sym
{
T 54100 61700 5 10 0 0 0 0 1
footprint=DIP28N
T 56300 61500 5 10 1 1 0 6 1
refdes=U?
T 54100 62500 5 10 0 0 0 0 1
device=ATmega8
}
C 50700 56600 1 0 0 capacitor-1.sym
{
T 50900 57300 5 10 0 0 0 0 1
device=CAPACITOR
T 50900 57100 5 10 1 1 0 0 1
refdes=C?
T 50900 57500 5 10 0 0 0 0 1
symversion=0.1
T 51300 56600 5 10 1 1 0 0 1
value=22pF
T 50700 56600 5 10 0 0 0 0 1
footprint=ACY200
}
C 50700 57300 1 0 0 capacitor-1.sym
{
T 50900 58000 5 10 0 0 0 0 1
device=CAPACITOR
T 50900 57800 5 10 1 1 0 0 1
refdes=C?
T 50900 58200 5 10 0 0 0 0 1
symversion=0.1
T 51300 57600 5 10 1 1 0 0 1
value=22pF
T 50700 57300 5 10 0 0 0 0 1
footprint=ACY200
}
C 49100 61900 1 270 0 capacitor-2.sym
{
T 49800 61700 5 10 0 0 270 0 1
device=POLARIZED_CAPACITOR
T 48600 61500 5 10 1 1 0 0 1
refdes=C?
T 50000 61700 5 10 0 0 270 0 1
symversion=0.1
T 48600 61300 5 10 1 1 0 0 1
value=10uF
T 49100 61900 5 10 0 0 0 0 1
netname=RCY100P
}
C 51300 61900 1 270 0 capacitor-2.sym
{
T 52000 61700 5 10 0 0 270 0 1
device=POLARIZED_CAPACITOR
T 51800 61500 5 10 1 1 0 0 1
refdes=C?
T 52200 61700 5 10 0 0 270 0 1
symversion=0.1
T 51800 61300 5 10 1 1 0 0 1
value=1uF
T 51300 61900 5 10 0 0 0 0 1
footprint=RCY100P
}
C 49600 61300 1 0 0 lm7805-1.sym
{
T 51200 62600 5 10 0 0 0 0 1
device=7805
T 50900 62300 5 10 1 1 0 6 1
refdes=U?
T 49600 61300 5 10 0 0 0 0 1
value=7805
T 49900 62300 5 10 1 1 0 0 1
footprint=TO220
}
C 51600 59600 1 180 0 led-1.sym
{
T 50800 59000 5 10 0 0 180 0 1
device=LED
T 51400 59800 5 10 1 1 180 0 1
refdes=LED?
T 50800 58800 5 10 0 0 180 0 1
symversion=0.1
T 51600 59600 5 10 0 0 0 0 1
footprint=LED3
}
C 52000 56800 1 90 0 crystal-1.sym
{
T 51500 57000 5 10 0 0 90 0 1
device=CRYSTAL
T 52500 57300 5 10 1 1 180 0 1
refdes=U?
T 51300 57000 5 10 0 0 90 0 1
symversion=0.1
T 52100 56900 5 10 1 1 0 0 1
value=16 MHz
T 52000 56800 5 10 0 0 0 0 1
footprint=XTAL200.fp
}
C 51900 59300 1 0 0 resistor-1.sym
{
T 52200 59700 5 10 0 0 0 0 1
device=RESISTOR
T 52100 59600 5 10 1 1 0 0 1
refdes=R?
T 52200 59100 5 10 1 1 0 0 1
value=220
T 51900 59300 5 10 0 0 0 0 1
footprint=R025
}
N 49300 61000 51500 61000 4
N 50400 61300 50400 61000 4
N 49300 62200 49300 61900 4
N 51600 57500 52200 57500 4
N 51600 56800 52200 56800 4
N 50400 56500 50400 61000 4
N 54000 57300 52200 57300 4
N 52200 57300 52200 57500 4
N 54000 57100 52200 57100 4
N 52200 57100 52200 56800 4
N 56600 59000 56900 59000 4
N 56900 54300 56900 61900 4
N 52500 60400 51700 60400 4
N 50700 60400 50400 60400 4
N 56600 58200 57200 58200 4
C 58100 59100 1 180 0 resistor-1.sym
{
T 57800 58700 5 10 0 0 180 0 1
device=RESISTOR
T 57900 58800 5 10 1 1 180 0 1
refdes=R?
T 57700 59300 5 10 1 1 180 0 1
value=10K
T 58100 59100 5 10 0 0 180 0 1
footprint=R025
}
N 50400 56800 50700 56800 4
N 50700 57500 50400 57500 4
C 50300 56200 1 0 0 gnd-1.sym
C 50400 53800 1 0 0 connector6-1.sym
{
T 52200 55600 5 10 0 0 0 0 1
device=ICSP
T 50500 55800 5 10 1 1 0 0 1
refdes=ICSP
T 50400 53800 5 10 0 0 0 0 1
footprint=HEADER6_2
}
N 54000 57500 53100 57500 4
N 53100 54900 53100 59400 4
N 54000 57700 52800 57700 4
N 52800 55500 52800 57700 4
N 54000 57900 52500 57900 4
N 52500 54600 52500 57900 4
N 52800 55500 52100 55500 4
N 53100 54900 52100 54900 4
N 52500 54600 52100 54600 4
N 52100 54300 56900 54300 4
C 52000 53400 1 0 0 gnd-1.sym
N 52100 54000 52100 53700 4
C 48200 57100 1 270 0 switch-spdt-1_jumper.sym
{
T 49000 56700 5 10 0 0 270 0 1
device=SPDT
T 48800 56700 5 10 1 1 270 0 1
refdes=S?
T 48200 57100 5 10 0 0 270 0 1
footprint=JUMPER3
}
N 51500 62200 51500 61900 4
C 45800 52200 0 0 0 title-A3.sym
T 55400 52900 9 10 1 0 0 0 1
arduino standalone
T 55400 52600 9 10 1 0 0 0 1
arduino_standalone_norefnum.sch
T 55400 52300 9 10 1 0 0 0 1
1
T 56900 52300 9 10 1 0 0 0 1
1
T 59200 52600 9 10 1 0 0 0 1
v0.2
T 59200 52300 9 8 1 0 0 0 1
Benjamin Horvat | http://horvat-elektronika.hr
C 49100 62200 1 0 0 vdd-1.sym
C 51300 62200 1 0 0 vcc-7805.sym
N 51200 61900 51500 61900 4
N 56600 57900 58400 57900 4
N 57200 57900 57200 58200 4
N 52500 60400 52500 61900 4
N 52500 61900 56900 61900 4
N 56900 59000 57200 59000 4
N 58400 57900 58400 59300 4
C 58200 59300 1 0 0 vcc-1.sym
C 47500 57400 1 0 0 vcc-7805.sym
C 53200 55200 1 0 0 vcc-7805.sym
C 48900 57400 1 0 0 vcc-ICSP.sym
C 48200 57400 1 0 0 vcc-1.sym
N 52100 55200 53400 55200 4
N 48400 57400 48400 57100 4
N 47700 57400 47700 56200 4
N 47700 56200 48200 56200 4
N 49100 57400 49100 56200 4
N 49100 56200 48600 56200 4
N 58100 59000 58400 59000 4
C 48300 61000 1 0 1 PowerJack-3.sym
{
T 47900 63100 5 8 0 0 0 6 1
device=PowerJack-3
T 46710 62097 5 8 1 1 0 6 1
refdes=CN?
T 48300 61000 5 10 0 0 0 0 1
footprint=Power_Plug_163-7620-E_5.5mm-2.1mm.fp
}
N 48300 60400 48300 61500 4
N 48300 60400 50400 60400 4
C 49200 59600 1 180 1 led-1.sym
{
T 50000 59000 5 10 0 0 180 6 1
device=LED
T 49500 59800 5 10 1 1 180 6 1
refdes=LED?
T 50000 58800 5 10 0 0 180 6 1
symversion=0.1
T 49200 59600 5 10 0 0 0 6 1
footprint=LED3
}
C 48000 59300 1 0 0 resistor-1.sym
{
T 48300 59700 5 10 0 0 0 0 1
device=RESISTOR
T 48200 59600 5 10 1 1 0 0 1
refdes=R?
T 48300 59100 5 10 1 1 0 0 1
value=220
T 48000 59300 5 10 0 0 0 0 1
footprint=R025
}
N 50400 59400 50700 59400 4
N 51600 59400 51900 59400 4
N 52800 59400 53100 59400 4
N 50100 59400 50400 59400 4
N 48900 59400 49200 59400 4
C 47500 59400 1 0 0 vcc-1.sym
N 47700 59400 48000 59400 4
C 50700 60200 1 0 0 switch-pushbutton-reset.sym
{
T 50250 60075 5 10 0 0 0 0 1
device=SWITCH_PUSHBUTTON_SPDT
T 51100 60600 5 10 1 1 0 0 1
refdes=S?
T 50700 60200 5 10 0 0 0 0 1
footprint=TYCO_fsm2j.fp
}
C 59300 60500 1 0 0 7404-3.sym
{
T 59600 62850 5 10 0 0 0 0 1
device=7404
T 59600 62650 5 10 0 0 0 0 1
footprint=DIP14
T 60800 62500 5 10 1 1 0 0 1
refdes=U?
}
C 61000 56500 1 0 1 DB9_RS232_DTE_pinout.sym
{
T 60800 60450 5 10 0 0 0 6 1
device=DB9
T 60800 59700 5 10 1 1 0 6 1
refdes=CONN?
T 61000 56500 5 10 0 0 0 6 1
footprint=SUBD_FEMALE_LAY 9
}
N 54000 61200 53700 61200 4
N 53700 61200 53700 63100 4
N 53700 63100 61600 63100 4
N 58700 62800 53400 62800 4
N 53400 62800 53400 61000 4
N 53400 61000 54000 61000 4
N 59300 61900 58700 61900 4
N 58700 61900 58700 62800 4
N 61300 62200 61600 62200 4
N 61600 62200 61600 63100 4
N 59300 62200 59000 62200 4
N 59000 62200 59000 58000 4
N 59000 58000 59700 58000 4
N 61300 61900 61600 61900 4
N 61600 61900 61600 60100 4
N 61600 60100 59400 60100 4
N 59400 60100 59400 58600 4
N 59400 58600 59700 58600 4
C 59300 56500 1 0 0 gnd-1.sym
N 59400 56800 59700 56800 4
C 48300 61700 1 0 0 diode-1.sym
{
T 48700 62300 5 10 0 0 0 0 1
device=DIODE
T 48600 62200 5 10 1 1 0 0 1
refdes=D?
}
N 49200 61900 49600 61900 4
