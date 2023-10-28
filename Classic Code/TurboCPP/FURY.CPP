#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <dos.h>
#include "c:\tc\bin\apoc.h"  //apocalypse intro
#include "c:\turboc\bin\themenu.h"//menu drawing
#include "c:\turboc\bin\star.h"//background while playing


/*ออออออออMAINอUSEDอVARIABLESอออ*/
//int clarkx,clarky,hitclark,starx,stary,start,shadx,shady,shadt,lifex,lifey,dead;
  int shadx, shady, shadt, start, stary, starx; //lifey, lifex, dead, //hitclark,
     // clarkx, clarky;

  int life=3, rank=0, direction=0, hits=0, shots=0, kills=0,//neccessary stuff
      firex[6], firey[6], i=0, h=0;
  double score=0;//so you can get one big old score


/*
อออออออออออออออPROCEDURESอOอPLENTYออออออออออออออออออออออออออออออออออออออ*/
void mmenu();//main menu options.  Other than game and quit are H files
void title();
void gamestuff(); //actual shooting and stuff.  You know
void board();//score, and rank listing thing while in play

void shadowexplode();//shadow boom
//void clarkboom();//clark bonus recieved
void starfuryexplode();

void fury();//variables for star fury drawing
void erasefury();//erase fury previous position
void shad();//variables for shadow vessel drawing
void eraseshad();//erases shadow
//void clark();//variables for clark drawing
//void eraseclk ();//erases clark
//void exlif(); /*Variables for extra life drawing*/
//void eraselif();//erases life thing

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
int main(void)//MAIN. Calling graphics mode
{
   nosound();
   int gdriver = VGA, gmode = MCGA, errorcode;
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
//ออออออWILLอRUNอINTROอHอFILESอออออออออออออออออออออออออออออออออออออออออออออออ
  //apocthing();
  title()
  mmenu();


 return 0;//closes up shop.
}//end of main

/*อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
       DRAWING PROCEDURE OF SHIPS, BONUSES BELOW
อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ*/

/*อออออออออออออFURYออPROCEDUREออออออออออออออออออออออออออออออออออออออออออ*/
void fury() //procedure for fury
 {

	setrgbpalette (3, 55,55,55);
	setrgbpalette (5, 28,28,28);
	setcolor(0);
	circle (start,445, 1); //Fury target to be hit
	//-------------------------
	setcolor(5);
	setfillstyle(SOLID_FILL, 5);
	bar (starx,     stary,      starx + 15, stary + 10);
	line (starx,    stary,      starx-14,   stary+14);   //left wing
	line (starx,    stary + 10, starx-14,   stary+19);
	line (starx-14, stary+21,   starx-14,   stary+12);//end of left wing
	line (starx,    stary,      starx-11,   stary+7);//left bottom wing
	line (starx-11, stary+5,    starx-11,   stary+10);
	line (starx+15, stary,      starx+30,   stary+14); //right wing
	line (starx+15, stary+10,   starx+30,   stary+19);
	line (starx+30, stary+21,   starx+30,   stary+12);//end of right wing
	line (starx+15, stary,      starx+27,   stary+7);//bottom right wing
	line (starx+27, stary+5,    starx+27,   stary+10);//end of bottom right wing
	setcolor (4);
	line (starx+2 , stary+1, starx+2,  stary+10);
	line (starx+3 , stary+1, starx+3,  stary+10);
	line (starx+14, stary+1, starx+14, stary+10);
	line (starx+13, stary+1, starx+13, stary+10);
	setcolor (9);
	line (starx+1,  stary-1, starx+3,  stary-3);//cockpit thing
	line (starx+15, stary-1, starx+13, stary-3);
	line (starx+13, stary-3, starx+3,  stary-3);
	line (starx+4,  stary-3, starx+4,  stary-1);
	line (starx+12, stary-3, starx+12, stary-1);//end of cockpit
 }//end of procedure
void erasefury()
{
	setcolor(0);
	setfillstyle(SOLID_FILL, 0);
	bar (starx-15, stary-15, starx+18, stary+15);
}

