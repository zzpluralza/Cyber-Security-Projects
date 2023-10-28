#include <conio.h>
#include <dos.h>
#include <iostream.h>
void snd()
   {
     sound(960);
     delay (55);
     nosound();
   }

void main()
{
 textmode (C4350);
 textcolor (12);
 clrscr();
 cout << "";
 delay (500);
 cout << "INC";
 snd();
 cout << "OMI";
 snd();
 cout << "NG I";
 snd();
 cout << "NTER";
 snd();
 cout << "CEPT";
 snd();
 cout << "ED M";
 snd();
 cout << "ESSA";
 snd();
 cout << "GE.";
 delay (500);
 cout << "\n\n";
 delay (200);
 textcolor (15);
 clreol();
 cout << "CON";
 snd();
 cout << "NEC";
 snd();
 cout << "TIN";
 snd();
 cout << "G N";
 snd();
 cout << "OW.";
 sleep (2);
 textcolor (10);
 clrscr();



