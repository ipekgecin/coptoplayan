//Sağ mesafe sensörü
#define sags_echo 34
#define sags_trig 35
//Sol Mesafe Sensörü
#define sols_echo 36
#define sols_trig 37
//motorlar
#define sol_motor1 40
#define sol_motor2 42
#define sol_pwm 44
#define sag_motor1 41
#define sag_motor2 43
#define sag_pwm 45
byte PWMA = 9; 
byte AIN1 = 7; 
byte AIN2 = 8; 
 
byte sec;
float byteRead;
float kd;
float kp;                                                                                                                                                                                                                                                                                                                        
float ki;
 
float ideal;
long sure;
long mesafe;
int pwm;
 
void setup() {
  Serial.begin(9600);
  digitalWrite(sags_trig,LOW);
 
}
 
void loop() {
  /*
  bu kısım serial monitorden kp, kd ve ki katsayılarını
   değiştirmemizi sağlıyor. kp için p, kd için d, ki için i
   yazıp ardından değeri girip enter tuşuna bastığımızda yazdığımız
   değer geçerli oluyor(girdiğimiz değer 100 bölünüyor)
   */
  while (Serial.available()) {
    byteRead = Serial.read();
    if (byteRead == 112) {
      sec = 1;
      kp = 0;
    }
    else if (byteRead == 100) {
      sec = 0;
      kd = 0;
    }
    else if (byteRead == 105) {
      sec = 2;
      ki = 0;
    }
 
    if (sec == 1) {
      if (byteRead > 47 && byteRead < 58) {
        kp = (kp * 10) + (byteRead - 48) / 100;
      }
    }
    else if (sec == 0) {
      if (byteRead > 47 && byteRead < 58) {
        kd = (kd * 10) + (byteRead - 48) / 100;
      }
    }
    else if (sec == 2) {
      if (byteRead > 47 && byteRead < 58) {
        ki = (ki * 10) + (byteRead - 48)/100;
 
      }
    }
  }
  //sensör değerleri okunuyor
  digitalWrite(sags_trig,HIGH);
  delay(10);
  digitalWrite(sags_trig,LOW);
  sure = pulseIn(sags_echo, HIGH);
  mesafe = sure /29.1/2;
  Serial.print("Uzaklık = ");
  Serial.println(mesafe);
  delay(10);
  ideal=10;
 
  //pid kontrol ile pwm hesaplanıyor
  pwm += pid(ideal, mesafe);
  pwm = constrain(pwm, -255, 255);
  don(pwm);
  delay(20);
 
  //bilgiler ekrana yazdırılıyor
  Serial.print(mesafe);
  Serial.print(" ");
  Serial.print(ideal);
  Serial.print(" ");
  Serial.print(pwm);
  Serial.print("   ");
  Serial.print(kp);
  Serial.print(" ");
  Serial.print(kd);
  Serial.print(" ");
  Serial.println(ki);
 
}
 
 
//motoru sürmek için
void don(int hiz){
 
  boolean inPin1;
  boolean inPin2;
  boolean inPin3;
  boolean inPin4;
  if(hiz<0){
    inPin1 = 0;
    inPin2 = 1;
  }
  else {
    inPin1 = 0;
    inPin2 = 1;
  }
 
  hiz=abs(hiz);
  digitalWrite(sol_motor1, inPin1);
  digitalWrite(sol_motor2, inPin2);
  analogWrite(sol_pwm, hiz);
  digitalWrite(sag_motor1, !inPin1);
  digitalWrite(sag_motor2, !inPin2);
  analogWrite(sag_pwm, hiz);
}
 
//pid hesabı
int pid(int hedef_dgr, int dgr) {
  float pidTerm;
  int hata;
  static int son_hata;
  static int toplam_hata;
  hata = hedef_dgr - dgr;
  toplam_hata += hata;
  pidTerm = (hata) * kp + (hata - son_hata) * kd + toplam_hata * ki;
  son_hata = hata;
  return (int(pidTerm));
}
