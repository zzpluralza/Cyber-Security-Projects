#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <dos.h>
#include "C:\tc\bin\stars.h"

void youfight();

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
   settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
   youfight();
//   closegraph();
//   return 0;
}


void youfight()
  {
    //--------------------------------------------------------
    setcolor (8);
    setfillstyle (SOLID_FILL,8);
    ////////////////////////////

    fillellipse (90,95,12,15);//helm

    line (128,93, 108,135);//-
    line (129,93, 109,135);//-
    line (131,93, 111,135);//sword blade
    line (132,93, 112,135);//-

    //--------------------------------------------------------
    setcolor(6);
    setfillstyle (SOLID_FILL, 6);
    /////////////////////////////

    bar (102, 136, 118,139);//handle

    //--------------------------------------------------------
    setcolor (7);
    /////////////

    line (85,85,83,102); //more helm stuff

    line (130,93, 110,135);//-sword blade

    //--------------------------------------------------------
    setcolor(2);
    setfillstyle(SOLID_FILL,10);
    ///////////////////////////////////////
    line (86,110,82,120);
    line (95,110, 92,120);

    //--------------------------------------------------------
    setcolor (0);
    setfillstyle (SOLID_FILL, 0);
    /////////////////////////////
    bar (100, 92, 90, 95);//visor thing on helm
    bar (100, 95, 96, 104);//visor stuff for helm

    getch();

  }