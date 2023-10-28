CLS
SCREEN 12
PRINT
PRINT
PRINT
PRINT "             ******THE GRAPHIC THING******"
PRINT "             **(c) 1993 Happy Towne Inc.**"
LINE (1, 80)-(680, 80), 4
LINE (1, 81)-(680, 81), 4
LINE (1, 82)-(680, 82), 4
LINE (1, 83)-(680, 83), 4
LINE (1, 84)-(680, 84), 4
LINE (1, 85)-(680, 85), 4
LINE (1, 86)-(680, 86), 12
LINE (1, 87)-(680, 87), 12
LINE (1, 88)-(680, 88), 12
LINE (1, 89)-(680, 89), 12
LINE (1, 90)-(680, 90), 12
LINE (1, 91)-(680, 91), 14
LINE (1, 92)-(680, 92), 14
LINE (1, 93)-(680, 93), 14
LINE (1, 94)-(680, 94), 14
LINE (1, 95)-(680, 95), 14
LINE (1, 96)-(680, 96), 2
LINE (1, 97)-(680, 97), 2
LINE (1, 98)-(680, 98), 2
LINE (1, 99)-(680, 99), 2
LINE (1, 100)-(680, 100), 2
LINE (1, 101)-(680, 101), 1
LINE (1, 102)-(680, 102), 1
LINE (1, 103)-(680, 103), 1
LINE (1, 104)-(680, 104), 1
LINE (1, 105)-(680, 105), 1
PRINT
PRINT
PRINT "CREATED BY: Garrett Burt"
PLAY "L16 L4 C# C# C. < < A A# A. L4 L16 F# F F. G# G."
PLAY "G A# L16 L16 C. C# C < B > L4 L16 F# F. G A < >"
PLAY "F F# G A. L16 C# C. F# < A. > F. L4 L4 L4 L4 < G >"
PLAY "G < < < > < B > A. L16 L16 L4 C# C# C. < < A A# A. L4 L16 F# F F."
PRINT
PRINT
PRINT "============================================================================"
PRINT "Howdy!"
INPUT "Please enter your name."; nam$
PRINT "Thank you, "; nam$; "."
PRINT
PRINT
INPUT "Hit ENTER"; e$
CLS
PRINT
PRINT
LINE (9, 9)-(640, 480), 1
LINE (9, 480)-(640, 1), 2
LINE (7, 290)-(180, 410), 3
LINE (1, 251)-(181, 420), 4
LINE (1, 272)-(182, 430), 5
LINE (2, 283)-(183, 440), 6
LINE (1, 1)-(184, 450), 7
LINE (2, 2)-(639, 479), 8
LINE (3, 3)-(638, 478), 9
LINE (4, 4)-(637, 477), 10
LINE (320, 240)-(310, 230), 11
LINE (420, 98)-(98, 420), 12
LINE (244, 89)-(190, 480), 13
LINE (350, 100)-(100, 410), 14
LINE (15, 150)-(680, 210), 15
PRINT
PRINT
LOCATE 20, 40
PRINT "Hi, "; nam$; "."
LOCATE 30, 40
INPUT "Hit ENTER"; ea$
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
LOCATE 15, 32
PRINT "Goodbye, "; nam$; "!"
PRINT
PRINT
PRINT
PRINT
PRINT
PRINT
PRINT
PRINT
LINE (100, 45)-(150, 45), 2
LINE (100, 46)-(150, 46), 2
LINE (100, 47)-(150, 47), 2
LINE (125, 47)-(125, 120), 10
LINE (126, 47)-(126, 120), 10
LINE (127, 47)-(124, 120), 10
LOCATE 5, 18
PRINT "HE END"
LINE (130, 77)-(680, 77), 4
LINE (130, 78)-(680, 78), 4
LINE (130, 79)-(680, 79), 4
LINE (130, 80)-(680, 80), 14
LINE (130, 81)-(680, 81), 14
LINE (130, 82)-(680, 82), 14
LINE (130, 83)-(680, 83), 2
LINE (130, 84)-(680, 84), 2
LINE (130, 85)-(680, 85), 2
LINE (130, 86)-(680, 86), 1
LINE (130, 87)-(680, 87), 1
LINE (130, 88)-(680, 88), 1
INPUT "Hit ENTER"; e$
CLS
startCol = 0
startRow = 0
endCol = 639
endRow = 479
FOR p = 1 TO 40
   LINE (startCol, startRow)-(ednCol, endRow), 1
   startCol = startCol + 5
   startRow = startRow + 5
   endCol = endCol - 5
   endRow = endRow - 5
NEXT p
LOCATE 25, 40
PRINT "    **STAFF**"
PRINT "CREATOR ***** Garrett Burt"
PRINT "ASSISTANS AND OTHER STUFF-"
PRINT "BY ********** Joe, Ned, Fred,"
PRINT "              Bob, Harold, & "
PRINT "              Harry"
PRINT "           (Who don't exist.)"
PRINT " ========================================================================"
INPUT "Hit ENTER"; e$
CLS
startCol = 0
startRow = 0
endCol = 639
endRow = 479
FOR p = 1 TO 40
   LINE (startCol, startRow)-(ednCol, endRow), 1
   startCol = startCol + 5
   startRow = startRow + 5
   endCol = endCol - 5
   endRow = endRow - 5
NEXT p
LOCATE 12, 40
PRINT "No animals were harmed, just killed."
PRINT "Ha! Just kidding. None were killed either."
PRINT "Thanks for playing this thing!!!"
PRINT
PRINT
INPUT "Hit ENTER"; e$
CLS
LINE (1, 80)-(680, 80), 4
LINE (1, 81)-(680, 81), 4
LINE (1, 82)-(680, 82), 4
LINE (1, 83)-(680, 83), 4
LINE (1, 84)-(680, 84), 4
LINE (1, 85)-(680, 85), 4
LINE (1, 86)-(680, 86), 12
LINE (1, 87)-(680, 87), 12
LINE (1, 88)-(680, 88), 12
LINE (1, 89)-(680, 89), 12
LINE (1, 90)-(680, 90), 12
LINE (1, 91)-(680, 91), 14
LINE (1, 92)-(680, 92), 14
LINE (1, 93)-(680, 93), 14
LINE (1, 94)-(680, 94), 14
LINE (1, 95)-(680, 95), 14
LINE (1, 96)-(680, 96), 2
LINE (1, 97)-(680, 97), 2
LINE (1, 98)-(680, 98), 2
LINE (1, 99)-(680, 99), 2
LINE (1, 100)-(680, 100), 2
LINE (1, 101)-(680, 101), 1
LINE (1, 102)-(680, 102), 1
LINE (1, 103)-(680, 103), 1
LINE (1, 104)-(680, 104), 1
LINE (1, 105)-(680, 105), 1
PRINT
PRINT
PRINT
PRINT
PRINT
PRINT
PRINT
PRINT "           BYE, "; nam$; "!"
PRINT "     THE END"
PLAY "L16 L4 C# C# C+ < < A+ < B L4 L16 C# C+ C#   "
PLAY "G A# L16 L16 C. C# C < B > L4 L16 F# F. G A < >"
PLAY "F F# G A. L16 C# C+ F# < A. > F  L4 L4 L4  < G >"
PLAY "G < < < < B A+ L16 L16 L4 C# C# C < < A A# A. L4 L16 F# F F. G# G."

