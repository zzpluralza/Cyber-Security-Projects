#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <dos.h>


void npc1();//peasant
void npc2();//guards
void npc3();//merchant


void town();//level 1

void wall();//level 1 can't walk into stuff
//-------------

//first row of grass stuff
void grass1();void grass2();void grass3();void grass4();void grass5();void grass6();void grass7();void grass8();void grass9();void grass10();void grass11();
void grass1a();void grass1b();void grass1c();void grass1d();void grass1e();void grass1f();void grass1g();void grass1h();void grass1i();void grass1j();
/* more grass stuff                                     */  void grass2e();void grass2f();void grass2g();void grass2h();void grass2i();void grass2j();
/* more grass stuff                                     */  void grass3e();void grass3f();void grass3g();void grass3h();void grass3i();void grass3j();
void grass9a();
void grass10a();
void grass11a();
void grass7a();
void grass8a();

//-------------
//fountain pathwaystuff
void fnt1();void fnt2();void fnt3();void fnt4();void fnt5();void fnt6();void fnt7();void fnt8();
//-------------
//path stuff
void path1();void path2(); void path3();//path to walk on
void path4();void path5();void path6();
void path7();void path8();void path9();
void path10();void path11();void path12();
void path13();void path14();void path15();
void path16();void path17();void path18();
void path19();void path20();void path21();

int guardx,guardy, psntx,psnty, merchx,merchy;
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
   cleardevice();
   town();
   getch();
return 0;
}

void town()
{
 grass1();grass2();grass3();grass4();grass5();grass6();grass7();grass8();grass9();grass10();grass11();
 //grass stuff along row
 grass1a();grass1b();grass1c();grass1d();grass1e();grass1f();grass1g();grass1h();grass1i();grass1j();
					 grass2e();grass2f();grass2g();grass2h();grass2i();grass2j();
					 grass3e();grass3f();grass3g();grass3h();grass3i();grass3j(); //more grass along wall stuff
 grass11a();
 grass10a();
 grass9a();
 grass8a();
 grass7a();


//----------------------
 fnt1();fnt2();fnt3();fnt4();fnt5();fnt6();fnt7();fnt8();

//-----------
 wall();
//-----------------
 path1();path2();path3();
 path4();path5();path6();
 path7();path8();path9();
 path10();path11();path12();
 path13();path14();path15();
 path16();path17();path18();
 path19();path20();path21();

 //npc1();
 guardx = 100;
 guardy = 348;
 npc2();
 guardx = 348;
 guardy = 100;
 npc2();
 merchx=317;
 merchy=255;
 npc3();
 merchx=131;
 merchy=100;
 npc3();
 psntx = 38;
 psnty = 38;
 npc1();

}

////-------begin the grass

void grass7a()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (254,99,224,69);

}

void grass8a()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (255,131,285,69);

}

void grass9a()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (316,131,286,69);

}

void grass10a()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (347,131,317,69);

}

void grass11a()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (348,131,378,69);

}
void grass1a()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (38,69,68,99);

}
void grass1b()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (38,100,68,130);

}
void grass1c()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (38,131,68,161);

}
void grass1d()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (38,162,68,192);

}
void grass1e()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (38,193,68,223);

}
void grass1f()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (38,224,68,254);

}
void grass1g()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (38,255,68,285);

}
void grass1h()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (38,286,68,316);

}
void grass1i()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (38,317,68,347);

}
void grass1j()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (38,348,68,378);

}
//---------
void grass2e()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (69,193,99,223);

}
void grass2f()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (69,224,99,254);

}
void grass2g()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (69,255,99,285);

}
void grass2h()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (69,286,99,316);

}
void grass2i()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (69,317,99,347);

}
void grass2j()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (69,348,99,378);

}

//---------------
void grass3e()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (100,193,130,223);

}
void grass3f()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (100,224,130,254);

}
void grass3g()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (100,255,130,285);

}
void grass3h()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (100,286,130,316);

}
void grass3i()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (100,317,130,347);

}
void grass3j()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (100,348,130,378);

}


