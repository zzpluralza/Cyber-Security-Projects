#include <iostream.h>
#include <conio.h>
#include <time.h>
#include <dos.h>
#include <stdlib.h>
#include <math.h>

void apoc();

void main()
{
    textmode (C4350);
    clrscr();
    apoc();

}

void apoc()
{
   long yeah, div, mod;
   int c = 1;
   char tf;
    tf = 'F';
    yeah = 3;
    textcolor(c);
    clreol();
    cout << "2 ";
    c++;
    while (!kbhit())
      {
	 if (c > 15)
	     c = 1;


	     div = 7;

	     while (div > 2)
		{
		    if (div == yeah)
			 {
			    div--;
			 }

		   mod = yeah % div;

		   if (mod > 0)
		       {
			tf = 'T';
		       }
		   else
		       {
			tf = 'F';
			break;
		       }
		  div--;
		}//end of for

	     if (tf == 'T')
		 {
		   textcolor(c);
		   clreol();
		   cout << yeah << " ";
		   c++;
		 }
	yeah = yeah + 2;
       }//end of while loop



}