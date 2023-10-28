#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <dos.h>

void introduction();
void stars();
void attack();
void planet();
void explosion();

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
   introduction();
return 0;
}

void stars()
{
 cleardevice();
 int x, y, cnt, col, c;
 cnt = 0;
 col = 1;
 for (cnt = 0; cnt < 350; cnt++)
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

}//end of stars function

void introduction()
{
 int x, c;
 stars();

 setlinestyle(SOLID_LINE, 1, 1);
 setcolor(7);     //PLANET
 circle (420,180,50); //PLANET
 setcolor(9);
 circle (420,180,49);
 setcolor(1);
 circle (420,180,48);
 setrgbpalette(3, 20,8,220);
 setfillstyle(SOLID_FILL, 3);
 fillellipse(420, 180,47, 47);//END OF PLANET
 setcolor (14);
 circle(320,130,8);
 setcolor (7);
 circle(320,130,7);
 setfillstyle(SOLID_FILL, 14);
 fillellipse(320,130,7,7);

 settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
 setcolor (2);
 outtextxy(12,300, "On a small planet a remote observation post detected something unusual.");

 setcolor (10);
 outtextxy(14,298, "On a small planet a remote observation post detected something unusual.");

 setcolor (2);
 outtextxy(12,310, "Scans showed it was a gasoeus cloud.  It classified it as harmless.");

 setcolor (10);
 outtextxy(14,308, "Scans showed it was a gasoeus cloud.  It classified it as harmless.");

 setcolor(2);
 outtextxy(12, 320, "Those on the observation post would soon learn it was far from that.");

 setcolor (10);
 outtextxy(14, 318, "Those on the observation post would soon learn it was far from that.");
 int blob;
 for (blob = 0; blob < 520; blob++)
 {
 if (blob % 2 == 0)
 {
  setfillstyle(SOLID_FILL, 10);
  bar(300,200,301,201);
 }
 else
 {
  setfillstyle(SOLID_FILL, 0);
  bar(300,200,301,201);
 }
 delay (45);
}//end of for loop
 cleardevice();
 attack();

}

void attack()
{

 setfillstyle(SOLID_FILL, 8);
 bar(30,30,600,470);
 setcolor (10);
 circle( 120, 120, 80);
 setfillstyle(SOLID_FILL, 0);
 fillellipse(120,120,78,78);
 setcolor (10);
 circle(120,120,60);  //Radar thing
 circle(120,120,40);
 circle(120,120,15);
 circle (120,120,5);
 bar(280,50,550,200); //info screen
 setcolor(7);
 setrgbpalette(3, 90,1,1);
 setrgbpalette(5, 120,10,10);

 setfillstyle(SOLID_FILL, 3);
 fillellipse(450,360,50,50);
 setcolor(0);
 rectangle(278,48,552,202);
 setcolor(0);
 rectangle(0, 380,140,480);
 setcolor (15);
 outtextxy(282,60,"DETECTION: LEVEL I");
 outtextxy(282,70,"ANALYSIS:  Gaseous anomoly");
 outtextxy(282,80,"DISTANCE:  1.36 AU");
 outtextxy(282,90,"COMPOSITION: UNKNOWN");
 outtextxy(282,100,"POWER SOURCE: Detected");
 setcolor(4);
 sleep(2);
 sound(950);
 delay(50);
 nosound();
 outtextxy(282,110,"MOVEMENT OF OBJECT DETECTED");
 delay(1100);
 sound(1200);
 delay(50);
 nosound();
 setcolor(12);
 outtextxy(282,120,"THREAT ASSESMENT: 96.5%");

 int ln, counter, thing;
 setcolor (2);
 ln =62;
 while (ln < 110)
 {
  outtextxy(ln, 115, "ú");
  ln = ln + 4;
  delay (350);
  sound(800);
  delay(50);
  nosound();
 }
 nosound();
 setcolor (12);
 settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
 sound(950);
 delay(50);
 nosound();
 outtextxy(300, 150, "     ALERT");
 delay (500);
 setrgbpalette(3, 90,1,1);
 setrgbpalette(5, 120,10,10);
 counter = 1;
 thing = 1;
 while (counter < 60)
 {
  if (counter%3 == 0)
  {
   thing = 0;
  }
  if (thing == 1)
      {
	ln = 4;
      }
  if (thing == 2)
      {
	ln = 5;
      }
  if (thing == 3)
      {
	thing = 0;
	ln = 3;
      }

  setfillstyle(SOLID_FILL, ln);
  fillellipse(450,360,50,50);
  sound(1250);
  delay(80);
  nosound();
  thing++;
  counter++;

 } //end of alarmloop
 nosound();
 sleep(2);
 closegraph();
 planet();
}


