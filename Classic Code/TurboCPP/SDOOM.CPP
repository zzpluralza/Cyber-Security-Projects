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
		case 3 : {here = '÷'; break;}
		case 4 : {here = 'ø'; break;}
		case 5 : {here = 'û'; break;}
		case 6 : {here = 'Ò'; break;}
		case 7 : {here = '×'; break;}
		case 8 : {here = 'Ç'; break;}
		case 9 : {here = 'ô'; break;}
		case 0 : {here = 'ñ'; break;}
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