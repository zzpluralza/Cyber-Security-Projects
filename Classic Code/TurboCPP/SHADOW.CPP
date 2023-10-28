#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <dos.h>
#include "c:\tc\bin\apoc.h"
#include "C:\tc\bin\stars.h"

int bonus=0, gotbonus=0, shipslost=0, shotsfired=0, hits=0;
int lifey = 120,lifex= -5, lifehere = 0, liferand;//life x coordinant, if here, random appearance
int lifetarget = 0, rank = 0;
int life=3, fire, dead = 0, killcount=0;
long score;
int starx = 302, stary = 450, start = 320;//stuff for starfury
int shadx = 310, shady = 30, shadt = 320;//shadow stuff
int clarkx= 10, appear= 0, hitclark = 10, clarkhead=240, rightarm, leftarm; //president Clark  BONUS
int ifhere= 0, ext = 0;
int randomshoot, enemyx;

//-----------------------------DO NOT LOOK ABOVE THIS POINT HA HA----------


void enemyfire(); //enemy fire if kills exceed certain point
void endstuff();//info things
void movinglife();//coming to screen
void lifejourney();//moving across screen
void exlife();//picture of extra guy  little earthforce symbol
void clarkmove();//moving across screen
void clarkcoming();//if clark comes or not
void clark();//drawing of clark
void clarkboom();//clark bites it
void title();//star fury title
void restart();//resets colors and stuff
void fury();//your ship
void shadow();//the ship
void board();//score enemy, lives, etc
void gamething(); //let's rock nuff said
void furyfire();//you guy firing
void shadowfire();//randomize if it shoots or not
void starfuryexplode();//selfexplanatory
void shadowexplode();//same here
void tutorial();//instructions of game
void exlifehere();//if extra life is here


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
   apocthing();//apoc intro
   restart();//restarting colors and such
    title();
   score = 0;//setting score and life before game starts
   life = 3;
   cleardevice();
   tutorial();//if want instructions
   cleardevice();
   gamething();//game body
  }
  closegraph();
  exit(0);
  return 0;
} //end of main nuff said




void enemyshoot()
{
 int i,snd=6;
 randomshoot = rand() % 180;
if (randomshoot % 13 == 0)
    {
     enemyx = (rand() % 64) * 10;
     setfillstyle (LTBKSLASH_FILL, 13);
     setcolor(13);

     for (i = 0; i < 450; i = i + 5)
     {
      bar (enemyx, i, enemyx + 2, i + 10);
      sound (snd * 100);
      if (i % 25 == 0)
	  snd = 8;
      else
	  snd = 6;
      delay (1);
     }
     nosound();
     if (enemyx == start)
	 { starfuryexplode();
	   delay (200);
	   setcolor(0);
	   setfillstyle(SOLID_FILL, 0);
	   bar (enemyx, 0, enemyx + 2, i+5);

	 }//end of if
     else
     {
	   setcolor(0);
	   setfillstyle(SOLID_FILL, 0);
	   bar (enemyx, 0, enemyx + 2, i+5);
	   shadow();
	   fury();
     }//end of else
    }//end of enemy shooting if statement
    else
    {
    }//else for that enemy shootin thing
}//end of enemy fire


void bye()
{
 cleardevice();
}