void planet()
{
	int gdriver = VGA, gmode = VGAHI, errorcode;
	initgraph(&gdriver, &gmode, "");
	struct palettetype pal;
	errorcode = graphresult();

	if (errorcode != grOk)

	{

	printf("Graphics error: %s\n", grapherrormsg(errorcode));
	printf("Press any key to halt:");
	getch();
	exit(1);

	}

 cleardevice();
 int boom, freq;

 setrgbpalette(3,82,82,82);
 setfillstyle(SOLID_FILL, 9);//SKY
 bar(0,0,640,320);

 setfillstyle(SOLID_FILL, 14);//SUN
 fillellipse(220,120,15,15);

 setfillstyle(SOLID_FILL, 8); //installation stuff
 setcolor(3);                //
 fillellipse(240,321,30,30); //

 setfillstyle(SOLID_FILL, 8);//
 bar(380,321,480,280); //
 setcolor(8);            //
 fillellipse(420,282,20,16);//
 bar(481,300,535,321);//
 line (460,281,460,272);//
 setcolor(3);//
 line (481,300,481,321);//
 line (400,280,440,280);//

 setfillstyle(SOLID_FILL, 6);/*GROUND*/
 bar(0,321,640,480);
 sleep(1);
 setcolor(7);
 outtextxy(100,460,"  Ceti Alpha Observation Post on planet Rigel 7");
 setcolor(15);
 outtextxy(102,458,"  Ceti Alpha Observation Post on planet Rigel 7");
 sleep (2);
 for (freq = 1; freq < 110; freq++)
 {
   sound(freq * 10);
   delay (20);
 }
 nosound();
 boom = 0;
 freq = 1200;
 delay(20);
 while ( boom < 315)
 {
  setfillstyle(SOLID_FILL, 12);
  setcolor(12);
  bar(410, boom, 414, (boom + 8));
  boom = boom + 8;
  sound (freq);
  delay (4);
  freq = freq - 10;
 }
 nosound();
 delay(20);
 closegraph(); //closing again
 explosion();
}

void explosion()
{
	int gdriver = VGA, gmode = VGAHI, errorcode;
	initgraph(&gdriver, &gmode, "");
	errorcode = graphresult();

	if (errorcode != grOk)

	{

	printf("Graphics error: %s\n", grapherrormsg(errorcode));
	printf("Press any key to halt:");
	getch();
	exit(1);

	}

 cleardevice();
 stars();

 setrgbpalette(5, 20, 8, 220);

 setfillstyle(SOLID_FILL, 14);
 setcolor(15);
 fillellipse (295, 200, 30,30);//sun

 setcolor(7);
 circle (400,210,100);//planet
 setcolor(9);
 circle (400,210,99);
 setcolor(1);
 circle (400,210,98);
 setfillstyle(SOLID_FILL, 5);
 fillellipse(400,210,97,97);

 setcolor(10);//blob
 setfillstyle(SOLID_FILL, 2);
 fillellipse(305,240,10,10);
 int rad;
 setcolor(12);
 line (314,245,332,239);
 delay(600);
 setcolor(4);

 for (rad = 1; rad <= 10; rad++)
 {
  setfillstyle(SOLID_FILL, 4);
  fillellipse(332,239,rad, (rad+2));
  delay (1000);
  if (rad >= 8)
    {
    setfillstyle(SOLID_FILL, 12);
    setcolor (12);
    }
 }//end of explosion loop
 delay(1000);
 cleardevice();
 setcolor(7);
 outtextxy(20,102,"You are Dirk McCloud a man without a cause or clue.  You start");
 outtextxy(15,112,"out no where near where the blob was.  You are currently looking");
 outtextxy(15,122,"for a good place to buy some things at the Intergalatic Mall.");
 setcolor(15);
 outtextxy(22,100,"You are Dirk McCloud a man without a cause or clue.  You start");
 outtextxy(17,110,"out no where near where the blob was.  You are currently looking");
 outtextxy(17,120,"for a good place to buy some things at the Intergalatic Mall.");
 getch();
} //end of introduction.


