CLS
SCREEN 12
PSET (1, 5)  ' Begin at (1,5)
FOR p = 1 TO 25
   LINE -STEP(35, 2), 6
   LINE -STEP(1, 45), 2
NEXT p
PSET (639, 0) ' Begin again at (620, 10)
FOR p = 1 TO 55
   LINE -STEP(-45, 2), 6
   LINE -STEP(2, 35), 2
NEXT p
LOCATE 16, 20
PRINT "       ******A HAPPY TOWNE PRODUCTION Inc."
PRINT "                                    PRESENTS..."
PLAY "L4 F# C# D# A# C# D#"
PRINT
PRINT
PRINT
PRINT
PRINT
PRINT
PRINT
PRINT
PRINT
PRINT
PRINT
INPUT "ENTER"; e$
CLS
LINE (1, 1)-(680, 1), 4
LINE (1, 2)-(680, 2), 4
LINE (1, 3)-(680, 3), 4
LINE (1, 4)-(680, 4), 4
LINE (1, 5)-(680, 5), 4
LINE (1, 6)-(680, 6), 4
LINE (1, 7)-(680, 7), 12
LINE (1, 8)-(680, 8), 12
LINE (1, 9)-(680, 9), 12
LINE (1, 10)-(680, 10), 12
LINE (1, 11)-(680, 11), 12
LINE (1, 12)-(680, 12), 14
LINE (1, 13)-(680, 13), 14
LINE (1, 14)-(680, 14), 14
LINE (1, 15)-(680, 15), 14
LINE (1, 16)-(680, 16), 14
LINE (1, 17)-(680, 17), 2
LINE (1, 18)-(680, 18), 2
LINE (1, 19)-(680, 19), 2
LINE (1, 20)-(680, 20), 2
LINE (1, 21)-(680, 21), 2
LINE (1, 22)-(680, 22), 1
LINE (1, 23)-(680, 23), 1
LINE (1, 24)-(680, 24), 1
LINE (1, 25)-(680, 25), 1
LINE (1, 26)-(680, 26), 1
LINE (1, 27)-(680, 27), 4
LINE (1, 28)-(680, 28), 4
LINE (1, 29)-(680, 29), 4
LINE (1, 30)-(680, 30), 4
LINE (1, 31)-(680, 31), 4
LINE (1, 32)-(680, 32), 4
LINE (1, 33)-(680, 33), 12
LINE (1, 34)-(680, 34), 12
LINE (1, 35)-(680, 35), 12
LINE (1, 36)-(680, 36), 12
LINE (1, 37)-(680, 37), 12
LINE (1, 38)-(680, 38), 14
LINE (1, 39)-(680, 39), 14
LINE (1, 40)-(680, 40), 14
LINE (1, 41)-(680, 41), 14
LINE (1, 42)-(680, 42), 14
LINE (1, 43)-(680, 43), 2
LINE (1, 44)-(680, 44), 2
LINE (1, 45)-(680, 45), 2
LINE (1, 46)-(680, 46), 2
LINE (1, 47)-(680, 47), 2
LINE (1, 48)-(680, 48), 1
LINE (1, 49)-(680, 49), 1
LINE (1, 50)-(680, 50), 1
LINE (1, 51)-(680, 51), 1
LINE (1, 52)-(680, 52), 1
PRINT
PRINT
PRINT
PRINT
PRINT "   ****THE QUIZ****"
PRINT "   (c) 1993 HTP Inc."
PRINT "**CREATED BY: Garrett Burt"
PRINT "   8/24/93"
PLAY "MB"
PLAY "L16 < B > F# A# C# D# D# L4 A. D A F F. A. A#"
LOCATE 30, 1
INPUT "ENTER"; e$
CLS
startCol = 0
startRow = 0
endCol = 639
endRow = 479
INPUT "Enter your name"; nam$
PRINT "          Hello, "; nam$; "."
PRINT
PRINT
PRINT "INSTRUCTIONS:"
PRINT "The goal in this program is to get as many questions right as "
PRINT "possible. You must answer them correctly with all capitol letters."
PRINT "Also every word answer will be only one word. So no: THE BOB. Good."
PRINT "Also there will be many trick questions. Just answer them by typing"
PRINT "in: TRICK, and then it will be right! And not wrong! What a concept."
PRINT "You will notice that every screen besides this one will have a"
PRINT "nifty background! That makes it alot cooler! To exit at any time"
PRINT "just press CTRL BREAK, or PAUSE. Okay? Good."
PRINT "It is a very simple program. so let's get going and play!"
PRINT "Let's do it! Oh yah! The questions will get tougher as you go along."
PRINT "Just thought I'd like to point that out. Let's go, "; nam$; "!"
PRINT
LOCATE 30, 1
INPUT "ENTER"; e$
CLS
LINE (100, 100)-(180, 300), 4, B  ' Green box
LINE (200, 100)-(280, 300), 14, B  ' Red box
LINE (300, 100)-(380, 300), 2, B  ' Brown box
LINE (400, 100)-(480, 300), 1, B   ' Gray box
PRINT
PRINT
PRINT
PRINT
INPUT "When was the war of 1812?"; war!
IF war! = 1812 THEN PRINT "GOOD JOB!";  ELSE PRINT "Sorry that's wrong."
PRINT
PRINT
INPUT "What is the total of 5+9-10X5-20= to?"; sum!
IF sum! = 0 THEN PRINT "Right oh, "; nam$; "!";  ELSE PRINT "Sorry, "; nam$; ". That's wrong."
PRINT
PRINT
PRINT "If a guy has 22 apples and gives you 2, how many do you have?"
INPUT "ANSWER"; ans!
IF ans! = 2 THEN PRINT "That is very right!";  ELSE PRINT "Whoops. You got that wrong."
PRINT
PRINT
INPUT "What is the biggest organ on the human body?"; bod$
IF bod$ = "SKIN" THEN PRINT "Very good, "; nam$; ".";  ELSE PRINT "Sorry, that's wrong."
PRINT
PRINT
LOCATE 30, 1
INPUT "ENTER"; e$
CLS
startCol = 0
startRow = 0
endCol = 639
endRow = 479
FOR p = 1 TO 40
   LINE (startCol, startRow)-(ednCol, endRow), 2
   startCol = startCol + 5
   startRow = startRow + 5
   endCol = endCol - 5
   endRow = endRow - 5
