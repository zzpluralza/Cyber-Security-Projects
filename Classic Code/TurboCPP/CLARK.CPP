#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <dos.h>


void clark();


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
   settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
   clark();
return 0;
}
void exlife()//extra life what it looks like
{
 setcolor(14);
 line (310,200,320,200);//top thing
 line (310,200,315,205);
 line (320,200,315,205);
 line (312,201,309,204);
 line (309,204,314,204);
 line (318,201,321,204);
 line (321,204,318,204);
 line (313,200,315,198);
 line (317,200,315,198);
 setcolor(9);
 line (311,201,319,201);
 line (313,202,317,202);
 line (314,203,316,203);


}
