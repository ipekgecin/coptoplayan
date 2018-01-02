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
  int r=0,g=0,b=0;
  for(int i=0;i<3;i++){
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
    r=redFrequency+r;
    b=blueFrequency+b;
    g=greenFrequency+g;
  }
  r=r/3;
  g=g/3;
  b=b/3;
  Serial.print("R=");
  Serial.print(r);
  Serial.print(" G=");
  Serial.print(g);
  Serial.print(" B=");
  Serial.print(b);
  Serial.println(" ");
  delay(100);
}

