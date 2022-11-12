#ifndef FSMLED_H
#define FSMLED_H

#include <stdio.h>
#include <stdlib.h>

#define STATE_ONE    0
#define STATE_TWO    1
#define STATE_THREE  2
#define STATE_FOUR   3


void fsmled(int input1, int input2, int *state, int *led){
    switch (*state){
        case STATE_ONE:
		{  
            if(input1 == 1 && input2 == 1){           // both button
				led[0] = 1;
				led[1] = 0;
				led[2] = 0;
				led[3] = 0;
            }
			else if(input1 == 1){
				*state = STATE_TWO;
				led[0] = 0;
				led[1] = 1;
				led[2] = 0;
				led[3] = 0;
			}
			else if(input2 == 1){
				*state = STATE_FOUR;
				led[0] = 0;
				led[1] = 0;
				led[2] = 0;
				led[3] = 1;
			}
			else{
			    led[0] = 1;
				led[1] = 0;
				led[2] = 0;
				led[3] = 0;
			}
            break;
		}
        case STATE_TWO:
		{
            if(input1 == 1 && input2 == 1){           // both button
				led[0] = 0;
				led[1] = 1;
				led[2] = 0;
				led[3] = 0;
            }
			else if(input1 == 1){
				*state = STATE_THREE;
				led[0] = 0;
				led[1] = 0;
				led[2] = 1;
				led[3] = 0;
			}
			else if(input2 == 1){
				*state = STATE_ONE;
				led[0] = 1;
				led[1] = 0;
				led[2] = 0;
				led[3] = 0;
			}
			else{
				led[0] = 0;
				led[1] = 1;
				led[2] = 0;
				led[3] = 0;
			}
            break;
        }
        case STATE_THREE:
		{  
            if(input1 == 1 && input2 == 1){           // both button
				led[0] = 0;
				led[1] = 0;
				led[2] = 1;
				led[3] = 0;
            }
			else if(input1 == 1){
				*state = STATE_FOUR;
				led[0] = 0;
				led[1] = 0;
				led[2] = 0;
				led[3] = 1;
			}
			else if(input2 == 1){
				*state = STATE_TWO;
				led[0] = 0;
				led[1] = 1;
				led[2] = 0;
				led[3] = 0;
			}
			else{
				led[0] = 0;
				led[1] = 0;
				led[2] = 1;
				led[3] = 0;
			}
            break;
		}
        case STATE_FOUR:
		{
            if(input1 == 1 && input2 == 1){           // both button
				led[0] = 0;
				led[1] = 0;
				led[2] = 0;
				led[3] = 1;
            }
			else if(input1 == 1){
				*state = STATE_ONE;
				led[0] = 1;
				led[1] = 0;
				led[2] = 0;
				led[3] = 0;
			}
			else if(input2 == 1){
				*state = STATE_THREE;
				led[0] = 0;
				led[1] = 0;
				led[2] = 1;
				led[3] = 0;
			}
			else{
				led[0] = 0;
				led[1] = 0;
				led[2] = 0;
				led[3] = 1;
			}
            break;
        }
        default:
            break;
    }
}

#endif