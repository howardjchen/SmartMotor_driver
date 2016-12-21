#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "rs232.h"

#include "control.h"

int main()
{
  	int cport_nr = 0,	/* (ttyS0 on linux) */
            bdrate=9600;	/* 9600 baud */

  	char mode[]={'8','N','1',0};

  	if(RS232_OpenComport(cport_nr, bdrate, mode))
  	{
    	printf("Can not open comport\n");
    	return 0;
  	}
  	
	
	printf("press any key to start");
	getchar();

	setvelocity(2,100000); //right wheel (positive is forward)
	setvelocity(1,100000); //left wheel (negative is forward)
	
	turnoff(0);
  	
	return 0;
}