NEXT p
PRINT
PRINT
PRINT
INPUT "Does a THUNDER BOARD suck? (YES/NO)"; thu$
IF thu$ = "YES" THEN PRINT "If you got that one wrong you would really suck.";  ELSE PRINT "Oh my! "; nam$; "! How could you get that wrong!"
PRINT
PRINT
PRINT
INPUT "Is EGA better than VGA or CGA?"; eg$
IF eg$ = "CGA" THEN PRINT "RIGHT, "; nam$; "!";  ELSE PRINT "Boy, you really suck, "; nam$; "."
PRINT
PRINT
PRINT
PRINT "STORY PROBLEM: In a story problem you will be asked a few questions. You"
PRINT "ofcourse will have to answer, and remember all capitol letters!"
PRINT
PRINT "A boy walks home from school, and sees a dead chipmunk and then taunts"
PRINT "the poor dead creature. Then a UFO comes and kills the boy. He is blown"
PRINT "up into a bloody pulp. Then a alien comes up and taunts the dead boy."
PRINT "Which leads to the death of that alien by a sudden implosion."
PRINT "      THE     END"
PRINT
INPUT "What blew up the boy?"; boy$
IF boy$ = "UFO" THEN PRINT "Right oh chap!";  ELSE PRINT "Not quite."
PRINT
INPUT "What did the boy do to the chipmunk?"; chip$
IF chip$ = "TAUNT" THEN PRINT "Very good.";  ELSE PRINT "Sorry, that's wrong."
PRINT
INPUT "What did the alien taunt?"; tau$
IF tau$ = "BOY" THEN PRINT "That is correct, "; nam$; ".";  ELSE PRINT "Sorry, that's wrong, "; nam$; "."
LOCATE , 30, 1
INPUT "ENTER"; e$
CLS
startCol = 0
startRow = 0
endCol = 639
endRow = 479
FOR p = 1 TO 40
   LINE (startCol, startRow)-(ednCol, endRow), 4
   startCol = startCol + 5
   startRow = startRow + 5
   endCol = endCol - 5
   endRow = endRow - 5
