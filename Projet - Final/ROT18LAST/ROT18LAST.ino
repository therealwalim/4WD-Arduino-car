// This is a simple Rotate 18 encryption sketch

// This sketch tests communication between your terminal program

// and the Arduino board.

// If you send a plain text message to the Arduino board,

// you get back an encrypted message.

// If you send the encrypted message back to the Arduino,

// you get the original plain text message back.

// All you need to test this sketch is a terminal program

// on your host system.  The Arduino serial monitor works

// fine for this test.  The putty terminal program also

// works fine.  Click on "Serial" and change COM1 to COM3.

// Testing procedure:

// Connect your USB to serial cable to the Arduino.

// Compile and upload this sketch to the Arduino board.

// Go to tools -> serial monitor.

// You will see the Arduino is sending you the letter 'A'.

// Type in a plain text message and send it.

// The Arduino will reply with an encrypted message.

int inByte;             // serial input and output character

void setup() {

  // put your setup code here, to run once:

  Serial.begin(9600);   // initialize the serial port at 9600 baud


  } /* setup */

void loop() {

  // put your main code here, to run repeatedly:

  // This is the Rotate 13 encryption algorithm

  // If you run the algorithm twice, you get back the original message

  // Example:   ABC -> NOP -> ABC

  if (Serial.available() > 0)        // if you have data input

         {

         inByte = Serial.read();        // read one byte of input

         // A to M get converted to N to Z

         if (inByte >= 'A' && inByte <= 'M')

            {

            inByte += 13;

            } /* if upper case A-M */

         // N to Z get converted to A to M

         else if (inByte >= 'N' && inByte <= 'Z')

            {

            inByte -= 13;

            } /* if upper case N-Z */

         // Lower case a to m get converted to n to z

         else if (inByte >= 'a' && inByte <= 'm')

            {

            inByte += 13;

            } /* if lower case a-m */

         // Lower case n to z get converted to a to m

         else if (inByte >= 'n' && inByte <= 'z')

            {

            inByte -= 13;

            } /* if lower case n-z */
            if(!isAlpha(inByte)){
              if (inByte >= '0' && inByte <= '4') {
                inByte +=5;
              } /* Numbers 0 to 4 */
              else if (inByte >= '5' && inByte <= '9') {
                inByte -=5;
              } /* Numbers 5 to 9 */
            }

         Serial.write(inByte);   // write the encrypted character back

         } // if Serial.available() > 0

}  /* loop */
