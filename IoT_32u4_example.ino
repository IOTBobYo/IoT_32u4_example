/*
 * refs :
 * 		[GPIO]
 * 		https://www.arduino.cc/en/Reference/PinMode
 * 		https://www.arduino.cc/en/Reference/DigitalWrite
 * 		https://www.arduino.cc/en/Reference/DigitalRead
 * 		https://www.arduino.cc/en/Reference/analogRead
 * 		[UART] 		
 * 		https://www.arduino.cc/en/Main/ArduinoBoardLeonardo
 * 		https://www.arduino.cc/en/Serial/IfSerial
 * 		https://www.arduino.cc/en/Serial/Begin
 * 		https://www.arduino.cc/en/Serial/Print
 * 		https://www.arduino.cc/en/Serial/Available
 * 		https://www.arduino.cc/en/Serial/Read
 */

#define BT_EN_PIN 15
#define BT_STATE_PIN A3

void setup()
{

	Serial.begin(115200);
	while (!Serial) {
		; // wait for serial port to connect. Needed for native USB
	}
	//Send Data: 8bits, Parity bit: N/A, Stop bit: 1bit
	Serial1.begin(9600, SERIAL_8N1);

/*GPIO test+
	pinMode(BT_EN_PIN, OUTPUT);
	pinMode(BT_STATE_PIN, INPUT);
GPIO test-*/

	Serial.println( "this str from Serial (CDC).");
	Serial1.println("this str from Serial1(HW).");
}

void PrintData(int incomingByte)
{
	char InStr[10];

	sprintf(InStr, "0x%02x(%c) ", incomingByte, incomingByte);
	Serial.print(InStr);
	//delay(50);
}

void ReceiveData()
{
	int InCnt;

	InCnt = Serial.available();
	if(0 < InCnt)
	{
		Serial.print("Serial-0 received: ");
		Serial.println(InCnt, DEC);
		while (0 != Serial.available())
		{
			PrintData(Serial.read());
		}
		Serial.println("");
	}

	InCnt = Serial1.available();
	if(0 < InCnt)
	{
		Serial.print("Serial-1 received: ");
		Serial.println(InCnt, DEC);
		while (0 != Serial1.available())
		{
			PrintData(Serial1.read());
		}
		Serial.println("");
	}
}

static boolean IsHigh;

// the loop routine runs over and over again forever:
void loop()
{
	Serial.print( "13579");
	Serial1.print("46");
	ReceiveData();
/*GPIO test+
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
GPIO test-*/

	delay(1000);
}
