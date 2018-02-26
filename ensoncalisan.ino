//Sol ON Mesafe Sensörü
#define solons_echo 35
#define solons_trig 34
//Sol ARKA Mesafe Sensörü
#define solarkas_echo 38
#define solarkas_trig 39
//Hazne Mesafe Sensörü
#define hs_echo 32
#define hs_trig 33
//Duvar Mesafe Sensörü
#define dvr_echo 48
#define dvr_trig 49
//ARKA Mesafe Sensörü
#define arka_echo 36
#define arka_trig 37
//Motorlar
#define sag_motor1 42 // İLERİ sağ
#define sag_motor2 40 //GERİ sağ
#define sag_pwm 44 // SAG pwm
#define sol_motor1 43 //SOL İLERİ
#define sol_motor2 41 //SOL GERİ
#define sol_pwm 45 //SOL pwm


#define pwm 60
#define kp 8
#define ideal 10
unsigned long t = 0;
int fark;
int fark2 = 0;
int kd = 1;
int hata = 0;

void duvartakip(int x)
{
  digitalWrite(sol_motor1, LOW);
  digitalWrite(sol_motor2, HIGH);
  digitalWrite(sag_motor1, LOW);
  digitalWrite(sag_motor2, HIGH);
  analogWrite(sol_pwm, pwm - x);
  analogWrite(sag_pwm, pwm + x);//+ 5 i sildik 20.05
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
  analogWrite(sol_pwm, pwm-5);
  analogWrite(sag_pwm, pwm-5);
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

void duvarayaklas(int x) {
  digitalWrite(sol_motor1, HIGH);
  digitalWrite(sol_motor2, LOW);
  digitalWrite(sag_motor1, HIGH);
  digitalWrite(sag_motor2, LOW);
  analogWrite(sol_pwm, pwm - x);
  analogWrite(sag_pwm, pwm + x);//+ 5 i sildik 20.05
}
int haznesensor() { //TAMAM
  delay(10);
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
  } else {
    Serial.print("Hazne=");
    Serial.print(mesafe);
    Serial.println(" cm");
    return mesafe;
  }
}
int duvarsensor() { //TAMAM
  delay(10);
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
  } else {
    Serial.print("Duvar=");
    Serial.print(mesafe);
    Serial.println(" cm");
    return mesafe;
  }
}
int arkasensor() { //TAMAM
  delay(10);
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
  } else {
    Serial.print("Arka sensor=");
    Serial.print(mesafe);
    Serial.println(" cm");
    return mesafe;
  }
}
int solonsensor() { //TAMAM
  delay(10);
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
  } else {
    Serial.print("Sol Ön=");
    Serial.print(mesafe);
    Serial.println(" cm");
    return mesafe;
  }
}
int solarkasensor() { //TAMAM
  delay(10);
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
  } else {
    Serial.print("Sol arka=");
    Serial.print(mesafe);
    Serial.println(" cm");
    return mesafe;
  }
}
void copat() {
  int arka = arkasensor();
  if (arka <= 13) {
    fren();
    while (1) {
      sol();
      if ((solonsensor - solarkasensor() < 2)||(solarkasensor()-solonsensor()<2)) {
        sol();
        delay(400);
        fren();
        dur();
        delay(250);

        if ((solonsensor() - solarkasensor() < 5) && !(arkasensor() < 10) && (solarkasensor() < 15) && (solonsensor() < 15)) {
        break;
    }
        
    } 
  }
} else {
  if (solarkasensor() <= ideal) {
      fark = solarkasensor() - solonsensor();
      fark = fark * kp;
      duvartakip(fark);
    } else {
      t = millis();
      fark =  ideal - solarkasensor();
      hata = (fark2) * 5 + kd * ((fark - fark2) / t);
      fark2 = fark;
      duvartakip(-hata);
      //delay(100);
      //duvarayaklas(-hata);
      //delay(25);
    }
  }

}
void setup() {
  pinMode(sag_pwm, OUTPUT);
  pinMode(sag_motor1, OUTPUT);
  pinMode(sag_motor2, OUTPUT);
  pinMode(sol_pwm, OUTPUT);
  pinMode(sol_motor1, OUTPUT);
  pinMode(sol_motor2, OUTPUT);                        //for motor driver with 2 dir pins
  pinMode(hs_trig, OUTPUT);
  pinMode(hs_echo, INPUT);
  pinMode(dvr_trig, OUTPUT);
  pinMode(dvr_echo, INPUT);
  pinMode(arka_trig, OUTPUT);
  pinMode(arka_echo, INPUT);

  pinMode(solons_trig, OUTPUT);
  pinMode(solons_echo, INPUT);
  pinMode(solarkas_trig, OUTPUT);
  pinMode(solarkas_echo, INPUT);

  Serial.begin(9600);
}
void loop() {
  copat();
}