NEXT p
CIRCLE (329, 229), 200, 11 ' Red outline
PAINT (320, 250), 4, 11     ' Green interior
PRINT
PRINT
INPUT "Who wrote: THE TEMPEST?"; temp$
IF temp$ = "SHAKESPEAR" THEN PRINT "Wow! You're pretty smart.";  ELSE PRINT "Nope. I guess you don't know your SHAKESPEAR!"
PRINT
PRINT
PRINT
INPUT "Are shooting stars, really stars?"; sta$
IF sta$ = "NO" THEN PRINT "You're good, "; nam$; ".";  ELSE PRINT "Nope, you're very wrong. MORON!"
PRINT
PRINT
PRINT
INPUT "What is 55X1+9-60X4=?"; x!
IF x! = 16 THEN PRINT "That's correct "; nam$; "!";  ELSE PRINT "Nope, "; nam$; " that's wrong."
PRINT
PRINT
PRINT
INPUT "What is the ultimate answer to life, universe, everything?"; lif!
IF lif! = 42 THEN PRINT "Right! You're correct!";  ELSE PRINT "Nope, no quite. I didn't know, the answer was,"; lif!; "."
LOCATE 30, 1
INPUT "ENTER"; e$
CLS
startCol = 0
startRow = 0
endCol = 639
endRow = 479
FOR p = 1 TO 50
   LINE (startCol, startRow)-(ednCol, endRow), 4
   startCol = startCol + 2
   startRow = startRow + 2
   endCol = endCol - 2
   endRow = endRow - 2
NEXT p
startCol = 48
startRow = 48
endCol = 639
endRow = 479
FOR p = 1 TO 40
   LINE (startCol, startRow)-(ednCol, endRow), 14
   startCol = startCol + 5
   startRow = startRow + 5
   endCol = endCol - 5
   endRow = endRow - 5
NEXT p
startCol = 75
startRow = 75
endCol = 639
endRow = 479
FOR p = 1 TO 40
   LINE (startCol, startRow)-(ednCol, endRow), 2
   startCol = startCol + 5
   startRow = startRow + 5
   endCol = endCol - 5
   endRow = endRow - 5
NEXT p
startCol = 110
startRow = 110
endCol = 639
endRow = 479
FOR p = 1 TO 40
   LINE (startCol, startRow)-(ednCol, endRow), 1
   startCol = startCol + 5
   startRow = startRow + 5
   endCol = endCol - 5
   endRow = endRow - 5
NEXT p
PRINT
PRINT "STORY PROBLEM: In this one there will be a trick question. You must"
PRINT "just type in: TRICK and you'll get it right. If not it of course will"
PRINT "be wrong, and remember, all caps please....."
PRINT
PRINT
PRINT "A psycotic killer walk up to a dog and kills the dog till it's dead."
PRINT "Then a police officer kills a mouse who had killed the killer. Then a"
PRINT "cat kills the cop who killed the mouse, which had killed the dog. Then"
PRINT "a nuclear explosion blows up the world, ending this story."
PRINT "     THE    END"
PRINT
PRINT
INPUT "Who killed the cop?"; kil$
IF kil$ = "CAT" THEN PRINT "Very good.";  ELSE PRINT "Nope I don't think it was, "; kil$; "."
PRINT
PRINT
INPUT "Who killed the world?"; wor$
IF wor$ = "TRICK" THEN PRINT "Good job, "; nam$; "! You've found the trick question.";  ELSE PRINT "Sorry, "; nam$; ". It was the trick question."
PRINT
PRINT
INPUT "Who killed the killer?"; kio$
IF kio$ = "MOUSE" THEN PRINT "That is correct.";  ELSE PRINT "Nope. It sure wasn't the "; kio$; "."
PRINT
PRINT
PRINT "FINAL QUESTION:"
PRINT "If it takes a rocket going around 1 MPH 2 hours to get to earth so it "
PRINT "can blow it up with a nuclear bomb, what is the capitol of Ohio?"
INPUT "ANSWER"; uns$
IF uns$ = "COLUMBUS" THEN PRINT "Bullseye!";  ELSE PRINT "WRONG! Ha ha ha!"
LOCATE 30, 1
INPUT "ENTER"; e$
CLS
FOR cnt = 1 TO 1500   ' 1500 pixels in all
   col = INT(RND * 640) + 1
   row = INT(RND * 480) + 1
   colr = INT(RND * 20) + 1
   PSET (col, row), colr
