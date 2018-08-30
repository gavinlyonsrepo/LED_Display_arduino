
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
  //foward
  for (int i = 0; i < _pinCount; i++)
  {
    digitalWrite(_ledPinsRed[i], HIGH);
    mydelay(_period_250);

    digitalWrite(_ledPinsRed[i], LOW);
  }

  for (int j = 0; j < _pinCount; j++)
  {
    digitalWrite(_ledPinsAmber[j], HIGH);
    mydelay(_period_250);
    digitalWrite(_ledPinsAmber[j], LOW);
  }

  for (int k = 0; k < _pinCount; k++)
    {
    digitalWrite(_ledPinsGreen[k], HIGH);
    mydelay(_period_250);
    digitalWrite(_ledPinsGreen[k], LOW);
  }
 
  //backward 
    for (int n = (_pinCount-1); n > -1; n--)
  {
    digitalWrite(_ledPinsGreen[n], HIGH);
    mydelay(_period_250);
    digitalWrite(_ledPinsGreen[n], LOW);
  }

  for (int m = (_pinCount-1); m > -1; m--)
  {
    digitalWrite(_ledPinsAmber[m], HIGH);
    mydelay(_period_250);
    digitalWrite(_ledPinsAmber[m], LOW);
  }

    for (int p = (_pinCount-1); p > -1; p--)
  {
    digitalWrite(_ledPinsRed[p], HIGH);
    mydelay(_period_250);
    digitalWrite(_ledPinsRed[p], LOW);
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
void Display_LED_lib::Ledmode_police_lights()
{
  Ledmode_alloff();
  Ledmode_redon();
  mydelay(_period_250);
  Ledmode_greenon();
  mydelay(_period_250);
}

//18
void Display_LED_lib::Ledmode_fast_blink()
{
  Ledmode_allon();
  mydelay(_period_100);
  Ledmode_alloff();
   mydelay(_period_100);
}

//19
void Display_LED_lib::Ledmode_pattern()
{
	int j = 5;
	Ledmode_alloff();
  for (int i = 0; i < _pinCount; i++)
  {
    j--;
    digitalWrite(_ledPinsRed[i], HIGH);
    digitalWrite(_ledPinsGreen[j], HIGH);
    mydelay(_period_250);
    digitalWrite(_ledPinsRed[i], LOW);
    digitalWrite(_ledPinsGreen[j], LOW);
  }
  
  for(int k = 0; k < 10; k++)
  {
  	Ledmode_amberon();
  	mydelay(_period_100);
  	Ledmode_alloff();
    mydelay(_period_100);
  }

}

//20
void Display_LED_lib::Ledmode_all()
{
  Ledmode_allon();
  mydelay(_period_1000);
  Ledmode_redon();
  mydelay(_period_1000);
  Ledmode_amberon();
  mydelay(_period_1000);
  Ledmode_greenon();
  mydelay(_period_1000);
  Ledmode_knightrider();
  Ledmode_knightrider_2();
  Ledmode_knightrider_3();
  Ledmode_knightrider_4();
  for(int k = 0; k < 3; k++)
  {
  	Ledmode_allblink();
  }
  Ledmode_trafficlight();
  Ledmode_trafficlight_fast();
  Ledmode_pwm();
  Ledmode_random();
  for(int m = 0; m < 10; m++)
  {
    Ledmode_random_2();
  }
  Ledmode_random_3();
  for(int p = 0; p < 10; p++)
  {
  	 Ledmode_police_lights();
  }
  for(int j = 0; j < 10; j++)
  {
  	 Ledmode_fast_blink();
  }
  for(int i = 0;i < 5; i++)
  {
  	Ledmode_pattern();
  }
}

//Method to replace delay with millis();
void Display_LED_lib::mydelay(int period)
{
  unsigned long time_now = 0;
time_now = millis();
   while(millis() - time_now <= period){
        //wait approx. [period] ms
      __asm__("nop\n\t");
    }
}