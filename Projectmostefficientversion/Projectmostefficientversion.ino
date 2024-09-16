const int temppin = A0;
void setup()
{
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  float voltage, degreeC;
  voltage = getVoltage(temppin);
  degreeC = -(voltage - 0.5)*100; //Necessary for aruduino to not make temperature negative
  Serial.print("TEMPERATURE = ");
  Serial.print(degreeC);
  Serial.print("*C\t");
  Serial.println();
  digitalWrite(11, HIGH);
  delay(200-degreeC);
  digitalWrite(11, LOW);
  delay(200-degreeC);

  
}

float getVoltage(int pin) {
  return (analogRead(pin) * 0.004882814);
}
 	