/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/
int led = 6;
int fadeAmount = 1;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  analogWrite(led, sensorValue); 
  sensorValue = sensorValue + fadeAmount;
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability
  if (sensorValue == 0 || sensorValue == 236) {
    fadeAmount = -fadeAmount; 
  }   
  //đợi 30 mili giây để thấy sự thay đổi của đèn
  delay(30);   
}
