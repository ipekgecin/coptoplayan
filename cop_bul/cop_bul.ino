#include <Servo.h>
Servo kapak_serv;
//Hazne Renk Sensörü
#define hs_S0 22
#define hs_S1 24
#define hs_S2 26
#define hs_S3 28
#define hs_SOut 30
//Çöp Kutu Renk Sensörü
#define ks_S0 23
#define ks_S1 25
#define ks_S2 27
#define ks_S3 29
#define ks_SOut 31
//Duvar Mesafe Sensörü
#define dvr_echo 48
#define dvr_trig 49
//Hazne Mesafe Sensörü
#define hs_echo 32
#define hs_trig 33
//Sağ Mesafe Sensörü
#define sags_echo 34
#define sags_trig 35
//Sol Mesafe Sensörü
#define sols_echo 36
#define sols_trig 37
//Ön Mesafe Sensörü
#define ons_echo 38
#define ons_trig 39
//Motorlar
#define sol_motor1 40
#define sol_motor2 42
#define sol_pwm 44
#define sag_motor1 41
#define sag_motor2 43
#define sag_pwm 45

int redFrequency=0;
int greenFrequency=0;
int blueFrequency=0;


int sure_hs;
int mesafe_hs;
int sure_dvr;
int mesafe_dvr;

//--------------------------------------------------------------------------Motor Hareketleri
void dur()
{
digitalWrite(sol_motor1,LOW);
digitalWrite(sol_motor2,LOW);
digitalWrite(sag_motor1,LOW);
digitalWrite(sag_motor2,LOW);
}
void ileri()
{
  digitalWrite(sol_motor1,HIGH);
  digitalWrite(sol_motor2,LOW);
  digitalWrite(sag_motor1,HIGH);
  digitalWrite(sag_motor2,LOW);
}
void soladon()
{
digitalWrite(sol_motor1,LOW);
digitalWrite(sol_motor2,HIGH);
digitalWrite(sag_motor1,HIGH);
digitalWrite(sag_motor2,LOW);
}
void sagadon()
{
  digitalWrite(sol_motor1,HIGH);
  digitalWrite(sol_motor2,LOW);
  digitalWrite(sag_motor1,LOW);
  digitalWrite(sag_motor2,HIGH);
}
//----------------------------------------------------------------Mesafe ölçümü
int cope_mesafe(){
digitalWrite(hs_trig,HIGH);
delay(10);
digitalWrite(hs_trig,LOW);
digitalWrite(hs_trig,LOW);
sure_hs=pulseIn(hs_echo,HIGH);
mesafe_hs=sure_hs /29.1/2;
}
int duvar_mesafe(){
digitalWrite(dvr_trig,HIGH);
delay(10);
digitalWrite(dvr_trig,LOW);
digitalWrite(dvr_trig,LOW);
sure_dvr=pulseIn(dvr_echo,HIGH);
mesafe_dvr=sure_dvr /29.1/2;
}
//-----------------------------------------------------------------Çöp bul
void cop_bul(){
  ileri();
  int duvar_mesafe();
  if (mesafe_dvr <= 16 || mesafe_hs>10){
    void sagadon();
    void ileri();
    delay(5000);
    void sagadon();
    void cop_bul();
    }
    else if(mesafe_dvr<= 16 || mesafe_hs<=10){
      cop_al();
      }
      else if(mesafe_dvr> 16 || mesafe_hs>10){
      cop_bul();
      }
      else if(mesafe_dvr> 16 || mesafe_hs<=10){
      cop_al();
      }
      else{
        ileri();
        }
}
//--------------------------------------------------------------------Çöp al
void cop_al(){
kapak_serv.write(10);
delay(1000);
}
//----------------------------------------------------------------------Çöp renk oku
void find_copcolor(){
// Setting red filtered photodiodes to be read
  char color;
  int red=0,green=0,blue=0;
  for(int i=0;i<10;i++){
    digitalWrite(hs_S2,LOW);
    digitalWrite(hs_S3,LOW);
    redFrequency = pulseIn(hs_SOut, LOW);
    redFrequency = map(redFrequency,35,440,255,0);
    delay(100); 
    digitalWrite(hs_S2,HIGH);
    digitalWrite(hs_S3,HIGH);
    greenFrequency = pulseIn(hs_SOut, LOW);
    greenFrequency = map(greenFrequency,35,440,255,0);
    delay(100);
    digitalWrite(hs_S2,LOW);
    digitalWrite(hs_S3,HIGH);
    blueFrequency = pulseIn(hs_SOut, LOW);
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
void setup() {
  // put your setup code here, to run once:
  kapak_serv.attach(46);
  kapak_serv.write(10);
}

void loop() {
  // put your main code here, to run repeatedly:

}
