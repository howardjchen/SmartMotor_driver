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
  	int cport_nr=0,		/* (ttyS0 on linux) */
            bdrate=9600;       /* 9600 baud */

  	char mode[]={'8','N','1',0};

  	if(RS232_OpenComport(cport_nr, bdrate, mode))
  	{
    	printf("Can not open comport\n");
    	return 0;
  	}
  	
  	addressing(5,cport_nr);
	//only the first need address(power led ir red)
	//for 5 motors

	initiallize(cport_nr);
	//set the motor mode

	//run();
	
	printf("press to continue\n");
	getchar();
	setposition(3,-100000);
	
	/*printf("press to continue\n");
	getchar();
	setposition(3,0);

	printf("press to continue\n");	
	getchar();
	setposition(4,-5000);

	printf("press to continue\n");	
	getchar();
	setposition(4,0);

	printf("press to continue\n");	
	getchar();
	setposition(4,3000);

	printf("press to continue\n");  	
	getchar();
	setposition(4,0);  

	printf("press to continue\n");	
	getchar();
	setposition(5,-2000);

	printf("press to continue\n");	
	getchar();
	setposition(5,0);

	printf("press to continue\n");	
	getchar();
	setposition(5,3000);

	printf("press to continue\n");  	
	getchar();
	setposition(5,0);  */
	
	turnoff(0);
  	
	return 0;
}