void tutorial()//for people like you! Ha ha! You'll never see this insult!!
{
 char tut;//tutorial
 setcolor (15);
 outtextxy (10,10, "Would you like a tutorial? (y/n)");
 tut = getch();
 if (tut == 'Y' || tut == 'y')
 {
   cleardevice();
   setcolor(15);
   outtextxy (1,10, "You are a Star Fury pilot. A member of Delta Squad assigned");
   outtextxy (1,20, "Babylon5 before its cecession from Earth.  You have been ");
   outtextxy (1,30, "alerted and launched to intercept attack shadow vessels. You");
   outtextxy (1,40, "must not let one get by else B5 will fall.");
   stary = stary- 390;
   starx = starx -200;
   fury();
   stary = 450;
   starx = 302;
   setcolor (10);
   outtextxy (145,60, "This is your ship. A Star Fury fighter");
   shady = shady + 60;
   shadx = shadx - 208;
   shadow();
   shady = 30;
   shadx = 310;
   setcolor (8);
   outtextxy (148, 92, " This is your enemy. A Shadow vessel (100pts)");
   clarkx = 102;
   clark();
   clarkx = 10;
   lifex = 102;
   lifey = 180;
   exlife();
   lifex = 0;
   lifey = 120;
   setcolor (2);
   outtextxy (135, 185, "This is an extra starfury. Get this if you can.");
   setcolor (7);
   outtextxy (135, 240, "This is President Clark.  He assassinated President Santiago &");
   outtextxy (135, 250, "now runs the show.  Shoot him and you get 1000 pts bonus!");
   setcolor (15);
   outtextxy (10, 300, "CONTROLS: ");
   outtextxy (100, 310, "Moving Left <Left arrow key>");
   outtextxy (100, 320, "Moving Right <Right arrow key>");
   outtextxy (100, 330, "Firing = 'F'  key");
   outtextxy (100, 340, "To exit while in play, press 'x'");
   outtextxy (10, 400, " For every 12 kills you get a promotion.");
   outtextxy (10, 410, "As your rank gets to a certain point things get a little harder.");
   outtextxy (10, 440, "Press any key to continue.");
   getch();
   //if yes on tutorial end
  }
  else
  {
  }

  gamething();//no tutorial goes to game

}//end of tutorial







void exlifehere()
{
 if (lifehere == 0)
    {
      liferand = (rand() % 220);
      movinglife();
    }
 else//do nothing
    {
    }
}//end of randomizing thing



void movinglife()
{
  if ((liferand == 32) && lifehere == 0)
  {
   lifehere = 1;
  }

}

void lifejourney()
{
  exlife();
  setcolor(0);
  setfillstyle(SOLID_FILL,0);
  bar (lifex-25,110,lifex+15,126);
  lifex = lifex + 20;
  lifetarget = lifetarget + 20;
  if (lifex == 655)
  {
   lifehere = 0;
   lifex = -5;
   lifetarget = 0;
  }
  else
  exlife();
}//end of life functions... Ha ha ha!

