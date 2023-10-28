5 PRINT ""
10 PRINT ""
15 PRINT "   /ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\"
20 PRINT "   ³ QUIZ MANIA 1.85 ³ "
25 PRINT "   \_______II________/"
30 PRINT " (c) Happy Towne Programming Inc. 1993"
35 PRINT ""
40 PRINT ""
45 PRINT "This program is the second of the hit Quiz Mania series."
50 PRINT "You do not need past experience from the other Quiz"
55 PRINT "Mania. You just need luck and skill."
60 PRINT "So get ready and put brain into gear and lets get going!"
65 PRINT ""
70 INPUT "For purposes sake please enter your name."; name$
75 PRINT ""
80 PRINT "Welcome to the game, "; name$; ""
85 PRINT ""
90 PRINT "One moment processing.........."
95 INPUT "Okay, please press ENTER to continue."; en$
100 PRINT ""
105 PRINT "RULES: The rules are simple, just answer a question, with"
110 PRINT "the number of the answer. But first you can choose the "
115 PRINT "level of difficulty! This is one of the newest improvements."
120 PRINT "Well enough with that, lets get going and answer some "
125 PRINT "Questions!"
130 PRINT "Remember 1=YES and 2=NO"
131 PRINT "______________________________________"
132 PRINT "Okay her are the options.             "
133 INPUT "Would you rather quit?"; qu!
134 IF qu! = 1 THEN GOTO 715:  ELSE GOTO 135
135 INPUT "Okay would you like to try the EASY level?"; e!
140 IF e! = 1 THEN GOTO 210:  ELSE GOTO 145
145 PRINT ""
150 INPUT "How about MEDIUM level?"; m!
155 IF m! = 1 THEN GOTO 310:  ELSE GOTO 160
160 PRINT ""
165 INPUT "How about HARD level?"; h!
170 IF h! = 1 THEN GOTO 410:  ELSE GOTO 175
175 PRINT ""
180 INPUT "How about going to MANIA level?"; ma!
185 IF ma! = 1 THEN GOTO 510:  ELSE GOTO 190
190 PRINT ""
195 PRINT "Hey if you haven't picked a level yet look again."
200 GOTO 132
210 PRINT "Okay so you choose EASY eh. Well it's understanable."
215 PRINT "Allright let's get going. Ready Set GO!!!"
216 PRINT ""
220 PRINT "1=1:42PM 2=May vary 3=Any time"
222 INPUT "What is the exact time right now?"; t!
225 IF t! = 3 THEN PRINT "Right good job!";  ELSE PRINT "Ha! You Liberal Airhead."
227 PRINT ""
230 PRINT "1=nothing 2=Political image 3=His family"
232 INPUT "What is more important to Clinton than his ego?"; ego!
234 IF ego! = 2 THEN PRINT "Right! Good work. Keep it up!";  ELSE PRINT "Ha you fool! You must be a Democrat!"
235 PRINT ""
240 PRINT "1=yes 2=no way 3=Only when he's in Eurpoe"
242 INPUT "Is Warren Christopher paranoid?"; p!
245 IF p! = 3 THEN PRINT "Cool!";  ELSE PRINT "You moronic Lobist!"
250 PRINT ""
252 PRINT "1=yes  2=no  3=What was the question again?"
255 INPUT "Is the answer to this question (Hi I am a moron.)?"; mo!
257 IF mo! = 1 THEN PRINT "Ha! Right!";  ELSE PRINT "LOSER!!!"
260 PRINT ""
262 PRINT "WARNING!!! You are now at the EASY's hard question!!"
263 PRINT "1=YES 2=NO"
265 INPUT "Do you wish to continue?"; c!
266 IF c! = 1 THEN GOTO 270:  ELSE GOTO 132
270 PRINT ""
275 PRINT "Okay updating question. All right lets do it!"
276 PRINT ""
280 PRINT "1=White 2=I'm color blind 3=I can read 4=pink duh!"
285 INPUT "What is the color of pink?"; pi!
286 IF pi! = 3 THEN GOTO 290:  ELSE GOTO 287
287 PRINT "Ha! You suck! You got it wrong! Ha!"
288 PRINT "Now warping you back to the Main menu..."
289 GOTO 132
290 PRINT "WOW! You got it right!!! Be happy!"
295 PRINT "Ready to go back to main menu..."
300 GOTO 132
310 PRINT "================================================================="
311 PRINT "Well you choose MEDIUM! Welcome, "; name$; ""
312 PRINT "You know the rules and stuff so let's get cracken!"
315 PRINT ""
317 PRINT "1=yes 2=no 3=This is half full 4=both"
318 INPUT "Is an ardvark a cat?"; cat!
320 IF cat! = 3 THEN PRINT "RIGHT! Don't these answers make sense?";  ELSE PRINT "HA! You loser!"; Ha!; ""
322 PRINT ""
323 PRINT "1=yes 2=because 3=uh... sure. 4=noway"
325 INPUT "Why is a goat a goat?"; goat!
327 IF goat! = 2 THEN PRINT "Oh that's good!";  ELSE PRINT "Oh fine be and act stupid!"
330 PRINT ""
331 PRINT "1=U 2=Me! 3=You 4=That one guy"
333 INPUT "Why ask why ask..."; ask!
335 IF ask! = 1 THEN PRINT "Yeah! RIGHT!";  ELSE PRINT "Boy you're stupid."
337 PRINT ""
340 PRINT "1=yes 2=no 3=maybe 4=so "
342 INPUT "Is the F-16 fighter a jet?"; jet!
345 IF jet! = 1 THEN PRINT "Oh boy that's right!";  ELSE PRINT "Only a moron would get that wrong. Oh sorry. NOT!"
347 PRINT ""
349 PRINT "On no! You are at the QUESTION OF PAINFUL THINKING!"
350 PRINT "You have two choice before you."
351 PRINT "You can 1=Cowardly go back to the main menu or"
352 INPUT "you can 2=Stupidly try it.Which will it be."; be!
356 IF be! = 1 THEN GOTO 132:  ELSE GOTO 360
360 PRINT "Oh boy are you dumb. Oh well it was nice knowing you."
365 PRINT ""
370 PRINT "1=Because he liked it  2=Don't know  3=he's an idiot"
374 PRINT "4=he likes to  5=he's bored  6=for fun"
375 INPUT "Why would a Woodchuck chuck so much wood?"; wood!
380 IF wood! = 5 THEN GOTO 390:  ELSE GOTO 382
382 PRINT "Oh golly! You got it wrong! You shall go back to "
383 PRINT "the Main Menu."
386 GOTO 132
390 PRINT "Wow! You go it right! Congradulations!"
395 PRINT "Now returning to the Main Menu!"
400 GOTO 132
410 PRINT "==============================================================="
411 PRINT "Welcome to the HARD level of QUIZ MANIA!"
412 PRINT "Now let's get going!"
413 PRINT ""
414 PRINT "1=a stupid group 2=a moron 3= a animal 4= who cares 5=me"
415 INPUT "What is the BHAFUC?"; bh!
416 IF bh! = 1 THEN PRINT "RIGHT!";  ELSE PRINT "Geek."
420 PRINT ""
422 PRINT "1=a green thing 2=paper 3=currency 4=dohickeygreen 5=Uh..."
425 INPUT "What is a dollar?"; dol!
428 IF dol! = 3 THEN PRINT "Good job!";  ELSE PRINT "Sucker! Loser! Ha!"
430 PRINT ""
432 PRINT "1=by a big margin 2=Oh yah 3=heck no 4=maybe 5=Ha ha ha!"
435 INPUT "Are APPLE computers better than IBMs?"; ibm!
438 IF ibm! = 3 THEN PRINT "Oh boy are you right!";  ELSE PRINT "How on earth could you get that wrong!"
440 PRINT ""
442 PRINT "1=yah, hu hu hu. 2=no 3=yes 4=yes, please 5=maybe"
444 INPUT "Is yogurt cool?"; yo!
445 IF yo! = 1 THEN PRINT "Cool. Hu hu hu hu hu.";  ELSE PRINT "Joyous suckiness!"
448 PRINT ""
450 PRINT "Here is the QUESTION OF PAINFUL THINKING!"
455 PRINT "Would you like to continue?"
456 INPUT "Well are you or not?"; con!
460 IF con! = 1 THEN GOTO 465:  ELSE GOTO 132
465 PRINT ""
470 PRINT "Well you don't have a brain."
475 PRINT ""
480 PRINT "1=to be evil 2=don't have one 3=to get it right 4=to win"
482 PRINT "5=to live another day 6=don't know 7=just do it"
485 INPUT "What is your quest?"; ques!
490 IF ques! = 3 THEN GOTO 500:  ELSE GOTO 494
494 PRINT "Oh you got it wrong! Oh my cow! Ha ha ha ha ha!"
495 PRINT "Now returning to the Main Menu! LOSER!"
498 GOTO 132
500 PRINT "Nice picken Sherlock! It was right! You liucky Loser!"
505 PRINT "Heading back to the Main Menu."
508 GOTO 132
510 PRINT "+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+"
512 PRINT "Welcome to the hardest level. Level MANIA!!!!"
515 PRINT "Only stupid fools would dare enter this level or you "
518 PRINT "could be very smart... Ha ha! Yah right! Not in a million"
520 PRINT "years! Or maybe?"
525 PRINT ""
530 PRINT "Here is your first question. Still ready to try this level?"
532 PRINT "1 = YES 2 = NO"
535 INPUT "Are you sure?"; sure!
540 IF sure! = 1 THEN GOTO 545:  ELSE GOTO 541
541 PRINT "Okay now returning to Main Menu."
543 GOTO 132
545 PRINT ""
550 PRINT "1=because its fun 2=no reason 3=cruel joke 4=missing eyeball"
555 PRINT "5=incrimination 6=for fun"
556 INPUT "Why are we here?"; liv!
558 IF liv! = 3 THEN PRINT "Bingo!";  ELSE PRINT "Wrongo! Moron!"
560 PRINT ""
565 PRINT "1=Disney Land 2=Disney World 3=Al's 4=joe's 5=Mc.D 6=Uh..."
575 INPUT "You just won the Super Bowl! What are going to next?"; nex!
580 IF nex! = 3 THEN PRINT "Correct... YAWN!...";  ELSE PRINT "Wrong! Wrong! You got it wrong!"
585 PRINT ""
590 PRINT "1=YES 2=Uh...no. 3=What was the question 4=uh...Sure."
594 PRINT "5=never! 6=Does the Pope wear a funny hat?"
595 INPUT "Does the THUNDER BOARD suck?"; suc!
600 IF suc! = 6 THEN PRINT "Cor...rected";  ELSE PRINT "Stupid! You're so STUPID!"
605 PRINT ""
610 PRINT "1=a goat 2=a piece of toast 3=a temple 4=a UFO 5=your lost sock"
614 PRINT "6=Jimmy Hoffa"
615 INPUT "What is on th vary peak of a mountain?"; peak!
620 IF peak! = 5 THEN PRINT "Right! Have you looked there?";  ELSE PRINT "Help me brother! You have it wrong!"
625 PRINT ""
630 PRINT "You are Danger level 20!!! You know the two choices!"
635 INPUT "Do you wish to continue?"; wish!
640 IF wish! = 1 THEN GOTO 650:  ELSE GOTO 642
642 PRINT "Okay ready togo back eh?"
645 GOTO 132
650 PRINT ""
655 PRINT "1=66mph 2=May vary 3=99mph 4=42! 5=What about a door? 6=110kph"
660 PRINT "7=-22 8=It would be dead 9=lightpeed 10=warp 92.8"
665 INPUT "What is the top speed of Europeon Muskrat carring a cow?"; cow!
670 IF cow! = 10 THEN GOTO 680:  ELSE GOTO 675
675 PRINT "Ha it was wrong! Ha! Returning to the Main Menu."
678 GOTO 132
680 PRINT "Good wrok there, "; name$; ""
685 PRINT "Be happy!!"
690 PRINT "           éééééé!YEAH!ééééééé "
695 PRINT "THE END!!!"
700 INPUT "Press ENTER to return back."; back$
710 GOTO 132
715 END


















