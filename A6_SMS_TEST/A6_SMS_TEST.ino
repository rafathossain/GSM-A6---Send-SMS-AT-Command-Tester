#include <SoftwareSerial.h>

SoftwareSerial mySerial(13, 15);

String sendTo = "01704005054" ;
String message = ".........massege to be send........." ;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  Serial.println("GSM A6 Send SMS");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("AT");
  delay(5);
  mySerial.println("AT");
  delay(5);
  updateGSM();
  Serial.println("GSM Ready");
  mySerial.println("AT+CMGF=1");
  delay(5);
  mySerial.println("AT+CMGS=\"+88" + sendTo + "\"\r");
  delay(5);
  mySerial.println(message);
  delay(5);
  mySerial.println((char)26);
  Serial.println("SMS Sent");
}

void loop() { // run over and over
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}

void updateGSM(){
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
}