void grass1()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (38,38,68,68);

}
void grass2()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (69,38,99,68);

}
void grass3()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (100,38,130,68);

}
void grass4()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (131,38,161,68);

}
void grass5()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (162,38,192,68);

}
void grass6()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (193,38,223,68);

}
void grass7()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (224,38,254,68);

}
void grass8()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (255,38,285,68);

}
void grass9()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (286,38,316,68);

}
void grass10()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (317,38,347,68);

}

void grass11()
{
 setcolor(2);
 setfillstyle(CLOSE_DOT_FILL, 2);
 bar (348,38,378,68);

}



//pathway thing begins////////
void path21()
{
 setcolor(4);
 setfillstyle(XHATCH_FILL, 4);
 bar (131,223,223,192);
}

void path20()
{
 setcolor(4);
 setfillstyle(XHATCH_FILL, 4);
 bar (255,378,285,317);
}

void path19()
{
 setcolor(4);
 setfillstyle(XHATCH_FILL, 4);
 bar (224,378,254,317);
}

void path18()
{
 setcolor(4);
 setfillstyle(XHATCH_FILL, 4);
 bar (161,254,130,224);
}
void path17()
{
 setcolor(4);
 setfillstyle(XHATCH_FILL, 4);
 bar (191,254,161,224);
}
void path16()
{
 setcolor(4);
 setfillstyle(XHATCH_FILL, 4);
 bar (222,254,192,224);
}

//----------------------------more path
void path15()
{
 setcolor(4);
 setfillstyle(XHATCH_FILL, 4);
 bar (160,285,130,255);
}
void path14()
{
 setcolor(4);
 setfillstyle(XHATCH_FILL, 4);
 bar (191,285,161,255);
}
void path13()
{
 setcolor(4);
 setfillstyle(XHATCH_FILL, 4);
 bar (222,285,192,255);
}

//----------------------------more path
void path12()
{
 setcolor(4);
 setfillstyle(XHATCH_FILL, 4);
 bar (160,316,130,286);
}
void path11()
{
 setcolor(4);
 setfillstyle(XHATCH_FILL, 4);
 bar (191,316,161,286);
}
void path10()
{
 setcolor(4);
 setfillstyle(XHATCH_FILL, 4);
 bar (222,316,192,286);
}
//----------------------------
void path9()
{
 setcolor(4);
 setfillstyle(XHATCH_FILL, 4);
 bar (160,347,130,317);
}
void path8()
{
 setcolor(4);
 setfillstyle(XHATCH_FILL, 4);
 bar (191,347,161,317);
}
void path7()
{
 setcolor(4);
 setfillstyle(XHATCH_FILL, 4);
 bar (222,347,192,317);
}
//----------------------------
void path6()
{
 setcolor(4);
 setfillstyle(XHATCH_FILL, 4);
 bar (160,378,130,348);
}
void path5()
{
 setcolor(4);
 setfillstyle(XHATCH_FILL, 4);
 bar (191,378,161,348);
}
void path4()
{
 setcolor(4);
 setfillstyle(XHATCH_FILL, 4);
 bar (222,378,192,348);
}
//-------------------
void path3()
{
 setcolor(4);
 setfillstyle(XHATCH_FILL, 4);
 bar (160,409,130,379);
}
void path2()
{
 setcolor(4);
 setfillstyle(XHATCH_FILL, 4);
 bar (191,409,161,379);
}

void path1()
{
 setcolor(4);
 setfillstyle(XHATCH_FILL, 4);
 bar (222,409,192,379);
}




///begin the fountain stuff
void fnt1()
{
 setcolor(7);
 setfillstyle(LTBKSLASH_FILL, 7);
 bar (378,222,348,193);
}

void fnt2()
{

 setcolor(7);
 setfillstyle(LTBKSLASH_FILL, 7);
 bar (347,222,317,193);
}
void fnt3()
{

 setcolor(7);
 setfillstyle(LTBKSLASH_FILL, 7);
 bar (316,222,286,193);
}
void fnt4()
{

 setcolor(7);
 setfillstyle(LTBKSLASH_FILL, 7);
 bar (316,192,286,162);
}

