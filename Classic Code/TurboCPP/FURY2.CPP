#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <dos.h>
#include "c:\tc\bin\apoc.h"
#include "c:\turboc\bin\star.h"

int life=3, lifex, lifey=-10, clarkx=-10, clarky=250, hitclark, starx=400,   stary=420,
    shady=60, shadx=320, dstar=0, dshad=0, ext = 0, smove, fc = -1, fl, shadhit=1,
    sfirex, sfirey, tofireornot, clarkhere = 0, ifclark=100, kills=0, hits= 0, hitcolor=8,
    odirect, lifecoming, lifehere=0, minex, miney=-10, firex[10], firey[10], minehere=0,
    minecome, sx, sy= -10, shere=0, scome, gotshield=0, bx, by=-10, bhere=0, bcome,
    missilex[5], missiley[5], mc=0, ml=0, bossx, bossy, dboss;

double score = 0;
char move;
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
//global stuff above
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
void mplode();//missile explode
void gameboss();//boss battle procedure
void missile();
void erasemissile();
void badguy();//boss guy
void erasebadguy();//boss guy
void bonus();//extra points
void erasebonud();//erase bonus
void shieldthing();//shield drawing
void eraseshield();//erases shield
void minexplode(); //mine explode on impact of player
void minething();//mine thing comes and kills
void erasemine();//erase mine
void youdead();
void eraselife();//erases life thing
void eraseclark();//erase clark. Enough said
void shadowfire();//shadow firing
void furyfire(); //fury firing
void gamething(); //main game body procedure
void clark(); //clark drawing procedure
void exlife();//extra life drawing procedure
void fury();//fury drawing procedure
void shadow();// shadow draw procedure
void erasefury();//fury erase procedure
void eraseshadow();// shadow erase procedure
void seeya();//exiting procedure
void shadowexplode();//shadow boom!
void furyexplode();//boom goes you!
void clarkexplode();//clark goes up!

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
//ออออออออออออออออออออออออออออออออออออออออออออ
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
  if (ext == 0)
  {

   cleardevice();
 //  apocthing();//apoc intro
 //  re();//reing colors and such
//    title();
    cleardevice();
  // tutorial();//if want instructions
  // cleardevice();
   sstart();
   setrgbpalette (3, 55,55,55);
   setrgbpalette (5, 28,28,28);

   gameboss();//game body
  }
  closegraph();
  exit(0);
  return 0;
} //end of main nuff said

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void youdead()
{
 exit(0);
}

void seeya()

