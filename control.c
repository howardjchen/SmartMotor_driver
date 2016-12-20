#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "rs232.h"
#include "control.h"

int cport_nr;
int i,j;
char str[20][20];
char addr;

void addressing(int len,int port)
{
	cport_nr = port;
	printf("addressing\n");
	char buffer[10];
	for(i=1;i<=len;i++)
	{
		sprintf(buffer,"%d",i);
		//0SADDRi
		strcpy(str[0], "SADDR");
	  	strcat(str[0], buffer);
  		strcat(str[0],"\r");
		RS232_SendByte(cport_nr,128);
		RS232_cputs(cport_nr, str[0]);
		printf("sent: %d%s\n", 0, str[0]);
		usleep(1100000);
		
		//iECHO
		RS232_SendByte(cport_nr,128+i);
		RS232_cputs(cport_nr, "ECHO\r");
		printf("sent: %d%s\n", i, "ECHO\r");
		usleep(1100000);
		
		//iSLEEP
		RS232_SendByte(cport_nr,128+i);
		RS232_cputs(cport_nr, "SLEEP\r");
		printf("sent: %d%s\n", i, "SLEEP\r");
		usleep(1100000);
	}
	RS232_SendByte(cport_nr,128);
	RS232_cputs(cport_nr, "WAKE\r");
    	printf("sent: %s\n", "0WAKE\r");	
    	usleep(1100000);
}
void turnon(int addr)
{
	RS232_SendByte(cport_nr,128+addr);
    	RS232_cputs(cport_nr, "G\r");
    	printf("sent: %d%s\n", addr, "G\r");
    	//usleep(1100000);
}
void initiallize(int port)
{  
	cport_nr = port;
	//disable limit & reset errors
	RS232_SendByte(cport_nr,128);
    	RS232_cputs(cport_nr, "EIGN(2) EIGN(3) ZS\r");
   	printf("sent: %d%s\n", 0, "EIGN(2) EIGN(3) ZS\r");
	usleep(1100000); 
  	
  	//address 1: left wheel
  	RS232_SendByte(cport_nr,129);
  	RS232_cputs(cport_nr, "MV ADT=10000\r");
   	printf("sent: %d%s\n", 1, "MV ADT=10000\r");
    	usleep(1100000); 
  	
  	//address 2: right wheel
  	RS232_SendByte(cport_nr,130);
  	RS232_cputs(cport_nr, "MV ADT=100\r");
   	printf("sent: %d%s\n", 2, "MV ADT=100\r");
    	usleep(1100000);
    
  	//address 3: expansion
  	RS232_SendByte(cport_nr,131);
  	RS232_cputs(cport_nr, "MP ADT=1000 VT=500000\r");
	printf("sent: %d%s\n", 3, "MP ADT=1000 VT=500000\r");
    	usleep(1100000);
  	
  	//address 4: camera left&right
  	RS232_SendByte(cport_nr,132);
  	RS232_cputs(cport_nr, "MP ADT=100 VT=10000\r");
   	printf("sent: %d%s\n", 4, "MP ADT=100 VT=10000\r");
    	usleep(1100000);
    
	//address 5: camera up&down 
	RS232_SendByte(cport_nr,133);
  	RS232_cputs(cport_nr, "MP ADT=100 VT=10000\r");
   	printf("sent: %d%s\n", 5, "MP ADT=100 VT=10000\r");
    	usleep(1100000);
}
void setvelocity(int addr,int v)
{
	char buffer[10];
	sprintf(buffer,"%d",v);
	RS232_SendByte(cport_nr,128+addr);		
	
  	strcpy(str[0], "VT=");
  	strcat(str[0],buffer);
  	strcat(str[0]," G\r");
    	RS232_cputs(cport_nr, str[0]);
    	printf("sent: %d%s\n", addr, str[0]);
    	usleep(100);

}
void setposition(int addr,int p)
{
	char buffer[10];
	sprintf(buffer,"%d",p);
	RS232_SendByte(cport_nr,128+addr);		
		
  	strcpy(str[0], "PT=");
  	strcat(str[0],buffer);
  	strcat(str[0]," G\r");
	RS232_cputs(cport_nr, str[0]);
    	printf("sent: %d%s\n", addr, str[0]);
    	usleep(100);
}
void plate_ahead(int v)
{
	//address 1: left wheel
  	setvelocity(1,v);
  	//address 2: right wheel
  	setvelocity(2,v);
}
void plate_right(int v)
{
	//address 1: left wheel
  	setvelocity(1,v);
  	//address 2: right wheel
  	setvelocity(2,-v);
}
void plate_left(int v)
{
	//address 1: left wheel
  	setvelocity(1,-v);
  	//address 2: right wheel
  	setvelocity(2,v);
}
void expand(int p)
{
	setposition(3,p);
	//4000 /round
	//8000 /round
	//0 for initial state
}
void camera_updown(int p)
{
	setposition(4,p);
}
void camera_leftright(int p)
{
	setposition(5,p);
}
void turnoff(int addr)
{	
	printf("press any key to stop\n");
	getchar();
	RS232_SendByte(cport_nr,128+addr);
    	RS232_cputs(cport_nr, "OFF\r");
    	printf("sent: %d%s\n", addr, "OFF\r");
    	usleep(1100000);
}
void run()
{
	plate_ahead(50000);
	expand(0);
	camera_updown(0);
 	camera_leftright(0);
}
