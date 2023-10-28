CLS
SCREEN 12
PLAY "L16 L4 E C# A# F# F# L16 L16 A A. A# F# < < B > > B. A#"
PLAY "L16 < < A > > < B > < A > F > F# A. > > < > > < >"
PRINT
PRINT
PRINT "            ******THE PROGRAM 1.08******"
PRINT "            **(c) 1993 HAPPY TOWNE INC.*"
PRINT
PRINT
LINE (180, 180)-(240, 240), 11
LINE (240, 240)-(360, 360), 11
LINE (240, 360)-(180, 200), 4
LINE (150, 450)-(440, 158), 10
LINE (250, 680)-(5, 158), 15
PSET (100, 15), 9
PLAY "L16 G G < > > B < B > F# F# L16 < L4 L4 > > < > >"
PLAY "G L16 L4 < G. > F# A. A < B > < >"
INPUT "ENTER"; e$
CLS
startCol = 5
startRow = 5
endCol = 640
endRow = 490
FOR P = 1 TO 40
LINE (startCol, startRow)-(endCol, endRow), 12
startCol = startCol + 9
startRow = startRow + 9
endCol = ednCol - 9
endRow = endRow - 9
NEXT P
LOCATE 22, 32
PRINT
PRINT
PRINT
PRINT
PRINT "Howdy."
INPUT "NAME:"; nam$
PRINT "Thank's "; nam$; "."
INPUT "ENTER"; e$
CLS
FOR cnt = 1 TO 60
   centerCol = INT(RND * 639) + 1
   centerRow = INT(RND * 479) + 1
   radius = INT(RND * 100) + 1
   CIRCLE (centerCol, centerRow), radius
NEXT cnt
LOCATE 15, 20
PRINT
PRINT
PRINT
PRINT "Howdy, "; nam$; ". Like it?"
INPUT "ENTER"; e$
CLS
PLAY "L4 F < > > > < B > < A > > < C# < F# L4 L16"
LOCATE 12, 30
PRINT
PRINT
PRINT
PRINT "See ya, "; nam$; "!"
LINE (180, 190)-(620, 480), 10
LINE (90, 78)-(370, 370), 8
LINE (99, 100)-(500, 45), 9
LINE (99, 100)-(99, 450), 7
INPUT "ENTER"; e$
PRINT
PRINT
PRINT
PRINT
PRINT "                       ****STAFF****"
PRINT "           CREATOR ******** MEEEEEEE"
PRINT "           ASSISTANTS ***** Joe, Fred,"
PRINT "                            Lud, Ned, &"
PRINT "                            Bob"
PRINT "           SPECIAL THANKS TO:"
PRINT "            Happy Towne Inc."
PRINT "           (c) 1993"
PRINT
PRINT "             AND"
PRINT "            !YOU!"
PRINT ""
PRINT
PRINT
PRINT "               ***THE END***"
INPUT "ENTER"; e$
CLS
PLAY "G G. G# C# A A# L16 L4 C C# > < B > G. L16 L4"
LINE (639, 479)-(1, 1), 1
LINE (10, 10)-(10, 80), 5
LINE (350, 120)-(120, 350), 14
LOCATE 12, 34
PRINT "Bye, "; nam$; "! Play me again soon!"
INPUT "ENTER"; e$
PLAY "L16 L4 C G. G. C C# A# A. < B > < A > C A# G# F# < >"
END

