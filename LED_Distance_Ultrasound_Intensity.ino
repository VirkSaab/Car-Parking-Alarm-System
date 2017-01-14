const int trigPin = 2;
const int echoPin = 3;
int LEDPIN = 5;
int BuzzerPin = 6 ;

void setup() 
{
    // put your setup code here, to run once:
    pinMode(echoPin, INPUT);
    pinMode(LEDPIN,OUTPUT);
    pinMode(trigPin, OUTPUT);
    Serial.begin(9600);
}

unsigned long ultraSound()
{
    // establish variables for duration of the ping, 
    // and the distance result in inches and centimeters:
    long duration, inches, cm;

    // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read the signal from the sensor: a HIGH pulse whose
    // duration is the time (in microseconds) from the sending
    // of the ping to the reception of its echo off of an object.
  
    duration = pulseIn(echoPin, HIGH);

    // convert the time into a distance
    inches = microsecondsToInches(duration);
    cm = microsecondsToCentimeters(duration);

    if(cm<55)
    {
        digitalWrite(LEDPIN,HIGH);
        analogWrite(BuzzerPin,255 - 3*cm);
    }
    else
    {
        digitalWrite(LEDPIN,LOW);
        digitalWrite(BuzzerPin,LOW);
    }
  
    Serial.print(inches);
    Serial.print("in, ");
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
  
    delay(50);
}
 
void loop() 
{
    // put your main code here, to run repeatedly:
    int x=0;
    x = ultraSound();
    delay(250);
}

long microsecondsToInches(long microseconds)
{
    return microseconds/74/2;
}
long microsecondsToCentimeters(long microseconds)
{
    return microseconds/29/2;
}



