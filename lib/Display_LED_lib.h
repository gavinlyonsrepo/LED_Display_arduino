// url:https://github.com/gavinlyonsrepo/LED_Display_arduino

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
	void Ledmode_redone();
	void Ledmode_amberone();
	void Ledmode_greenone();
	void Ledmode_all();
	void Ledmode_setup();
	void mydelay(int)


  private:
	bool _msg;
	int _period_100;
	int _period_250;
	int _period_500;
	int _period_750;
	int _period_1000;
	int _period_4000;
	int _period_7000;

	 //led arrays  of pin numbers to which LEDs are attached
	  int _pinCount = 5;
	  int _ledPinsRed[5] = {3, 4, 5, 6, 7};
	  int _ledPinsAmber[5] = {8, 9, 10, 11, 12};
	  int _ledPinsGreen[5] = {13, 14, 15, 16, 17};
	  int _ledPinsPwm[6] = {3, 5, 6, 9, 10, 11};

};
#endif
