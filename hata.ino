#include <Servo.h>
Servo kapak_sag;
Servo kapak_sol;
Servo servokol;

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
//Hazne Mesafe Sensörü
#define hs_echo 32
#define hs_trig 33
//Duvar Mesafe Sensörü
#define dvr_echo 48
#define dvr_trig 49
//Sol ON Mesafe Sensörü
#define solons_echo 34
#define solons_trig 35
//Sol ARKA Mesafe Sensörü
#define solarkas_echo 38
#define solarkas_trig 39
//ARKA Mesafe Sensörü
#define arka_echo 36
#define arka_trig 37
//Motorlar
#define sag_motor1 40 // İLERİ sağ
#define sol_motor2 42 //SOL GERİ
#define sag_pwm 44 // SAG pwm
#define sag_motor2 41 //GERİ sağ
#define sol_motor1 43 //SOL İLERİ
#define sol_pwm 45 //SOL pwm



//SABIT DEGISKENLER
#define pwm 50


int haznesensor() { //TAMAM
  delay(100);
  long sure, mesafe;
  digitalWrite(hs_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(hs_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(hs_trig, LOW);
  sure = pulseIn(hs_echo, HIGH);
  mesafe = (sure / 2) / 29.1;
  if (mesafe > 200 || mesafe < 0) {
    Serial.println("Menzil Disi");
    return -1;
  } else {
    Serial.print("Hazne=");
    Serial.print(mesafe);
    Serial.println(" cm");
    return mesafe;
  }
}
int duvarsensor() { //TAMAM
  delay(100);
  long sure, mesafe;
  digitalWrite(dvr_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(dvr_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(dvr_trig, LOW);
  sure = pulseIn(dvr_echo, HIGH);
  mesafe = (sure / 2) / 29.1;
  if (mesafe > 200 || mesafe < 0) {
    Serial.println("Menzil Disi");
    return -1;
  } 
  else {
    Serial.print("Duvar=");
    Serial.print(mesafe);
    Serial.println(" cm");
    return (int) mesafe;
  }
}
int solonsensor() { //TAMAM
  delay(100);
  long sure, mesafe;
  digitalWrite(solons_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(solons_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(solons_trig, LOW);
  sure = pulseIn(solons_echo, HIGH);
  mesafe = (sure / 2) / 29.1;
  if (mesafe > 200 || mesafe < 0) {
    Serial.println("Menzil Disi");
    return -1;
  } else {
    Serial.print("Sol Ön=");
    Serial.print(mesafe);
    Serial.println(" cm");
    return mesafe;
  }
}
int solarkasensor() { //TAMAM
  delay(100);
  long sure, mesafe;
  digitalWrite(solarkas_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(solarkas_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(solarkas_trig, LOW);
  sure = pulseIn(solarkas_echo, HIGH);
  mesafe = (sure / 2) / 29.1;
  if (mesafe > 200 || mesafe < 0) {
    Serial.println("Menzil Disi");
    return -1;
  } else {
    Serial.print("Sol arka=");
    Serial.print(mesafe);
    Serial.println(" cm");
    return mesafe;
  }
}
int arkasensor() { //TAMAM
  delay(100);
  long sure, mesafe;
  digitalWrite(arka_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(arka_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(arka_trig, LOW);
  sure = pulseIn(arka_echo, HIGH);
  mesafe = (sure / 2) / 29.1;
  if (mesafe > 200 || mesafe < 0) {
    Serial.println("Menzil Disi");
    return -1;
  } else {
    Serial.print("Arka sensor=");
    Serial.print(mesafe);
    Serial.println(" cm");
    return mesafe;
  }
}
void ileri() { //TAMAM
  digitalWrite(sol_motor1, HIGH);
  digitalWrite(sol_motor2, LOW);
  digitalWrite(sag_motor1, HIGH);
  digitalWrite(sag_motor2, LOW);
  analogWrite(sol_pwm, pwm);
  analogWrite(sag_pwm, pwm);
}
void geri() { //TAMAM
  digitalWrite(sol_motor1, LOW);
  digitalWrite(sol_motor2, HIGH);
  digitalWrite(sag_motor1, LOW);
  digitalWrite(sag_motor2, HIGH);
  analogWrite(sol_pwm, pwm);
  analogWrite(sag_pwm, pwm);
}
void dur() { //TAMAM
  digitalWrite(sol_motor1, LOW);
  digitalWrite(sol_motor2, LOW);
  digitalWrite(sag_motor1, LOW);
  digitalWrite(sag_motor2, LOW);
  analogWrite(sol_pwm, 0);
  analogWrite(sag_pwm, 0);
}
void fren() { //TAMAM
  digitalWrite(sol_motor1, !digitalRead(sol_motor1));
  digitalWrite(sol_motor2, !digitalRead(sol_motor2));
  digitalWrite(sag_motor1, !digitalRead(sag_motor1));
  digitalWrite(sag_motor2, !digitalRead(sag_motor2));
  analogWrite(sol_pwm, 200);
  analogWrite(sag_pwm, 200);
  delay(30);
}
void sol() { //TAMAM
  digitalWrite(sol_motor1, LOW);
  digitalWrite(sol_motor2, HIGH);
  digitalWrite(sag_motor1, HIGH);
  digitalWrite(sag_motor2, LOW);
  analogWrite(sol_pwm, pwm);
  analogWrite(sag_pwm, pwm);
  delay(100);
}
void sag() { //TAMAM
  digitalWrite(sol_motor1, HIGH);
  digitalWrite(sol_motor2, LOW);
  digitalWrite(sag_motor1, LOW);
  digitalWrite(sag_motor2, HIGH);
  analogWrite(sol_pwm, pwm);
  analogWrite(sag_pwm, pwm);
  delay(100);
}
void duvartakip(int x) { //TAMAM
  digitalWrite(sol_motor1, LOW);
  digitalWrite(sol_motor2, HIGH);
  digitalWrite(sag_motor1, LOW);
  digitalWrite(sag_motor2, HIGH);
  analogWrite(sol_pwm, pwm - x);
  analogWrite(sag_pwm, pwm + x);
}
void tara() {
  if (haznesensor() - duvarsensor() >= 8) { //ÇÖP VAR
    fren();
    //Kapaklar kapanacak
    //Rengine bakılacak
    //koşullar ayarlanacak
  } else { //ÇÖP YOK (sanırım tamam)
    if (duvarsensor() <= 15) {
      fren();
      while (solonsensor() - solarkasensor() > 2 && duvarsensor() <= 15)

        sag();
      ileri();
      delay(200);
      fren();
      sag();
    } else {
      ileri();
    }
  }
}
void duvarayaklas() {
  digitalWrite(sol_motor1, LOW);
  digitalWrite(sol_motor2, HIGH);
  digitalWrite(sag_motor1, LOW);
  digitalWrite(sag_motor2, HIGH);
  analogWrite(sol_pwm, pwm);
  analogWrite(sag_pwm, pwm + 50);
  delay(100);
}
void copal() {

}
void copat() { //DÜŞÜNMEK GEREK
  if (arkasensor() > 15) {
    if (solonsensor() <= 15 && solarkasensor() <= 15) {
      int fark = solonsensor() - solarkasensor();
      fark = fark * 10;
      duvartakip(fark);
    } else if (solonsensor() > 15 && solarkasensor() > 15 && solonsensor() < 30 && solarkasensor() < 30) {
      duvarayaklas();
      Serial.print("Duvara yaklaş");
    }
    else {
      geri();
      delay(1000);
      Serial.println("Else");
    }
    if (solonsensor() <= 15) {
      if (solonsensor() > 10 && solarkasensor() > 10 && solonsensor() <= 20 && solarkasensor() <= 20) {
        sol();
        delay(200);
      } else if (solarkasensor() - solonsensor() > 10) {
        geri();
        delay(100);
        sag();
        geri();
        delay(100);
      }
    }
  }
}
  void setup() {
    
    kapak_sag.attach(46);
    kapak_sag.write(0); // servo kapağın ilk pozisyonu
    kapak_sol.attach(47);
    kapak_sol.write(180); // servo kapağın ilk pozisyonu
    servokol.attach(51);
    servokol.write(0);  // servonun ilk pozisyon açısı

    pinMode(sag_pwm, OUTPUT);
    pinMode(sag_motor1, OUTPUT);
    pinMode(sag_motor2, OUTPUT);
    pinMode(sol_pwm, OUTPUT);
    pinMode(sol_motor1, OUTPUT);
    pinMode(sol_motor2, OUTPUT);

    pinMode(solons_trig, OUTPUT);
    pinMode(solons_echo, INPUT);
    pinMode(solarkas_trig, OUTPUT);
    pinMode(solarkas_echo, INPUT);
    pinMode(arka_trig, OUTPUT);
    pinMode(arka_echo, INPUT);
    pinMode(hs_trig, OUTPUT);
    pinMode(hs_echo, INPUT);
    pinMode(dvr_trig, OUTPUT);
    pinMode(dvr_echo, INPUT);

    pinMode(ks_S0, OUTPUT);
    pinMode(ks_S1, OUTPUT);
    pinMode(ks_S2, OUTPUT);
    pinMode(ks_S3, OUTPUT);
    pinMode(ks_SOut, INPUT);
    digitalWrite(ks_S0, HIGH);
    digitalWrite(ks_S1, LOW);
    pinMode(hs_S0, OUTPUT);
    pinMode(hs_S1, OUTPUT);
    pinMode(hs_S2, OUTPUT);
    pinMode(hs_S3, OUTPUT);
    pinMode(hs_SOut, INPUT);
    digitalWrite(hs_S0, HIGH);
    digitalWrite(hs_S1, LOW);

    
  }

  void loop() {
  copat();
    //  if (durum==0){
    //çöparama, bulursa durum 1 e geçecek
    //  }else if(durum==1){
    //çöp atacak kutu bulacak bitirince 3 e ge
    //  }else if(durum==2){
    //çöpü atacak ve sıfırlanıp başa dönecek
    //  }
  }



