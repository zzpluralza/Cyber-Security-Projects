5 CLS
6 PLAY "L16 L16 L4 C D D. C# A L16 E F L4 L16"
10 PRINT ""
20 PRINT "  **********************  Û Û"
30 PRINT "  * ROLE PLAY O' DEAHT * \___/"
40 PRINT "  ***(c)*HAPPY*TOWNE*Inc.**1993***"
50 PRINT ""
60 PRINT "You must kill the monster O' alla thingyio."
70 PRINT "First you have to kill his Bob the Pet thing."
80 PRINT "All we need is your name and you are set!"
90 PRINT ""
100 PRINT "---------MAIN-MENU--------------------------------------"
110 PRINT ""
115 INPUT "Please enter your name."; name$
120 PRINT ""
125 PRINT "Remember 1=YES and 2=NO!"
130 PRINT ""
135 INPUT "What is the answer to Life, the Universe Everything?"; e!
140 IF e! = 42 THEN GOTO 145:  ELSE GOTO 450
145 PLAY "L4 L16 B A A C E F G. < B > L4 L4"
149 PRINT "Okay that's good."
150 PRINT "What type of character do you want?";
155 INPUT "Would you like to be a fighter?"; f!
160 IF f! = 1 THEN GOTO 220:  ELSE GOTO 165
165 INPUT "How about being a transvilaquist?"; t!
170 IF t! = 1 THEN GOTO 220:  ELSE GOTO 175
175 INPUT "Okay last one how about a ballarina?"; b!
180 IF b! = 1 THEN GOTO 220:  ELSE GOTO 185
185 PRINT ""
190 PRINT "Hey you have to choose one okay!"
195 GOTO 150
196 BEEP
197 BEEP
198 PRINT ""
200 PRINT "  /***\             *      *        *   "
201 PRINT "  *o o*              *     *      *     "
202 PRINT "  *\_/*               *    *    *       "
203 PRINT "  \***/                *   *  *         "
205 PRINT "    *                   *  * *          "
206 PRINT "    *            ***** !!BOOM!! *****  "
207 PRINT " *********            *   *  *"
208 PRINT "    *                *    *   *"
209 PRINT "   *  *             *     *    *"
210 PRINT "  *     *          *      *     *"
211 PRINT "***     ***"
212 PRINT ""
214 INPUT "Press ENTER to contnue."; enter$
215 INPUT "Did you come from first monster?"; mon!
216 IF mon! = 1 THEN GOTO 300:  ELSE GOTO 391
220 PRINT "Okay. You have choosen who you want to be."
222 PRINT "Now we take you to a deep dark castle in Norway."
225 PRINT ""
230 PRINT "You walk up to the door and then a monster of hidous"
240 PRINT "looks comes up to you."
250 PRINT ""
255 PRINT ""
260 PRINT "             (0)"
261 PRINT "            /___\"
262 PRINT "            \   /"
263 PRINT "   YOU       { }"
265 PRINT "   |        / _ \"
266 PRINT "    \.    %%%% %%%% "
268 PRINT ""
270 INPUT "Do you wish to kill it?"; he!
275 IF he! = 1 THEN GOTO 280:  ELSE GOTO 430
280 PRINT ""
285 PRINT "You have plundged your sharp sword into the beast's"
290 PRINT "heart! It falls to the floor and explodes!!!!"
295 GOTO 196
300 PRINT "You walk into the castle. You come towards a nice highly."
305 PRINT "bright throne room. You see the evil deamon thing in the "
310 PRINT "seat. He looks down and stands up."
315 INPUT "Do you wish to slay him?"; slay!
320 IF slay! = 1 THEN GOTO 325:  ELSE GOTO 430
325 PRINT ""
330 PRINT "Your sword is useless to him, so yo quickly open your"
335 PRINT "backpack and look inside."
340 PRINT ""
345 PRINT "You have, 1=knife, 2=clown nose, 3=horn, 4= annoying thing,"
350 PRINT "5=a bow 6=puppet 7=gold bag."
355 INPUT "You must choose one of the items quickly!"; qui!
360 IF qui! = 6 THEN GOTO 365:  ELSE GOTO 430
365 PRINT "You pulled out the puppet and you begin to make it talk."
370 PRINT "The deamon thing stops and looks in a puzzled way."
380 PRINT "After listening to you he explodes! The second monster is"
385 PRINT "Destroyed! You killed it and the kingdom is saved!"
390 GOTO 196
391 BEEP
392 BEEP
393 BEEP
394 BEEP
395 PRINT "Congradulations You won! You killed the evil deamon thing!"
400 PRINT "The people of the unnamed kingdom thank you by eating your"
405 PRINT "appendix, which you saved for a special occasion."
410 PRINT "    THE     Û Û"
415 PRINT "       END  \_/"
420 GOTO 450
430 BEEP
431 PRINT "You did not attack him there fore he killed you."
432 PRINT "You are now dead."
433 GOTO 450
450 PRINT "Bye!, "; name$; ""
455 END

