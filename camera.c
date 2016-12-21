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
	setposition(5,-5000);
	setposition(4,3000);
	//setposition(3,-30000);

	printf("press any key to start");
	getchar();
	setposition(5,3000);
	setposition(4,-3000);
	
	printf("press any key to stop!");
	getchar();
	setposition(5,0);
	setposition(4,0);
	//setposition(3,0);
	//setvelocity(2,100000);
	//setvelocity(1,100000);
	
	//printf("press any key to cintinue2!");
	//getchar();
	
	//setposition(4,-5000);
	/*
	printf("press any key to cintinue!");
	getchar();
	setposition(4,0);
	
	printf("press any key to cintinue!");
	getchar();
	setposition(4,3000);
  	
	printf("press any key to cintinue!");
	getchar();
	setposition(4,0);  
	
	printf("press any key to cintinue!");
	getchar();
	setposition(5,-2000);
	
	printf("press any key to cintinue!");
	getchar();
	setposition(5,0);
	
	printf("press any key to cintinue!");
	//getchar();
	setposition(5,3000);
  	
	printf("press any key to cintinue!");
	getchar();
	setposition(5,0);  
	*/
	turnoff(0);
  	
	return 0;
}

