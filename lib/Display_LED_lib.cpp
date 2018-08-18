
#include "Display_LED_lib.h"

Display_LED_lib::Display_LED_lib(bool displayMsg) {
  // Anything you need when instantiating your object goes here
  _msg = displayMsg;
}

// this is our 'begin' function
void Display_LED_lib::begin(int baudRate) {
  Serial.begin(baudRate);
  if (_msg) {
    Serial.println("TestLib constructor instantiated (created) successfully.");
  }
}


//setup
void Display_LED_lib::Ledmode_setup()
{
//LED Outputs
  for (int thisPin = 0; thisPin < _pinCount; thisPin++)
  {
    pinMode(_ledPinsRed[thisPin], OUTPUT);
    pinMode(_ledPinsAmber[thisPin], OUTPUT);
    pinMode(_ledPinsGreen[thisPin], OUTPUT);
  }
}

//1
void Display_LED_lib::Ledmode_alloff()
{
  for (int thisPin = 0; thisPin < _pinCount; thisPin++)
  {
    digitalWrite(_ledPinsRed[thisPin], LOW);
    digitalWrite(_ledPinsAmber[thisPin], LOW);
    digitalWrite(_ledPinsGreen[thisPin], LOW);
  }
}

//2
void Display_LED_lib::Ledmode_allon()
{
  for (int thisPin = 0; thisPin < _pinCount; thisPin++)
  {
    digitalWrite(_ledPinsRed[thisPin], HIGH);
    digitalWrite(_ledPinsAmber[thisPin], HIGH);
    digitalWrite(_ledPinsGreen[thisPin], HIGH);
  }
}

//3
void  Display_LED_lib::Ledmode_redon()
{
  for (int thisPin = 0; thisPin < _pinCount; thisPin++)
  {
    // turn the pin off:
    digitalWrite(_ledPinsRed[thisPin], HIGH);
    digitalWrite(_ledPinsAmber[thisPin], LOW);
    digitalWrite(_ledPinsGreen[thisPin], LOW);
  }
}

//4
void Display_LED_lib::Ledmode_amberon()
{
  for (int thisPin = 0; thisPin < _pinCount; thisPin++)
  {
    // turn the pin off:
    digitalWrite(_ledPinsRed[thisPin], LOW);
    digitalWrite(_ledPinsAmber[thisPin], HIGH);
    digitalWrite(_ledPinsGreen[thisPin], LOW);
  }
}

//5
void Display_LED_lib::Ledmode_greenon()
{
  for (int thisPin = 0; thisPin < _pinCount; thisPin++)
  {
    // turn the pin off:
    digitalWrite(_ledPinsRed[thisPin], LOW);
    digitalWrite(_ledPinsAmber[thisPin], LOW);
    digitalWrite(_ledPinsGreen[thisPin], HIGH);
  }
}

//6
void Display_LED_lib::Ledmode_knightrider()
{
  Ledmode_alloff();
  for (int thisPin = 0; thisPin < _pinCount; thisPin++)
  {
    digitalWrite(_ledPinsRed[thisPin], HIGH);
    mydelay(_period_250);
    // turn the pin off:
    digitalWrite(_ledPinsRed[thisPin], LOW);
  }
  for (int thisPin = 0; thisPin < _pinCount; thisPin++)
  {
    digitalWrite(_ledPinsAmber[thisPin], HIGH);
   mydelay(_period_250);
    // turn the pin off:
    digitalWrite(_ledPinsAmber[thisPin], LOW);
  }
  for (int thisPin = 0; thisPin < _pinCount; thisPin++)
  {
    digitalWrite(_ledPinsGreen[thisPin], HIGH);
    mydelay(_period_250);
    // turn the pin off:
    digitalWrite(_ledPinsGreen[thisPin], LOW);
  }

}

//7
void Display_LED_lib::Ledmode_knightrider_2()
{
  Ledmode_alloff();
  for (int thisPin = 0; thisPin < _pinCount; thisPin++)
  {
    digitalWrite(_ledPinsRed[thisPin], HIGH);
    mydelay(_period_250);
  }
  for (int thisPin = 0; thisPin < _pinCount; thisPin++)
  {
    digitalWrite(_ledPinsAmber[thisPin], HIGH);
    mydelay(_period_250);
  }
  for (int thisPin = 0; thisPin < _pinCount; thisPin++)
  {
    digitalWrite(_ledPinsGreen[thisPin], HIGH);
    mydelay(_period_250);
  }
}

//8
void Display_LED_lib::Ledmode_knightrider_3()
{
  Ledmode_alloff();
  for (int thisPin = 0; thisPin < _pinCount; thisPin++)
  {
    digitalWrite(_ledPinsRed[thisPin], HIGH);
    digitalWrite(_ledPinsAmber[thisPin], HIGH);
    digitalWrite(_ledPinsGreen[thisPin], HIGH);
    mydelay(_period_250);
  }
}

