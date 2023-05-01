int M1A=PD2; //PWM
int M1B=PD3; //PWM
int M1C=A0;
int M1D=A1;

int M2A=PD4; //PWM
int M2B=PD5; // PWM
int M2C=A2;
int M2D=A3;

int ch1 = PD6;
int ch3 = PD7;
int ch5 = MOSI;

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> 
#endif
#define PIN MISO
#define NUMPIXELS 18 
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 50

void setup(){
Serial.begin(9600);
//MOTOR1
pinMode(PD2, OUTPUT);
pinMode(PD3, OUTPUT);
pinMode(A0, OUTPUT);
pinMode(A1, OUTPUT);
digitalWrite(A1, HIGH);
digitalWrite(A0, HIGH);

//MOTOR2
pinMode(PD4, OUTPUT);
pinMode(PD5, OUTPUT);
pinMode(A2, OUTPUT);
pinMode(A3, OUTPUT);
digitalWrite(A2, HIGH);
digitalWrite(A3, HIGH);

//led ouputs
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  pixels.begin(); 
for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(51, 102, 255));
    pixels.show();   
    delay(DELAYVAL);  
  }

}

void loop()
{
ch5 = pulseIn(MOSI,LOW);
ch1 = pulseIn(PD6,LOW);
ch3 = pulseIn(PD7,LOW);
if((ch5>1)&&(ch5<8000))
{    
  motor_A1();
  motor_B1();
}
else
{     
  motor_A();
  motor_B();
}
}
void motor_A()
{
if((ch1>900)&&(ch1<1000))
{     
 digitalWrite(M1A,LOW);
 digitalWrite(M1B,LOW);
}
else if((ch1>1500)&&(ch1<7000))
{
  digitalWrite(M1A,LOW);
  analogWrite(M1B, 150);
}

else
{     
  digitalWrite(M1A,LOW);
  digitalWrite(M1B,LOW);

}
}

void motor_A1()
{
if((ch1>900)&&(ch1<1000))
{     
 digitalWrite(M1A,LOW);
 digitalWrite(M1B,LOW);
}
else if((ch1>1500)&&(ch1<7000))
{
  digitalWrite(M1A, HIGH);
  digitalWrite(M1B, LOW);
}

else
{     
  digitalWrite(M1A,LOW);
  digitalWrite(M1B,LOW);

}
}
void motor_B()
{
  //if((ch3>1700)&&(ch3<7000))
  if((ch3>2000)&&(ch3<5000))
{
    
  digitalWrite(M2A,LOW);
  analogWrite(M2B,150);
}
//else if((ch3>9000)&&(ch3<13000))
else 
{
  digitalWrite(M2A,LOW);
    digitalWrite(M2B,LOW);
}

}

void motor_B1()
{
  //if((ch3>1700)&&(ch3<7000))
  if((ch3>2000)&&(ch3<5000))
{
    
  digitalWrite(M2A,HIGH);
  digitalWrite(M2B,LOW);
}
//else if((ch3>9000)&&(ch3<13000))
else 
{
  digitalWrite(M2A,LOW);
    digitalWrite(M2B,LOW);
}

}


