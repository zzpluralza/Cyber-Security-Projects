#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <dos.h>
#include "C:\tc\bin\stars.h"


void mainmenu();

int main(void)
{

   nosound();
   int gdriver = VGA, gmode = VGAHI, errorcode;
   initgraph(&gdriver, &gmode, "");
   struct palettetype pal;
   int color, maxcolor, ht;
   errorcode = graphresult();

   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
   getpalette(&pal);

   mainmenu();
//   return 0;
}

  void mainmenu()
    {
      cleardevice();
      setcolor (4);
      setfillstyle (SOLID_FILL,8);
      bar3d (10,10,628,470,10,5);
	 setfillstyle(SOLID_FILL,0);
	 setcolor(0);
	 rectangle (388,63,616,406);
	 bar (390,65,610,400);
//++++++++++++++++++++++++++
      settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
      setfillstyle (HATCH_FILL, 8);
      bar3d (15,4,606,45,5,2);
      setcolor (9);
      outtextxy (26,10, "ROLE PLAY O' DEATH");


//++++++++++++++++++++++++++
      setcolor (12);
      setfillstyle (XHATCH_FILL, 8);
      bar3d (50,50,100,110,5,2);//INTRO
      bar3d (100,50,350,100,5,2);//INTRO

      bar3d (50,120,100,180,5,2);//play the game
      bar3d (100,120,350,170,5,2);//game

      bar3d (50,190,100,250,5,2);//credits
      bar3d (100,190,350,240,5,2);//credits

      bar3d (50,260,100,320,5,2);//inspirational message
      bar3d (100,260,350,310,5,2);//im

      bar3d (50,330,100,390,5,2);//exit
      bar3d (100,330,350,380,5,2);//exit

//+++++++++++++++++++++++++++++
      setcolor (15);

      outtextxy (60,  65, "I");
      outtextxy (60, 135, "P");
      outtextxy (60, 205, "C");
      outtextxy (60, 275, "M");
      outtextxy (60, 345, "X");
      settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
      outtextxy (12,420, " (c) 1997 Apocalypse Inc.  All rights reserved.  Any reproduction of");
      outtextxy (12,430, "this program will result in your kidneys exploding, while you still");
      outtextxy (12,440, "have them in you!");
      settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
      outtextxy (68,  68, "    Introduction");
      outtextxy (68, 138, "    Play RPO'D");
      outtextxy (68, 208, "    Credits");
      outtextxy (68, 278, "    Message");
      outtextxy (68, 348, "    Exit");



      getch();



    }
