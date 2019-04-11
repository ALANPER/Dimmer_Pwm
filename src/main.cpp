#include <mbed.h>
#include "dimmer.h"
int main() {

  // put your setup code here, to run once:

  while(1) {
    // put your main code here, to run repeatedly:



PwmOut Leds[]={(PD_13),(PD_15),(PA_9)};

enum states {DOWN, UP, RISE,FALL, MIN, MAX};	//state of machine 
enum events {PRESS_BUTTON_LESS_1S, PRESS_BUTTON_MORE_1S, BUTTON_RELEASE};	//event of machine

void StateMachine(int event){ //change to the next state

switch (nextstate){
	case UP:
		switch(event){
			case PRESS_BUTTON_LESS_1S://button press for less the 1 second
				nextState = DOWN;
				break;
      case PRESS_BUTTON_MORE_1S ://button press for more the 1 second
				nextState = RISE;
				break;
		}
	break;

	case DOWN:
		switch(event){
			case PRESS_BUTTON_LESS_1S://button press for less the 1 second
				nextState = UP;
				break;
			case PRESS_BUTTON_MORE_1S ://button press for more the 1 second
				nextState = FALL;
				break;
		}
	break;

	case FALL:
		switch(event){
			case PRESS_BUTTON_DURING_1S://button press during 1 second
				nextState = MIN;
				break;
			case BUTTON_RELEAZE://button releaze
				nextState =;
				break;
	
		}
	break;

	case RISE:
		switch(event){
			case PRESS_BUTTON_DURING_1S://button press during 1 second
				nextState = MAX
				break;
			case BUTTON_RELEAZE://button releaze
				nextState = ;
      break;
		}
	break;

	case MIN:
		switch(event){
			case BUTTON_RELEASE://button releaze
				nextState = DOWN
				break;
		}
	break;

case MAX:
		switch(event){
			case BUTTON_RELEASE://button releaze
				nextState = UP
				break;
}
}