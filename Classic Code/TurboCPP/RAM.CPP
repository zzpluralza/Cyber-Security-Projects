#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <dos.h>
 void ram();

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
   ram();
return 0;
}

void ram()
{
 cleardevice();
 setcolor(7);
 outtextxy (10,20, "Engaging the thrusters, you move your ship on an intercept");
 outtextxy (10,30, "course towards the blob.");
 setcolor(15);
 outtextxy (12,18, "Engaging the thrusters, you move your ship on an intercept");
 outtextxy (12,28, "course towards the blob.");
// sleep(7);
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
 sleep (2);
 sound (950);
 delay(50);
 nosound();
 setcolor(1);
 line (292,306,292,314);
 delay(220);
 sound (950);
 delay(50);
 nosound();
 setcolor(9);
 line(291,307,291,313);
 delay(220);
 sound (950);
 delay(50);
 nosound();
 setcolor(7);
 line(291,308,291,312);
 sound (950);
 delay(50);
 nosound();
 delay(100);
 setcolor(15);
 line (291,309,291,311);

 int head, cock, thrus, body, blb;
 blb = 52;
 body = 257;
 cock = 244;
 thrus = 291;

for (head = 250; head >= 125; head = head - 5)

{
 setcolor(8);
 setfillstyle(SOLID_FILL, 8);
 fillellipse(head,310,6,6);  //HEAD

 bar (body, 308, body+13,312);    //BODY
 fillellipse (body+24,310,10,10); //BODY

 setcolor(1);
 line (cock+1,307,cock+5,307);  //COCKPIT THING
 line (cock,308,cock+5,308);
 setcolor(9);
 line (cock,307,cock+2,307); //end of ship

 setcolor(1);
 line (thrus+1,306,thrus+1,314);

 setcolor(9);
 line(thrus,307,thrus,313);

 setcolor(7);
 line(thrus,308,thrus,312);

 setcolor(15);
 line (thrus,309,thrus,311);
 delay(40);

 setfillstyle(SOLID_FILL, 10);
 setcolor(2);
 fillellipse(100,300,50,50);
 circle(100,300,51);
 circle(100,300,52); //end of blob

 setcolor(0);
 setfillstyle(SOLID_FILL, 0);
 fillellipse(head,310,6,6);  //HEAD

 bar (body, 308, body+13,312);    //BODY
 fillellipse (body+24,310,10,10); //BODY

 setcolor(0);
 line (cock+1,307,cock+5,307);  //COCKPIT THING
 line (cock,308,cock+5,308);
 setcolor(0);
 line (cock,307,cock+2,307); //end of ship

 line (thrus+1,306,thrus+1,314);

 line(thrus,307,thrus,313);

 line(thrus,308,thrus,312);

 line (thrus,309,thrus,311);

  setfillstyle(SOLID_FILL, 10);
  setcolor(2);
  fillellipse(100,300,50,50);
  circle(100,300,51);
  circle(100,300,52); //end of blob

 thrus = thrus - 5;
 body = body - 5;
 cock = cock - 5;

}//ram loop end
 delay(100);
 for (blb = 52; blb < 250; blb= blb+5)
  {
   sound (blb + 700);
   setfillstyle(SOLID_FILL, 10);
   setcolor(2);
   fillellipse(100,300,blb,blb);
   circle(100,300,blb+1);
   circle(100,300,blb+2); //end of blob
   blb++;
   delay(10);
  }
   nosound();
   delay(400);
   cleardevice();

}