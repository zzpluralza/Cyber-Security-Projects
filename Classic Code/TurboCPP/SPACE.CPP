#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <dos.h>
#include "C:\tc\bin\apoc.h"
#include "C:\tc\bin\intrd.h"
#include "c:\tc\bin\alert.h"
#include "C:\tc\bin\game1.h"
#include "C:\tc\bin\imessage.h"

void title();
void gamestuff();

int main(void)
{

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
    if (kbhit() == 'q' || kbhit() == 'Q') //QUIT ANYTIME THING
   {
    cleardevice();
    setcolor (15);
    outtextxy(80, 200, "Oh running away are you! You yellow ---");//Should print this
    getch();
    exit;
   }

   apocthing();
   closegraph(); //CLOSES TO RESET PALETTE
   initgraph(&gdriver, &gmode, ""); //REINTIALIZES GRAPHICS
   gamestuff();
   return 0;

}

void gamestuff()
{
 char ch1;

 title();

while (ch1 != 'x' && ch1 != 'X')
{
 setlinestyle(DASHED_LINE, 1, 1);
 menu(); //menu H file thing "INTRD.H"

 ch1 = getche(); //CHOICE THING AND LIGHT OF THINGAMAJIG
 if (ch1 == 'I' || ch1 == 'i')
    {
     setcolor (11);
     outtextxy(20, 90, "°±²Û  I  Û²±°  INTRODUCTION");
     sound (950);
     delay(50);
     nosound();
     delay (800);
     introduction();
    }
 else
 if (ch1 == 'p' || ch1 == 'P')
 {
  setcolor (11);
  outtextxy(20,140, "°±²Û  P  Û²±°  PLAY THE GAME");
  sound (950);
  delay(50);
  nosound();
  delay (800);
  setlinestyle(SOLID_LINE, 1, 1);
  play(); //playing game
 }
 else
 if (ch1 == 'M' || ch1 == 'm')
 {
   setcolor(11);
   outtextxy (20,190,"°±²Û  M  Û²±°  INSPIRATIONAL MESSAGE");
   sound(950);
   delay(50);
   nosound();
   delay(800);
   message();
 }
 else
 if (ch1 == 'x' || ch1 == 'X')
 {
  setcolor(11);
  outtextxy(20,240,"°±²Û  X  Û²±°  EXIT");
  sound(950);
  delay(50);
  nosound();
  delay(800);
  closegraph();
 }

 }//end of loop

}//end of thing


void title()
{
 struct palettetype pal; //TITLE
 getpalette(&pal);
 setrgbpalette( 3, 200,100,100);
 settextstyle(DEFAULT_FONT, HORIZ_DIR, 5);
 setcolor(3);
 outtextxy(1,40,"     DIRK");
 settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
 outtextxy(40, 90, "          & the Evil Blob");
 settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
 setcolor(15);
 outtextxy(30,300,"(c) 1997 Apocalypse Inc. All rights reserved. Any reproduction");
 outtextxy(25,310, "of this product will result in your kidneys exploding. Apocalypse");
 outtextxy(25,320, "Inc., and 'Over 2 years of violent family entertainment.' are ");
 outtextxy(25,330, "trademarks of Apocalypse Inc.  Don't mess with us. We know where");
 outtextxy(25,340, "you live.  And you can't do anything about it!");
 outtextxy(200,220, "Press any key to continue");
 getch();
}//end of title thing
