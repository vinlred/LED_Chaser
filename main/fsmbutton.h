#ifndef FSMBUTTON_H
#define FSMBUTTON_H

#include <stdio.h>
#include <stdlib.h>

#define IDLE        0
#define DEBOUNCING  1
#define HELD        2

void fsmbutton(int input, int *state, int *counter, int *output){
    switch (*state){
        case IDLE:
		{
            if(input == 1){           // input rising edge
                *state = HELD;
                *output = 1;          // trigger action 
            }
            break;
		}
		case HELD:
		{
			*output = 0;
			if(input == 0){           // falling edge
				*state = DEBOUNCING;
			}
			break;
		}
        case DEBOUNCING:
		{
			*counter += 1;
            if(*counter > 5){
				if(input == 1){
					*state = IDLE;
				}
				else{
					*counter = 5;    // prevent integer overflow
				}
			}
            break;
        }
        default:
            break;
    }
}

#endif