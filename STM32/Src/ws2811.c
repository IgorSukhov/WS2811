#include "ws2811.h"

#define BIT_OFF 36
#define BIT_ON 86

unsigned short length = DATA_LENGTH;
unsigned short wsData[DATA_LENGTH] = {0};

void setup()
{
	int i;
	for(i=0;i<PAUSE_BYTES;i++)
	{
		wsData[i]=0;
	}
	for(i=PAUSE_BYTES;i<DATA_LENGTH;i++)
	{
		wsData[i]=BIT_OFF;
	}
}


void setState(unsigned short n, unsigned char g, unsigned char r, unsigned char b)
{
	int i;
	unsigned short *ptr = wsData + PAUSE_BYTES + n*24;
	for(i=0;i<8;i++)
	{
		*ptr = g & 0x80 ? BIT_ON : BIT_OFF;
		g = g << 1;
		ptr++;
	}
	for(i=0;i<8;i++)
	{
		*ptr = r & 0x80 ? BIT_ON : BIT_OFF;
		r = r << 1;
		ptr++;
	}
	for(i=0;i<8;i++)
	{
		*ptr = b & 0x80 ? BIT_ON : BIT_OFF;
		b = b << 1;
		ptr++;
	}
}
