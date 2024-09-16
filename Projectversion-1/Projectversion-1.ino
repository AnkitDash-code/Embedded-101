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
  degreeC = -(voltage - 0.5)*100;
  Serial.print("TEMPERATURE = ");
  Serial.print(degreeC);
  Serial.print("*C\t");
  Serial.println();
  if (degreeC > 35.00){
    digitalWrite(11, HIGH);
    delay(5);
    digitalWrite(11, LOW);
    delay(5);
  }
  else {
    digitalWrite(11, HIGH);
    delay(100);
    digitalWrite(11, LOW);
    delay(100);
  }
  
}

float getVoltage(int pin) {
  return (analogRead(pin) * 0.004882814);
}
 	