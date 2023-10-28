/*nclude <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <dos.h>

int i, x[20],y[20];
void stars();
void sstart();
void sfield();

int main(void)
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
   //getpalette(&pal);
   sstart();
   sfield();
   return 0;
}*/
int i, x[15],y[15];
void stars();
void sstart();
void sfield();

void sstart()//initializes variables for stars
{
  y[1]=23; y[0]=71; y[2]=450; y[3]=314;y[4]=453;y[5]=128;y[6]=80;y[7]=69;y[8]=120;y[9]=180;
  y[10]=321;y[11]=111;y[12]=141;y[13]=60;y[14]=33;/*y[15]=91;y[16]=99;y[17]=52;y[18]=54;
  y[19]=145;y[20]=232;y[21]=100;y[22]=10;y[23]=5;y[24]=300;y[25]=250;y[26]=119;y[27]=23;y[28]=33;y[29]=400;
*/
  x[1]=24; x[0]=198; x[2]=421; x[3]=134;x[4]=231;x[5]=238;x[6]=121;x[7]=53;x[8]=121;x[9]=239;
  x[10]=264;x[11]=545;x[12]=600;x[13]=85;x[14]=133;/*x[15]=191;x[16]=399;x[17]=521;x[18]=544;
  x[19]=545;//x[20]=100;x[21]=33;x[22]=10;x[23]=4;x[24]=621;x[25]=598;x[26]=73;x[27]=607;x[28]=12;x[29]=575;
   */
}

void sfield()
{

  for (i = 0; i < 15; i++)
  {
    putpixel (x[i],y[i],0);
  }
  y[1]=y[1]+2; y[0]=y[0]+4; y[2]=y[2]+3; y[3]=y[3]+5;y[4]=y[4]+4;y[5]=y[5]+3;y[6]=y[6]+2;y[7]=y[7]+3;y[8]=y[8]+4;y[9]=y[9]+3;
  y[10]=y[10]+2;y[11]=y[11]+5;y[12]=y[12]+3;y[13]=y[13]+5;y[14]=y[14]+3;/*y[15]=y[15]+1;y[16]=y[16]+2;y[17]=y[17]+5;y[18]=y[18]+5;
  y[19]=y[19]+5;//y[20]=y[20]+2;y[21]=y[21]+3;y[22]=y[22]+1;y[23]=y[23]+4;y[24]=y[24]+1;y[25]=y[25]+3;y[26]=y[26]+3;y[27]=y[27]+1;y[28]=y[28]+2;y[29]=y[29]+3;
*/
  stars();
  for (i = 0; i < 15; i ++)
  {
    if (y[i] > 479)
       { y[i]= 0;
	 x[i] = random(638);
       }
    else {}
    putpixel (x[i],y[i],15);
  }//end of for loop
}//end of that

void stars()
{
 putpixel(432,129,8); putpixel(52,73,15);  putpixel(123,432,7); putpixel(321,204,8);
 putpixel(457,412,8); putpixel(58,154,8); putpixel(433,23,7);  putpixel(127,64,8);
 putpixel(74,5,15);   putpixel(236,65,7);  putpixel(210,45,7);  putpixel(75,108,7);
 putpixel(123,199,8); putpixel(73,78,15);  putpixel(573,400,7); putpixel(421,201,8);
 putpixel(167,316,8); putpixel(608,429,8); putpixel(523,76,7);  putpixel(577,54,8);
 putpixel(82,64,7);   putpixel(438,134,8); putpixel(56,456,7);  putpixel(12,310,8);
 putpixel(45,132,8);  putpixel(32,215,8);  putpixel(99,54,8);   putpixel(54,9,8);
 putpixel(106,80,8);  putpixel(200,45,7);  putpixel(78,110,8);  putpixel(113,110,8);
 putpixel(67,78,8);   putpixel(310,410,7); putpixel(320,221,8); putpixel(187,356,8);
 putpixel(198,459,8); putpixel(533,29,7);  putpixel(557,35,8);  putpixel(132,97,8);
 putpixel(198,413,8); putpixel(51,402,7);  putpixel(62,401,8);  putpixel(233,59,8);
 putpixel(451,465,8); putpixel(568,149,7); putpixel(477,328,8); putpixel(446,236,7);
 putpixel(615,454,8); putpixel(444,265,8); putpixel(223,186,7); putpixel(191,77,7);
 putpixel(213,407,7); putpixel(575,69,9);  putpixel(194,167,7); putpixel(173,56,7);
 putpixel(85,189,8);  putpixel(273,430,7); putpixel(431,240,1); putpixel(429,225,7);
 putpixel(175,169,1); putpixel(304,237,7); putpixel(193,54,8);  putpixel(95,564,7);
 putpixel(373,630,8); putpixel(421,23,1);  putpixel(633,244,7); putpixel(631,186,7);
 putpixel(134,331,7); putpixel(101,298,7); putpixel(165,256,8); putpixel(510,421,7);
 putpixel(122,131,7); putpixel(401,298,7); putpixel(565,356,8); putpixel(510,421,7);
//planet stuff sort of
 setfillstyle(SOLID_FILL, 15);
 setcolor(1);
 circle (514,219,5);
 circle (142,329,5);

 setcolor(9);
 circle (514,219,4);
 circle (142,329,4);
 circle (142,329,3);

 circle (514,219,3);
 setcolor (7);
 circle (514,219,2);
  circle (142,329,2);

 setcolor(15);
 fillellipse (514,219,1,1);
 circle (142,329,1);


}