{
 exit(0);

}

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void bonus()
{
     setcolor(2);
     circle (bx,by,6);
     circle (bx,by,7);
     setcolor(10);
     circle (bx,by,5);
     setcolor(12);
     circle (bx,by,1);
}

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void erasebonus()
{
 setcolor (0);
 setfillstyle(SOLID_FILL, 0);
 bar (bx-8,by-8,bx+8,by+8);
}

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void minething()
{
    setcolor(8);
    ellipse (minex,miney,0,360,5,4);//centerthing
    line (minex+5,miney,minex+8,miney);//side thing
    line (minex-5,miney,minex-8,miney);//side thing
    line (minex,miney-4,minex,miney-7);//top
    line (minex,miney+4,minex,miney+7);
}//end of mine thing comes down and beats the crap out of you.... One
 //each time **maybe more later version**

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void minexplode()
{
 int crad;
 setcolor (7);
 setfillstyle (LTSLASH_FILL, 14);
 sound (650);
 for (crad = 1; crad < 20; crad++)
   {
    fillellipse (minex,miney,crad+2,crad);
    delay(3);
   }
 nosound();

}//end of mine explode

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void erasemine()
{
   setcolor(0);
   setfillstyle(SOLID_FILL, 0);
   bar (minex-22,miney-22,minex+22,miney+22);
}

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void eraselife()
{
 setcolor(0);
 setfillstyle(SOLID_FILL, 0);
 bar (lifex-5,lifey-5,lifex+12,lifey+6);

}//end of erase life procedure

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void shieldthing()
{
    setcolor(9);
    setfillstyle (LTBKSLASH_FILL, 7);
    fillellipse (sx,sy,6,4);
    setcolor (9);
    ellipse (sx,sy,0,360,7,5);
    setcolor(1);
    ellipse (sx,sy,0,360,7,6);

}//end of shield thing

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void eraseshield()
{
 setcolor(0);
 setfillstyle(SOLID_FILL, 0);
 bar (sx-9,sy-9,sx+9,sy+9);

}//end of eraseshield

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void exlife()//extra life what it looks like
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
}

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void clark()//here comes clark!!
{
 //clarky = 240
 setcolor(15);
 setfillstyle (SOLID_FILL, 15);
 fillellipse (clarkx,clarky,4,4);
 setcolor (13);
 line (clarkx, clarky+3,  clarkx,   clarky+15);
 line (clarkx, clarky+15, clarkx-5, clarky+25);//left leg
 line (clarkx, clarky+15, clarkx+5, clarky+25); //right leg
 line (clarkx, clarky+10, clarkx+7, clarky+10);//right arm
 line (clarkx, clarky+10, clarkx-6, clarky+5);//left arm
 setcolor(0);
 circle (hitclark, clarky+2,1);
 setfillstyle(SOLID_FILL, 0);
 bar (clarkx-2, clarky-2, clarkx-1, clarky-1);
 bar (clarkx+2, clarky-2, clarkx+1, clarky-1);
 //must say FINISH HIM
}

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void clarkexplode()
{
 int cboom;
 setcolor (14);
 setfillstyle (HATCH_FILL, 7);
 sound (780);
 for (cboom = 1; cboom < 15; cboom++)
  {
   fillellipse (clarkx, clarky, cboom + 3, cboom);
   delay (3);
  }
  nosound();
  eraseclark();

}//end of clark boom procedure

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void eraseclark()
  {
   setcolor(0);
   setfillstyle(SOLID_FILL, 0);
   bar(clarkx-16,clarky-15,clarkx+12,clarky+25);

  }

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void furyfire()
{
  if (fc < 5)
  {
   fc = fc + 1;//fire counter up one s from -1
   firex[fc] = starx;
   firey[fc] = stary - 10;
   sound (970);
   delay (2);
   nosound();
  }
  else fc = -1;
}

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void furyexplode()
  {
     int frad, cnt= 1;
     setcolor(12);
     setfillstyle (LTBKSLASH_FILL, 14);

   for (frad = 1; frad < 22; frad++)
      {
	fillellipse (starx, stary, frad + 3, frad);
	if (cnt % 2 == 0)
	   {sound (900); }
	else {sound (800);}
	delay (5);
	nosound();
	cnt++;
      }
   erasefury();
   life = life - 1;//lose a life
  }//end of fury explode

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void fury()
{
 if (gotshield > 0)
    { setcolor(9);
      line (starx-8,stary-8,starx+24, stary-8);
      setcolor(1);
      line (starx-8,stary-9,starx+24, stary-9);
    }//if has shield up one thing
 setcolor(5);
 rectangle(starx,stary,starx + 15,stary + 10);
 line (starx,stary,starx-14,stary+14);   //left wing
 line (starx, stary + 10, starx-14,stary+19);
 line (starx-14, stary+21, starx-14, stary+12);//end of left wing
 line (starx,stary, starx-11, stary+7);//left bottom wing
 line (starx-11,stary+5, starx-11, stary+10);
 line (starx+15, stary, starx+30, stary+14); //right wing
 line (starx+15, stary+10, starx+30, stary+19);
 line (starx+30, stary+21, starx+30, stary+12);//end of right wing
 line (starx+15,stary,starx+27, stary+7);//bottom right wing
 line (starx+27, stary+5, starx+27, stary+10);//end of bottom right wing
 setcolor (4);
 line (starx+2, stary+1, starx+2, stary+10);
 line (starx+3, stary+1, starx+3, stary+10);
 line (starx+14, stary+1, starx+14, stary+10);
 line (starx+13, stary+1, starx+13, stary+10);
 setcolor (9);
 line (starx+1, stary-1, starx+3, stary-3);//cockpit thing
 line (starx+15, stary-1, starx+13, stary-3);
 line (starx+13,stary-3,starx+3,stary-3);
 line (starx+4,stary-3,starx+4,stary-1);
 line (starx+12,stary-3,starx+12,stary-1);//end of cockpit
}

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void erasefury()
  {
    setcolor(0);
    setfillstyle(SOLID_FILL, 0);
    bar (starx-24, stary-24, starx+38, stary+30);
  }

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void shadow()
{
 setcolor(hitcolor);
 line (shadx,shady,shadx-35,shady+7);
 line (shadx,shady,shadx+4,shady+3);
 line (shadx+4,shady+3,shadx+10,shady+3);
 line (shadx+10,shady+3,shadx+14,shady);
 line (shadx+14,shady,shadx+49,shady+7);
 line (shadx+49,shady+7,shadx+16,shady+4);//Right side
 line (shadx+16,shady+4,shadx+39,shady+12);
 line (shadx+39,shady+12,shadx+17,shady+7);
 line (shadx+17,shady+7,shadx+32,shady+16);
 line (shadx+32,shady+16,shadx+16,shady+10);
 line (shadx+16,shady+10,shadx+13,shady+12);
 line (shadx+13,shady+12,shadx+10,shady+10);
 line (shadx-35,shady+7,shadx-2,shady+4);//left side
 line (shadx-2,shady+4,shadx-25,shady+12);
 line (shadx-25,shady+12,shadx-3,shady+7);
 line (shadx-3,shady+7,shadx-18,shady+16);
 line (shadx-18,shady+16,shadx-2,shady+10);
 line (shadx-2,shady+10,shadx+1,shady+12);
 line (shadx+1,shady+12,shadx+4,shady+10);
 line (shadx+4,shady+10,shadx+10,shady+10);//center thing
}

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void eraseshadow()
  {
   setcolor(0);
   setfillstyle(SOLID_FILL, 0);
   bar (shadx-39, shady-25, shadx+50, shady+28);
  }

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void shadowfire()
  {
    int thing;
    sfirex = shadx;
    sfirey = shady + 8;
    setcolor (13);
    for (thing = sfirey; thing < stary + 5; thing = thing +11)
      {
       line (sfirex, sfirey, sfirex, thing);
       sound (780);
       delay (2);
       nosound();
      }//end of for loop
      if ((sfirex >= starx - 8) && (sfirex <= starx + 8))
	 {
	   if (gotshield < 1)
	      {
		furyexplode();
		starx = random(62) * 10;
		delay(5);
		fury();
	      }
	  else if (gotshield > 0)
	     {
	       gotshield = gotshield-1;
	       sound (1050);
	       delay(5);
	       nosound();
	     }

	 }//end of if hit thing
      setcolor (0);
      line (sfirex, sfirey, sfirex, thing);

  }//end of shadow fire thing

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void shadowexplode()
  {
   int erad = 1, scnt= 1;
   firey[fl] = 9;
   setcolor (6);
   setfillstyle (XHATCH_FILL, 14);
   for (erad = 1; erad < 27; erad++)
     {
       fillellipse (shadx, shady, erad+2, erad);
       if (scnt % 2 == 0)
	   { sound (700); }
	else sound (800);
	delay (5);
	nosound();
	scnt++;

     }//end of for loop

  eraseshadow();
  kills++;
  delay (8);
  shadx = random(60) * 10;
  shadow();
  delay (8);

  }//end of shadow exploding thing

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void gamething()
{

  cleardevice();
  gotoxy (1,1);
  cout << "SCORE : "<< score << " LIFE : " << life << "  KILLS : " << kills << "  SHIELDS : " << gotshield;
  fury();
  shadow();
  randomize();
  while (!kbhit())
     {
       sfield();
       fury();
       shadow();
/*fire */if (fc > -1)
	 {
	  for (fl = 0; fl <= fc; fl++)
/*loopfire*/{

	     if (firey[fl] > 10)
	     {
	      setcolor(0);
	      setfillstyle (XHATCH_FILL, 0);
	      fillellipse (firex[fl],firey[fl],1,3);
	      firey[fl] = firey[fl] - 6;
	      firex[fl] = firex[fl];
	      if ((firey[fl] <=clarky+9) && (firey[fl] >=clarky+9))
		 {
		    if ((firex[fl] <= clarkx+25) && (firex[fl] >= clarkx-25))
			{
			  clarkexplode();
			  score = score + 1000;
			  clarkhere = 0;
			  clarkx = -10;
			}//end of hitting clark thing
		    else if (clarkx < 636)
			 { clarkhere = 1; }
		       else if (clarkx > 636)
			     {clarkhere = 0;
			      clarkx = - 10;
			     }
		  }
	      if ((firey[fl] < shady+21) && (firey[fl] > shady-21))
		{ if ((firex[fl] <= shadx+24) && (firex[fl] > shadx-24))
		   {
		     hits= hits + 1;
		      if (hits == 1)
			  {
			   hitcolor = 4;
			   delay (2);
			   score = score + 50;
			  }

		   else if (hits == 2)
			 {
			    shadowexplode();
			    score = score + 100;
			    hits = 0;
			    hitcolor= 8;
			 }//END OF IF FOR HITS
		   }//END OF INNER IF ON HITTING SHADOWSHIP
		}//END OF OUTTER IF FOR HITTING SHADOWSHIP
	      else {/*doing nothing if not hit*/  }
	      setcolor(14);
	      setfillstyle (XHATCH_FILL, 7);
	      fillellipse (firex[fl],firey[fl],1,3);

	     }//end of inner if thingamajig
	     else if (firey[fl] < 10)
	      {
		setcolor(0);
		setfillstyle (XHATCH_FILL, 0);
		fillellipse (firex[fl],firey[fl],1,3);
	      }//end of else
	    }//end of for loop

/*fire */}//end of if statement
//---------------------------------------------------
       if (clarkx > 636)
	    { clarkx = - 10;
	      clarkhere = 0;
	    }//safety precaution

       if (clarkhere == 0)
	   {  ifclark = rand()% 380;
	      if ((ifclark % 2 == 0))// || (ifclark == 175))//IF CLARK COMES
			 { clarkhere = 1;}
	      else if (ifclark % 2 > 0)//NOT COMING
		      { clarkhere = 0; }
	   }
       if (clarkhere == 1)//IF FIND IS HERE THEN THIS STUFF
	    {
	      eraseclark();
	      if (clarkx+3 < 636)
		  {
		   clarkx = clarkx + 3;
		   clark();
		   delay(1);
		  }
	      if (clarkx >= 636)
		  { clarkhere = 0;
		    eraseclark();
		    clarkx = -10; }
	    }//END OF CLARK COMING STUFF
//---------------------------------------------
//---------------------------------------------
       if (lifehere == 0)
	   {  lifecoming = rand()% 455;
	      if ((lifecoming == 88) || (lifecoming == 134))//IF CLARK COMES
			 { lifehere = 1;
			   lifex = ((rand() % 59) * 10) + 10; }
	      else if (lifecoming % 25 > 0)//NOT COMING
		      { lifehere = 0; }
	   }//END OF LIFE IF == 0
       if (lifehere == 1)//IF FIND IS HERE THEN THIS STUFF
	    {
	      eraselife();
	      if (lifey+2 < 478)
		  {
		   lifey = lifey + 2;
		   exlife();
		   delay(1);
		  }
	      if (lifey >= 479)
		  { lifehere = 0;
		    eraselife();
		    lifey = -10; }
	    }//END OF LIFE COMING THING
//-----------------------------------------------
//-----------------------------------------------

       if (bhere == 0)
	   {  bcome = rand()% 400;
	      if (bcome % 88 == 0)//IF CLARK COMES
			 { bhere = 1;
			   bx = ((rand() % 59) * 10) + 10; }
	      else if (bcome % 25 > 0)//NOT COMING
		      { bhere = 0; }
	   }//END OF LIFE IF == 0
       if (bhere == 1)//IF FIND IS HERE THEN THIS STUFF
	    {
	      erasebonus();
	      if (by+2 < 478)
		  {
		   by = by + 2;
		   bonus();
		   delay(1);
		  }
	      if (by >= 479)
		  { bhere = 0;
		    erasebonus();
		    by = -10; }
	    }//END OF LIFE COMING THING

   if (minehere == 0)
      {
	  minecome = rand() % 100;

	if ((minecome % 22 == 0))
	  {
	     minex = rand() % 59 * 10 + 10;
	     minehere = 1;
	  }//end of minecome if
      }
	if (minehere == 1)//IF FIND IS HERE THEN THIS STUFF
	   {
	      erasemine();
	      if (miney+3 < 478)
		  {
		   miney = miney + 3;
		   minething();
		   delay(1);
		  }
	      if (miney > 479)
		     {
		       minehere = 0;
		       erasemine();
		       miney = -10;
		     }

	   }//END OF MINECOMING THING

   if (shere == 0)
      {
	  scome = rand() % 650;

	if ((scome % 86 == 0))
	  {
	     sx = rand() % 59 * 10 + 10;
	     shere = 1;
	  }//end of shield come
      }
	if (shere == 1)//IF FIND IS HERE THEN THIS STUFF
	   {
	      eraseshield();
	      if (sy+3 < 478)
		  {
		   sy = sy + 3;
		   shieldthing();
		   delay(1);
		  }
	      if (sy > 479)
		     {
		       shere = 0;
		       eraseshield();
		       sy = -10;
		     }

	   }//END OF MINECOMING THING


    if (minehere== 1)
     {
      if ((miney > stary-48) && (miney < stary+48))
	 {
	   if ((minex > starx-48) && (minex < starx+48))
	      {
		minexplode();
		if (gotshield <= 1)
		      {
			furyexplode();
			erasemine();
			gotshield = 0;
			minehere=0;
			score = score - 1000;
			starx = rand() % 62 * 10;
			fury();
			miney = -10;
		    }//end of if
	       else if (gotshield > 1)
		 {
		  gotshield = gotshield-2;
		  sound (1050);
		  delay(4);
		  nosound();
		  erasemine();
		  miney = - 10;

		 }//end of else if

	      }//end of minex >starx if
	   else {
		 minehere = 0;
		 erasemine();
		 miney = -10;
		}//end of else thign
	 }//end of minex if
     }//end of mine thing
//==========================================
  //mine stuff up above here---
   if ((lifehere == 1))
      { if ((lifey >= stary-12) && (lifey <= stary+12))
	 {
	   if ((lifex >=starx-20) && (lifex <= starx+20))
	   { sound (1000);
	     eraselife();
	     life++;
	     lifey = -10;
	     lifehere = 0;
	     delay (2);
	     nosound();
	   }//end of if hit life
	  else { lifehere = 0;
		 eraselife();
		 lifey = - 10;
	       }

	 }//end of second big if

       }//end of big if

  if ((shere == 1))
      { if ((sy >= stary-23) && (sy <= stary+23))
	 {
	  if ((sx >=starx-25) && (sx <= starx+25))
	   { sound (1200);
	     eraseshield();
	     score = score + 75;
	     gotshield = gotshield + 1;
	     if (gotshield > 8)
	       { gotshield = 8; }
	     else { score = score + 100; }
	     sy = -10;
	     shere = 0;
	     delay (3);
	     nosound();
	   }//end of if hit life
	  else { shere = 0;
		 eraseshield();
		 sy = - 10;
	       }

	 }//end of second big if

       }//end of big if

  if ((bhere == 1))
      { if ((by >= stary-19) && (by <= stary+39))
	 {
	  if ((bx >=starx-29) && (bx <= starx+29))
	   { sound (680);
	     erasebonus();
	     score = score + (life * 250);
	     by = -10;
	     bhere = 0;
	     delay (3);
	     nosound();
	   }//end of if hit life
	  else { //bhere = 0;
		 erasebonus();
		 bhere = 0;
		 by = -10;
	       }

	 }//end of second big if

       }//end of big if


       smove = rand()%10;
       if (smove % 6 == 0)
	   { dshad = rand() % 6; }
       switch (dstar) {
			case 0 : { starx = starx; break; }
			case 1 : { erasefury();
				   starx = starx - 4;
				   if (starx < 20)
				       starx = 22;

				   break;
				 }
			case 2 : { erasefury();
				   starx = starx + 4;
				   if (starx > 630)
				       starx = 628;
				   break;
				 }
			case 3 : { furyfire();
				   dstar = odirect;
				   break;
				 }

			}//end of case
//  if (shadhit == 1)//if shadow not hit
//     {
      switch (dshad) {
		       case 0 : {shadx = shadx; break; }
		       case 1 : {
				 eraseshadow();
				 shadx = shadx - 4;
				 if (shadx <= 20)
				     { shadx = 22; }

				 break;
				}
		       case 2 : {
				 eraseshadow();
				 shadx = shadx + 4;
				 if (shadx >= 620)
				    { shadx = 618; }

				 break;
				}
		       case 3 : {
				 eraseshadow();
				 shadx = shadx + 4;
				 if (shadx >= 620)
				    { shadx = 618; }

				 break;
				}

		       case 4 : {
				 eraseshadow();
				 shadx = shadx - 4;
				 break;
				}
		       case 5 : {
				 tofireornot = rand() % 85;
				 if (tofireornot % 10 == 0)
				       shadowfire();
				 break;
				}

		     }//end of shadow case
//     }//end of if for if shadow hit
      shadow();
      fury();
//     if (life < 1)
//	 { youdead(); }//you die
//     else {/*do nothing else */}

}//end of loop
///-------------------.....---695046805496PROG7(*&)(%^*&%&*^%&^%*^&
//k = left  m = right
     dshad = rand() % 6;
     move = getch();
       switch (move) {
		       case 'F': {odirect = dstar;
				  dstar = 3; break; }//fire
		       case 'K': {dstar = 1; break; }//left
		       case 'M': {dstar = 2; break; }//right
		       case 'S': {dstar = 0; break; }//stop
		       case 'Q': {seeya(); break; }//quit
		     }//end of case

     gamething();//reruns gamething procedure


}//end of game stuff

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
void mplode()
{

}

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void missile()
{
/*  setcolor(8);
  line (missilex[mc],  missiley[mc],   missilex[mc]+8,missiley[mc]+8 );
  line (missilex[mc],  missiley[mc],   missilex[mc]-8,missiley[mc]+8 );
  line (missilex[mc]-8,missiley[mc]+8, missilex[mc]-2,missiley[mc]+16);
  line (missilex[mc]-2,missiley[mc]+16,missilex[mc]-5,missiley[mc]+22);
  line (missilex[mc]-5,missiley[mc]+22,missilex[mc],  missiley[mc]+30);
  line (missilex[mc]+8,missiley[mc]+8, missilex[mc]+2,missiley[mc]+16);
  line (missilex[mc]+2,missiley[mc]+16,missilex[mc]+5,missiley[mc]+22);
  line (missilex[mc]+5,missiley[mc]+22,missilex[mc],  missi1ey[mc]+30);*/
}
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
void erasemissile()
{
  setcolor(0);
  setfillstyle (SOLID_FILL, 0);
  bar (missilex[mc]-10,missiley[mc]-10,missilex[mc]+10,missiley[mc]+30);
}
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
void bossguy()
{
//bossx = 320, bossy = 80
 setcolor(hitcolor);
 circle (bossx,   bossy,   22);
 circle (bossx+20,bossy+4, 12);
 circle (bossx-20,bossy+4, 12);
 circle (bossx,   bossy-28,6);
 line   (bossx-8, bossy+22,bossx-20,bossy+50);
 line   (bossx-20,bossy+50,bossx-4, bossy+22);
 line   (bossx+8, bossy+22,bossx+20,bossy+50);
 line   (bossx+20,bossy+50,bossx+4, bossy+22);
 line   (bossx,   bossy-28,bossx+60,bossy-12);
 line   (bossx+60,bossy-12,bossx,   bossy-33);
 line   (bossx,   bossy-28,bossx-60,bossy-12);
 line   (bossx-60,bossy-12,bossx,   bossy-33);
 line   (bossx+60,bossy-6, bossx+60,bossy-16);
 line   (bossx-60,bossy-16,bossx-60,bossy-6 );
 setcolor (7);
 circle (bossx,   bossy-35,1);
 circle (bossx-60,bossy-5 ,1);
 circle (bossx+60,bossy-5 ,1);

}
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
void erasebossguy()
{
 setcolor (0);
 setfillstyle(SOLID_FILL, 0);
 bar (bossx-60,bossy-35,bossx+60,bossy+55);

}
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
void gameboss()
{
  cleardevice();
  gotoxy (1,1);
  cout << "SCORE : "<< score << " LIFE : " << life << "  KILLS : " << kills << "  SHIELDS : " << gotshield;
  fury();
  bossguy();

  while (!kbhit())//shooting
     {

/*fire */if (fc > -1)
	 {
	   for (fl = 0; fl <= fc; fl++)
/*loopfire*/{

	     if (firey[fl] > 10)
	     {
	      setcolor(0);
	      setfillstyle (XHATCH_FILL, 0);
	      fillellipse (firex[fl],firey[fl],1,3);
	      firey[fl] = firey[fl] - 6;
	      firex[fl] = firex[fl];

	      if ((firey[fl] < bossy+20) && (firey[fl] > bossy-20))
		{
		  if ((firex[fl] <= bossx+26) && (firex[fl] > bossx-26))
		   {
		     hits= hits + 1;
		      if (hits < 20)
			  {
			   hitcolor = 15;
			   bossguy();
			   sound (800);
			   delay (5);
			   hitcolor = 8;
			   bossguy();
			   score = score + 100;
			   nosound();
			  }

		   else if (hits >= 20)
			 {
			    score = score + 10000;
                            seeya();
			  //  endthing();
			 }//END OF IF FOR HITS
		   }//END OF INNER IF ON HITTING SHADOWBOSS
		}//END OF OUTTER IF FOR HITTING SHADOWBOSS
	      else {/*doing nothing if not hit*/  }
	      setcolor(14);
	      setfillstyle (XHATCH_FILL, 7);
	      fillellipse (firex[fl],firey[fl],1,3);

	     }//end of inner if thingamajig
	     else if (firey[fl] < 10)
	      {
		setcolor(0);
		setfillstyle (XHATCH_FILL, 0);
		fillellipse (firex[fl],firey[fl],1,3);
	      }//end of else
	    }//end of for loop

/*fire */}//end of if statement
     if (ml > 0)
	 {
	  for (mc = 0; mc < ml+1; mc++)
	    {
	      if (missiley[mc] < 475)
		{
		 erasemissile();
		 missiley[mc] = missiley[mc] + 8;

		 if ((missiley[mc] <= stary+12) && (missiley[mc] >= stary-12))
		      {
		       if ((missilex[mc] <= starx+15) && (missilex[mc] >= starx-15))
			  {
			    if (gotshield >= 3)
				 {
				  mplode();
				   erasemissile();
				  gotshield = gotshield - 3;

				 }//end of if
			    else
				{
				 mplode();
				 furyexplode();
				 gotshield = 0;
				 starx = rand() % 62 * 10;
				 fury();

				}//end of else
			  }//end of missile hit
		       else {  setcolor(8);
				  line (missilex[mc],  missiley[mc],   missilex[mc]+8,missiley[mc]+8 );
				  line (missilex[mc],  missiley[mc],   missilex[mc]-8,missiley[mc]+8 );
				line (missilex[mc]-8,missiley[mc]+8, missilex[mc]-2,missiley[mc]+16);
				line (missilex[mc]-2,missiley[mc]+16,missilex[mc]-5,missiley[mc]+22);
				line (missilex[mc]-5,missiley[mc]+22,missilex[mc],  missiley[mc]+30);
				line (missilex[mc]+8,missiley[mc]+8, missilex[mc]+2,missiley[mc]+16);
				line (missilex[mc]+2,missiley[mc]+16,missilex[mc]+5,missiley[mc]+22);
				line (missilex[mc]+5,missiley[mc]+22,missilex[mc],  missiley[mc]+30);

			}

		      }//end of y missile hit
		}//end of if thing
		  else if (missiley[mc] > 475)
		       {
			erasemissile();
			 missiley[mc] = bossy;
		       }
	    }//end of for
	 }//end of big if

       dboss = rand() % 4;

       switch (dstar) {
			case 0 : { starx = starx; break; }
			case 1 : { erasefury();
				   starx = starx - 4;
				   if (starx < 20)
				       starx = 22;

				   break;
				 }
			case 2 : { erasefury();
				   starx = starx + 4;
				   if (starx > 630)
				       starx = 628;
				   break;
				 }
			case 3 : { furyfire();
				   dstar = odirect;
				   break;
				 }

			}//end of case

      switch (dboss) {
		       case 0 : {bossx = bossx; break; }//stop
		       case 1 : {
				 erasebossguy();//left
				 bossx = bossx - 4;
				 if (bossx <= 20)
				     { bossx = 22; }

				 break;
				}
		       case 2 : {
				 erasebossguy();//right
				 bossx = bossx + 4;
				 if (bossx >= 620)
				    { bossx = 618; }

				 break;
				}
		       case 3 : {//fire or not
				 tofireornot = rand() % 85;
				 if ((tofireornot % 10 == 0) && (ml < 6))
				     {
				      ml++;
				      missiley[ml] = bossy + 8;
				      missilex[ml] = bossx;

				     }
				 else { /* do nothing*/}

				 break;
				}

		     }//end of shadow case

     }//end of loop
//-----------------------------
       move = getch();
       switch (move) {
		       case 'F': {odirect = dstar;
				  dstar = 3; break; }//fire
		       case 'K': {dstar = 1; break; }//left
		       case 'M': {dstar = 2; break; }//right
		       case 'S': {dstar = 0; break; }//stop
		       case 'Q': {seeya(); break; }//quit
		     }//end of case
     gameboss();//reruns gameboss procedure


}//end of game boss procedure