/*ออออออออออSHADOWอPROCEDUREออออออออออออออออออออออออออออออออออออออออออออ*/
void shad()//shadow procedure
 {
	setcolor(0);
	circle (shadt,45,1);//target to hit
	setcolor(8);
	line (shadx,   shady,   shadx-35, shady+7);
	line (shadx,   shady,   shadx+4,  shady+3);
	line (shadx+4, shady+3, shadx+10, shady+3);
	line (shadx+10,shady+3, shadx+14, shady);
	line (shadx+14,shady,   shadx+49, shady+7);
	line (shadx+49,shady+7, shadx+16, shady+4);//Right side
	line (shadx+16,shady+4, shadx+39, shady+12);
	line (shadx+39,shady+12,shadx+17, shady+7);
	line (shadx+17,shady+7, shadx+32, shady+16);
	line (shadx+32,shady+16,shadx+16, shady+10);
	line (shadx+16,shady+10,shadx+13, shady+12);
	line (shadx+13,shady+12,shadx+10, shady+10);
	line (shadx-35,shady+7, shadx-2,  shady+4);//left side
	line (shadx-2, shady+4, shadx-25, shady+12);
	line (shadx-25,shady+12,shadx-3,  shady+7);
	line (shadx-3, shady+7, shadx-18, shady+16);
	line (shadx-18,shady+16,shadx-2,  shady+10);
	line (shadx-2, shady+10,shadx+1,  shady+12);
	line (shadx+1, shady+12,shadx+4,  shady+10);
	line (shadx+4, shady+10,shadx+10, shady+10);//center thing
 }//end of shadow procedure
void eraseshad()
  {
   setcolor(0);
   setfillstyle(SOLID_FILL, 0);
   bar (shadx-39, shady-1, shadx+50, shady+17);
  }

/*ออออออออCLARKอPROCEDUREออออออออออออออออออออออออออออออออออออออออออออออออออ*/
void clark ()//begin of clark procedure
 {
	setcolor(15);
	setfillstyle (SOLID_FILL, 15);
	fillellipse (clarkx, 240, 4, 4);
	setcolor (13);
	line (clarkx, 243, clarkx,   255);
	line (clarkx, 255, clarkx-5, 265);//left leg
	line (clarkx, 255, clarkx+5, 265); //right leg
	line (clarkx, 250, clarkx+7, 250);//right arm
	line (clarkx, 250, clarkx-6, 245);//left arm
	setcolor(0);
	circle (hitclark, 242, 1);
	setfillstyle(SOLID_FILL, 0);
	bar (clarkx-2, 238, clarkx-1, 239);
	bar (clarkx+2, 238, clarkx+1, 239);
 }//end of clark
void eraseclk()
  {
   setcolor(0);
   setfillstyle(SOLID_FILL, 0);
   bar (clarkx-10, clarkx-10, clarkx+10, clarky+10);
  }

/*อออออออออออEXTRAอFURYอPROCEDUREอออออออออออออออออออออออออออออออออออออออออ*/
void exlif()//extra life thing
 {
	setcolor(14);
	line (lifex,   lifey,   lifex+10,lifey);//top thing
	line (lifex,   lifey,   lifex+5, lifey+5);
	line (lifex+10,lifey,   lifex+5, lifey+5);
	line (lifex+2, lifey+1, lifex-1, lifey+4);
	line (lifex-1, lifey+4, lifex+4, lifey+4);
	line (lifex+8, lifey+1, lifex+11,lifey+4);
	line (lifex+11,lifey+4, lifex+8, lifey+4);
	line (lifex+3, lifey,   lifex+5, lifey-2);
	line (lifex+7, lifey,   lifex+5, lifey-2);
	setcolor(9);
	line (lifex+1, lifey+1, lifex+9, lifey+1);
	line (lifex+3, lifey+2, lifex+7, lifey+2);
	line (lifex+4, lifey+3, lifex+6, lifey+3);
 }//end of extra life procedure
void eraselif(int lifex, int lifey)
  {
   setcolor(0);
   setfillstyle(SOLID_FILL, 0);
   bar (lifex-10, lifey-10, lifex+10, lifey+10);
  }

