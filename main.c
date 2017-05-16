#include <regx51.h>
//#include "delay.h"
#include "keyboard.h"
//#include "lcd.h"

void main()
{
  unsigned char getkey=0;
	
  while(1)
  {
    getkey=presskey();
    P1=getkey;
  }
}