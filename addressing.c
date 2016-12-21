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
  	
  	//Addressing the motors
	printf("Addressing the motors\n");
	addressing(5,cport_nr);
	//only the first need address(power led ir red)

	initiallize(cport_nr);
	//run();
	
	turnoff(0);
        printf("Motors succesfully addressed\n");	
	return 0;
}