//9
void Display_LED_lib::Ledmode_knightrider_4()
{
  Ledmode_alloff();
  for (int thisPin = 0; thisPin < _pinCount; thisPin++)
  {
    digitalWrite(_ledPinsRed[thisPin], HIGH);
    digitalWrite(_ledPinsAmber[thisPin], HIGH);
    digitalWrite(_ledPinsGreen[thisPin], HIGH);
    mydelay(_period_250);
    digitalWrite(_ledPinsRed[thisPin], LOW);
    digitalWrite(_ledPinsAmber[thisPin], LOW);
    digitalWrite(_ledPinsGreen[thisPin], LOW);
  }
}

//10
void Display_LED_lib::Ledmode_trafficlight()
{
  Ledmode_alloff();
  Ledmode_greenon();
  mydelay(_period_7000);
  Ledmode_amberon();
  mydelay(_period_4000);
  Ledmode_redon();
  mydelay(_period_7000);
}

//11
void Display_LED_lib::Ledmode_allblink()
{
  Ledmode_allon();
  mydelay(_period_1000);
  Ledmode_alloff();
   mydelay(_period_1000);
}

//12
void Display_LED_lib::Ledmode_trafficlight_fast()
{
  Ledmode_alloff();
  Ledmode_greenon();
   mydelay(_period_750);
  Ledmode_amberon();
   mydelay(_period_750);
  Ledmode_redon();
  mydelay(_period_750);
}

//13
void Display_LED_lib::Ledmode_pwm()
{
  Ledmode_alloff();
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    for (int thispin = 0 ; thispin < 6; thispin ++)
    {
      analogWrite(_ledPinsPwm[thispin], fadeValue);
    }
    // wait for 100 milliseconds to see the dimming effect
    mydelay(_period_100);
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    for (int thispin = 0 ; thispin < 6; thispin ++)
    {
      analogWrite(_ledPinsPwm[thispin], fadeValue);
    }
    // wait for 100 milliseconds to see the dimming effect
    mydelay(_period_100);
  }
}

//14
void Display_LED_lib::Ledmode_random()
{
  Ledmode_alloff();
  uint8_t ranNumpin = random(3, 18);
  digitalWrite(ranNumpin, HIGH);
  mydelay(_period_500);
}

//15
void Display_LED_lib::Ledmode_random_2()
{
  Ledmode_alloff();
  uint8_t ranNumpin_red = random(3, 8);
  uint8_t ranNumpin_amber = random(8, 13);
  uint8_t ranNumpin_green = random(13, 18);
  digitalWrite(ranNumpin_red, HIGH);
  digitalWrite(ranNumpin_amber, HIGH);
  digitalWrite(ranNumpin_green, HIGH);
  mydelay(_period_500);
}

//16
void Display_LED_lib::Ledmode_random_3()
{
  Ledmode_alloff();
  for (int count = 0; count <= 3; count++)
  {
    uint8_t ranNumpin_red = random(3, 8);
    uint8_t ranNumpin_amber = random(8, 13);
    uint8_t ranNumpin_green = random(13, 18);
    digitalWrite(ranNumpin_red, HIGH);
    digitalWrite(ranNumpin_amber, HIGH);
    digitalWrite(ranNumpin_green, HIGH);
  }
  mydelay(_period_1000);
}

//17
void Display_LED_lib::Ledmode_redone()
{
  Ledmode_alloff();
  mydelay(_period_1000);
  digitalWrite(_ledPinsRed[2], HIGH);
  mydelay(_period_1000);
}

//18
void Display_LED_lib::Ledmode_amberone()
{
  Ledmode_alloff();
  mydelay(_period_1000);
  digitalWrite(_ledPinsAmber[2], HIGH);
  mydelay(_period_1000);
}

//19
void Display_LED_lib::Ledmode_greenone()
{
  Ledmode_alloff();
  mydelay(_period_1000);
  digitalWrite(_ledPinsGreen[2], HIGH);
  mydelay(_period_1000);
}

//20
void Display_LED_lib::Ledmode_all()
{
  Ledmode_allon();
  Ledmode_redon();
  Ledmode_amberon();
  Ledmode_greenon();
  Ledmode_knightrider();
  Ledmode_knightrider_2();
  Ledmode_knightrider_3();
  Ledmode_knightrider_4();
  Ledmode_trafficlight();
  Ledmode_allblink();
  Ledmode_trafficlight_fast();
  Ledmode_pwm();
  Ledmode_random();
  Ledmode_random_2();
  Ledmode_random_3();
  Ledmode_redone();
  Ledmode_amberone();
  Ledmode_greenone();
}

//Method to replace delay with millis();
void mydelay(int period)
{
  unsigned long time_now = 0;
time_now = millis();
   while(millis() < time_now + period){
        //wait approx. [period] ms
      __asm__("nop\n\t");
    }
}