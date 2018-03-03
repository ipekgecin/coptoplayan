void setup() {
  // put your setup code here, to run once:

}

void yaklas() {

  digitalWrite(sol_motor1, LOW);
  digitalWrite(sol_motor2, HIGH);
  digitalWrite(sag_motor1, LOW);
  digitalWrite(sag_motor2, HIGH);
  analogWrite(sol_pwm, 50);
  analogWrite(sag_pwm, 50);
 
}


void kolindir() {
  
  copal();
  delay(1000);
  for (i=0; i<=150; i++){
  servokol.write(i);
  delay(50);
}





void copbirak() {

  int x = 1;
  int i = 0;
  kuturenk = renkoku(x);
  coprenk = renkoku(i);
  
  if ( coprenk == kuturenk ) {
  
     while (1) {
       yaklas();
       if ( arkamesafe == 13 ) {
     
         fren();
         break;
       }
    }
    kolkaldir(); // LOOPA YAZMAYA GEREK YOK
    delay(3000);
    kolindir();
    kapakac();
    kutuara();//LOOPA YAZMAYA GEREK KALMADI
    }

  else {
    kutuara();
  }
  
}



void loop() {
  // put your main code here, to run repeatedly:

}
