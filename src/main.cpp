#include <Arduino.h>
//Joystick
int Ax = A0;
int Ay = A1;

int Vx = 0;
int Vy = 0;
int Posx = 0;
int Posy = 0;

//Shift Register1
int clearPin = 5;
int serialData = 6;
int shiftClock = 7;
int latchClock = 8;

//Shift Register2
int serialData2 = 9;
int shiftClock2 = 10;
int latchClock2 = 11;


void setup() {
  // Serial.begin(9600);
  //Joystick
  pinMode(Ax, INPUT);
  pinMode(Ay, INPUT);

  //Shift Register
  pinMode(clearPin, OUTPUT);
  pinMode(serialData, OUTPUT);
  pinMode(shiftClock, OUTPUT);
  pinMode(latchClock, OUTPUT);

  //Shift Register2
  pinMode(serialData2, OUTPUT);
  pinMode(shiftClock2, OUTPUT);
  pinMode(latchClock2, OUTPUT);

  digitalWrite(clearPin, LOW);
  digitalWrite(clearPin, HIGH);
}


void loop() {
  //Joystick
  Vx = analogRead(Ax);
  Vy = analogRead(Ay);

  Posx = map(Vx, 0, 1023, -512, 512);
  Posy = map(Vy, 0, 1023, 512, -512);
  // Serial.print("X: ");
  // Serial.println(Posx);
  // Serial.print("Y: ");
  // Serial.println(Posy);

  

  //Shift Register 1
  if (-512 <= Posx && Posx <= -384 ){
    digitalWrite(latchClock, LOW);
    shiftOut(serialData, shiftClock, MSBFIRST, 128);
    digitalWrite(latchClock, HIGH);
  }
  if (-384 <= Posx && Posx <= -256 ){
  digitalWrite(latchClock, LOW);
  shiftOut(serialData, shiftClock, MSBFIRST, 128>>1);
  digitalWrite(latchClock, HIGH);
  }
  if (-256 <= Posx && Posx <= -128 ){
  digitalWrite(latchClock, LOW);
  shiftOut(serialData, shiftClock, MSBFIRST, 128>>2);
  digitalWrite(latchClock, HIGH);
  }
  if (-128 <= Posx && Posx <= 128 ){
  digitalWrite(latchClock, LOW);
  shiftOut(serialData, shiftClock, MSBFIRST, 192>>3);
  digitalWrite(latchClock, HIGH);
  }
  if (128 <= Posx && Posx <= 256 ){
  digitalWrite(latchClock, LOW);
  shiftOut(serialData, shiftClock, MSBFIRST, 128>>5);
  digitalWrite(latchClock, HIGH);
  }
  if (256 <= Posx && Posx <= 384 ){
  digitalWrite(latchClock, LOW);
  shiftOut(serialData, shiftClock, MSBFIRST, 128>>6);
  digitalWrite(latchClock, HIGH);
  }
  if (384 <= Posx && Posx <= 512 ){
  digitalWrite(latchClock, LOW);
  shiftOut(serialData, shiftClock, MSBFIRST, 128>>7);
  digitalWrite(latchClock, HIGH);
  }

  // digitalWrite(latchClock, LOW);
  // shiftOut(serialData, shiftClock, MSBFIRST, 255);
  // digitalWrite(latchClock, HIGH);


  //shift register 2 Columns
  if (-512 <= Posy && Posy <= -384 ){
    digitalWrite(latchClock2, LOW);
    shiftOut(serialData2, shiftClock2, MSBFIRST, ~128);
    digitalWrite(latchClock2, HIGH);
  }
  if (-384 <= Posy && Posy <= -256 ){
  digitalWrite(latchClock2, LOW);
  shiftOut(serialData2, shiftClock2, MSBFIRST, ~128>>1);
  digitalWrite(latchClock2, HIGH);
  }
  if (-256 <= Posy && Posy <= -128 ){
  digitalWrite(latchClock2, LOW);
  shiftOut(serialData2, shiftClock2, MSBFIRST, ~128>>2);
  digitalWrite(latchClock2, HIGH);
  }
  if (-128 <= Posy && Posy <= 128 ){
  digitalWrite(latchClock2, LOW);
  shiftOut(serialData2, shiftClock2, MSBFIRST, ~192>>3);
  digitalWrite(latchClock2, HIGH);
  }
  if (128 <= Posy && Posy <= 256 ){
  digitalWrite(latchClock2, LOW);
  shiftOut(serialData2, shiftClock2, MSBFIRST, ~128>>5);
  digitalWrite(latchClock2, HIGH);
  }
  if (256 <= Posy && Posy <= 384 ){
  digitalWrite(latchClock2, LOW);
  shiftOut(serialData2, shiftClock2, MSBFIRST, ~128>>6);
  digitalWrite(latchClock2, HIGH);
  }
  if (384 <= Posy && Posy <= 512 ){
  digitalWrite(latchClock2, LOW);
  shiftOut(serialData2, shiftClock2, MSBFIRST, ~128>>7);
  digitalWrite(latchClock2, HIGH);
  }


}