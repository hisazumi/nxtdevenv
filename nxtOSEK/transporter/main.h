#include <t_services.h>

#define EVENT_none (0)

#ifndef _MACRO_ONLY

#include <LightSensor.h>
#include <Motor.h>
#include <Port.h>
#include <Lcd.h>
using namespace ecrobot;

// API for generated codes
extern "C"
{
void stop();
void forward();
void turnRight();
void turnLeft();
void backward();
void backTurnRight();
void backTurnLeft();
}

#endif 