/*อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
       EXPLODING PROCEDURES BELOW
อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ*/

/*อออออออSHADOWออBOOMอEXPLOSIONอPROCEDUREอออออออออออออออออออออออออออออออ*/
void shadowexplode()
{
 int rad;
  setcolor(4);
  setfillstyle(SOLID_FILL,4);
  for (rad = 1; rad < 30; rad++)
  {
    fillellipse (shadt, 30, rad,rad);
    sound (rad * 100);
    delay(8);
  }
  delay (2);
  setcolor(0);
  setfillstyle(SOLID_FILL,0);
  bar (shadt-60,80,shadt+40,0);
  nosound();
  shadt = (rand() % 64) * 10;
  if (shadt > 630)
      shadt = 620;
  if (shadt < 20)
      shadt = 30;
  shadx = shadt - 10;
/*  if (score % 2500 == 0 && score > 100)
     {
       score = score + 300;
       setcolor(14);
       outtextxy (180, 200, "BONUS 300 points");
       sleep (1);
       setcolor(0);
       outtextxy (180, 200, "BONUS 300 points");
     }

  score = score + 100;*/
}//end of shadow explosion thing
/*อออFURYอEXPLODINGอPROCEDUREออออออออออออออออออออออออออออออออออออออออออออ*/

void starfuryexplode()//boom goes you
{
  int rad;
  setcolor(14);
  setfillstyle(SOLID_FILL,14);
  for (rad = 1; rad < 30; rad++)
  {
    fillellipse (start, 450, rad,rad);
    sound (rad * 100);
    delay(5);
  }
  setcolor(0);
  setfillstyle(SOLID_FILL,0);
  bar (start-50,400,start+40,480);
//  life--;
  nosound();
  start = (rand() % 64) * 10;
  starx = start - 18;
  delay (900);
  fury();
}
/*ออCLARKออEXPLODINGอPROCEDUREออออออออออออออออออออออออออออออออออออออออออออออ*/
void clarkboom()// he explodes 1000pts bonus
{
 int clarkhead, leftarm, rightarm;
/*  gotbonus++;
  int seeya= 0;
  clark();
  setcolor(15);
  outtextxy (starx-10, 435, "Sorry, Clark. You've been impeached!");
  sleep (2);
  outtextxy (clarkx-10, 230, "Oh no!");
  sleep (2);
  setcolor(0);
  outtextxy (clarkx-10, 230, "Oh no!");*/

  leftarm = clarkx;//flying arms
  rightarm = clarkx;//flying arms heh heh heh

  for (clarkhead = 240; clarkhead > -275; clarkhead = clarkhead - 5)//head flies off loop
  {
   setcolor(0);
   setfillstyle(SOLID_FILL, 0);
   fillellipse (clarkx, clarkhead,4,4);
   outtextxy (clarkx+5,clarkhead-10, "I'll be back.");
   line (rightarm,250, rightarm+7,250);//right arm
   line (leftarm, 250, leftarm-6, 245);//left arm
     setcolor(15);//redrawing the head
   setfillstyle(SOLID_FILL, 15);
   fillellipse (clarkx,clarkhead-5,4,4);
   outtextxy (clarkx+5,clarkhead-15, "I'll be back.");
   rightarm = rightarm + 5;
   leftarm = leftarm - 5;
   setcolor(13);
   line (rightarm,250, rightarm+7,250);//right arm
   line (leftarm, 250, leftarm-6, 245);//left arm
   setcolor(0);
   setfillstyle(SOLID_FILL, 0);
   bar (clarkx-2,clarkhead-2,clarkx-1,clarkhead-1);//redrawing the eyes
   bar (clarkx+2, clarkhead-2, clarkx+1, clarkhead-1);//eyes redrawing
   sound (clarkhead * 10);
   delay(10);
  }
   setcolor(0);//double check, head gets erased
   setfillstyle(SOLID_FILL, 0);
   fillellipse (clarkx, clarkhead,4,4);//end of double check
   nosound();//head flies off
  for (seeya = 0; seeya < 32; seeya++)
  {
    setcolor (0);
    setfillstyle(SOLID_FILL, 0);
    fillellipse (clarkx, 245, seeya + 1, seeya);
    sound (50 * seeya);
    delay (25);
  }
  nosound();
  setcolor (12);
  outtextxy (clarkx+10, 200, "1000 POINTS AWARDED!");
  sleep (1);
  setcolor (0);
  outtextxy (clarkx+10, 200, "1000 POINTS AWARDED!");
  outtextxy (starx-10,435, "Sorry, Clark. You've been impeached!");
  ifhere = 0;
  clarkx = 10;
  hitclark = 10;
}
/*อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
   GUTS OF GAME  BELOW
อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ*/


