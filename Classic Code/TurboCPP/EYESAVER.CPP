#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <dos.h>
#include "C:\tc\bin\stars.h"


int eyex=-1, eyey, b;


void eye();
void saver();

void main()//the main thing man...
{

   nosound();
   int gdriver = VGA, gmode = VGAHI, errorcode;
   struct palettetype pal;
   int color, maxcolor, ht;
   initgraph(&gdriver, &gmode, "");

   errorcode = graphresult();

   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
   getpalette(&pal);
   settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);//sort of necessary
   cleardevice();
   saver();
   closegraph();
   exit(0);
} //end of main nuff said


//---------------------------------------------------------------------


void eye()
{
 setcolor(7);
 setfillstyle(SOLID_FILL, 15);
 fillellipse (eyex+15, eyey+13,17,15);
 setcolor(b);
 setfillstyle (LTBKSLASH_FILL, b);
 fillellipse (eyex+15, eyey+13,9,7 );
 setfillstyle (SOLID_FILL, 0);
 fillellipse (eyex+15,eyey+13,4,3);
 setcolor(7);
 setfillstyle (SOLID_FILL, 15);
 fillellipse (eyex+11,eyey+9,2,2);

}


//-------------------------------------HI---------------------------

void saver()
{
 int randstuff, lev; //level of sound
 char snd; /*SOUND CHOICE*/

 setcolor (10);
 outtextxy (10,10, "Do you wish to have sound? (y/n)");
 snd = getche();
 if (snd == 'Y' || snd == 'y')
      {
	outtextxy (10,20, "Enter the level of sound in Hz (50-5000)");
	gotoxy (2,30);
	cout << "";
	cin >> lev;
	  if (lev > 5000)
	      lev = 5000;
	  if (lev < 50)
	      lev = 50;

      }//sound level

 cleardevice();

 stars();

 setrgbpalette(3,45,45,50);
 setcolor (12);
 settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);//sort of necessary

 outtextxy (10, 130, "Press any key to exit");
 sleep (2);
 while (!kbhit())
  {
   randstuff = rand() % 20;
   eyex = rand() % 620 + randstuff;
   delay (2);
   b = rand() % 4;
   if (b == 0)
       b = 6;
   if (b == 1)
       b = 9;
   if (b == 2)
       b = 2;
   if (b == 3)
       b = 10;

   eyey = rand() % 460 + (randstuff + 1);
   eye();
   if (snd == 'y' || snd == 'Y')
     {
      sound (lev);
      delay (2);
      nosound();
     }
     else
       {
	 nosound();
       }


   delay ((randstuff - 5) + (randstuff * 2));

  }
}



//------------------END-SO-FAR------------------------------------------