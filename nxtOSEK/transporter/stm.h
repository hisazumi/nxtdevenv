
#ifndef D_MEXU_H_
#define D_MEXU_H_

#include "main.h"
#include "MEXU.h"

class Transporter;
class foo;



/*====================================================
 * Transporter class
 *
 */
class Transporter : public StateMachine {
public:

  enum states { 
	S_IGNORE = -1,
	S_1031594446 = 0,
	S_785274 = 1,
	S_385390750 = 2,
	S_385387922 = 3,
  };
  enum events {
	E_BumperPushed = 0,
	E_BumperReleased = 1,
	E_CarrierPushed = 2,
	E_CarrierReleased = 3,
	E_ObstacleDetected = 4,
	E_OnLine = 5,
	E_OffLine = 6,
  };

  /* attributes */

  /* methods */                          

  Transporter() : StateMachine(){
      eventManager.addSTM(this);
      current_state = S_785274;
}


  ~Transporter() {}

  int execute(MEXUEvent *event);
  void action(states state);
  void initial_action(void) { action (S_785274); }



private:

  static const states matrix[];

};


/*====================================================
 * foo class
 *
 */
class foo : public StateMachine {
public:

  enum states { 
	S_IGNORE = -1,
	S_3540994 = 0,
  };
  enum events {
	E_BumperPushed = 0,
	E_BumperReleased = 1,
	E_CarrierPushed = 2,
	E_CarrierReleased = 3,
	E_ObstacleDetected = 4,
	E_OnLine = 5,
	E_OffLine = 6,
  };

  /* attributes */

  /* methods */                          

  foo() : StateMachine(){
      eventManager.addSTM(this);
      current_state = S_3540994;
}


  ~foo() {}

  int execute(MEXUEvent *event);
  void action(states state);
  void initial_action(void) { action (S_3540994); }



private:

  static const states matrix[];

};

// created instances
extern Transporter iTransporter;
extern foo ifoo;
#endif /* D_MEXU_H_ */
