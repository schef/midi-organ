/* Simple Serial ECHO script : Written by ScottC 03/07/2012 */

/* Use a variable called byteRead to temporarily store
   the data coming from the computer */
byte byteRead;

void setup() {                
// Turn the Serial Protocol ON
  Serial.begin(31250);
}

void loop() {
   /*  check if data has been sent from the computer: */
  if (Serial.available()) {
    /* read the most recent byte */
    byteRead = Serial.read();
    /*ECHO the value that was read, back to the serial port. */
    Serial.write(byteRead);
  }
}

//I used this code using serial in (RX) from FTDI chip and serial out over midi port. I coudnt set the right rate but nevertheless it did recive some kind of bytes.
//I used printf \x90 > /dev/ttyUSB0 to send bytes to serial and qmidiroute to see what id get.