NEXT cnt
CIRCLE (329, 229), 200, 14 ' Red outline
PAINT (320, 250), 9, 14    ' Green interior
PRINT
PRINT "Okay, if a shoe fits a man who has a sie 12 and then shoots a gun "
PRINT "towards Mars, but only makes it half way, what is the color of an"
INPUT "orange?"; or$
IF or$ = "ORANGE" THEN PRINT "Wow "; nam$; "! You're smarter than the last peron.";  ELSE PRINT "Nope I don't think it is, "; or$; "."
PRINT
PRINT
PRINT
INPUT "What state is Washinton D.C. belong to?"; sta$
IF sta$ = "TRICK" THEN PRINT "Very good. It does not belong to any state!";  ELSE PRINT "Nope it doesn't belong to any state! Duh!"
LOCATE 30, 1
INPUT "ENTER"; e$
CLS
LINE (50, 100)-(115, 100), 2
LINE (50, 100)-(72, 130), 2
LINE (115, 100)-(120, 112), 2
LINE (120, 112)-(128, 100), 2
LINE (128, 100)-(150, 100), 2
LINE (150, 100)-(170, 118), 2
LINE (170, 118)-(190, 100), 2
LINE (190, 100)-(218, 100), 2
LINE (218, 100)-(223, 112), 2
LINE (223, 112)-(231, 100), 2
LINE (231, 100)-(296, 100), 2
LINE (296, 100)-(274, 130), 2
LINE (170, 118)-(170, 170), 2
LINE (170, 170)-(72, 170), 2
LINE (120, 112)-(120, 170), 2
LINE (170, 170)-(274, 170), 2
LINE (223, 112)-(223, 170), 2
LINE (72, 130)-(72, 170), 2
LINE (274, 130)-(274, 170), 2
LINE (274, 135)-(265, 130), 2
LINE (265, 130)-(232, 130), 2
LINE (232, 130)-(223, 135), 2
LINE (72, 135)-(81, 130), 2
LINE (81, 130)-(111, 130), 2
LINE (111, 130)-(120, 135), 2
LINE (72, 170)-(72, 230), 2
LINE (274, 170)-(274, 230), 2
LINE (74, 215)-(274, 215), 2
LINE (74, 230)-(85, 235), 2
LINE (274, 230)-(265, 235), 2
LINE (265, 235)-(85, 235), 2
LINE (74, 170)-(100, 215)
LINE (100, 215)-(126, 170)
LINE (126, 170)-(154, 215)
LINE (154, 215)-(180, 170)
LINE (180, 170)-(206, 215)
LINE (206, 215)-(232, 170)
LINE (232, 170)-(258, 215)
LINE (258, 215)-(272, 170)
PRINT "CONGRADULATIONS, "; nam$; "! You're ready for the final and most "
PRINT "challenging question. It is made up of two parts. You of course must"
PRINT "Answer them in all caps, or it will ofcourse be counted wrong. So relax"
PRINT "And solve it! Good luck "; nam$; "!"
FOR cnt = 1 TO 800
   col = INT(RND * 640) + 1
   row = INT(RND * 480) + 1
   colr = INT(RND * 20) + 1
   PSET (col, row), colr
NEXT cnt
CIRCLE (329, 229), 50, 14  ' Red outline
PAINT (320, 250), 9, 14    ' Green interior
CIRCLE (400, 100), 50, 14  ' Red outline
PAINT (400, 100), 9, 14    ' Green interior
CIRCLE (500, 400), 50, 14  ' Red outline
PAINT (500, 400), 9, 14    ' Green interior
startCol = 75
startRow = 75
endCol = 639
endRow = 479
FOR p = 1 TO 40
   LINE (startCol, startRow)-(ednCol, endRow), 2
   startCol = startCol + 5
   startRow = startRow + 5
   endCol = endCol - 5
   endRow = endRow - 5