void fnt5()
{
 setcolor(7);
 setfillstyle(LTBKSLASH_FILL, 7);
 bar (378,192,348,162);
}

void fnt6()
{

 setcolor(7);
 setfillstyle(LTBKSLASH_FILL, 7);
 bar (316,161,286,131);
}

void fnt7()
{

 setcolor(7);
 setfillstyle(LTBKSLASH_FILL, 7);
 bar (347,161,317,131);
}
void fnt8()
{
 setcolor(7);
 setfillstyle(LTBKSLASH_FILL, 7);
 bar (378,161,348,131);
}


//--------------------------
////walls stuff  you can't walk into this stuff...
///////includes other stuff can't walk into besides walls


void wall()
{
 setrgbpalette(3,35,35,35);//setcolorthing
 setcolor(3);
 setfillstyle(SOLID_FILL,3);
 bar (7,7,409,37);//outter wall begin
 bar (7,7,37,409);//left wall
 bar (409,7,379,409);//right wall
 bar (409,409,223,379);//bottom wall
 bar (37,409, 130,379); // bottom wall
 //end of outer walls

 bar (68,68,98,192);//shop 1
 bar (68,68,192,98);
 bar (192,192,162,162);//column thing
 //provision sign

 setcolor (14);
 setfillstyle (SOLID_FILL, 14);
 bar (193,162,223,192);
 setcolor(6);
 rectangle (193,162,223,192);
 rectangle (194,163,222,191);
 rectangle (195,164,221,190);
 rectangle (196,165,220,189);
 line (208,187, 208, 170);
 line (209, 187, 209, 170);
 line (207, 187, 207, 170);

 setcolor(8);
 line (199,169,215,169);
 line (200,168,215,168);
 line (201,167,214,167);

 //end of provision shop
 setcolor(3);
 setfillstyle (SOLID_FILL, 3);
 bar (409,223,255,254);//top wall of shop
 bar (255,254,285,317);//side wall

	 //shop table
 setcolor(6);
 setfillstyle(SOLID_FILL, 6);
 bar (378, 286, 317, 316);

     //sign-------------
   setcolor(7);
   setfillstyle (SOLID_FILL, 7);
   bar (224,316,254,286);
   setcolor(1);
   rectangle (224,316,254,286);
   rectangle (225,317,253,285);
   setcolor(8);
   line (239,290, 239, 308);
   line (238,291, 238, 308);
   line (240,291, 240, 308);
   line (237,292, 237, 308);
   line (241,292, 241, 308);
   setcolor (6);
   line (230, 309, 248, 309);
   line (230, 310, 248, 310);
   setfillstyle (SOLID_FILL, 6);
   bar (241, 311, 237, 316);
   bar (100,131,161,161);//provision shop thing


//fountain-----------------
 setfillstyle(SOLID_FILL, 7);
 setcolor(7);
 bar (347,192,317,162);
 setcolor(8);
 circle (332, 177, 13);
 circle (332, 177, 12);
 circle (332, 177, 11);
 circle (332, 177, 10);
 setfillstyle (SOLID_FILL, 8);
 fillellipse (332,177,1,1);
 putpixel (332,177,9);
 setcolor(1);
 circle (332, 177, 9);
 circle (332, 177, 8);

 setcolor(9);
 circle (332, 177, 7);
 circle (332, 177, 6);
 circle (332, 177, 5);

 setcolor(7);
 circle (332, 177, 4);
 circle (332, 177, 3);
 setcolor(15);
 circle (332, 177, 2);
 circle (332, 177, 1);
//end of fountain


}//end of wall function

