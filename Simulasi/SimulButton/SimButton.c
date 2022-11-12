#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\user\Desktop\Scanned\Semester_7\PSE\Tugas\Tugas_3_Cascade\Code\fsmbutton.h"

int main(){
    int state = 0;
    int counter = 0;
    int output = 0;

    int debounce[20] = {0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0};

    for(int i = 0; i < 20; i++){
        printf("Initial State: %i, Input: %i\n", state, debounce[i]);
        fsmbutton(debounce[i], &state, &counter, &output);
        printf("Final State: %i, Output: %i\n", state, output);
        printf("\n");
    }
}
