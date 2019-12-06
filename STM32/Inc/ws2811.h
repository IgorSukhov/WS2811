#ifndef WS2811_H
#define WS2811_H



#define PAUSE_BYTES 20
#define LED_COUNT 1
#define DATA_LENGTH (PAUSE_BYTES + LED_COUNT*3*8)

void setup();
void setState(unsigned short n, unsigned char g, unsigned char r, unsigned char b);

#endif
