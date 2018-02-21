#define solon_echo 34
#define solon_trig 35
//Sol ARKAMesafe Sensörü
#define solarka_echo 38 
#define solarka_trig 39
//Ön Mesafe Sensörü
#define ons_echo 36
#define ons_trig 37
//Motorlar
#define sol_motor1 40 // İLERİ sağ
#define sol_motor2 42 //SOL GERİ
#define sol_pwm 44 // SAG pwm
#define sag_motor1 41 //GERİ sağ
#define sag_motor2 43 //SOL İLERİ
#define sag_pwm 45 //SOL pwm
#define pwm 50
void setup(){
  pinMode(sag_pwm,OUTPUT);
  pinMode(sag_motor1,OUTPUT);
  pinMode(sag_motor2,OUTPUT);
  pinMode(sol_pwm,OUTPUT);
  pinMode(sol_motor1,OUTPUT);
  pinMode(sol_motor2,OUTPUT);                         //for motor driver with 2 dir pins
  pinMode(solon_trig,OUTPUT);
  pinMode(solon_echo,INPUT);
  pinMode(solarka_trig,OUTPUT);
  pinMode(solarka_echo,INPUT);
  Serial.begin(9600);
}
int solonsensor(){
  long sure, mesafe;
  digitalWrite(solon_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(solon_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(solon_trig, LOW);
  sure = pulseIn(solon_echo, HIGH);
  mesafe = (sure/2) / 29.1;
  if (mesafe > 200 || mesafe < 0){
  Serial.println("Menzil Disi");
  }
  else {
  Serial.print(mesafe);
  Serial.println(" cm");
  return mesafe;
  }
}
int solarkasensor(){
  long sure, mesafe;
  digitalWrite(solarka_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(solarka_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(solarka_trig, LOW);
  sure = pulseIn(solarka_echo, HIGH);
  mesafe = (sure/2) / 29.1;
  if (mesafe > 200 || mesafe < 0){
  Serial.println("Menzil Disi");
  }
  else {
  Serial.print(mesafe);
  Serial.println(" cm");
  return mesafe;
  }
delay(500);
}
void ileri(int x)
{
  digitalWrite(sol_motor1, LOW);
  digitalWrite(sol_motor2, HIGH);
  digitalWrite(sag_motor1, LOW);
  digitalWrite(sag_motor2, HIGH);
  analogWrite(sol_pwm,pwm-x);
  analogWrite(sag_pwm,pwm+x);
}
void loop(){
  if (solonsensor()<=15){
    int fark= solonsensor()-solarkasensor();
    fark=fark*10;
    ileri(fark);
  }else{
 
        digitalWrite(sol_motor1, LOW);
        digitalWrite(sol_motor2, HIGH);
        digitalWrite(sag_motor1, LOW);
        digitalWrite(sag_motor2, HIGH);
        analogWrite(sol_pwm,50);
        analogWrite(sag_pwm,150);
        delay(100);
    }
  
}
