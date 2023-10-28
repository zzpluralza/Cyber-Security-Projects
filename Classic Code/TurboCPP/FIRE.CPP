#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <dos.h>

void fire();


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
   fire();
return 0;
}

void fire()
{
 cleardevice();
 int x, y, cnt, col, c;
 cnt = 0;
 col = 1;
 for (cnt = 0; cnt < 185; cnt++)
 {
  if (col > 3)
  {
   col =1;
  }

  if (col == 1)
  {
   c = 7;
  }
  if (col == 2)
  {
   c =15;
  }
  if (col == 3)
  {
   c = 8;
  }
  x = rand() % 639;

  y = rand() % 479;
  putpixel (x,y,c);
  col++;

} //end of stars loop

 setrgbpalette(3, 25, 25, 25);
 setfillstyle(SOLID_FILL, 10);
 setcolor(2);
 fillellipse(100,300,50,50);
 circle(100,300,51);
 circle(100,300,52); //end of blob

 setcolor(3);       //SHIP STUFF
 circle (251,311,6);
 circle(282,311,10);
 rectangle (257,308,271,313);

 setcolor(8);
 setfillstyle(SOLID_FILL, 8);
 fillellipse(250,310,6,6);  //HEAD

 bar (257, 308, 270,312);    //BODY
 fillellipse (281,310,10,10); //BODY

 setcolor(1);
 line (245,307,249,307);  //COCKPIT THING
 line (244,308,249,308);
 setcolor(9);
 line (245,307,247,307); //end of ship

 sleep (1);
   putpixel (249, 314, 4);
   delay (800);
   putpixel (249, 314, 12);
   delay (400);
   int bang, big, hi;
  for (hi = 0; hi < 3; hi++)
  {
   for (bang = 249; bang > 150; bang = bang - 4)
   {
     setcolor(12);
     line (bang, 314, bang-4, 314);
     delay (10);
   }
   setcolor(0);
   line (249, 314, 150, 314);
   setcolor(3);       //SHIP STUFF
   circle (251,311,6);
   setcolor(8);
   setfillstyle(SOLID_FILL, 8);
   fillellipse(250,310,6,6);  //HEAD
   setcolor(1);
   line (245,307,249,307);  //COCKPIT THING
   line (244,308,249,308);
   setcolor(9);
   line (245,307,247,307); //end of ship
   delay (100);
  }
   big = 1;
 for (hi = 0; hi < 4; hi++)
  {
   for (bang = 240; bang > 153; bang = bang - 4)
   {
    setfillstyle(SOLID_FILL, 12);
    setcolor(12);
    fillellipse(bang, 310, big, big);
    delay (20);

    setfillstyle(SOLID_FILL, 0);
    setcolor(0);
    fillellipse(bang, 310, big, big);
    big++;
    if (big > 2)
     big = 1;
   }
  }

  for (hi = 52; hi < 450; hi = hi + 10)
  {
   setfillstyle(SOLID_FILL, 10);
   setcolor(2);
   fillellipse(100,300,hi,hi);
   circle(100,300,hi + 1);
   circle(100,300,hi+2); //end of blob
   delay (30);
   if (hi > 100)
   {
    setcolor(7);
    outtextxy (255, 300, "ARGH!");
    setcolor(15);
    outtextxy (257, 298, "ARGH!");
   }

  }
  sleep(1);

 getch();
}