#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <dos.h>

void message();

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
  message();
  return 0;
}

void message()
{
 cleardevice();
 setcolor(7);
 outtextxy(4,2, "Getting inspirational messages.");
 int mes, tme;
 randomize();
 tme = random(150);
 delay (tme);
 mes = (rand() % 10);
 delay (800);
 if (mes == 1)
 {
  setcolor(8);
  outtextxy(60, 180, "°±² Don't eat from Taco Bell");
  delay (120);
  setcolor(7);
  outtextxy(60, 180, "°±² Don't eat from Taco Bell");
  delay(120);
  setcolor(15);
  outtextxy(60, 180, "°±² Don't eat from Taco Bell");
  sleep (4);
  setcolor(7);
  outtextxy(60, 180, "°±² Don't eat from Taco Bell");
  delay (120);
  setcolor(8);
  outtextxy(60, 180, "°±² Don't eat from Taco Bell");
  delay (120);
  cleardevice();
 }

 else
 if (mes == 2)
 {
  setcolor(8);
  outtextxy(60, 180, "°±² Bring out your dead!");
  delay (120);
  setcolor(7);
  outtextxy(60, 180, "°±² Bring out your dead!");
  delay (120);
  setcolor(15);
  outtextxy(60, 180, "°±² Bring out your dead!");
  sleep (4);
  setcolor(7);
  outtextxy(60, 180, "°±² Bring out your dead!");
  delay (120);
  setcolor(8);
  outtextxy(60, 180, "°±² Bring out your dead!");
  delay (120);
  cleardevice();
 }
 else
 if (mes == 3)
  {
    setcolor(8);
    outtextxy(60, 180, "°±² Do not smoke near propane gas.");
    delay (120);
    setcolor(7);
    outtextxy(60, 180, "°±² Do not smoke near propane gas.");
    delay (120);
    setcolor(15);
    outtextxy(60, 180, "°±² Do not smoke near propane gas.");
    sleep (4);
    setcolor(7);
    outtextxy(60, 180, "°±² Do not smoke near propane gas.");
    delay (120);
    setcolor(8);
    outtextxy(60, 180, "°±² Do not smoke near propane gas.");
    delay (120);
    cleardevice();
  }
 else
 if (mes == 4)
 {
    setcolor(8);
    outtextxy(60, 180, "°±² The Paranoids are after you!");
    delay (120);
    setcolor(7);
    outtextxy(60, 180, "°±² The Paranoids are after you!");
    delay (120);
    setcolor(15);
    outtextxy(60, 180, "°±² The Paranoids are after you!");
    sleep (4);
    setcolor(7);
    outtextxy(60, 180, "°±² The Paranoids are after you!");
    delay (120);
    setcolor(8);
    outtextxy(60, 180, "°±² The Paranoids are after you!");
    delay (120);
    cleardevice();
 }
 else
 if (mes == 5)
 {
    setcolor(8);
    outtextxy(60, 180, "°±² Oliver Stone is a robot.");
    delay (120);
    setcolor(7);
    outtextxy(60, 180, "°±² Oliver Stone is a robot.");
    delay (120);
    setcolor(15);
    outtextxy(60, 180, "°±² Oliver Stone is a robot.");
    sleep (4);
    setcolor(7);
    outtextxy(60, 180, "°±² Oliver Stone is a robot.");
    delay (120);
    setcolor(8);
    outtextxy(60, 180, "°±² Oliver Stone is a robot.");
    delay (120);
    cleardevice();
 }
 else
 if  (mes == 6)
 {
    setcolor(8);
    outtextxy(60, 180, "°±² Panasonic is a CIA front.");
    delay (120);
    setcolor(7);
    outtextxy(60, 180, "°±² Panasonic is a CIA front.");
    delay (120);
    setcolor(15);
    outtextxy(60, 180, "°±² Panasonic is a CIA front.");
    sleep (4);
    setcolor(7);
    outtextxy(60, 180, "°±² Panasonic is a CIA front.");
    delay (120);
    setcolor(8);
    outtextxy(60, 180, "°±² Panasonic is a CIA front.");
    delay (120);
    cleardevice();
 }
 else
  { setcolor(8);
    outtextxy(60, 180, "°±² Booze helps parents care for their children.");
    delay (120);
    setcolor(7);
    outtextxy(60, 180, "°±² Booze helps parents care for their children.");
    delay (120);
    setcolor(15);
    outtextxy(60, 180, "°±² Booze helps parents care for their children.");
    sleep (4);
    setcolor(7);
    outtextxy(60, 180, "°±² Booze helps parents care for their children.");
    delay (120);
    setcolor(8);
    outtextxy(60, 180, "°±² Booze helps parents care for their children.");
    delay (120);
    cleardevice();
  }
  delay (400);

}//end of inspirational message