//ออออFURYออFIRINGอออออออออออออออออออออออออออออออออออออออออออออออออออออออ
void furyfire()
   {
    if (i > 5)//checking thing
	{ i = 0; }

    setcolor (9);
    setfillstyle (LTBKSLASH, 1);
    firey[i] = 430;
    firex[i] = furyx;
    fillellipse (firex[i], firey[i], 1, 3);
   }


//อออMAINอMENUอAREAอTHINGออออออออออออออออออออออออออออออออออออออออออออออออ

void mmenu()
  {
   char isupper(char menufury);

     while ((menufury != 'X') && (menufury != 'x'))
	 {
	  menuthing();
	  menufury = getch();
	  switch (menufury) {
			       case 'T' : { tutorial(); break; }//tutorial procedure H
			       case 'P' : { gamestuff(); break; }//game procedure
			       case 'C' : { credito(); break; } //credit procedure H
			       case 'I' : { inspire(); break; } //IM procedure H
			    }//end of case
	 }//end of loop

  }//end of main menu


//อออออออออGAMEอSTUFFอPROCEDUREอออออออออออออออออออออออออออออออออออออออออออ
void gamestuff()//game main body procedure
 {
  char isupper(char move);
  /* 1 = star fury
     2 = shadow
     3 = clark
     4 = ex life
     i = shot counter thing */

  cleardevice();
  sstart();

  while ((move != 'X') && (move != 'x') && (life > 0))
    {
     sfield();
     board();
     shadow();
     fury  ();
     move = getch();
     switch (move) {
		     case 'K' : { direction = 1; break; }
		     case 'M' : { direction = 2; break; }
		     case 'F' : { furyfire(); break; }

		   }//end of case thing

     switch (direction) {
			  case 1 : { erasefury(); //moving left
				     x1 = x1 - 2;
				     if (x1 < 2)
					 { x1 = 2; }
				     fury();
				     break;
				   }
			  case 2 : { erasefury();
				     x1 = x1 + 2;
				     if (x1 > 638)
					 { x1 = 638; }
				     fury();
				     break;
				   }
			}//end of direction thing

    }//end of loop for game play

 }//end of gamestuff procedure

//อออออออออออออBOARDออPROCEDUREอออออออออออออออออออออออออออออออออออออออออออออ
void board()//stuff shown during play
  {
     gotoxy (1,1);
     cout << "SCORE : " << score << "     Star Fury(s) : " << life << "   KILLS : "<< killcount<< "    RANK: ";
     switch (rank) {//beginning of case statement
		      case 0 : { cout<<"Flt.Officer"; break; }
		      case 1 : { cout<<"2nd Lt.    "; break; }
		      case 2 : { cout<<"1st Lt.    "; break; }
		      case 3 : { cout<<"Major      "; break; }
		      case 4 : { cout<<"Commander  "; break; }
		      case 5 : { cout<<"Captain    "; break; }
		   }//end of case statement
  }//end of board procedure

