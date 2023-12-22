import string
flag =[]
with open("messagemod37.txt") as f:
    datum = f.read()
    numval = [int(val) for val in datum.split()]
    for num in numval:
        modval = num % 37
        if modval in range (26):
            flag.append(string.ascii_uppercase[modval])
        elif modval in range (26, 36):
            flag.append(string.digits[modval-26])
        elif modval == 36:
            flag.append('_')
    
joined = "".join(flag)
joined = "picoCTF{" + joined + "}"
print (joined)
