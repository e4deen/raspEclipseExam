/*
 * main.c
 *
 *  Created on: 2016. 3. 11.
 *      Author: crave
 */


#include <stdio.h>
#include <pthread.h>
#include "wiringPi/wiringPi.h"

static void *threadTest(void *argument)
{
	printf("Thread!!\n");
	return NULL;
}



int main(void)
{
	pthread_t thread;
    wiringPiSetupGpio () ;
	printf("hello Word\n");

	pthread_create(&thread,NULL,threadTest,NULL);
	pthread_join(thread,NULL);
	printf("threadTestDone\n");
	return 0;
}
