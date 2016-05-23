#define air_pin1 8
#define air_pin2 9
#define motor_pin1 10
#define motor_pin2 11
// the setup function runs once when you press reset or power the board
int AIR = 0;
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(air_pin1, OUTPUT);
  pinMode(air_pin2, OUTPUT);
  pinMode(motor_pin1, OUTPUT);
  pinMode(motor_pin2, OUTPUT);
  Serial.begin(9600);
  digitalWrite(air_pin1, LOW);
  delay(100);
  digitalWrite(air_pin1, HIGH);
  delay(100);
  digitalWrite(air_pin2, LOW);
  delay(100);
  digitalWrite(air_pin2, HIGH);
  delay(100);
  digitalWrite(motor_pin1, HIGH);
  delay(100);
  digitalWrite(motor_pin1, LOW);
  delay(100);
  digitalWrite(motor_pin2, HIGH);
  delay(100);
  digitalWrite(motor_pin2, LOW);
  delay(100);
  AIR = analogRead(A0);
  Serial.println(AIR);
  AIR = analogRead(A0);
  Serial.println(AIR);
  AIR = analogRead(A0);
  Serial.println(AIR);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(motor_pin1, HIGH);
  digitalWrite(air_pin1, LOW);
  digitalWrite(air_pin2, HIGH);
  AIR = analogRead(A0);
  
  while (AIR > 100) {//負壓50
    AIR = analogRead(A0);
    Serial.println(AIR);
  }
  
  //delay(5000);
  digitalWrite(motor_pin1, LOW);
  digitalWrite(air_pin1, HIGH);
  digitalWrite(air_pin2, HIGH);
  delay(3000);
  digitalWrite(air_pin1, LOW);
  digitalWrite(air_pin2, LOW);
  delay(1000);
  digitalWrite(motor_pin2, HIGH);
  digitalWrite(air_pin2, LOW);
  digitalWrite(air_pin1, HIGH);
  AIR = analogRead(A0);
  while (AIR < 600) {//正壓600
    AIR = analogRead(A0);
    Serial.println(AIR);
  }
  digitalWrite(motor_pin2, LOW);
  digitalWrite(air_pin1, HIGH);
  digitalWrite(air_pin2, HIGH);
  delay(3000);
  digitalWrite(air_pin1, LOW);
  digitalWrite(air_pin2, LOW);
  delay(1000);
}


void Read_A0() {
  Serial.print("sensor = " );
  Serial.println(analogRead(A0));

}
