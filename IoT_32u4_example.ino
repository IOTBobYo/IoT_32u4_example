/*
 * refs :
 * 		https://www.arduino.cc/en/Reference/PinMode
 * 		https://www.arduino.cc/en/Reference/DigitalWrite
 * 		https://www.arduino.cc/en/Reference/DigitalRead
 * 		https://www.arduino.cc/en/Reference/analogRead
*/

#define BT_EN_PIN 15
#define BT_STATE_PIN A3

void setup()
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);

  pinMode(BT_EN_PIN, OUTPUT);
  pinMode(BT_STATE_PIN, INPUT);
}

static boolean IsHigh;

// the loop routine runs over and over again forever:
void loop()
{
  Serial.println(" - - - - - - - - - - - - ");

  if(true == IsHigh)
  {
    Serial.println(" Set BT_EN_PIN to High.");
    digitalWrite(BT_EN_PIN, HIGH);
  } else {
    Serial.println(" Set BT_EN_PIN to Low.");
    digitalWrite(BT_EN_PIN, LOW);
  }
  IsHigh = !IsHigh;

  delay(100);
  Serial.println(" - - - - - - - - - - - - ");
  int DigiState = digitalRead(BT_STATE_PIN);
  Serial.print("BT_STATE_PIN[D]: ");	Serial.println(DigiState);

  // read the input on analog pin 0:
  int AlgValue = analogRead(BT_STATE_PIN);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = AlgValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.print("BT_STATE_PIN[A]: ");	Serial.println(voltage);


 delay(500);
}
