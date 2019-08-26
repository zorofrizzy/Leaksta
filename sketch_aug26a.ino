int X1;
int Y1;
int X2;
int Y2;
float TIME1 = 0;
float TIME2 = 0;
float FREQUENCY1 = 0;
float FREQUENCY2 = 0;
float WATER1 = 0;
float WATER2 = 0;
float TOTAL1 = 0;
float TOTAL2 = 0;
float LS1 = 0;
float LS2 = 0;
const int input1 = A0;
const int input2 = A1;
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;

void setup()
{
Serial.begin(9600);

pinMode(input1,INPUT);
pinMode(input2,INPUT);
pinMode(trigPin, OUTPUT);       // Sets the trigPin as an Output
pinMode(echoPin, INPUT);      // Sets the echoPin as an Input

}


void loop()
{
X1 = pulseIn(input1, HIGH);
Y1 = pulseIn(input1, LOW);
X2 = pulseIn(input2, HIGH);
Y2 = pulseIn(input2, LOW);
TIME1 = X1 + Y1;
TIME2 = X2 + Y2;
FREQUENCY1 = 1000000/TIME1;
FREQUENCY2 = 1000000/TIME2;
//Frequency (Hz) = 7.5 * Flow rate (L/min)

WATER1 = FREQUENCY1/7.5;
LS1 = WATER1/60;
TOTAL1 =(TOTAL1 + LS1);

WATER2 = FREQUENCY2/7.5;
LS2 = WATER2/(60);

TOTAL2 =(TOTAL2 + LS2);

digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;
delay(500);

Serial.print(LS1);
Serial.print("     ");
Serial.println(LS2);
Serial.print("Distance: ");
Serial.print("     ");
Serial.println(distance);
if(distance>20)
Serial.println("Low Water Level");
int temp = 0;
/*while((TOTAL1 - TOTAL2)> 0.05 && temp<10)
{ delay(1000); 
  temp++;
}
if(temp>=10)
Serial.println("Leakage detected");
*/
Serial.println(LS1 - LS2);
if((LS1 - LS2)< -0.05 )
Serial.println("Leakage detected");

}