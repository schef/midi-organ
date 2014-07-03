#include <MIDI.h>  // Add Midi Library

#define LED 13    // Arduino Board LED is on Pin 13


//ZA CUDO RADI SAMO JEDNOM C ili ton 60

// Below is my function that will be called by the Midi Library
// when a MIDI NOTE ON message is received.
// It will be passed bytes for Channel, Pitch, and Velocity
void MyHandleNoteOn(byte channel, byte pitch, byte velocity) {
  digitalWrite(LED,HIGH);  //Turn LED on
}
void MyHandleNoteOff(byte channel, byte pitch, byte velocity) {
    digitalWrite(LED,LOW);//Turn LED off
}

void setup() {
  pinMode (LED, OUTPUT); // Set Arduino board pin 13 to output
  MIDI.begin(MIDI_CHANNEL_OMNI); // Initialize the Midi Library.
// OMNI sets it to listen to all channels.. MIDI.begin(2) would set it
// to respond to channel 2 notes only.
  MIDI.setHandleNoteOn(MyHandleNoteOn); // This is important!! This command
  MIDI.setHandleNoteOff(MyHandleNoteOff); // This is important!! This command
  // tells the Midi Library which function I want called when a Note ON command
  // is received. in this case it's "MyHandleNoteOn".
}

void loop() { // Main loop
  MIDI.read(); // Continually check what Midi Commands have been received.
}