void exlife()//extra life what it looks like
{

/* line (310,200,320,200);//top thing
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
  line (314,203,316,203);*/

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


void endstuff()
{
 cleardevice();
 setcolor(9);
 rectangle (1,1,639,479);
 rectangle (2,2,638,478);
 rectangle (3,3,637,477);
 rectangle (4,4,636,476);
 gotoxy (4,4);
 cout << "SCORE   : "<<score;
 gotoxy (4,5);
 cout << "KILLS   : "<<killcount;
 gotoxy (4,6);
 cout << "BONUSES : "<<bonus;
 gotoxy (4,7);
 cout << "BONUSES RECEIVED : "<< gotbonus;
 gotoxy (4,8);
 cout << "STAR FURY(s) DESTROYED : "<< shipslost;
 gotoxy (4,9);
 cout << "RANK  : ";

     if (rank == 0)
	cout << " Flt.Officer";
     if (rank == 1)
	cout << " 2nd Lt.    ";
     if (rank == 2)
	cout << " 1st Lt.    ";
     if (rank == 3)
	cout << " Major      ";
     if (rank == 4)
	cout << " Commander  ";
     if (rank == 5)
	 cout << " Captain   ";
  gotoxy (4,10);
 cout << "SHOTS FIRED : "<< shotsfired;
 gotoxy (4,11);
 cout << "NUMBER OF HITS : "<< hits;
 setcolor(15);
 outtextxy (100,300, "Press any key to exit");
 getch();
 ext = 1;
 sleep(1);
 exit(0);

}


void shadowfire() //boom he fires at ye! Har!
{
 int i;
 if ((fire == 9) || (fire == 8) || (shadx == 9)||(fire==0))//moves right
   {
    if (shadx+10 < 640)
    {
    setcolor(0);
    setfillstyle(SOLID_FILL, 0);
    bar(shadx-35,shady-30,shadx+50,shady+50);
    shadx = shadx + 10;
    shadt = shadt + 10;
    shadow();
    }
  else
   {
     setcolor(0);
     setfillstyle(SOLID_FILL, 0);
     bar(shadx-40,shady-30,shadx+50,shady+50);

    shadx = shadx - 10;
    shadt = shadt - 10;
    shadow();
   }
 }//end of big if
 if ((fire == 2) || (fire == 1) || (fire ==4) || (fire == 10))//moves left
   {
    if (shadx-10 > 0)
    {
     setcolor(0);
     setfillstyle(SOLID_FILL, 0);
     bar(shadx-35,shady-30,shadx+50,shady+50);
     shadx = shadx - 10;
     shadt = shadt - 10;

     shadow();
   }
   else
    {
     setcolor(0);
     setfillstyle(SOLID_FILL, 0);
     bar(shadx-40,shady-30,shadx+50,shady+50);

     shadx = shadx + 10;
     shadt = shadt + 10;
     shadow();
    }
  }//end of big if
 else
 if ((fire == 3) || (fire == 5) || (fire == 6))//fires
  {
    int snd= 10;
    setcolor(13);
    setfillstyle(LTBKSLASH_FILL, 13);

    for (i = 45; i < 460; i = i + 5)
    {
     bar (shadx - 1 , i, shadx + 1, i +10);
     if (i % 25 == 0)
	  snd = 9;
      else
	  snd = 6;
      sound (snd * 100);
      delay(1);

    }
    nosound();
    if ((shadt == start) || (shadt - start < 11 && shadt - start > 0) || start - shadt < 11 && start - shadt > 0)
    //if it hits...  --/\
    {
      starfuryexplode();//boom goes you
      shipslost++;
	 setcolor(0);
	 setfillstyle(SOLID_FILL,0);
	 bar (shadx-2,44,shadx+2,i+10);//erases if hit boom you go!
    }
    else
    {
    setcolor(0);
    setfillstyle(SOLID_FILL,0);
    bar (shadx-1,44,shadx+1,i+10);//erases if missed
    shadow();
    fury();
    }                                                                  \


  }


}

void clarkcoming()
{
  appear = rand() % 145;
  if ((appear == 116) && (ifhere == 0))
  {
   bonus++;
   delay (500);
   setcolor (7);
   outtextxy (240, 210, "Oh no! Here comes President Clark!");
   sleep(3);
   setcolor (0);
   outtextxy (240, 210, "Oh no! Here comes President Clark!");
   settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
   setcolor (4);
   outtextxy (100, 200, "FINISH HIM!");
   sleep (2);
   setcolor (0);
   outtextxy (100, 200, "FINISH HIM!");
   settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
   ifhere = 1;
   delay (100);
   clark();
  }
}


void clark()//here comes clark!!
{
 setcolor(15);
 setfillstyle (SOLID_FILL, 15);
 fillellipse (clarkx,240,4,4);
 setcolor (13);
 line (clarkx, 243, clarkx, 255);
 line (clarkx, 255, clarkx-5, 265);//left leg
 line (clarkx,255, clarkx+5, 265); //right leg
 line (clarkx,250, clarkx+7,250);//right arm
 line (clarkx, 250, clarkx-6, 245);//left arm
 setcolor(0);
 circle (hitclark, 242,1);
 setfillstyle(SOLID_FILL, 0);
 bar (clarkx-2,238,clarkx-1,239);
 bar (clarkx+2, 238, clarkx+1, 239);
 //must say FINISH HIM

}

void clarkmove()
{

 setcolor(0);
 setfillstyle(SOLID_FILL, 0);
 bar(clarkx-10,230,clarkx+10,270);
 clarkx = clarkx + 20;
 hitclark = hitclark + 20;
 clark();
 if (clarkx == 650)
 {
  ifhere = 0;
  clarkx = 10;
  hitclark = 10;
 }

}



void clarkboom()// he explodes 1000pts bonus
{
  gotbonus++;
  int seeya= 0;
  clark();
  setcolor(15);
  outtextxy (starx-10, 435, "Sorry, Clark. You've been impeached!");
  sleep (2);
  outtextxy (clarkx-10, 230, "Oh no!");
  sleep (2);
  setcolor(0);
  outtextxy (clarkx-10, 230, "Oh no!");

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
  sleep (2);
  setcolor (0);
  outtextxy (clarkx+10, 200, "1000 POINTS AWARDED!");
  outtextxy (starx-10,435, "Sorry, Clark. You've been impeached!");
  ifhere = 0;
  clarkx = 10;
  hitclark = 10;
}




void starfuryexplode()//boom goes you
{
  int rad;
  setcolor(14);
  setfillstyle(SOLID_FILL,14);

  for (rad = 1; rad < 30; rad++)
  {
    fillellipse (start, 450, rad,rad);
    sound (rad * 100);
    delay(6);
  }
  setcolor(0);
  setfillstyle(SOLID_FILL,0);
  bar (start-50,400,start+40,480);

  life--;
  nosound();
  start = (rand() % 64) * 10;
  starx = start - 18;
  delay (900);
  fury();

}







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
  delay (500);
  if (score % 2500 == 0 && score > 100)
     {
       score = score + 300;
       setcolor(14);
       outtextxy (180, 200, "BONUS 300 points");
       sleep (1);
       setcolor(0);
       outtextxy (180, 200, "BONUS 300 points");
     }

  score = score + 100;


}




