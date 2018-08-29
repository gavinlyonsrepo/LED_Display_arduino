//******************* HEADER ***********************************
/*
  Name : LED_Display_arduino
  Title : Arduino Based LED Display unit.
  Desc: An Arduino Based LED Display unit with 15 LEDS and 20 lighting modes.
  A Potentiometer controls mode and push button selects it.
  Author: Gavin Lyons
  URL:https://github.com/gavinlyonsrepo/LED_Display_arduino
*/

//*************************** Libraries ********************
//Custom Library by author can be found at URL in header.
#include <Display_LED_lib.h>

//*************************** GLOBALS ********************

//declare an instance of the Led control class
Display_LED_lib display_LED_lib(true);

// pot pin
#define potPin  19

// Push Button pin
#define buttonPin 2

// Var to hold mode
uint8_t mode = 1;

//*************************** SETUP ************************
void setup() {
  // Setup serial
  display_LED_lib.begin(9600);
  //Serial.println("----------- Arduino Comms up ------------");

  // Setup pins for button enable internal pull-up resistors and ISR
  digitalWrite(buttonPin, HIGH);
  attachInterrupt(0, TestButton, FALLING);

  //setup LED pins arrays as outputs
  display_LED_lib.Ledmode_setup();
}

//******************* MAIN LOOP *****************
void loop() {
 // Serial.println("Mode no 1-20: ");
  //Serial.println(mode);
  switch (mode)
  {
    case 1: display_LED_lib.Ledmode_alloff(); break;
    case 2: display_LED_lib.Ledmode_allon(); break;
    case 3: display_LED_lib.Ledmode_redon(); break;
    case 4: display_LED_lib.Ledmode_amberon(); break;
    case 5: display_LED_lib.Ledmode_greenon(); break;
    case 6: display_LED_lib.Ledmode_knightrider(); break;
    case 7: display_LED_lib.Ledmode_knightrider_2(); break;
    case 8: display_LED_lib.Ledmode_knightrider_3(); break;
    case 9: display_LED_lib.Ledmode_knightrider_4(); break;
    case 10: display_LED_lib.Ledmode_trafficlight(); break;
    case 11: display_LED_lib.Ledmode_allblink(); break;
    case 12: display_LED_lib.Ledmode_trafficlight_fast(); break;
    case 13: display_LED_lib.Ledmode_pwm(); break;
    case 14: display_LED_lib.Ledmode_random(); break;
    case 15: display_LED_lib.Ledmode_random_2(); break;
    case 16: display_LED_lib.Ledmode_random_3(); break;
    case 17: display_LED_lib.Ledmode_police_lights(); break;
    case 18: display_LED_lib.Ledmode_fast_blink(); break;
    case 19: display_LED_lib.Ledmode_pattern(); break;
    case 20: display_LED_lib.Ledmode_all(); break;
  }
}

// ********************* FUNCTIONS *************************
// TestButton:  ISR interrupt service routine on button press
void TestButton()
{
  mode = map(analogRead(potPin), 0, 1023, 1, 20);
}

//*************************** EOF *****************************
