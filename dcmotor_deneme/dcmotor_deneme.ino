//Motorlar
#define sol_motor1 40
#define sol_motor2 42
#define sol_pwm 44
#define sag_motor1 41
#define sag_motor2 43
#define sag_pwm 45

void setup() {
  // put your setup code here, to run once:

}


void dur()
{
  digitalWrite(sol_motor1, HIGH);
  digitalWrite(sol_motor2, HIGH);
  digitalWrite(sag_motor1, HIGH);
  digitalWrite(sag_motor2, HIGH);
  delay(1000);
}
void ileri()
{
  digitalWrite(sol_motor1, HIGH);
  digitalWrite(sol_motor2, LOW);
  digitalWrite(sag_motor1, HIGH);
  digitalWrite(sag_motor2, LOW);
  delay(1000);
  analogWrite(sol_pwm, 125);
  analogWrite(sag_pwm, 125);
}
void soladon()
{
  digitalWrite(sol_motor1, LOW);
  digitalWrite(sol_motor2, HIGH);
  digitalWrite(sag_motor1, HIGH);
  digitalWrite(sag_motor2, LOW);
  delay(400);
  digitalWrite(sol_pwm, HIGH);
  digitalWrite(sag_pwm, HIGH);
}
void sagadon()
{
  digitalWrite(sol_motor1, HIGH);
  digitalWrite(sol_motor2, LOW);
  digitalWrite(sag_motor1, LOW);
  digitalWrite(sag_motor2, HIGH);
  delay(400);
  digitalWrite(sol_pwm, HIGH);
  digitalWrite(sag_pwm, HIGH);
}
void loop() {
  // put your main code here, to run repeatedly:
 ileri();
 dur();
 soladon();
 ileri();
 dur();
 sagadon();
 ileri();
 dur();
}