void gamething()
{
 int i;
 char move;
 //killcount = 0;
 //life = 3;
 cleardevice();
 while (move != 'x' && move != 'X' && life > 0)
 {
   stars();
   board();
   shadow();
   fury();
   move = getch();
 if (move == 'M' || move == 'm' && starx < 640)
   {
    setcolor(0);
    setfillstyle(SOLID_FILL,0);
    bar(starx-20,stary-10,starx+40,stary+40);
    starx = starx + 10;
    start = start + 10;
    fury();
    fire = rand() % 10;
    shadowfire();
    if (ifhere == 1)
      {
	clarkmove();  //here he comes
      }
    else
      clarkcoming();
    if (lifehere == 1)
      {
       lifejourney();
      }
    else
      exlifehere();
   if (rank > 2)
      {enemyshoot();}

   }
 else
 if (move == 'k' || move == 'K' && starx > 0)
   {
    setcolor(0);
    setfillstyle(SOLID_FILL, 0);
    bar(starx-20,stary-10,starx+40,stary+40);
    starx = starx - 10;
    start = start - 10;
    fury();
    fire = rand() % 10;
    shadowfire();
    if (rank > 2)
      enemyshoot();
    else
      {  }
    if (ifhere == 1)
      {
	clarkmove();  //here he comes
      }
    else
      clarkcoming();
    if (lifehere == 1)
      {
       lifejourney();
      }
    else
      exlifehere();

   }

 else
 if (move == 'F' || move == 'f')
   {
     shotsfired++;
     furyfire();


	 if ((start == hitclark))
	   {
	    hits++;
	    clarkboom();
	    score = score + 1000;
	     if (score % 2000 == 0 && life < 10)
	     { life++;  //extra guy if
	       setcolor (10);
	       outtextxy (300,200,"Extra Star Fury Awarded");
	       for (i = 0; i < 25; i++)
	       {
		sound (i * 100);
		delay (25);
	       }
	       nosound();
	       setcolor (0);
	       outtextxy (300,200,"Extra Star Fury Awarded");
	      }
	     else
	     if (score % 2000 == 0 && life > 9)
	      {
		setcolor(2);
		outtextxy (300, 200, "Bonus 500 points");
		sleep (1);
		setcolor(0);
		outtextxy (300,200, "Bonus 500 points");
		score = score + 500;
	      }

	   }

	 if (start == lifetarget && life < 10)//if hits the thing
	   {
	     hits++;
	     setcolor(10);
	     outtextxy (300,200,"Extra Star Fury Awarded");
	     delay(100);
	     for (i = 0; i < 27; i++)
	     {
	      sound (i * 100);
	      delay(20);
	     }
	     nosound();
	     life++;
	     setcolor(0);
	     setfillstyle(SOLID_FILL, 0);
	     bar(lifex - 15, 110, lifex+15,130);
	     outtextxy (300,200,"Extra Star Fury Awarded");
	     lifehere = 0;
	     lifex = -5;
	     lifetarget = 0;
	    }//if hits thing
	    else
	    if (score % 2000 == 0 && life > 9)
	    {
	      hits++;
	      setcolor(2);
	      outtextxy (300, 200, "Bonus 500 points");
	      sleep (1);
	      setcolor(0);
	      outtextxy (300,200, "Bonus 500 points");
	      score = score + 500;
	    }

	 if ((shadt == start) || (shadt - start < 11 && shadt - start > 0) || start - shadt < 11 && start - shadt > 0)
	 {
	  hits++;
	  shadowexplode();
	  killcount++;

	    if ((killcount % 12 == 0) && (rank <= 5))
	     {
	       rank++;
	      if (rank >= 6)//safety procaution
	      {
		 rank = 5;
	      }
		else
	      {
		setcolor(14);
		outtextxy (100,180, "You've been promoted!");
		outtextxy (130,190, "BONUS 500 pts");
		score = score + 500;
		delay(200);
		for (i = 0; i < 25; i ++)
		{
		  sound (i * 100);
		  delay(15);
		}

		 for (i = 25; i > 0; i--)
		{
		  sound (i * 100);
		  delay (15);
		}

		 nosound();
		 setcolor(0);
		 outtextxy (100,180, "You've been promoted!");
		 outtextxy (130,190, "BONUS 500 pts");
	      }//end of else
	     }//end of if kill count thing


	     if (score % 2000 == 0 && life < 10)
	     { life++;  //extra guy if
	       setcolor (10);
	       outtextxy (300,200,"Extra Star Fury Awarded");
	       for (i = 0; i < 25; i++)
	       {
		sound (i * 100);
		delay (25);
	       }
	       nosound();
	       setcolor (0);
	       outtextxy (300,200,"Extra Star Fury Awarded");
	     }
	     else
	     if (score % 2000 == 0 && life > 9)
	      {
		setcolor(2);
		outtextxy (300, 200, "Bonus 500 points");
		sleep (1);
		setcolor(0);
		outtextxy (300,200, "Bonus 500 points");
		score = score + 500;
	      }

	   }//end of huge firing if
	 else
	 if ((shadt != start) || (shadt - start > 11 && shadt - start > 0) || start - shadt > 11 && start - shadt > 0)
	 {
	  shadowfire();
	 }

	  setcolor(0);
	  setfillstyle(SOLID_FILL,0);
	  bar (start-1, 445, start+1, 45);
	  fury();
	  shadow();

	if (rank > 2)
	enemyshoot();

   } //end of fire if thing
   if ((move == 'x') || (move == 'X') || (life < 1))
	  { break; }
  }//end of loop

  for (i = 25; i > 0; i--)
  {
   sound (i * 100);
   delay (20);
  }
  nosound();

  setcolor(12);
  outtextxy (130, 180, "Bite the hand that feeds you!");
  sleep(3);
  endstuff();

}//end of function







