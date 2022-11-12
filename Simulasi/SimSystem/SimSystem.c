#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\user\Desktop\Scanned\Semester_7\PSE\Tugas\Tugas_3_Cascade\Code\fsmbutton.h"
#include "C:\Users\user\Desktop\Scanned\Semester_7\PSE\Tugas\Tugas_3_Cascade\Code\fsmled.h"

int main(){
    int input1[20] = {0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0};
    int state1 = 0;
    int counter1 = 0;
    int output1 = 0;

    int input2[20] = {0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int state2 = 0;
    int counter2 = 0;
    int output2 = 0;

    int stateled = 0;
    int led[4] = {1, 0, 0, 0};

    for(int i = 0; i < 20; i++){
        printf("Simulation T: %i\n", i);
        printf("Initial LED State: %i\n", stateled);
        printf("Initial B1 State: %i, Input 1: %i\n", state1, input1[i]);
        printf("Initial B2 State: %i, Input 2: %i\n", state2, input2[i]);

        fsmbutton(input1[i], &state1, &counter1, &output1);
        fsmbutton(input2[i], &state2, &counter2, &output2);

        printf("Final B1 State: %i, Output B1: %i\n", state1, output1);
        printf("Final B2 State: %i, Output B2: %i\n", state2, output2);

        fsmled(output1, output2, &stateled, &led);
        printf("Final LED State: %i, Output LED: %i%i%i%i\n", stateled, led[0], led[1], led[2], led[3]);
        printf("\n");
    }
}
