CLS
SCREEN 12
PRINT
PRINT
PRINT
PRINT "       ******THE THING******"
PRINT "     (c) 1993 HAPPY TOWNE INC."
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
LINE (1, 106)-(680, 106), 4
LINE (1, 107)-(680, 107), 4
LINE (1, 108)-(680, 108), 4
LINE (1, 109)-(680, 109), 4
LINE (1, 110)-(680, 110), 4
LINE (1, 111)-(680, 111), 4
LINE (1, 112)-(680, 112), 12
LINE (1, 113)-(680, 113), 12
LINE (1, 114)-(680, 114), 12
LINE (1, 115)-(680, 115), 12
LINE (1, 116)-(680, 116), 12
LINE (1, 117)-(680, 117), 14
LINE (1, 118)-(680, 118), 14
LINE (1, 119)-(680, 119), 14
LINE (1, 120)-(680, 120), 14
LINE (1, 121)-(680, 121), 14
LINE (1, 122)-(680, 122), 2
LINE (1, 123)-(680, 123), 2
LINE (1, 124)-(680, 124), 2
LINE (1, 125)-(680, 125), 2
LINE (1, 126)-(680, 126), 2
LINE (1, 127)-(680, 127), 1
LINE (1, 128)-(680, 128), 1
LINE (1, 129)-(680, 129), 1
LINE (1, 130)-(680, 130), 1
LINE (1, 131)-(680, 131), 1
PLAY "MB"
PLAY "L16 L4 < B > L16 F# < < G G# L16 L4 G L16 D. < < D"
PLAY "L16 L4 < D > L4 F > > G G# L16 L16 G L4 C. > > C"
PRINT
PRINT
PRINT
PRINT
INPUT "Please enter your name."; name$
PRINT "Hello, "; name$; "."
PRINT
INPUT "Hit ENTER."; e$
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
CIRCLE (329, 229), 200, 5 ' Red outline
PAINT (320, 250), 2, 5     ' Green interior
LOCATE 15, 30
PRINT "Howdy, "; name$; ". You're cool."
PRINT
PRINT
PRINT
PRINT
PRINT
PRINT
PRINT
PRINT
PRINT
INPUT "ENTER"; en$
CLS
FOR cnt = 1 TO 1500   ' 1500 pixels in all
   col = INT(RND * 640) + 1
   row = INT(RND * 480) + 1
   colr = INT(RND * 20) + 1
   PSET (col, row), colr
NEXT cnt
LOCATE 18, 24
PRINT "Cool, huh? Kinda like a night sky."
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
INPUT "ENTER"; en$
CLS
FOR cnt = 1 TO 50     ' Draw 50 circles
   centerCol = INT(RND * 639) + 2  ' From 1 to 639
   centerRow = INT(RND * 479) + 2  ' From 1 to 479
   radius = INT(RND * 150) + 2     ' From 1 to 100
   colr = INT(RND * 15) + 2        ' From 1 to 15
   CIRCLE (centerCol, centerRow), radius, colr
LOCATE 14, 25
PRINT "Neato, Huh "; name$; "?"
NEXT cnt
PRINT
PRINT
PRINT
PRINT
PRINT
PRINT
INPUT "ENTER"; e$
CLS
LINE (100, 100)-(180, 300), 4, B  ' Green box
LINE (200, 100)-(280, 300), 2, B  ' Red box
LINE (300, 100)-(380, 300), 9, B  ' Brown box
LINE (400, 100)-(480, 300), 10, B  ' Gray box
PRINT
PRINT
PRINT
PRINT
PRINT
LOCATE 22, 1
INPUT "ENTER"; e$
CLS
CIRCLE (329, 229), 200, 2 ' Red outline
PAINT (320, 250), 9, 2    ' Green interior
LOCATE 15, 20
PRINT "Howdy again, "; name$; "!"
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
PLAY "MB"
PLAY "L16 L16 L4 < < B C D. > A# B. F# F# L16 L4 L16 L4 A# B < B > A# F"
PLAY "L4 L16 L16 > > D C B < A# F F# L4 L16 L4 L16 A# B."
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
LOCATE 14, 40
PRINT "Goodbye, "; name$; "!"
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
LINE (50, 50)-(195, 320), 4, B    ' Green box
LINE (100, 100)-(300, 320), 2, B  ' Red box
LINE (200, 100)-(400, 320), 9, B  ' Brown box
LINE (300, 100)-(500, 320), 10, B  ' Gray box
LOCATE 15, 15
PRINT "Bye now, "; name$; "! Play me again soon!"
PLAY "L16 L16 F# F# C < C > B < < A# B. D < D# > L16 L4 C."
PLAY "L4 < C > F. F C# A. A < < < L16 L16 E E > C A#"
PLAY "L16 L16 B. B D. > D < C > > A A# D. < C# > L16 L4 C."
PRINT
PRINT
PRINT
PRINT
PRINT
PRINT
PRINT
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
LOCATE 15, 5
PRINT " ***STAFF***"
PRINT " CREATOR**** GARRETT BURT"
PRINT " OTHER  STUFF* THOSE PEOPLE"
PRINT " WHO DON'T EXIST***********"
PRINT
PRINT
PRINT
PRINT
PRINT
PRINT
PRINT "Bye, "; name$; "!!"
PRINT
PRINT
INPUT "ENTER"; e$
CLS
PRINT
PRINT
PRINT
PRINT
PRINT "    ****THE END****"
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
LINE (1, 106)-(680, 106), 4
LINE (1, 107)-(680, 107), 4
LINE (1, 108)-(680, 108), 4
LINE (1, 109)-(680, 109), 4
LINE (1, 110)-(680, 110), 4
LINE (1, 111)-(680, 111), 4
LINE (1, 112)-(680, 112), 12
LINE (1, 113)-(680, 113), 12
LINE (1, 114)-(680, 114), 12
LINE (1, 115)-(680, 115), 12
LINE (1, 116)-(680, 116), 12
LINE (1, 117)-(680, 117), 14
LINE (1, 118)-(680, 118), 14
LINE (1, 119)-(680, 119), 14
LINE (1, 120)-(680, 120), 14
LINE (1, 121)-(680, 121), 14
LINE (1, 122)-(680, 122), 2
LINE (1, 123)-(680, 123), 2
LINE (1, 124)-(680, 124), 2
LINE (1, 125)-(680, 125), 2
LINE (1, 126)-(680, 126), 2
LINE (1, 127)-(680, 127), 1
LINE (1, 128)-(680, 128), 1
LINE (1, 129)-(680, 129), 1
LINE (1, 130)-(680, 130), 1
LINE (1, 131)-(680, 131), 1
PRINT
PRINT
PRINT
PRINT
PRINT "    ***A HAPPY TOWNE PRODUCTION***"
PRINT "    ******** (c)  1993 ***********"
PLAY "L4 L4 L16 F < B > D. D. F# L4 E C# A. A# < < A A# L16"
PLAY "L4 L4 F L16 > B > D C. A# A. F# L4 A. D."

