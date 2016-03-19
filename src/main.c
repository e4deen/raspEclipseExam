/*
 * main.c
 *
 *  Created on: 2016. 3. 11.
 *      Author: crave
 */


#include <stdio.h>
#include <pthread.h>
#include "wiringPi/wiringPi.h"
#include "wiringPi/wiringPiI2C.h"


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
/*

	int i = 0;
	for(i=0; i<0x77;i++)
	{
		int fd = wiringPiI2CSetup(i);
		printf("fd [%x] index[%x]\n",fd, i);
	}

*/
	int fd = wiringPiI2CSetup(0x40);
	printf("fd [%x]\n",fd);


	wiringPiI2CWriteReg8(fd,0xfa,0);
	wiringPiI2CWriteReg8(fd,0xfb,0);
	wiringPiI2CWriteReg8(fd,0xfc,0);
	wiringPiI2CWriteReg8(fd,0xfd,0);

	wiringPiI2CWriteReg8(fd,0x01,0x04);
	wiringPiI2CWriteReg8(fd,0x00,0x01);

	int reg = wiringPiI2CReadReg8(fd,0x00);
	printf("reg 0  [%x]\n",reg);
	reg = wiringPiI2CReadReg8(fd,0x01);
	printf("reg 1 [%x]\n",reg);
	reg = wiringPiI2CReadReg8(fd,0x02);
	printf("reg 2 [%x]\n",reg);

/*	int i = 0;
	for(i=0; i<20;i++)
	{
		reg = wiringPiI2CReadReg8(fd,i);
		printf("reg %d [%x]\n",i,reg);
	}*/

	for(;;)
	{
	    digitalWrite (LED, HIGH) ;	// On
	    delay (1) ;		// mS
	    digitalWrite (LED, LOW) ;	// Off
	    delay (1) ;
	}
	return 0;
}
