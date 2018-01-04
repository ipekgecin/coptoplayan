#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
int redFrequency=0;
int greenFrequency=0;
int blueFrequency=0;
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}
void loop() {
  findcolor();
}
void findcolor(){
// Setting red filtered photodiodes to be read
  char color;
  int red=0,green=0,blue=0;
  for(int i=0;i<10;i++){
    digitalWrite(S2,LOW);
    digitalWrite(S3,LOW);
    redFrequency = pulseIn(sensorOut, LOW);
    redFrequency = map(redFrequency,35,440,255,0);
    delay(100); 
    digitalWrite(S2,HIGH);
    digitalWrite(S3,HIGH);
    greenFrequency = pulseIn(sensorOut, LOW);
    greenFrequency = map(greenFrequency,35,440,255,0);
    delay(100);
    digitalWrite(S2,LOW);
    digitalWrite(S3,HIGH);
    blueFrequency = pulseIn(sensorOut, LOW);
    blueFrequency = map(blueFrequency,27,350,255,0);
    delay(100);
    red=redFrequency+red;
    blue=blueFrequency+blue;
    green=greenFrequency+green;
  }
  red=red/10;
  green=green/10;
  blue=blue/10;
  //Serial.print("R=");
  //Serial.print(r);
  //Serial.print(" G=");
  //Serial.print(g);
  //Serial.print(" B=");
  //Serial.print(b);
  //Serial.println(" ");
  //delay(100);
  if (red > 8  && red < 18   &&  green >  9 && green < 19    &&  blue > 8  && blue < 16)   color = "WHITE";
  else if (red > 80 && red < 125  &&  green > 90 && green < 125   &&  blue > 80 && blue < 125)  color = "BLACK";
  else if (red > 12 && red < 30   &&  green > 40 && green < 70    &&  blue > 33 && blue < 70)   color = "RED";
  else if (red > 50 && red < 95   &&  green > 35 && green < 70    &&  blue > 45 && blue < 85)   color = "GREEN";
  else if (red > 10 && red < 20   &&  green > 10 && green < 25    &&  blue > 20 && blue < 38)   color = "YELLOW";
  else if (red > 65 && red < 125  &&  green > 65 && green < 115   &&  blue > 32 && blue < 65)   color = "BLUE";
  else  color = "NO_COLOR";
  Serial.print(color);
  
}

