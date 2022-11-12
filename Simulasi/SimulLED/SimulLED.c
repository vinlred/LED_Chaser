#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\user\Desktop\Scanned\Semester_7\PSE\Tugas\Tugas_3_Cascade\Code\fsmled.h"

int main(){
    int state = 0;
    int output[4] = {1, 0, 0, 0};

    int input1[20] = {0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0};
    int input2[20] = {0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1};

    for(int i = 0; i < 20; i++){
        printf("Initial State: %i, Input 1: %i, Input 2: %i\n", state, input1[i], input2[i]);
        fsmled(input1[i], input2[i], &state, &output);
        printf("Final State: %i, Output: %i%i%i%i\n", state, output[0], output[1], output[2], output[3]);
        printf("\n");
    }
}

