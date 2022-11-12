#include <stdio.h>
#include "driver/gpio.h"
#include "driver/timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "fsmbutton.h"
#include "fsmled.h"

#define GPIO_OUTPUT_1 12
#define GPIO_OUTPUT_2 27
#define GPIO_OUTPUT_3 25
#define GPIO_OUTPUT_4 32
#define GPIO_OUTPUT_PIN_SEL  ((1ULL<<GPIO_OUTPUT_1)|(1ULL<<GPIO_OUTPUT_2)|(1ULL<<GPIO_OUTPUT_3)|(1ULL<<GPIO_OUTPUT_4))

#define GPIO_INPUT_PB_1 5
#define GPIO_INPUT_PB_2 4
#define GPIO_INPUT_PIN_SEL ((1ULL<<GPIO_INPUT_PB_1)|(1ULL<<GPIO_INPUT_PB_2))

const TickType_t xDelay = 25 / portTICK_PERIOD_MS;  // F = 10 Hz

int input1 = 0;
int state1 = 0;
int counter1 = 0;
int output1 = 0;

int input2 = 0;
int state2 = 0;
int counter2 = 0;
int output2 = 0;

int stateled = 0;
int led[4];

void app_main(void)
{
	gpio_config_t io_conf;
	io_conf.intr_type = 0;
	io_conf.mode = GPIO_MODE_OUTPUT;
	io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
	io_conf.pull_down_en = 0;
	io_conf.pull_up_en = 0;
	gpio_config(&io_conf);
	
	io_conf.pin_bit_mask = GPIO_INPUT_PIN_SEL;
	io_conf.mode = GPIO_MODE_INPUT; // mode input
	io_conf.pull_up_en = 1; // menggunakan pull up
	gpio_config(&io_conf);
	
    while (1)
	{	
		input1 = !(gpio_get_level(GPIO_INPUT_PB_1));
		input2 = !(gpio_get_level(GPIO_INPUT_PB_2));

		/*
		if(input1){
			gpio_set_level(GPIO_OUTPUT_1, 1);
		}
		if(input2){
			gpio_set_level(GPIO_OUTPUT_4, 0);
		}
		gpio_set_level(GPIO_OUTPUT_1, 0);
		gpio_set_level(GPIO_OUTPUT_2, 1);
		gpio_set_level(GPIO_OUTPUT_3, 1);
		gpio_set_level(GPIO_OUTPUT_4, 1);
		*/
		
		fsmbutton(input1, &state1, &counter1, &output1);
		fsmbutton(input2, &state2, &counter2, &output2);
		
		fsmled(output2, output1, &stateled, &led);

		gpio_set_level(GPIO_OUTPUT_1, led[0]);
		gpio_set_level(GPIO_OUTPUT_2, led[1]);
		gpio_set_level(GPIO_OUTPUT_3, led[2]);
		gpio_set_level(GPIO_OUTPUT_4, led[3]);
		
        vTaskDelay(xDelay);
    }
}