NEXT p
LOCATE 16, 1
PRINT "What is the one word that rymes with: ORANGE and what color is it?"
INPUT "Ryming word="; rym$
IF rym$ = "TRICK" THEN PRINT "You've got the first part correct...";  ELSE PRINT "Oh... That is sad. Well try the second part."
INPUT "Color="; col$
IF col$ = "TRICK" THEN PRINT "Wow! You got the second part right! Nice going, "; nam$; "!";  ELSE PRINT "Sorry, "; nam$; ". That wasn't correct."
PRINT
PRINT
PRINT
PRINT
BEEP
LOCATE 30, 1
INPUT "ENTER"; e$
CLS
startCol = 0
startRow = 0
endCol = 639
endRow = 479
FOR p = 1 TO 50
   LINE (startCol, startRow)-(ednCol, endRow), 4
   startCol = startCol + 2
   startRow = startRow + 2
   endCol = endCol - 2
   endRow = endRow - 2
NEXT p
startCol = 48
startRow = 48
endCol = 639
endRow = 479
FOR p = 1 TO 40
   LINE (startCol, startRow)-(ednCol, endRow), 14
   startCol = startCol + 5
   startRow = startRow + 5
   endCol = endCol - 5
   endRow = endRow - 5
NEXT p
startCol = 75
startRow = 75
endCol = 639
endRow = 479
FOR p = 1 TO 40
   LINE (startCol, startRow)-(ednCol, endRow), 2
   startCol = startCol + 5
   startRow = startRow + 5
   endCol = endCol - 5
   endRow = endRow - 5
NEXT p
startCol = 110
startRow = 110
endCol = 639
endRow = 479
FOR p = 1 TO 40
   LINE (startCol, startRow)-(ednCol, endRow), 1
   startCol = startCol + 5
   startRow = startRow + 5
   endCol = endCol - 5
   endRow = endRow - 5
NEXT p
PLAY "L16 < B > F# A# C# D# D# L4 A. D A F F. A. A#"
PRINT
PRINT
PRINT
LOCATE 15, 16
PRINT "CONGRADUTLATIONS"
PRINT "Congradulations to, "; nam$; ". For finishing The Quiz."
PRINT "If you did not get all the questions right just keep trying and"
PRINT "You will soon. Even if you did get them all right wait and then"
PRINT "play me again soon. So take it easy and hope that you'll play me"
PRINT "again soon, "; nam$; "!"
LOCATE 30, 1
INPUT "ENTER"; e$
CLS
FOR cnt = 1 TO 800
   col = INT(RND * 640) + 1
   row = INT(RND * 480) + 1
   colr = INT(RND * 20) + 1
   PSET (col, row), colr
NEXT cnt
CIRCLE (329, 229), 50, 14  ' Red outline
PAINT (320, 250), 9, 14    ' Green interior
CIRCLE (400, 100), 50, 14  ' Red outline
PAINT (400, 100), 9, 14    ' Green interior
CIRCLE (500, 400), 50, 14  ' Red outline
PAINT (500, 400), 9, 14    ' Green interior
startCol = 75
startRow = 75
endCol = 639
endRow = 479
FOR p = 1 TO 40
   LINE (startCol, startRow)-(ednCol, endRow), 2
   startCol = startCol + 5
   startRow = startRow + 5
   endCol = endCol - 5
   endRow = endRow - 5
NEXT p
LOCATE 8, 1
PRINT "        ****STAFF****"
PRINT "CREATOR=== Garrett Burt"
PRINT "OTHER STUFF== none"
PRINT
PRINT "No animals were harmed or KILLED during the making of this program."
PRINT "Thank's again, "; nam$; " for play this game. Do try it again soon."
LOCATE 30, 1
INPUT "ENTER"; e$
CLS
PSET (1, 1)  ' Begin at (1,1)
FOR p = 1 TO 25
   LINE -STEP(35, 2), 4
   LINE -STEP(1, 20), 2
NEXT p
PSET (639, 0) ' Begin again at (639, 0)
FOR p = 1 TO 55
   LINE -STEP(-20, 2), 2
   LINE -STEP(2, 35), 4
NEXT p
LOCATE 16, 20
PRINT "       ******A HAPPY TOWNE PRODUCTION Inc.******"
PRINT "                             THANKS FOR PLAYING"
PLAY "L4 F# C# D# A# C# D#"
PLAY "L16 < B > F# A# C# D# D# L4 A. D A F F. A. A#"

