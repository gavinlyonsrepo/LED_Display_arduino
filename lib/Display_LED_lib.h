/* URL : https://github.com/gavinlyonsrepo/LED_Display_arduino
 Library used by project LED_Display_arduino
 Version 1.0-1
 Author: Gavin Lyons
 */
#ifndef tl
#define tl

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class Display_LED_lib {
  public:
	

	// Constructor 
	Display_LED_lib(bool displayMsg=false);

	// Methods
	void begin(int baudRate=9600);

	void Ledmode_alloff();
	void Ledmode_allon();
    void Ledmode_redon();
	void Ledmode_amberon();
	void Ledmode_greenon();
	void Ledmode_knightrider();
	void Ledmode_knightrider_2();
	void Ledmode_knightrider_3();
	void Ledmode_knightrider_4();
	void Ledmode_trafficlight();
	void Ledmode_allblink();
	void Ledmode_trafficlight_fast();
	void Ledmode_pwm();
	void Ledmode_random();
	void Ledmode_random_2();
	void Ledmode_random_3();
	void Ledmode_police_lights();
	void Ledmode_fast_blink();
	void Ledmode_pattern();
	void Ledmode_all();
	void Ledmode_setup();
    void mydelay(int);


  private:
	bool _msg;
	 //led arrays  of pin numbers to which LEDs are attached to
    int _period_100 = 100;
	int _period_250 = 250;
	int _period_500 = 500;
	int _period_750 = 750;
	int _period_1000 = 1000;
	int _period_4000 = 4000;
	int _period_7000 = 7000;
    
    int _pinCount = 5; // size of arrays
	int _ledPinsRed[5] = {3, 4, 5, 6, 7};  // Red leds
	int _ledPinsAmber[5] = {8, 9, 10, 11, 12}; //amber leds
	int _ledPinsGreen[5] = {13, 14, 15, 16, 17}; // green leds
	int _ledPinsPwm[6] = {3, 5, 6, 9, 10, 11}; // pins which have pwm capability 

	

};
#endif
