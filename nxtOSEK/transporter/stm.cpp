
#include "stm.h"





/*============================================================================
 * Transporter class
 *
 */

const Transporter::states Transporter::matrix[] = {
S_385387922,S_IGNORE,S_IGNORE,S_IGNORE,S_IGNORE,S_IGNORE,S_IGNORE,S_IGNORE,S_IGNORE,S_1031594446,S_IGNORE,S_IGNORE,S_IGNORE,S_IGNORE,S_785274,S_IGNORE,S_IGNORE,S_IGNORE,S_IGNORE,S_385387922,S_IGNORE,S_785274,S_IGNORE,S_IGNORE,S_IGNORE,S_IGNORE,S_IGNORE,S_385390750
};

int Transporter::execute(MEXUEvent *event) {
  if (!event) {
    return 0;
  }                                        

  states next_state = matrix[current_state * 7 + event->event_id];
    
  if(next_state == S_IGNORE) {
    return 0;
    }

//  printf("Transporter: event %d, state: %d -> %d\n",
//    event->event_id, current_state, next_state);
    
  current_state = (int)next_state;
  this->action((states)current_state);
  return 0;
}

void Transporter::action(states state) {
  switch(state) {
      case S_1031594446: /* 荷物搭載 */
	{
    stop();    	}
   	break;
      case S_785274: /* 待機 */
	{
    stop();    	}
   	break;
      case S_385390750: /* ライン外 */
	{
    turnRight();    	}
   	break;
      case S_385387922: /* ライン上 */
	{
    turnLeft();    	}
   	break;
      default:
        break;
  }
}




/*============================================================================
 * foo class
 *
 */

const foo::states foo::matrix[] = {
S_IGNORE,S_IGNORE,S_IGNORE,S_IGNORE,S_IGNORE,S_IGNORE,S_IGNORE
};

int foo::execute(MEXUEvent *event) {
  if (!event) {
    return 0;
  }                                        

  states next_state = matrix[current_state * 7 + event->event_id];
    
  if(next_state == S_IGNORE) {
    return 0;
    }

//  printf("foo: event %d, state: %d -> %d\n",
//    event->event_id, current_state, next_state);
    
  current_state = (int)next_state;
  this->action((states)current_state);
  return 0;
}

void foo::action(states state) {
  switch(state) {
      case S_3540994: /* stop */
	{
    stop();    	}
   	break;
      default:
        break;
  }
}



// created instances
Transporter iTransporter;
foo ifoo;
