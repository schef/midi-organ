#include <MIDI.h>
//inicializacija programa
void setup() {
  MIDI.begin(10);          // Launch MIDI and listen to channel 4
  pinMode(5, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(5, LOW );
  digitalWrite(13, LOW );
}

byte commandByte;
byte noteByte;
byte velocityByte;

void noteon(byte channel, byte note, byte velocity) {
  if(note == 127) {
  digitalWrite(5, HIGH );
  digitalWrite(13, HIGH );
  }
}

void noteoff(byte channel, byte note, byte velocity) {
  if(note == 127) {
  digitalWrite(5, LOW );
  digitalWrite(13, LOW );
}
}

void loop() {

  if (MIDI.read())                // If we have received a message
  {
    //digitalWrite(13,HIGH);
    //..MIDI.sendNoteOn(42,127,1);  // Send a Note (pitch 42, velo 127 on channel 1)
    //delay(1000);		        // Wait for a second
    //MIDI.sendNoteOff(42,0,1);   // Stop the note
    //digitalWrite(13,LOW);
    MIDI.setHandleNoteOn(noteon);                             // call noteon when a note on message is received
    MIDI.setHandleNoteOff(noteoff);                            // call noteoff when a note off message is received
  }
  //mojShift();
}

