#undef CALIBRATION_MODE

extern "C"
{
#include "kernel.h"
#include "kernel_id.h"
#include "main.h"
}

#include <LightSensor.h>
#include <TouchSensor.h>
#include <SonarSensor.h>
#include <Motor.h>
#include <LegoLight.h>
#include <Nxt.h>
#include <Clock.h>
#include <Lcd.h>

#include "MEXU.h"
#include "stm.h"

// 
void generate_external_LightWhite()
{
  iTransporter.sendEvent(Transporter::E_OffLine);
}

void generate_external_LightBlack()
{
  iTransporter.sendEvent(Transporter::E_OnLine);
}

void generate_external_LightGray()
{
}

void generate_external_TouchPress()
{
  iTransporter.sendEvent(Transporter::E_BumperPushed);
}

void generate_external_TouchRelease()
{
  iTransporter.sendEvent(Transporter::E_BumperReleased);
}

void generate_external_TouchPress2()
{
  iTransporter.sendEvent(Transporter::E_CarrierPushed);
}

void generate_external_TouchRelease2()
{
  iTransporter.sendEvent(Transporter::E_CarrierReleased);
}

void generate_external_sonar()
{
  iTransporter.sendEvent(Transporter::E_ObstacleDetected);
}


// nxtJSP hook to be invoked from an 1msec periodical ISR
extern "C"
{
  void jsp_systick_low_priority(void)
  {
    if (get_OS_flag()) /* check whether JSP already started or not */
      {
	isig_tim();          /* cyclic task dispatcher */
	check_NXT_buttons();
      }
  }
}

// Timer driver for nxt JSP
MEXUTimerEventManager timer;

extern "C"
{
  void tsk_timer (VP_INT exinf) {
    timer.tick ();
  }
}

void mexu_lock() 
{
  loc_cpu();
}

void mexu_unlock() 
{
  unl_cpu();
}

// Main function
EventManager eventManager;

extern "C"
{
  void tsk_main (VP_INT exinf) 
  {
    /* event loop */
    for(;;) 
      {
	eventManager.execute();
      }
  }
}

// Sensors
LightSensor lightSensor(PORT_3);
Motor rightMotor(PORT_A);
Motor leftMotor(PORT_C);
Lcd lcd;
TouchSensor touch1(PORT_1);
TouchSensor touch2(PORT_2);
SonarSensor sonar(PORT_4);

// API for generated codes
void stop() 
{
  rightMotor.setPWM(0);
  leftMotor.setPWM(0);
}

void forward() 
{
  rightMotor.setPWM(60);
  leftMotor.setPWM(60);
}

void turnRight() 
{
  rightMotor.setPWM(60);
  leftMotor.setPWM(0);
}

void turnLeft() 
{
  rightMotor.setPWM(0);
  leftMotor.setPWM(60);
}

void backward() 
{
  rightMotor.setPWM(-60);
  leftMotor.setPWM(-60);
}

void backTurnRight() 
{
  rightMotor.setPWM(0);
  leftMotor.setPWM(-60);
}

void backTurnLeft() 
{
  rightMotor.setPWM(-60);
  leftMotor.setPWM(0);
}

void print(char *s) 
{
  lcd.putf("s", s);
}

void sys_wait1sec() 
{
  tslp_tsk(1000);                     
}

void sys_wait2sec() 
{
  tslp_tsk(2000);                     
}

void sys_wait3sec() 
{
  tslp_tsk(3000);                     
}

void sys_wait4sec() 
{
  tslp_tsk(4000);                     
}

void sys_wait5sec() 
{
  tslp_tsk(5000);                     
}


#define WHITE 590
#define BLACK 335
#define EDGE_COLOR ((BLACK + WHITE) / 2)

#define LIGHT_STATUS_BLACK 0
#define LIGHT_STATUS_WHITE 2
int prev_light_status = -1;

