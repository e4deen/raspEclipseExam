/*
 * main.c
 *
 *  Created on: 2016. 3. 11.
 *      Author: crave
 */


#include <stdio.h>
#include <pthread.h>
#include "wiringPi/wiringPi.h"


#define LED 0	///BCM 0

static void *threadTest(void *argument)
{
	printf("Thread!!\n");
	return NULL;
}



int main(void)
{
	pthread_t thread;
    wiringPiSetupGpio () ;
    pinMode (LED, OUTPUT) ;
	printf("hello Word\n");

	pthread_create(&thread,NULL,threadTest,NULL);
	pthread_join(thread,NULL);
	printf("threadTestDone\n");
	for(;;)
	{
	    digitalWrite (LED, HIGH) ;	// On
	    delay (1) ;		// mS
	    digitalWrite (LED, LOW) ;	// Off
	    delay (1) ;
	}
	return 0;
}
