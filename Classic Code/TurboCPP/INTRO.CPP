#include <iostream.h>
#include <dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
/* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy, mode;
   char numname[80], modename[80];

   initgraph(&gdriver, &gmode, "");

   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   mode = getgraphmode();
   settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
   setcolor (45);
   outtextxy(1,20,"Hi there");
   setcolor(13);

/* clean up */
   getch();
   return 0;
}