/*อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
       TITLE THINGAMAJIG WHEN BEGINNING
อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ*/
void title()
{
  int top, bot, mid, mid2;
  cleardevice();

  setcolor(15);
  outtextxy (135, 180, " Star Fury fighter vs. Shadow vessel ");
  outtextxy (155, 190, " BUILD 0300");
  outtextxy(150, 260, "Press space to continue");
  setcolor(9);
  outtextxy (10, 320, "Based on the hit TV show BABYLON 5!");
  setcolor(15);
  outtextxy(5,340, "(c) 1997 Apocalypse Inc.  All rights reserved.  Any reproduction");
  outtextxy(5,350, "of this program will result in your kidneys exploding and such.");
  outtextxy(5,360, "all this stuff is ours.  Please read the legal disclaimer.");
  top = 14;
  mid = 12;
  mid2 = 4;
  bot = 6;
  cnt = 0;
  while (!kbhit())
  {
   setcolor(top);
   outtextxy (85, 110, "        ÛÛÛÛÛÛ    ÛÛ   Û   ÛÛÛÛÛÛÛ    ÛÛ   Û ");
   outtextxy (85, 118, "       ÛÛÛ   Û   ÛÛ   ÛÛ  ÛÛÛ    ÛÛ  ÛÛ   ÛÛ  ");
   outtextxy (45, 40, "  ÛÛÛÛÛ   ÛÛÛÛÛÛÛ  ÛÛÛÛÛÛ  ÛÛÛÛÛÛ ");
   outtextxy (45, 48, " ÛÛ         ÛÛ    ÛÛ   ÛÛ ÛÛ    ÛÛ");
   setcolor(mid);
   outtextxy (85, 126, "      ÛÛÛ       ÛÛ   ÛÛ  ÛÛ     ÛÛ   ÛÛ ÛÛÛ  ");
   outtextxy (85, 134, "      ÛÛÛÛÛÛ   ÛÛ   ÛÛ   ÛÛÛÛÛÛÛÛ     ÛÛÛ    ");
   outtextxy (45, 56, "ÛÛ          ÛÛ   ÛÛ   ÛÛ  ÛÛ    ÛÛ");
   outtextxy (45, 64, "ÛÛÛÛÛ      ÛÛ   ÛÛÛÛÛÛÛ   ÛÛÛÛÛÛÛ ");
   setcolor(mid2);
   outtextxy (85, 142, "      ÛÛÛ      ÛÛ   ÛÛ   ÛÛ   ÛÛ     ÛÛ      ");
   outtextxy (85, 150, "      ÛÛ       ÛÛ  ÛÛ   ÛÛ     ÛÛ    ÛÛ      ");
   outtextxy (45, 72, "    ÛÛ     ÛÛ   ÛÛ   ÛÛ  ÛÛ   ÛÛ  ");
   outtextxy (45, 80, "   ÛÛ     ÛÛ   ÛÛ   ÛÛ  ÛÛ     ÛÛ ");
   setcolor(bot);
   outtextxy (45, 88, "  ÛÛ      ÛÛ   ÛÛ   ÛÛ  ÛÛ     ÛÛ ");
   outtextxy (45, 96, "ÛÛÛ      ÛÛ   ÛÛ   ÛÛ  ÛÛ      ÛÛ ");
   outtextxy (85, 158, "      ÛÛ       ÛÛ  ÛÛ   ÛÛ     ÛÛ   ÛÛ       ");
   outtextxy (85, 166,"      ÛÛ       ÛÛÛÛÛÛ   ÛÛ      ÛÛ  ÛÛ       ");
   cnt++;
   switch (cnt) {
		  case 5 : {  cnt = 1; break; }
//-----------------------------------------------------------------------
		  case 1 : {  top = 12;
			      bot = 14;
			      mid = 4;
			      mid2 = 6;
			      break; }
//-----------------------------------------------------------------------
		  case 2 : {  top = 4;
			      mid = 6;
			      mid2 = 14;
			      bot = 12;
			      break; }
//-----------------------------------------------------------------------
		  case 3 : {  top =6;
			      mid =14;
			      mid2 =12;
			      bot = 4;
			      break; }
//-----------------------------------------------------------------------
		  case 4 : {  top =14;
			      mid =12;
			      mid2 =4;
			      bot = 6;
			      break; }
	       }//end of case
//-------------END-OF-CASE-----------------------------------------------
	 }//end of loop
  getch();//counters loop thing so next page is not skipped
}//end of function