void furyfire()
{
   int i, snd;
   setcolor(9);
   setfillstyle(XHATCH_FILL,9);
   snd = 1;
   for (i = 445; i > 45; i = i -5)
   {
     bar (start - 1, i, start + 1, i + 5);
     sound (snd * 100);
     snd++;
     delay (1);
   }
   nosound();

}




void board()
  {
     gotoxy (1,1);
     cout << "SCORE : " << score << "     Star Fury(s) : " << life << "   KILLS : "<< killcount<< "    RANK: ";
     if (rank == 0)
	cout << " Flt.Officer";
     if (rank == 1)
	cout << " 2nd Lt.    ";
     if (rank == 2)
	cout << " 1st Lt.    ";
     if (rank == 3)
	cout << " Major      ";
     if (rank == 4)
	cout << " Commander  ";
     if (rank == 5)
	 cout << " Captain   ";
  }


void fury()
{
  setrgbpalette (3, 55,55,55);
  setrgbpalette (5, 28,28,28);
 setcolor(0);
 circle (start,445, 1); //Fury target to be hit
 //-------------------------
 setcolor(5);
 setfillstyle(SOLID_FILL, 5);
 bar (starx,stary,starx + 15,stary + 10);

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







void shadow()
{
 setcolor(0);
 circle (shadt,45,1);//target to hit

 setcolor(8);

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

void restart()
{
  closegraph();
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

} //end of restart graphics stuff

void title()
{
  cleardevice();
  int bot, mid, top, mid2, cnt;
  setcolor(15);
  outtextxy (135, 180, " Star Fury fighter vs. Shadow vessel ");
  outtextxy (155, 190, " Version 1.54");

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
   outtextxy (85, 110, "        лллллл    лл   л   ллллллл    лл   л ");
   outtextxy (85, 118, "       ллл   л   лл   лл  ллл    лл  лл   лл  ");
   outtextxy (45, 40, "  ллллл   ллллллл  лллллл  лллллл ");
   outtextxy (45, 48, " лл         лл    лл   лл лл    лл");
   setcolor(mid);
   outtextxy (85, 126, "      ллл       лл   лл  лл     лл   лл ллл  ");
   outtextxy (85, 134, "      лллллл   лл   лл   лллллллл     ллл    ");
   outtextxy (45, 56, "лл          лл   лл   лл  лл    лл");
   outtextxy (45, 64, "ллллл      лл   ллллллл   ллллллл ");
   setcolor(mid2);
   outtextxy (85, 142, "      ллл      лл   лл   лл   лл     лл      ");
   outtextxy (85, 150, "      лл       лл  лл   лл     лл    лл      ");
   outtextxy (45, 72, "    лл     лл   лл   лл  лл   лл  ");
   outtextxy (45, 80, "   лл     лл   лл   лл  лл     лл ");
   setcolor(bot);
   outtextxy (45, 88, "  лл      лл   лл   лл  лл     лл ");
   outtextxy (45, 96, "ллл      лл   лл   лл  лл      лл ");
   outtextxy (85, 158, "      лл       лл  лл   лл     лл   лл       ");
   outtextxy (85, 166,"      лл       лллллл   лл      лл  лл       ");
   cnt++;
   if (cnt > 4)
      cnt = 1;

   if (cnt == 1)
      {  top = 12;
	 bot = 14;
	 mid = 4;
	 mid2 = 6;
      }
   if (cnt == 2)
      {
       top = 4;
       mid = 6;
       mid2 = 14;
       bot = 12;
      }
   if (cnt == 3)
   {
       top =6;
       mid =14;
       mid2 =12;
       bot = 4;
   }
      if (cnt == 4)
   {
       top =14;
       mid =12;
       mid2 =4;
       bot = 6;
   }
  }//end of loop
  getch();
}//end of function


