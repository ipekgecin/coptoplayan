#define sags_echo 34
#define sags_trig 35
//Sol ARKAMesafe Sensörü
#define sols_echo 38 
#define sols_trig 39
//Ön Mesafe Sensörü
#define ons_echo 36
#define ons_trig 37
//Motorlar
#define sag_motor1 40 // İLERİ sağ
#define sol_motor2 42 //SOL GERİ
#define sag_pwm 44 // SAG pwm
#define sag_motor2 41 //GERİ sağ
#define sol_motor1 43 //SOL İLERİ
#define sol_pwm 45 //SOL pwm
#define pwm 50
void setup(){
  pinMode(sag_pwm,OUTPUT);
  pinMode(sag_motor1,OUTPUT);
  pinMode(sag_motor2,OUTPUT);
  pinMode(sol_pwm,OUTPUT);
  pinMode(sol_motor1,OUTPUT);
  pinMode(sol_motor2,OUTPUT);                         //for motor driver with 2 dir pins
  pinMode(sags_trig,OUTPUT);
  pinMode(sags_echo,INPUT);
  pinMode(sols_trig,OUTPUT);
  pinMode(sols_echo,INPUT);
  Serial.begin(9600);
}
int solonsensor(){
  long sure, mesafe;
  digitalWrite(sags_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(sags_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sags_trig, LOW);
  sure = pulseIn(sags_echo, HIGH);
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
  digitalWrite(sols_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(sols_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sols_trig, LOW);
  sure = pulseIn(sols_echo, HIGH);
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
