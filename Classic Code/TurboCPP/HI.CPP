#include <iostream.h>
#include <conio.h>
#include <dos.h>
void main()
{
 textmode (C4350);
 textcolor (1);
 clrscr();
 int c, x;
 c = 1;
 x = 1;
 while (c < 100)
 {
  if (c > 15)
      c = 1;
  textcolor(c);
  clreol();
  if (x >= 100)
    {
     cout << "UPLIFTING ISN'T IT?!?";
     x = 1;
    }
  else
  cout << "DIE  ";
  c = c + 1;
  x = x + 1;
  delay (10);
 }
}

