#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <time.h>

int main(void)
{
   int gdriver = DETECT, gmode, errorcode;
   int c, x, y;
   initgraph(&gdriver, &gmode, "");
   errorcode = graphresult();
   if (errorcode != grOk)
   {  printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
   c = 1;
   settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
   cleardevice();
   while (c < 20)
   {
   srand(640);
   if (c > 15)
     { c = 1;}
   randomize ();
   x = (rand() % 640);
   srand(480);
   randomize ();
   y = (rand() % 480);
   setcolor (c);
   outtextxy(x,y, " ARGH ");
   c++;
   }
   return 0;
}