void npc3()//merchant
{
 setcolor(14);
 setfillstyle(SOLID_FILL,14);
 fillellipse (merchx+15,merchy+3,4,4);//head
 bar (merchx+14,merchy+6,merchx+16,merchy+9);//neck
 fillellipse (merchx+24,merchy+21,3,2);//hand
 fillellipse (merchx+6,merchy+21,3,2);//other hand
 //270 = merchx+15
 //7 = merchy

 setcolor(10);
 setfillstyle(SOLID_FILL, 10);
 bar (merchx+9,merchy+9,merchx+21,merchy+19);//torso
   bar (merchx+9,merchy+9,merchx+5,merchy+12);//right arm
   bar (merchx+5,merchy+12,merchx+7,merchy+21);// end

  bar (merchx+21,merchy+9,merchx+25,merchy+12);//left arm
  bar (merchx+25,merchy+12,merchx+23,merchy+21);//end

  bar (merchx+9,merchy+21,merchx+14,merchy+30);//leg
  bar (merchx+21,merchy+21,merchx+17,merchy+30);//other leg

 setcolor(15);
 setfillstyle(SOLID_FILL,15);
 bar (merchx+11, merchy+9, merchx+13, merchy+13);
 bar (merchx+19, merchy+9, merchx+17, merchy+13);
 bar (merchx+20, merchy+12,merchx+10, merchy+24);


}

void npc2()//guard
{
 setcolor(8);
 setfillstyle(SOLID_FILL, 8);
 fillellipse (guardx+15,guardy+5,4,5);//head
 bar (guardx+13,guardy+8,guardx+17,guardy+11);//neck
 fillellipse (guardx+25,guardy+24,2,3);//hand left
 fillellipse (guardx+5,guardy+14,2,3);//right
 setcolor(0);
 setfillstyle(SOLID_FILL,0);
 bar (guardx+12,guardy+4,guardx+18,guardy+6);//visor thing
 putpixel (guardx+13,guardy+5,15);//eyes
 putpixel (guardx+17,guardy+5,15);
 setcolor(9);
 setfillstyle(SOLID_FILL, 9);
 bar (guardx+9, guardy+12, guardx+21, guardy+22);//body
 bar (guardx+9, guardy+12, guardx+5,  guardy+15);//right arm
 bar (guardx+21,guardy+12, guardx+26, guardy+15);//left begin
 bar (guardx+26,guardy+15, guardx+23, guardy+23);
 bar (guardx+9, guardy+24, guardx+21, guardy+25);//leg stuff begin
 bar (guardx+9, guardy+25, guardx+14, guardy+30);
 bar (guardx+21,guardy+25, guardx+16, guardy+30);//leg end
 setcolor(8);
 line (guardx+15, guardy+12, guardx+15, guardy+21);
 setcolor(6);
 setfillstyle(SOLID_FILL, 6);
 bar (guardx+4, guardy+30, guardx+6, guardy+9);
 setcolor(7);
 setfillstyle(SOLID_FILL,7);
 fillellipse (guardx+5,guardy+7,1,5);
}

void npc1()//peasant
{
 setcolor(14);
 setfillstyle(SOLID_FILL,14);
 fillellipse (psntx+13,psnty+6,3,3);//head
 putpixel (psntx+11,psnty+6,1);//eyes
 putpixel (psntx+15,psnty+6,1);//eyes
 bar (psntx+12,psnty+9,psntx+14,psnty+12);//neck
 fillellipse (psntx+21,psnty+24,1,2);//left hand
 fillellipse (psntx+4,psnty+24,1,2);//right hand
 setcolor(6);
 setfillstyle(SOLID_FILL,6);
 bar (psntx+8,psnty+15,psntx+18,psnty+21);//body
 bar (psntx+8,psnty+15,psntx+3,psnty+18);//right arm stuff begin
 bar (psntx+3,psnty+18,psntx+6,psnty+23);//end right arm
 bar (psntx+18,psnty+13,psntx+23,psnty+16);//left begin
 bar (psntx+23,psnty+16,psntx+20,psnty+23);//end of left
 bar (psntx+8,psnty+23, psntx+18,psnty+25);
 bar (psntx+8,psnty+23, psntx+12, psnty+30);
 bar (psntx+18,psnty+23, psntx+14,psnty+30);
}
