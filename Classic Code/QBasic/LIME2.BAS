4 CLS
5 BEEP
8 PRINT "ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป"
10 PRINT ""
15 PRINT "               A                   Û Û"
20 PRINT "   Happy Towne Programming Inc. \_______/"
25 PRINT "          PRESENTS"
30 PRINT ""
35 PRINT "  @ ROLE PLAY II @"
40 PRINT "(Return of the Deamon Thing)"
50 PRINT ""
60 PRINT ""
90 PRINT ""
120 PRINT "Welcome... To the almost ultimate adventure."
125 PRINT ""
130 PRINT "Years have passed since your clash with the deamon"
135 PRINT "thing. You hear news of another threat near a small"
140 PRINT "village, called Swamii. You leave the comforts of a"
145 PRINT "big town and head off towards Swamii."
150 PRINT ""
160 INPUT "What shall you be known as?"; name$
165 PRINT "Wo, "; name$; " is a cool name."
170 PRINT ""
180 INPUT "What gender shall you be? (M/F)"; be$
190 PRINT ""
192 PRINT "1=H-ORC 2=HUMAN 3=GOBLIN 4=MUTANT 5=DWARF 6=ELF"
200 INPUT "What type of creature would you like to be?"; cre!
210 PRINT ""
215 PRINT "1=YES 2=NO"
216 PRINT ""
220 INPUT "HEY, want to be a FIGHTER?"; f!
222 IF f! = 1 THEN GOTO 252:  ELSE GOTO 224
224 PRINT ""
225 INPUT "Shall you be an ARCHER?"; a!
226 IF a! = 1 THEN GOTO 252:  ELSE GOTO 228
228 PRINT ""
229 INPUT "Okay how about being a TOWN DRUNK?"; d!
230 IF d! = 1 THEN GOTO 252:  ELSE GOTO 232
232 PRINT ""
234 INPUT "Okay how about being a PALADIN?"; p!
235 IF p! = 1 THEN GOTO 252:  ELSE GOTO 238
238 PRINT ""
240 PRINT "Hey YOU have to be something here!"
242 GOTO 215
252 INPUT "Is everything okay?"; ok!
254 IF ok! = 1 THEN GOTO 256:  ELSE GOTO 150
256 CLS
258 PRINT "You walk along a nice dirt path that leads you to a sign."
260 PRINT "The sign reads: VILLAGE -> CASTLE <-."
262 PRINT "You think about going to the town, but have some doubts."
263 INPUT "Should you go into town?"; town!
266 IF town! = 1 THEN GOTO 270:  ELSE GOTO 267
267 PRINT "Along the way you get attacked! You blank out."
268 GOTO 485
270 CLS
275 PRINT "       /\"
276 PRINT "     /____\  You are now entering"
277 PRINT "     |Û  Û|  the Village of Swamii."
278 PRINT "     |  Û |    "
279 PRINT "     ๏๐๐๐๐๏"
280 PRINT ""
282 INPUT "Do you want to talk to a person?"; per!
283 IF per! = 1 THEN GOTO 285:  ELSE GOTO 485
285 PRINT ""
286 CLS
290 PRINT "    /-----\ Hi, I'm Bubo."
291 PRINT "    | O O | You ineed of a sword?"
292 PRINT "    |  <  | It sure looks like it. You can get one if"
293 PRINT "    \==== / you answer a question. Okay. Good."
294 PRINT "     \__ /"
295 INPUT "What is 6 * 7 - 5 + 2=?"; plus!
296 IF plus! = 39 THEN GOTO 298:  ELSE GOTO 485
298 PRINT "Good job here is your sword."
300 PRINT "You take the sword and then walk off towards the castle."
310 PRINT "Oh by the way, the clue number to the castle is 98012!"
312 INPUT "Press ENTER to continue."; e$

