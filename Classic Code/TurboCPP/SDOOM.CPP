#include <iostream.h>
#include <dos.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
 textmode (C4350);
 clrscr();
 char here;
 int freq, del,x,y,c, hi;
 while (!kbhit())
 {
       hi = random (10);
	  switch (hi) {
		case 1 : {here = ''; break;}
		case 2 : {here = ''; break;}
		case 3 : {here = '�'; break;}
		case 4 : {here = '�'; break;}
		case 5 : {here = '�'; break;}
		case 6 : {here = '�'; break;}
		case 7 : {here = '�'; break;}
		case 8 : {here = '�'; break;}
		case 9 : {here = '�'; break;}
		case 0 : {here = '�'; break;}
	       }//end of case
       freq = random (8800) + 250;
       del = random(40);
       c = random (16);
       x = random (80) + 2;
       y = random(50);
       sound (freq);
       gotoxy (x,y);
       clreol();
       textcolor (c);
       cout << here;
       delay (del + 2);
       nosound();
 }
 nosound();
}