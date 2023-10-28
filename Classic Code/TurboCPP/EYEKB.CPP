#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <dos.h>

int x, y;

void loopy();
void eye();
void eraser();

int main(void)//the main thing man...
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
   loopy();

  return 0;
} //end of main nuff said


///////////////////EYE/FUNCTION///\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


void eye()
{
 setcolor(7);
 setfillstyle(SOLID_FILL, 15);
 fillellipse (x, y,16,14);
 setcolor(1);
 setfillstyle (LTBKSLASH_FILL, 9);
 fillellipse (x, y,9,7 );
 setfillstyle (SOLID_FILL, 0);
 fillellipse (x,y,4,3);
}



////END/////OF////EYE////FUNCTION////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\



/////////EYE////ERASING////FUNCTION//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


void eraser()
{
 setcolor(0);
 setfillstyle(SOLID_FILL, 0);
 fillellipse (x, y,16,14);
}



/////END////OF////EYE///ERASING////FUNCTION//\\\\\\\\\\\\\\\\\\\\\\\\\



////////////////////LOOPY//FUNCTION//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


void loopy()
{
  x = 320;
  y = 180;
  eye();
  while ((kbhit() != 'q') && (kbhit() != 'Q'))
    {
       if (kbhit() == '\0')
	 {

	   if ((kbhit() == 'K') || (kbhit() == 'k'))
	    {
	       eraser();
	       x =+ 10;
	       eye();
	    }//end of left move if
	   if ((kbhit() == 'M') || (kbhit() == 'm'))
	    {
	      eraser();
	      x =- 10;
	      eye();
	      direct =
	    }//end of right move if

	 }//end of kbhit if stuff
    }//end of loop


} // end of loopy function



////////////END/////OF////FUNCTION/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\