#define TOUCH_STATUS_NOT_PRESS 0
#define TOUCH_STATUS_PRESS 1
int prev_touch_status = TOUCH_STATUS_NOT_PRESS;

#define TOUCH_STATUS_NOT_PRESS_2 0
#define TOUCH_STATUS_PRESS_2 1
int prev_touch_status_2 = TOUCH_STATUS_NOT_PRESS_2;

#define SONAR_STATUS_SMALL_10 0
#define SONAR_STATUS_NOT_SMALL_10 1
int prev_sonar_status = SONAR_STATUS_NOT_SMALL_10;

int sonacnt;

extern "C"
{

#ifdef CALIBRATION_MODE

  void tsk_event(VP_INT exinf)
  {
    while (1)
      {
	lcd.clear();
	lcd.putf("s", "lig=");
	S16 n = lightSensor.getBrightness();
	lcd.putf("d", n);
	lcd.disp();
	tslp_tsk(50);
      }
  }

#else

  void tsk_event(VP_INT exinf)
  {
    while (1)
      {
	S16 value = lightSensor.getBrightness();

	if(value > EDGE_COLOR)
	  {
	    if(prev_light_status != LIGHT_STATUS_WHITE)
	      {
		//generate signal
		generate_external_LightWhite();
		lcd.putf("s", "LightWhite\n");
	      }
	    prev_light_status = LIGHT_STATUS_WHITE;
	  }
	else if(value<=EDGE_COLOR)
	  {
	    if(prev_light_status != LIGHT_STATUS_BLACK)
	      {
		//generate signal
		generate_external_LightBlack();
		lcd.putf("s", "LightBlack\n");
	      }
	    prev_light_status = LIGHT_STATUS_BLACK;
	  }

	if(touch1.isPressed())
	  {
	    // lcd.putf("s", "press");
	    if(prev_touch_status != TOUCH_STATUS_PRESS)
	      {
		generate_external_TouchPress();
		lcd.putf("s", "TouchPress\n");
		wup_tsk(TSK_MAIN);
	      }
	    prev_touch_status = TOUCH_STATUS_PRESS;
	  }
	else
	  {
	    // lcd.putf("s", "not press");
	    if(prev_touch_status != TOUCH_STATUS_NOT_PRESS)
	      {
		generate_external_TouchRelease();
		wup_tsk(TSK_MAIN);
	      }
	    prev_touch_status = TOUCH_STATUS_NOT_PRESS;
	  }

	if(touch2.isPressed())
	  {
	    /// lcd.putf("s", "press");
	    if(prev_touch_status_2 != TOUCH_STATUS_PRESS_2)
	      {
		generate_external_TouchPress2();
		lcd.putf("s", "TouchPress2\n");
		wup_tsk(TSK_MAIN);
	      }
	    prev_touch_status_2 = TOUCH_STATUS_PRESS_2;
	  }
	else
	  {
	    // lcd.putf("s", "not press");
	    if(prev_touch_status_2 != TOUCH_STATUS_NOT_PRESS_2)
	      {
		generate_external_TouchRelease2();
		wup_tsk(TSK_MAIN);
	      }
	    prev_touch_status_2 = TOUCH_STATUS_NOT_PRESS_2;
	  }
 
	sonacnt++;
	if(10 < sonacnt)
	  {
	    sonacnt = 0;
	    if(sonar.getDistance() < 10)
	      {
		if(prev_sonar_status != SONAR_STATUS_SMALL_10)
		  {
		    generate_external_sonar();
		    lcd.putf("s", "Sonar\n");
		  }
		prev_sonar_status = SONAR_STATUS_SMALL_10;
	      }
	    else
	      {
		if(prev_sonar_status != SONAR_STATUS_NOT_SMALL_10)
		  {
		    // generate_external_NotSonar(NULL);
		  }
		prev_sonar_status = SONAR_STATUS_NOT_SMALL_10;

	      }
	  }

	lcd.disp();

	tslp_tsk(50);
      }
  }
#endif
}
