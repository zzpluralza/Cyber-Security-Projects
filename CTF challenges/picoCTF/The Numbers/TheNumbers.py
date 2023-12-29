#Number Conversion for picoCTF "The Numbers"
import string
flag = []
header = [16,9,3,15,3,20,6]
flagmain=[20,8,5,14,21,13,2,5,18,19,13,1,19,15,14]

for n in header:
    flag.append(string.ascii_uppercase[n-1])
flag.append("{")

for i in flagmain:
    flag.append(string.ascii_uppercase[i-1])
flag.append("}")
flagjoined = ''.join(flag)
print (flagjoined)
