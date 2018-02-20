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

//Sağ Mesafe Sensörü

#define sags_echo 34

#define sags_trig 35

//Sol Mesafe Sensörü

#define sols_echo 38

#define sols_trig 39

//Ön Mesafe Sensörü

#define ons_echo 36

#define ons_trig 37

//Motorlar

#define sol_motor1 40

#define sol_motor2 42

#define sol_pwm 44

#define sag_motor1 41

#define sag_motor2 43

#define sag_pwm 45

void setup()
{
  pinMode(sol_motor1, OUTPUT):
  pinMode(sol_motor2, OUTPUT);
  pinMode(sag_motor1, OUTPUT);
  pinMode(sag_motor2, OUTPUT);
  pinMode(sol_pwm,OUTPUT);
  pinMode(sag_pwm,OUTPUT);
  pinMode(sags_echo,INPUT);
  pinMode(sags_trig,OUTPUT);
  pinMode(sols_echo,INPUT);
  pinMode(sols_trig,OUTPUT); 
  int hizmax;
  int kp = x ; //bunlar eklenecek
  int ki = x ;
  int kd = x ;
  int sure;
  int solmesafe;
  int sagmesafe;
  sol_hiz = x // buraya başlangıç değeri girilecek
  sag_hiz = y // buraya başlangıç değeri girilecek

}
void copuatma()
{
  
  
  digitalWrite(sol_motor1,HIGH) ;  //motorlara pid kontrolünde verilen hız
  digitalWrite(sol_motor2,LOW) ;
  analogWrite(sol_pwm,sol_hiz) ;
  
  digitalWrite(sag_motor1,HIGH) ;  
  digitalWrite(sag_motor2,LOW) ;
  analogWrite(sag_pwm,sag_hiz) ;
  
  soltakip();
  
}


int mesafeokuma()  //--- mesafe okuma
{  
  digitalWrite(sags_trig,HIGH);
  delay(10);
  digitalWrite(sags_trig,LOW);
  sure = pulseIn(sags_echo, HIGH);
  solmesafe = sure /29.1/2;
  digitalWrite(sols_trig,HIGH);
  delay(10);
  digitalWrite(sols_trig,LOW);
  sure=pulseIn(sols_echo,HIGH);
  sagmesafe = sure /29.1/2;
  delay(10);
  return solmesafe,sagmesafe;
  }

int pid(int solmesafe) 
  int ideal
  float pidTerm;
  int hata;
  static int son_hata;
  static int toplam_hata;
  hata = ideal - mesafe;
  toplam_hata += hata;
  pidTerm = (hata) * kp + (hata - son_hata) * kd + toplam_hata * ki;
  son_hata = hata;
  return (int(pidTerm));
}

void soltakip()
{
    if( pid < -hizmax)           // pid değerinin fazla yükselmesini veya fazla azalmasını engellemek için
    {
    pid = -hizmax;
    
  }
    if( pid > hizmax)
  {
    pid = hizmax;
    
  }

    if(pid < 0 ) //mesafe > ideal   
    {
		abs(pid);	
    sol_hiz = sol_hiz + pid;
    sag_hiz = sag_hiz - pid;
    }
    else if(pid > 0) // mesafe < ideal
    {
		abs(pid);
    sol_hiz = sol_hiz - pid;
    sag_hiz = sag_hiz + pid;
    
}
    else
    {
    sol_hiz = sol_hiz + pid; //boş kalırsa sıkıntı olur mu karar veremedik
    sag_hiz = sag_hiz + pid;
    }

  
}