320 CLS
321 PRINT "You walk in and see a hidous beast snarling at you!"
322 INPUT "Are you going to kill it?"; kil!
323 IF kil! = 1 THEN GOTO 325:  ELSE GOTO 485
325 PRINT "You kill that darn ugly sucker!"
328 BEEP
330 PRINT "You walked up to the castle and see a code pad."
334 INPUT "Enter the code!"; code!
335 IF code! = 98012 THEN GOTO 340:  ELSE GOTO 338
338 PRINT "You suddenly feel sick and you fall down."
339 GOTO 485
340 CLS
341 PRINT "Two hideuos beasts are in your path!"
342 INPUT "Are you going to kill them?"; ill!
343 IF ill! = 1 THEN GOTO 485:  ELSE GOTO 345
345 PRINT "YOu walk up to the monsters and they look back."
346 PRINT "You say hello and they wave back and then go back"
347 PRINT "talking. And you walked onward."
348 INPUT "Press ENTER when ready."; ent$
350 CLS
351 PRINT "   (0)      (0)"
353 PRINT "  /___\    /___\"
354 PRINT "  \   /    \ _ /"
355 PRINT " *** ***  *** ***"
356 PRINT "       . <----YOU"
358 PRINT ""
360 INPUT "Press ENTER when ready."; entr$
362 CLS
364 PRINT "You come up to the end of the room where two doors are."
365 PRINT "You must decide which one to choose. One door says"
366 PRINT "42, and the other 56. Which one is right?"
368 INPUT "Which door do you choose 42 or 56?"; num!
370 IF num! = 42 THEN GOTO 380:  ELSE GOTO 372
372 CLS
373 PRINT "You open door number 56 and a quick burst of "
374 PRINT "flames shoots out towards you. Everything is dark."
375 GOTO 485
380 CLS
382 PRINT "You open door number 42 and it is the right way. "
383 PRINT "You walked farther and another two more monster"
384 PRINT "appear! "
385 INPUT "Are you going to kill them?"; kel!
386 IF kel! = 1 THEN GOTO 392:  ELSE GOTO 388
388 CLS
389 PRINT "The monsters swing their claws and hit you..."
390 GOTO 485
392 CLS
394 PRINT "You swack both of them before they even spotted you!"
396 PRINT "They are all dead!"
397 PRINT ""
398 PRINT " *  /|\0)"
399 PRINT " */    |"
400 PRINT " *____/  . <--YOU"
401 INPUT "Press ENTER when ready."; en$
405 CLS
410 PRINT "You look around and walk onward towards the main hall."
415 PRINT "You notice in the end of the giant table is the "
416 PRINT "deamon thing you had slain before! But he still lives!"
418 PRINT "The deamon thing rises and looks  down at you."
420 PRINT "Ahh, my dear friend."
421 PRINT "So good to see you!"
424 INPUT "Press ENTER when ready."; entre$
425 CLS
428 PRINT "You are carring 1=puppet 2=horn 3=gold 4=cat"
429 PRINT "5=dog 6=a soda 7=your sword 8=dagger 9=leaf"
430 INPUT "You have to act fast! Which one to choose?"; cho!
434 IF cho! = 9 THEN GOTO 440:  ELSE GOTO 435
435 CLS
436 PRINT "You see it is useless and the deamon thing burns you"
437 PRINT "into a tiny piece of coal that is to be bought in a bag"
438 PRINT "with other tiny pieces of coal."
439 GOTO 485
440 CLS
441 BEEP
442 PRINT "You take the leaf and tickle the deamon thing's nose."
443 PRINT "He start to sneeze and he does! He flies threw the "
444 PRINT "brick wall. And then he explodes for good!"
445 BEEP
446 BEEP
447 BEEP
448 BEEP
450 INPUT "Press ENTER when ready."; enter$
451 CLS
455 PRINT "Congradulations! You did it!"
456 PRINT "You beat ROLE PLAY II!! Not many people can say that!"
457 PRINT "=]  Û Û  [="
458 PRINT "  \_____/"
459 BEEP
460 PRINT "Yeah! You saved the world again! The people are rejoycing!"
465 PRINT ""
466 PRINT "  oO ooOo OO o O oo O O o"
467 PRINT "  || |||| || | | || | | |   Hooray for our new hero..."
468 PRINT ""
470 INPUT "Press ENTER when ready."; ente$
472 CLS
475 PRINT "Congradulations once again on finishing this game!"
480 GOTO 500
485 PRINT "You have just died! Sorry, not my fault!"
490 PRINT ""
495 INPUT "Press ENTER when ready."; e$
500 PRINT "   THE"
510 PRINT "     END"
515 PRINT "Goodbye! Please read this information below!!"
518 BEEP
520 PRINT "WARNING!! This is an unregistered version."
521 PRINT "Please register $4 to Happy Towne Programming Inc."
522 PRINT ""
525 PRINT "SEND TO:      Happy Towne Programming"
526 PRINT "              2395East Bernadine Dr."
527 PRINT "              Salt Lake City, Utah"
528 PRINT "                          84109"
529 PRINT ""
530 PRINT "Thanks for playing!"
531 BEEP
532 END

